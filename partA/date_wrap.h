#ifndef DATEWRAP_H_
#define DATEWRAP_H_

#include <iostream>
extern "C" 
{
    #include "../provided/date.h"
}
using std::ostream;

namespace mtm
{
    //A class which represents a date (consisting of day, month and year).
    class DateWrap;
    //Both functions are being put here because both are declared as friend functions.
    ostream& operator<< (ostream& out, const DateWrap& date);//print operator
    DateWrap operator+ (int, DateWrap&);//int before date for instance: (3 + date1).
}

    class mtm::DateWrap 
    {
        int date_day;
        int date_month;
        int date_year;

    public:
        DateWrap(int day, int month, int year); // Constructor
        DateWrap(const DateWrap&);// Copy constructor

        const int day () const;//Returns day.
        const int month () const;//returns month.
        const int year() const;//returns year.


        friend ostream& operator<< (ostream& out, const DateWrap& date);
        bool operator< (const DateWrap&) const;//less than operator (this < date2)
        bool operator> (const DateWrap&) const;//more than operator (this > date2)
        bool operator== (const DateWrap&) const;//is equal operator (this == date2)
        bool operator<= (const DateWrap&) const;//less than or equal operator (this <= date2)
        bool operator>= (const DateWrap&) const;//more than or equal operator (this >= date2)
        bool operator!= (const DateWrap&) const;//Not equal operator (this != date2)
        DateWrap operator++ (int); //this++
        DateWrap& operator++ () = delete; //++i not needed 
        DateWrap& operator+= (int); // this += date2 -----> eventually returns this by reference after adding date2.
        DateWrap operator+ (int); // this + 3 --------> eventually returns a new date which occurs 3 days after (this).
        friend DateWrap operator+ (int, DateWrap&); // 3 + this , eventually returns a new date which occurs 3 days after (this).
        
        
    };

#endif//DATEWRAP_H_

