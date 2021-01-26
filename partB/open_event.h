#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_


#include "base_event.h"

namespace mtm
{
    class OpenEvent : public BaseEvent
    {

    public:
        OpenEvent(const DateWrap&, const std::string&);
        OpenEvent(const OpenEvent&);
        ~OpenEvent() = default;
        BaseEvent* clone() const override; 
    };
}


#endif


