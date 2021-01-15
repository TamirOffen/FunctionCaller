#include <iostream>
#include "base_event.h"
using namespace std;


int main() {

    /*
    StudentsList students;

    students.addStudent(2);
    students.addStudent(1);
    students.addStudent(5);
    students.addStudent(6);
    cout << students.studentInList(6) << endl;

    //StudentsList students2 = students;
    students.removeStudent(6);
    cout << students.studentInList(6) << endl;


    students2.removeStudent(6);
    cout << students2.studentInList(6) << endl;

    cout << students.studentInList(6) << endl;
    */

    DateWrap date1(30,10,2020);
    BaseEvent be1(date1, "test 1");
    be1.registerParticpant(10);
    be1.registerParticpant(15);
    be1.registerParticpant(5);
    be1.registerParticpant(5);
    be1.registerParticpant(7);
    be1.registerParticpant(16);

    be1.unregisterParticipant(5);
    be1.unregisterParticipant(16);

    be1.printLong(cout);

    BaseEvent be2 = *(be1.clone());



    return 0;
}