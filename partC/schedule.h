#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include <iostream>
#include "date.h"
#include "../partB/base_event.h"

using std::string;

class Schedule
{


public:
    Schedule();
    ~Schedule();
    
    void addEvents(EventContainer&);
    void registerToEvent(date&, string, StudentNode&); //student should be by reference or value?
    void unregisterFromEvent(date&, string, StudentNode&);//
    void printAllEvents();
    void printMonthEvents(int, int);
    void printSomeEvents();//Needs to be updated
    void printEventDetails(string, date&);
};





#endif //SCHEDULE_H_
