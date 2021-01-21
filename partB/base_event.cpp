
#include <iostream>
#include "base_event.h"

using std::endl;
using std::cout;
using mtm::DateWrap;
using mtm::BaseEvent;
using mtm::StudentsList;

#define MIN_STUDENT 1
#define MAX_STUDENT 1234567890 //TODO: check

////////////////////////////////////////////////
// Implementation of the Students Linked List //
////////////////////////////////////////////////
StudentsList::StudentsList(): head(NULL) {
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
        // return ???
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

StudentsList StudentsList::copy() const {
    StudentsList copy_list;
    for(StudentNode *elem = head; elem != NULL; elem=elem->next) 
    {
        copy_list.addStudent(elem->id);
    }
    return copy_list;
}



///////////////////////////////////////////
// Implementation of the BaseEvent class //
///////////////////////////////////////////
BaseEvent::BaseEvent(const DateWrap& date, const string& name): date(date), name(name)
{  
}

BaseEvent::~BaseEvent() 
{
}

void BaseEvent::registerParticipant(int student) {
    if(student < MIN_STUDENT || student > MAX_STUDENT) {
        //TODO: Throw exeption  InvalidStudent
        cout<<"illegal student"<<endl;
    }
    
    if(students.studentInList(student) == true) {
        //TODO: throw exeption  AlreadyRegistred
        cout<<"alrady registered"<<endl;
    }

    students.addStudent(student);
}

void BaseEvent::unregisterParticipant(int student) {
    if(students.studentInList(student) == false) {
        //TODO: throw exeption  NotRegistered
        std::cout << "Exception: NotRegistred" << std::endl;
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

bool BaseEvent::operator< (const BaseEvent& rhs ) const {
    cout << "called" << endl;
    return true;
}

// test:
bool BaseEvent::operator() (const BaseEvent& lhs, const BaseEvent& rhs) const 
{
    std::cout <<"called: " << std::endl;
    if(lhs.date < rhs.date) {
        return true;
    } else if (lhs.date > rhs.date) {
        return false;
    } else {
        // dates are equal, therefore we'll compare the names of the events
        if(lhs.name <= rhs.name) {
            return true;
        } else {
            return false;
        }
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





