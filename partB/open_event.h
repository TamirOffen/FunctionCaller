
#include "base_event.h"

class OpenEvent : public BaseEvent
{

public:
    OpenEvent(const DateWrap&, const string&);
    OpenEvent(const OpenEvent&);
    ~OpenEvent() = default;
    BaseEvent* clone() const override; 
};


