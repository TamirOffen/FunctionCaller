
#include "open_event.h"


OpenEvent::OpenEvent(const DateWrap& date, const string& name) : 
BaseEvent(date, name) 
{

}

OpenEvent::OpenEvent(const OpenEvent& event) : 
    BaseEvent(event)
{

}

BaseEvent* OpenEvent::clone() const {
    return new OpenEvent(*this);
}