#ifndef CUSTOM_EVENT_H_
#define CUSTROM_EVENT_H_

#include "base_event.h"

template <class CanRegister>
class CustomEvent : public BaseEvent
{

private:
    CanRegister registration_condition; 

public:
    CustomEvent(const DateWrap&, const string&, const CanRegister&);
    CustomEvent(const CustomEvent&);

    void registerParticpant(int) override;
    BaseEvent* clone() const override;

};

//implementation in .h and not .cpp ???
template <class CanRegister>
CustomEvent<CanRegister>::CustomEvent(const DateWrap& date, const string& name, const CanRegister& condition) :
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
void CustomEvent<CanRegister>::registerParticpant(int student_id) {
    //TODO: check if student_id is legal

    if(registration_condition(student_id) == false) {
        //can't register
        //throw Exeption ???
        std::cout << "can't register student" << std::endl;
        return;
    }

    students.addStudent(student_id);
}

template <class CanRegister>
BaseEvent* CustomEvent<CanRegister>::clone() const {
    return new CustomEvent(*this);
}



#endif

