#ifndef ONE_TIME_EVENT_H_
#define ONE_TIME_EVENT_H_

#include "event_container.h"

namespace mtm 
{
    //A container of events which contains one event.
    template <class EventType>
    class OneTimeEvent : public EventContainer 
    {

    public:
        OneTimeEvent(const DateWrap& date, const string& name);//Constructor
        //Used in order to override the add function for EventContainer in order to throw an error.
        void add(const BaseEvent&) override;
    };
}


using mtm::OneTimeEvent;

template <class EventType>
OneTimeEvent<EventType>::OneTimeEvent(const DateWrap& date, const string& name) {
    add_event(EventType(date, name));
}


template <class EventType>
void OneTimeEvent<EventType>::add(const BaseEvent& event) 
{
    throw mtm::NotSupported();
}


#endif

