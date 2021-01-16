
#include "base_event.h"

class OpenEvent : public BaseEvent
{

public:
    OpenEvent(const DateWrap&, const string&);

    //do i need func declerations???

    OpenEvent* clone() const; //is this an override of clone?
};


