#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_

#include "base_event.h"

namespace mtm 
{
    class ClosedEvent : public BaseEvent
    {

    private:
        StudentsList invited_students;

    public:
        ClosedEvent(const DateWrap&, const std::string&);
        ClosedEvent(const ClosedEvent&);
        ~ClosedEvent() = default;

        void addInvitee(const int);
        void registerParticipant(int) override;
        BaseEvent* clone() const override;
    };
}

#endif

