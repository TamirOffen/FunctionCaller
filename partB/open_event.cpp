
#include "open_event.h"

using mtm::OpenEvent;
using mtm::BaseEvent;
using std::string;

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