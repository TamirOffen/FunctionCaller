#include <iostream>

#include "open_event.h"
#include "festival.h"
#include "base_event.h"
using namespace std;

struct StudentFilter {
    bool operator()(int student) {
        return (student%2 == 0);
    }
};

int main() {

  /* 
    StudentsList students;

    students.addStudent(2);
    students.addStudent(1);
    students.addStudent(5);
    students.addStudent(6);
    students.printStudents(cout);

    StudentsList students2 = students.copy();
    students2.removeStudent(6);
    students.removeStudent(1);
    students2.printStudents(cout);

*/

    
    /*
    DateWrap date1(1,2,2000);
    string oeName = "boxing match";
    OpenEvent oe1(date1, oeName);
    oe1.registerParticpant(10);
    oe1.registerParticpant(7);
    oe1.registerParticpant(100);
    oe1.registerParticpant(-1);
    oe1.registerParticpant(7);

    OpenEvent* oe2 =(OpenEvent*)oe1.clone();

    oe1.unregisterParticipant(7);

    oe1.printLong(cout);

    oe2->unregisterParticipant(100);
    oe2->registerParticpant(99);
    oe2->printLong(cout);

    delete oe2;

    */

/*
    DateWrap date1(1,2,2000);
    string ceName = "boxing match";
    ClosedEvent ce1(date1, ceName);

    ce1.registerParticpant(10);

    ce1.addInvitee(10);
    ce1.addInvitee(10);
    ce1.registerParticpant(10);
    ce1.printLong(cout);

    ClosedEvent* ceClone = (ClosedEvent*)ce1.clone();

    ce1.unregisterParticipant(10);
    ce1.printLong(cout);

    ceClone->addInvitee(5);
    ceClone->registerParticpant(5);
    ceClone->printLong(cout);

    delete ceClone;

*/
    
/*
    CustomEvent<StudentFilter> c1(DateWrap(21,20,2020), "Custom Event", StudentFilter());
    c1.registerParticpant(10);
    c1.registerParticpant(5);
    c1.registerParticpant(20);
    c1.registerParticpant(2);
    c1.unregisterParticipant(20);
    c1.printLong(cout);

    CustomEvent<StudentFilter>* c1Clone = (CustomEvent<StudentFilter>*)c1.clone();
    c1.unregisterParticipant(2);
    c1Clone->printLong(cout);

    delete c1Clone;
    */
    

/*
    DateWrap date(2,4,2020);
    Festival f(date);

    OpenEvent event1(date, "event1");
    event1.registerParticpant(12);
    event1.registerParticpant(10);
    f.add(event1);

    event1.registerParticpant(100);

    f.printEvents();
*/


    return 0;
}