#include <iostream>
#include "base_event.h"
using namespace std;


int main() {

    StudentsList students;

    students.addStudent(2);
    students.addStudent(4);
    students.addStudent(5);
    students.addStudent(6);
    cout << students.studentInList(6) << endl;

    students.~StudentsList();
    cout << students.studentInList(6) << endl;

    return 0;
}