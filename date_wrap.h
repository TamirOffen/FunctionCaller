#ifndef DATEWRAP_H_
#define DATEWRAP_H_

#include <iostream>
#include "date.h"
using std::ostream;

class dateWrap 
{
    int day;
    int month;
    int year;

    public:
    dateWrap(int day, int month, int year);

    const int dayReturn ();
    const int monthReturn ();
    const int yearReturn();

    friend ostream& operator<< (ostream& out, const dateWrap& date);
    bool operator< (const dateWrap&) const;
    bool operator> (const dateWrap&) const;
    bool operator== (const dateWrap&) const;
    bool operator<= (const dateWrap&) const;
    bool operator>= (const dateWrap&) const;
    bool operator!= (const dateWrap&) const;
    dateWrap operator++ (int);
    dateWrap& operator+= (int);
    dateWrap operator+ (int);
    dateWrap operator+ (const dateWrap&);

};
#endif//DATEWRAP_H_
