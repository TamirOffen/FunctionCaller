#ifndef DATEWRAP_H_
#define DATEWRAP_H_

#include <iostream>
#include "date.h"
using std::ostream;

class DateWrap 
{
    int day;
    int month;
    int year;

public:
    DateWrap(int day, int month, int year);

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
    DateWrap operator++ (int);
    DateWrap& operator+= (int);
    DateWrap operator+ (int);
    friend DateWrap operator+ (int, DateWrap&);
    

};

#endif//DATEWRAP_H_


