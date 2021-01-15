

#include <iostream>
#include "base_event.h"

// Implementation of the Students Linked List:
StudentsList::StudentsList() {
    head = NULL;
}

StudentsList::~StudentsList() {
    while(head) {
        removeStudent(head->id);
    }
}

void StudentsList::addStudent(int id) {
    StudentNode *new_student = new StudentNode(); //check the ()
    new_student->id = id;
    new_student->next = head;
    head = new_student;
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

bool StudentsList::studentInList(int id) {
    for(StudentNode *elem = head; elem != NULL; elem=elem->next) 
    {
        if(elem->id == id) 
        {
            return true;
        }
    }
    return false;
}

StudentsList::StudentsList(const StudentsList& list) {
    
}



// Implementation of BaseEvent class:
BaseEvent::BaseEvent(const DateWrap& date, const string& name): date(date), name(name)
{

}



