#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_

#include "base_event.h"
#include "../partA/exceptions.h"

namespace mtm 
{
    template <class CanRegister>
    class CustomEvent : public BaseEvent
    {

    private:
        CanRegister registration_condition; 

    public:
        CustomEvent(const DateWrap&, const std::string&, const CanRegister&);
        CustomEvent(const CustomEvent&);

        void registerParticipant(int) override;
        BaseEvent* clone() const override;

    };
}

using mtm::BaseEvent;
using mtm::CustomEvent;

template <class CanRegister>
CustomEvent<CanRegister>::CustomEvent(const DateWrap& date, const std::string& name, const CanRegister& condition) :
    BaseEvent(date, name)
{
    registration_condition = condition;
}

template <class CanRegister>
CustomEvent<CanRegister>::CustomEvent(const CustomEvent& event) :
    BaseEvent(event)
{
    registration_condition = event.registration_condition;
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

