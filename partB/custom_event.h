#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_

#include "base_event.h"
#include "../partA/exceptions.h"

namespace mtm 
{
    //A generic subclass that represents a custom event which returns if a student can participate in the event or not.
    template <class CanRegister>
    class CustomEvent : public BaseEvent
    {

    private:
        //shows if a student can participate in the event or not.
        CanRegister registration_condition; 

    public:
        CustomEvent(const DateWrap&, const std::string&, const CanRegister&);
        CustomEvent(const CustomEvent&);
        ~CustomEvent() = default;

        //Registers a participant to the event.
        void registerParticipant(int) override;

        //Copies the current event to a new one and return it.
        BaseEvent* clone() const override;

    };
}

using mtm::BaseEvent;
using mtm::CustomEvent;

template <class CanRegister>
CustomEvent<CanRegister>::CustomEvent(const DateWrap& date, const std::string& name, const CanRegister& condition) :
    BaseEvent(date, name),
    registration_condition(condition)
{
}

template <class CanRegister>
CustomEvent<CanRegister>::CustomEvent(const CustomEvent& event) :
    BaseEvent(event),
    registration_condition(event.registration_condition)
{
}

template <class CanRegister>
void CustomEvent<CanRegister>::registerParticipant(int student_id) {
    if(student_id < MIN_STUDENT || student_id > MAX_STUDENT) 
    {
        throw mtm::InvalidStudent();
    }

    if(students.studentInList(student_id) == true) {
        throw mtm::AlreadyRegistered();
    }

    if(registration_condition(student_id) == false) 
    {
        throw mtm::RegistrationBlocked();
    }

    students.addStudent(student_id);
}

template <class CanRegister>
BaseEvent* CustomEvent<CanRegister>::clone() const 
{
    return new CustomEvent(*this);
}



#endif

