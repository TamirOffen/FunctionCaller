#include <iostream>

#include "open_event.h"
using namespace std;


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
    DateWrap date1(30,10,2020);
    BaseEvent be1(date1, "test 1");
    be1.registerParticpant(10);
    be1.registerParticpant(15);
    be1.registerParticpant(5);
    be1.registerParticpant(5);
    be1.registerParticpant(7);
    be1.registerParticpant(16);
    // be1.printLong(cout);

    // BaseEvent* be2 = be1.clone();
    // be2->registerParticpant(100);

    be1.unregisterParticipant(5);
    be1.unregisterParticipant(7); 
    // be2->printShort(cout);
    // (*be2).printLong(cout);
    */

    DateWrap date1(1,2,2000);
    string oeName = "boxing match";
    OpenEvent oe1(date1, oeName);
    oe1.registerParticpant(10);
    oe1.registerParticpant(7);
    oe1.registerParticpant(100);
    oe1.registerParticpant(-1);
    oe1.registerParticpant(7);

    oe1.unregisterParticipant(7);

    oe1.printLong(cout);

    OpenEvent* oe1Clone = oe1.clone();


    return 0;
}