#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "../partB/event_container.h"

#include <iostream>
#include <set>

using std::set;


namespace mtm 
{
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
        BaseEvent* getBaseEvent(const DateWrap&, const string&) const; //returns NULL if event isn't in events

    public:
        Schedule();
        ~Schedule();

        void addEvents(const EventContainer&); 

        // date + name => event
        void registerToEvent(const DateWrap&, const string&, const int);
        void unregisterFromEvent(const DateWrap&, const string&, const int);

        void printAllEvents() const;
        void printMonthEvents(const int month, const int year) const;
        void printEventDetails(const string&, const DateWrap&) const;

        // test:
        template <class Predicate>
        void printSomeEvents(Predicate predicate, const bool verbose) const;

    };
}


template <class Predicate>
void mtm::Schedule::printSomeEvents(Predicate predicate, const bool verbose) const {
    set<BaseEvent*>::iterator iter = events.begin();
    for( ; iter != events.end(); ++iter) 
    {
        if(predicate(**iter) == true) 
        {
            if(verbose == true) 
            {
                (**iter).printLong(std::cout);
            } else 
            {
                (**iter).printShort(std::cout);
            }
            std::cout << std::endl;
        }
    }
}






#endif
