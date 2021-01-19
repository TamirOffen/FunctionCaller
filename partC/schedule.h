#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "../partB/event_container.h"

#include <iostream>
#include <set>

using std::set;

struct compare {
    bool operator() (const BaseEvent* lhs, const BaseEvent* rhs) const;
};


class Schedule
{

private:
    set<BaseEvent*, compare> events;
    bool isInEvents(BaseEvent&);
    bool canAddEventContainer(const EventContainer&);
    bool eventContainerIsLegal(const EventContainer&); //doesn't contain dublicate events

public:
    Schedule();
    ~Schedule();

    void addEvents(const EventContainer&); 
    void printAllEvents();


};






#endif
