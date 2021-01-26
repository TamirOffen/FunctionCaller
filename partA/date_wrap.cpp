#include <iostream>
#include "date_wrap.h"
#include "exceptions.h"

using mtm::DateWrap;

extern "C" 
{
    #include "date.h"
}
//Initialize this's day month and year to the given day month and year.
DateWrap::DateWrap(int day, int month, int year) : date_day(day), date_month(month), date_year(year)
{
    //In case of invalid date.
    if(day < 1 || day > 30 || month < 1 || month > 12) 
    {
        throw mtm::InvalidDate();
    }
}


const int DateWrap::day () const
{
    return date_day;
}

const int DateWrap::month () const
{
    return date_month;
}

const int DateWrap::year() const
{
    return date_year;
}

//Prints in the required format (d/m/yyyy)
ostream& mtm::operator<<(ostream& out, const DateWrap& date)
{
    out << date.date_day << '/' << date.date_month << '/' << date.date_year;
    return out;
}

bool DateWrap::operator< (const DateWrap& date) const
{
    if(this->date_year < date.date_year){
        return true;
    }else if(this->date_year > date.date_year){
        return false;
    }else if(this->date_month < date.date_month){
        return true;
    }else if(this->date_month > date.date_month){
        return false;
    }else if (this->date_day < date.date_day){
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
    if (this->date_day == date.date_day && this->date_month == date.date_month && this->date_year == date.date_year){
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
    Date date = dateCreate(this->date_day, this->date_month, this->date_year);
    //Increases the date by 1 day.
    dateTick(date);
    //put the new values of date after the increment into the day month and year of the current date (this).
    dateGet(date, &this->date_day, &this->date_month, &this->date_year);
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
    Date date = dateCreate(this->date_day, this->date_month, this->date_year);
    //Increases the date by (increment) days.
    for (int i = 0 ; i < increment ; i++)
    {
        dateTick(date);
    }
    //Put the day month and year of date after the addition into the current date (this).
    dateGet(date, &this->date_day, &this->date_month, &this->date_year);
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
    DateWrap newDate(this->date_day, this->date_month, this->date_year);
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
    DateWrap newDate(date.date_day, date.date_month, date.date_year);
    newDate += increment;

    return newDate;
}


//copy constructor
DateWrap::DateWrap(const DateWrap& date) :
    date_day(date.date_day), date_month(date.date_month), date_year(date.date_year)
{
}

