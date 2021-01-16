

#include "base_event.h"


class ClosedEvent : public BaseEvent
{

private:
    StudentsList invited_students;

public:
    ClosedEvent(const DateWrap&, const string&);
    ClosedEvent(const ClosedEvent&);
    // add destructor ?

    void addInvitee(const int);
    void registerParticpant(int) override;
    BaseEvent* clone() const override;


};


