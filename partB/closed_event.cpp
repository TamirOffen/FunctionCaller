
#include "closed_event.h"

using mtm::ClosedEvent;
using mtm::BaseEvent;

ClosedEvent::ClosedEvent(const DateWrap& date, const string& name) :
    BaseEvent(date, name)
{

}

ClosedEvent::ClosedEvent(const ClosedEvent& event) :
    BaseEvent(event),
    invited_students(event.invited_students)
{

}

void ClosedEvent::addInvitee(const int student_id) 
{
    //TODO check if student id is legal ????

    if(invited_students.studentInList(student_id) == true) {
        //throw exeption:  AlreadyRegistred
        std::cout << student_id << " already registred EXEPTION" << std::endl;
        return;
    }

    invited_students.addStudent(student_id);
}


void ClosedEvent::registerParticipant(int student_id) 
{
    //check if student_id is legal ???

    if(invited_students.studentInList(student_id) == false) {
        //throw exeption:  ????
        std::cout << "not in list! EXEPTION" << std::endl;
        return;
    }

    students.addStudent(student_id);

}


BaseEvent* ClosedEvent::clone() const {
    return new ClosedEvent(*this);
}



