#ifndef DATEWRAP_H_
#define DATEWRAP_H_

#include <iostream>
#include "date.h"

namespace mtm
{
    class DateWrap;
    std::ostream& operator<< (std::ostream& out, const DateWrap& date);
    DateWrap operator+ (int, DateWrap&);
}

    class mtm::DateWrap 
    {
        int day;
        int month;
        int year;

    public:
        DateWrap(int day, int month, int year);
        DateWrap(const DateWrap&);
        ~DateWrap() = default;

        const int day() const; 
        const int month() const;
        const int year() const;


        friend std::ostream& operator<< (std::ostream& out, const DateWrap& date);
        bool operator< (const DateWrap&) const;
        bool operator> (const DateWrap&) const;
        bool operator== (const DateWrap&) const;
        bool operator<= (const DateWrap&) const;
        bool operator>= (const DateWrap&) const;
        bool operator!= (const DateWrap&) const;
        DateWrap operator++ (int); //i++
        DateWrap& operator++ () = delete; //++i (is not supported)
        DateWrap& operator+= (int); 
        DateWrap operator+ (int); 
        friend DateWrap operator+ (int, DateWrap&);
        
        
    };

#endif//DATEWRAP_H_

