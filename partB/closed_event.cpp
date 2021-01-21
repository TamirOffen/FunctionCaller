
#include "closed_event.h"
#include "../partA/exceptions.h"

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
    if(student_id < MIN_STUDENT || student_id > MAX_STUDENT) 
    {
        throw mtm::InvalidStudent();
    }

    if(invited_students.studentInList(student_id) == true) 
    {
        throw mtm::AlreadyInvited();
    }

    invited_students.addStudent(student_id);
}


void ClosedEvent::registerParticipant(int student_id) 
{
    if(student_id < MIN_STUDENT || student_id > MAX_STUDENT) 
    {
        throw mtm::InvalidStudent();
    }

    if(students.studentInList(student_id) == true) 
    {
        throw mtm::AlreadyRegistered();
    }

    if(invited_students.studentInList(student_id) == false) 
    {
        throw mtm::RegistrationBlocked();
    }

    students.addStudent(student_id);
}


BaseEvent* ClosedEvent::clone() const {
    return new ClosedEvent(*this);
}



