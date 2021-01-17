#include <iostream>

#include "open_event.h"
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
    OpenEvent oe1(DateWrap(29,2,1999),"Boxing Match 1");
    OpenEvent oe2(DateWrap(1,3,1999), "Boxing Match 2");
    OpenEvent oe3(DateWrap(1,3,1999), "Rap Contest");
    OpenEvent oe4(DateWrap(30,2,1999), "Lunch");
    OpenEvent oe5(DateWrap(1,2,1999), "Boxing Weight in");
    OpenEvent oe6(DateWrap(1,1,2000), "NYE Celebration");
    OpenEvent oe7(DateWrap(30,2,2001), "Students Day");
    OpenEvent oe8(DateWrap(7,2,2000), "Free Lunch");
    EventsList el;
    el.addEvent(oe1);
    el.addEvent(oe2);
    el.addEvent(oe3);
    el.addEvent(oe4);
    el.addEvent(oe5);
    el.addEvent(oe6);
    el.addEvent(oe7);
    el.addEvent(oe8);
    el.addEvent(oe1);
    el.addEvent(oe2);
    el.addEvent(oe3);
    el.addEvent(oe4);
    el.addEvent(oe5);
    el.addEvent(oe6);
    el.addEvent(oe7);
    el.addEvent(oe8);
    el.printEvents();
    */

/*
    DateWrap date(2,4,2020);
    Festival f(date);
    OpenEvent event1(date, "event 1");
    f.add(event1);
*/
    return 0;
}