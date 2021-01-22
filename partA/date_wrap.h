#ifndef DATEWRAP_H_
#define DATEWRAP_H_

#include <iostream>
#include "date.h"
using std::ostream;

namespace mtm
{
    class DateWrap;
    ostream& operator<< (ostream& out, const DateWrap& date);
    DateWrap operator+ (int, DateWrap&);
}

    class mtm::DateWrap 
    {
        int day;
        int month;
        int year;

    public:
        DateWrap(int day, int month, int year); // throw: InvalidDate
        DateWrap(const DateWrap&);

        const int dayReturn () const; 
        const int monthReturn () const;
        const int yearReturn() const;


        friend ostream& operator<< (ostream& out, const DateWrap& date);
        bool operator< (const DateWrap&) const;
        bool operator> (const DateWrap&) const;
        bool operator== (const DateWrap&) const;
        bool operator<= (const DateWrap&) const;
        bool operator>= (const DateWrap&) const;
        bool operator!= (const DateWrap&) const;
        DateWrap operator++ (int); //i++
        DateWrap& operator++ () = delete; //++i (is not supported)
        DateWrap& operator+= (int); // throw: NegativeDays
        DateWrap operator+ (int); // throw: NegativeDays
        friend DateWrap operator+ (int, DateWrap&);
        
        
    };

#endif//DATEWRAP_H_

