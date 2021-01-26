#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_

#include "base_event.h"

namespace mtm 
{
    //A subclass of BaseEvent which represents the closed events which require an invitation in order to join them.
    class ClosedEvent : public BaseEvent
    {

    private:
        StudentsList invited_students;

    public:
        ClosedEvent(const DateWrap&, const string&);//Constructor
        ClosedEvent(const ClosedEvent&);//Copy constructor
        ~ClosedEvent() = default;

        //Adds an invitee who can now join the closed event.
        void addInvitee(const int);
        //Registers a participant to the event after validating that he is in the invited students list.
        void registerParticipant(int) override;
        //Copies the current event to a new one and return it.
        BaseEvent* clone() const override;
    };
}

#endif
