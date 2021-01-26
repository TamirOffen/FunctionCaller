#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_


#include "base_event.h"

namespace mtm
{
    //A subclass of BaseEvent which is represents an open event for anyone.
    class OpenEvent : public BaseEvent
    {

    public:
        OpenEvent(const DateWrap&, const std::string&);
        OpenEvent(const OpenEvent&);
        ~OpenEvent() = default;

        //Copies the current event to a new one and return it.
        BaseEvent* clone() const override; 
    };
}


#endif


