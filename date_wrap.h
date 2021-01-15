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

    const int dayReturn ();
    const int monthReturn ();
    const int yearReturn();

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

};

#endif//DATEWRAP_H_


