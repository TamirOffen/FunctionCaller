#include <iostream>
#include "date_wrap.h"
#include "exceptions.h"

using mtm::DateWrap;

extern "C" 
{
    #include "date.h"
}

DateWrap::DateWrap(int day, int month, int year) : day(day), month(month), year(year)
{
    if(day < 1 || day > 30 || month < 1 || month > 12) 
    {
        throw mtm::InvalidDate();
    }
}


const int DateWrap::dayReturn () const
{
    return day;
}

const int DateWrap::monthReturn () const
{
    return month;
}

const int DateWrap::yearReturn() const
{
    return year;
}


ostream& mtm::operator<<(ostream& out, const DateWrap& date)
{
    out << date.day << '/' << date.month << '/' << date.year;
    return out;
}

bool DateWrap::operator< (const DateWrap& date) const
{
    if(this->year < date.year){
        return true;
    }else if(this->year > date.year){
        return false;
    }else if(this->month < date.month){
        return true;
    }else if(this->month > date.month){
        return false;
    }else if (this->day < date.day){
        return true;
    }else {
        return false;
    }
}

 bool DateWrap::operator> (const DateWrap& date) const
 {
     return (date < *this);
 }

bool DateWrap::operator== (const DateWrap& date) const
{
    if (this->day == date.day && this->month == date.month && this->year == date.year){
        return true;
    }
    return false;  
}

bool DateWrap::operator<= (const DateWrap& date) const
{
    return (*this < date || *this == date);
}

bool DateWrap::operator>= (const DateWrap& date) const
{
    return (date <= *this);
}

bool DateWrap::operator!= (const DateWrap& date) const
{
    return (!(*this == date));
}

DateWrap DateWrap::operator++ (int)
{
    DateWrap temp = *this;
    Date date = dateCreate(this->day, this->month, this->year);
    dateTick(date);
    dateGet(date, &this->day, &this->month, &this->year);
    dateDestroy(date);
    return temp;    
}

DateWrap& DateWrap::operator+= (int increment)
{
    if(increment < 0){
        throw mtm::NegativeDays();
    }

    Date date = dateCreate(this->day, this->month, this->year);
    for (int i = 0 ; i < increment ; i++)
    {
        dateTick(date);
    }
    dateGet(date, &this->day, &this->month, &this->year);

    dateDestroy(date);
    return *this;
}

DateWrap DateWrap::operator+(int increment)
{
    if(increment < 0)
    {
        throw mtm::NegativeDays();
    }

    DateWrap newDate(this->day, this->month, this->year);
    newDate += increment;

    return newDate;
}

DateWrap mtm::operator+ (int increment, DateWrap& date)
{
    if(increment < 0)
    {
        throw mtm::NegativeDays();
    }

    DateWrap newDate(date.day, date.month, date.year);
    newDate += increment;

    return newDate;
}



DateWrap::DateWrap(const DateWrap& date) :
    day(date.day), month(date.month), year(date.year)
{
}




