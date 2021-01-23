
#include <iostream>
#include "base_event.h"
#include "../partA/exceptions.h"

using std::endl;
using std::cout;
using mtm::DateWrap;
using mtm::BaseEvent;
using mtm::StudentsList;
using std::string;
using std::ostream;

////////////////////////////////////////////////
// Implementation of the Students Linked List //
////////////////////////////////////////////////
StudentsList::StudentsList(): head(nullptr) {
}

StudentsList::~StudentsList() {
    while(head) {
        removeStudent(head->id);
    }
}

void StudentsList::addStudent(int id) {
    if(studentInList(id) == true) {
        return;
    }

    StudentNode *new_student = new StudentNode(); //check the ()
    new_student->id = id;

    if(head == nullptr) {
        head = new_student;
        head->next = nullptr;
        return;
    }

    if(head->next == nullptr) {
        if(id > head->id) {
            head->next = new_student;
            new_student->next = nullptr;
        } else {
            StudentNode *temp_node = head;
            head = new_student;
            head->next = temp_node;
        }
        return;
    }

    if(id < head->id) {
        StudentNode *temp_node = head;
        head = new_student;
        head->next = temp_node;
    }

    for(StudentNode *elem = head; elem != nullptr; elem=elem->next) {
        if(id > elem->id && elem->next == nullptr) {
            new_student->next = nullptr;
            elem->next = new_student;
            return;
        }
        if(id > elem->id && id < elem->next->id) {
            StudentNode *temp_next_node = elem->next;
            elem->next = new_student;
            new_student->next = temp_next_node;
            return;
        }
    }
    

}

void StudentsList::removeStudent(int id) {
    if(studentInList(id) == false) {
        return;
    }

    //checks the first student in the list:
    if(head->id == id) {
        StudentNode *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    for(StudentNode *elem = head; elem != nullptr; elem=elem->next) {
        if(elem->next->id == id) {
            StudentNode *temp = elem->next;
            elem->next = elem->next->next;
            delete temp;
            return;
        }
    }
}

bool StudentsList::studentInList(int id) const {
    for(StudentNode *elem = head; elem != NULL; elem=elem->next) 
    {
        if(elem->id == id) 
        {
            return true;
        }
    }
    return false;
}

StudentsList::StudentsList(const StudentsList& list): head(nullptr){
    for(StudentNode *elem = list.head; elem != nullptr; elem=elem->next) 
    {
        addStudent(elem->id);
    }
}

void StudentsList::printStudents(ostream& out) const {
    for(StudentNode *elem = head; elem != nullptr; elem=elem->next) 
    {
        out << elem->id << endl;
    }
}



///////////////////////////////////////////
// Implementation of the BaseEvent class //
///////////////////////////////////////////
BaseEvent::BaseEvent(const DateWrap& date, const string& name): date(date), name(name)
{  
}

void BaseEvent::registerParticipant(int student) 
{
    if(student < MIN_STUDENT || student > MAX_STUDENT) 
    {
        throw mtm::InvalidStudent();
    }
    
    if(students.studentInList(student) == true) {
        throw mtm::AlreadyRegistered();
    }

    students.addStudent(student);
}

void BaseEvent::unregisterParticipant(int student) 
{
    if(student < MIN_STUDENT || student > MAX_STUDENT) 
    {
        throw mtm::InvalidStudent();
    }

    if(students.studentInList(student) == false) 
    {
        throw mtm::NotRegistered();
    }

    students.removeStudent(student);
}

ostream& BaseEvent::printShort(ostream& out) {
    out << name << " " << date << endl;
    return out;
}

ostream& BaseEvent::printLong(ostream& out) {
    out << name << " " << date << endl;
    students.printStudents(out);
    return out;
}

BaseEvent::BaseEvent(const BaseEvent& event): 
    date(event.date), 
    name(event.name), 
    students(event.students)
{
}

// compares just the name and date of the events (not the students list)
bool BaseEvent::operator== (const BaseEvent& event) const {
    if(name == event.name && date == event.date) {
        return true;
    } 
    else {
        return false;
    }
}


DateWrap BaseEvent::getDate() const {
    return date;
}

string BaseEvent::getName() const {
    return name;
}


bool BaseEvent::isSameEvent(const DateWrap& date, const string& name) const {
    if(this->date == date && this->name == name) {
        return true;
    } else {
        return false;
    }
}

bool BaseEvent::isInMonth(const int month, const int year) const {
    if(date.monthReturn() == month && date.yearReturn() == year) {
        return true;
    } else {
        return false;
    }
}





