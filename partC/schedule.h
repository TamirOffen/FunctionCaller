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

    //A class that represents a schedule of events, which allows adding events to it and students to the events in it.
    class Schedule
    {

    private:
        //A set of events in the current schedule.
        set<BaseEvent*, compare> events;
        //Checks whether the given event is currently in the schedule.
        bool isInEvents(BaseEvent&) const;
        bool canAddEventContainer(const EventContainer&);
        bool eventContainerIsLegal(const EventContainer&); //doesn't contain dublicate events
        BaseEvent* getBaseEvent(const DateWrap&, const string&) const; //returns NULL if event isn't in events

    public:
        Schedule() = default;//Constructor
        ~Schedule();
        
        //Adds a container of events to the schedule.
        void addEvents(const EventContainer&); 

        //Adds the given student (int) to the event with the same name and date as given if it finds it in schedule.
        void registerToEvent(const DateWrap&, const string&, const int);
        //Removes the given student (int) to the event with the same name and date as given if it finds it in schedule.
        void unregisterFromEvent(const DateWrap&, const string&, const int);

        //Prints all the events in the schedule.
        void printAllEvents() const;
        //Prints all the events in the schedule which occur on the same month and year as given.
        void printMonthEvents(const int month, const int year) const;
        //Prints the event with the same name and date as given in detail.
        void printEventDetails(const string&, const DateWrap&) const;

        // Prints all the events which the given predicate returns true over them, detailed print if verbose it true and short print if not.
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
