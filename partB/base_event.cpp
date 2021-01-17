
#include <iostream>
#include "base_event.h"

using std::endl;
using std::cout;

#define MIN_STUDENT 1
#define MAX_STUDENT 20000

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
        // cout << "called: " <<  elem->id <<endl;
    }
}

StudentsList StudentsList::copy() const {
    cout << "called" << endl;
    StudentsList copy_list;
    for(StudentNode *elem = head; elem != NULL; elem=elem->next) 
    {
        copy_list.addStudent(elem->id);
    }

    return copy_list;
}


//////////////////////////////////////////////
// Implementation of the Events Linked List //
//////////////////////////////////////////////
EventNode::EventNode(BaseEvent& event) : event(event)
{
}

EventsList::EventsList() : head(NULL)
{
}

EventsList::~EventsList() {
    EventNode* elem = head;
    while(elem) {
        EventNode* temp = elem;
        elem = elem->next;
        delete temp;
    }

}

void EventsList::addEvent(BaseEvent& event) {
    // not needed???
    // if(eventInList(event) == true) {
    //     // event already is in the list
    //     return;
    // }

    EventNode *new_event = new EventNode(event);
    
    //if list is empty:
    if(head == NULL) {
        head = new_event;
        new_event->next = NULL;
        return;
    }

    //if there is only one event in the list:
    if(head->next == NULL) {
        //if event's date comes before the head's date
        if(event.getDate() < head->event.getDate()) {
            EventNode *temp_node = head;
            head = new_event;
            new_event->next = temp_node;
            return;
        }
        //if event's date comes after the head's date
        if(event.getDate() > head->event.getDate()) {
            head->next = new_event;
            new_event->next = NULL;
            return;
        }
        // else: event's date is equal to head's date:
        if(event.getName() <= head->event.getName()) { //here
            EventNode *temp_node = head;
            head = new_event;
            new_event->next = temp_node;
            return;
        } else {
            head->next = new_event;
            new_event->next = NULL;
            return;
        }
    }

    //if list has >1 event, and event is the smallest one:
    if(head->event.getDate() > event.getDate()) {
        EventNode *temp_node = head;
        head = new_event;
        new_event->next = temp_node;
        return;
    }
    if(head->event.getDate() == event.getDate()) {
        if(head->event.getName() <= event.getName()) { //here
            new_event->next = head->next;
            head->next = new_event;
        } else if(head->event.getName() > event.getName()){
            EventNode *temp_node = head;
            head = new_event;
            new_event->next = temp_node;
        } else {
            //SAME EXACT EVENT, what to do???
        }
        return;
    }

    //for every other case:
    for(EventNode* elem = head; elem != NULL; elem = elem->next) {
        if(elem->next == NULL) {
            if(event.getDate() > elem->event.getDate()) {
                new_event->next = NULL;
                elem->next = new_event;
            } 
            if(event.getDate() == elem->event.getDate() && event.getName() >= elem->event.getName()) { //here
                new_event->next = NULL;
                elem->next = new_event;
            }
            return;
        }
        if(elem->next->event.getDate() == event.getDate()) {
            if(elem->next->event.getName() >= event.getName()) { //here
                new_event->next = elem->next;
                elem->next = new_event;
                return;
            }
        }
        if(event.getDate() == elem->event.getDate()) {
            //same date, but event's name comes after elem's name
            if(elem->event.getName() <= event.getName()) { //here
                new_event->next = elem->next;
                elem->next = new_event;
                return;
            }
        }
        if(event.getDate() > elem->event.getDate() && event.getDate() < elem->next->event.getDate()) {
            new_event->next = elem->next;
            elem->next = new_event;
            return;
        }
        
        
    }

}

bool EventsList::eventInList(BaseEvent& event) {
    for(EventNode* elem = head; elem != NULL; elem = elem->next) {
        if(event == elem->event) {
            return true;
        }
    }
    return false;
}

void EventsList::printEvents() {
    for(EventNode* elem = head; elem != NULL; elem = elem->next) {
        elem->event.printLong(cout);
    }
}


///////////////////////////////////////////
// Implementation of the BaseEvent class //
///////////////////////////////////////////
BaseEvent::BaseEvent(const DateWrap& date, const string& name): date(date), name(name)
{
    
}

BaseEvent::~BaseEvent() {

}

void BaseEvent::registerParticpant(int student) {
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

/*
BaseEvent* BaseEvent::clone() const {
    return new BaseEvent(*this);
}
*/

BaseEvent::BaseEvent(const BaseEvent& event): 
    date(event.date), 
    name(event.name), 
    students(event.students)
{

}

// compares just the name and date of the events (not the students list)
bool BaseEvent::operator== (const BaseEvent& event) {
    if(name == event.name && date == event.date) {
        return true;
    } 
    else {
        return false;
    }
}

DateWrap& BaseEvent::getDate() {
    return date;
}

string BaseEvent::getName() {
    return name;
}

