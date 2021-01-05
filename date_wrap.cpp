#include <iostream>
#include "date_wrap.h"
using std::ostream;


dateWrap::dateWrap(int day, int month, int year)//Constructor
{
    if(!((day >= 1 && day <= 30) && (month >= 1 && month <= 12))){
        return;
    }
    this->day = day;
    this->month = month;
    this->year = year;
}

const int dateWrap::dayReturn ()
{
    return day;
}

const int dateWrap::monthReturn ()
{
    return month;
}

const int dateWrap::yearReturn()
{
    return year;
}


ostream& operator<<(ostream& out, const dateWrap& date)
{
    out << date.day << '/' << date.month << '/' << date.year;
    return out;
}

bool dateWrap::operator< (const dateWrap& date) const //Should use the copy functions maybe instead of typing this.
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

 bool dateWrap::operator> (const dateWrap& date) const
 {
     return (date < *this);
 }

bool dateWrap::operator== (const dateWrap& date) const
{
    if (this->day == date.day && this->month == date.month && this->year == date.year){
        return true;
    }
    return false;  
}

bool dateWrap::operator<= (const dateWrap& date) const
{
    return (*this < date || *this == date);
}

bool dateWrap::operator>= (const dateWrap& date) const
{
    return (date <= *this);
}

bool dateWrap::operator!= (const dateWrap& date) const
{
    return (!(*this == date));
}

dateWrap dateWrap::operator++ (int)
{
    dateWrap temp = *this;
    Date date = dateCreate(this->day, this->month, this->year);
    dateTick(date);
    dateGet(date, &this->day, &this->month, &this->year);
    dateDestroy(date);

    return temp;    
}

dateWrap& dateWrap::operator+= (int increment)
{
    Date date = dateCreate(this->day, this->month, this->year);
    for (int i = 0 ; i < increment ; i++)
    {
        dateTick(date);
    }
    dateGet(date, &this->day, &this->month, &this->year);

    return *this;
}

dateWrap dateWrap::operator+ (int increment)
{
    dateWrap newDate(this->day, this->month, this->year);
    newDate += increment;

    return newDate;
}