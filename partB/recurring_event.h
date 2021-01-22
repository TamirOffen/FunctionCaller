#ifndef RECURRING_EVENT_H_
#define RECURRING_EVENT_H_

#include "event_container.h"
#include "../partA/exceptions.h"

namespace mtm 
{
    template <class EventType>
    class RecurringEvent : public EventContainer 
    {

    public:
        RecurringEvent(const DateWrap& first_date, const string& name, const int num_occurrences, const int interval_days);
        void add(const BaseEvent&) override;
    };
}


using mtm::RecurringEvent;

template <class EventType>
RecurringEvent<EventType>::RecurringEvent(const DateWrap& first_date, const string& name, const int num_occurrences, const int interval_days) 
{
    if(num_occurrences <= 0) 
    {
        throw mtm::InvalidNumber();
    }
    if(interval_days <= 0) {
        throw mtm::InvalidInterval();
    }
    DateWrap date_copy(first_date);
    for(int i = 0; i < num_occurrences; i++) {
        add_event(EventType(date_copy, name));
        date_copy += interval_days;
    }
}

template <class EventType>
void RecurringEvent<EventType>::add(const BaseEvent& event) 
{
    throw mtm::NotSupported();
}



#endif


