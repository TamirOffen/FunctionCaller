
#include "event_container.h"


/////////////////////////////////////
// Implementation of EventIterator //
/////////////////////////////////////

EventIterator::EventIterator(const EventsList& events) : 
    events(events)
{

}



EventContainer::EventContainer() 
{
}

EventIterator EventContainer::begin() 
{
    EventIterator iterator(events);
    return iterator;
}



