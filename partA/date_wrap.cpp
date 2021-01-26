#include <iostream>
#include "date_wrap.h"
#include "exceptions.h"

using mtm::DateWrap;

extern "C" 
{
    #include "date.h"
}
//Initialize this's day month and year to the given day month and year.
DateWrap::DateWrap(int day, int month, int year) : day(day), month(month), year(year)
{
    //In case of invalid date.
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

//Prints in the required format (d/m/yyyy)
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
     //Uses the less than operator function.
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
    //Uses the is equal operator function.
    return (*this < date || *this == date);
}

bool DateWrap::operator>= (const DateWrap& date) const
{
    ////Uses the less than or equal operator function.
    return (date <= *this);
}

bool DateWrap::operator!= (const DateWrap& date) const
{
    //Uses the is equal operator function.
    return (!(*this == date));
}

DateWrap DateWrap::operator++ (int)
{
    //Creates a new DateWrap to store this in it.
    DateWrap temp = *this;
    //Creates a new date and initializes it with copeis of the values of the current DateWrap (this).
    Date date = dateCreate(this->day, this->month, this->year);
    //Increases the date by 1 day.
    dateTick(date);
    //put the new values of date after the increment into the day month and year of the current date (this).
    dateGet(date, &this->day, &this->month, &this->year);
    //Frees the created date.
    dateDestroy(date);
    return temp;    
}

DateWrap& DateWrap::operator+= (int increment)
{
    if(increment < 0){
        throw mtm::NegativeDays();
    }

    //Creates a new date and puts the current's date information copies in it.
    Date date = dateCreate(this->day, this->month, this->year);
    //Increases the date by (increment) days.
    for (int i = 0 ; i < increment ; i++)
    {
        dateTick(date);
    }
    //Put the day month and year of date after the addition into the current date (this).
    dateGet(date, &this->day, &this->month, &this->year);
    //Frees the created date.
    dateDestroy(date);
    return *this;
}

DateWrap DateWrap::operator+(int increment)// this + 3
{
    if(increment < 0)
    {
        throw mtm::NegativeDays();
    }
    //Uses the += operator
    DateWrap newDate(this->day, this->month, this->year);
    newDate += increment;

    return newDate;
}

DateWrap mtm::operator+ (int increment, DateWrap& date)// 3 + this
{
    if(increment < 0)
    {
        throw mtm::NegativeDays();
    }
    //Uses the += operator
    DateWrap newDate(date.day, date.month, date.year);
    newDate += increment;

    return newDate;
}


//copy constructor
DateWrap::DateWrap(const DateWrap& date) :
    day(date.day), month(date.month), year(date.year)
{
}

