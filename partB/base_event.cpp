

#include <iostream>
#include "base_event.h"

using std::endl;
using std::cout;

#define MIN_STUDENT 1
#define MAX_STUDENT 20000

// Implementation of the Students Linked List:
StudentsList::StudentsList(): head(NULL) {
}

StudentsList::~StudentsList() {
    while(head) {
        removeStudent(head->id);
    }

}

void StudentsList::addStudent(int id) {
    /*
    StudentNode *new_student = new StudentNode(); //check the ()
    new_student->id = id;
    new_student->next = head;
    head = new_student; 
    */

    if(studentInList(id) == true) {
        return;
    }

    StudentNode *new_student = new StudentNode(); //check the ()
    new_student->id = id;

    if(head == NULL) {
        head = new_student;
        head->next = NULL;
        return;
    }

    if(head->next == NULL) {
        if(id > head->id) {
            head->next = new_student;
            new_student->next = NULL;
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

    for(StudentNode *elem = head; elem != NULL; elem=elem->next) {
        if(id > elem->id && elem->next == NULL) {
            new_student->next = NULL;
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

    for(StudentNode *elem = head; elem != NULL; elem=elem->next) {
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

// copy constructor 
StudentsList::StudentsList(const StudentsList& list): head(NULL){
    for(StudentNode *elem = list.head; elem != NULL; elem=elem->next) 
    {
        addStudent(elem->id);
    }
}

void StudentsList::printStudents(ostream& out) const {
    for(StudentNode *elem = head; elem != NULL; elem=elem->next) 
    {
        out << elem->id << endl;
    }
}



// Implementation of BaseEvent class:
BaseEvent::BaseEvent(const DateWrap& date, const string& name): date(date), name(name)
{
    
}

void BaseEvent::registerParticpant(int student) {
    if(student < MIN_STUDENT || student > MAX_STUDENT) {
        //TODO: Throw exeption  InvalidStudent
    }
    
    if(students.studentInList(student) == true) {
        //TODO: throw exeption  AlreadyRegistred
    }

    students.addStudent(student);
}

void BaseEvent::unregisterParticipant(int student) {
    if(students.studentInList(student) == false) {
        //TODO: throw exeption  NotRegistered
    }

    //TODO: check if it is needed
    if(student < MIN_STUDENT || student > MAX_STUDENT) {
        //TODO: Throw exeption  InvalidStudent
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


BaseEvent* BaseEvent::clone() const {
    BaseEvent* base_event_copy = new BaseEvent(DateWrap(date), string(name));
    
    base_event_copy->students.~StudentsList(); //maybe not needed?

    base_event_copy->students = students;

    return base_event_copy;
}



