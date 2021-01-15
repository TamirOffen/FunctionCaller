

#include <iostream>
#include "../partA/date_wrap.h"

using std::ostream;
using std::istream;
using std::string;

//linked list for the students
struct StudentNode
{
    int id;
    StudentNode *next;
};

class StudentsList 
{
private:
    StudentNode *head;

public:
    StudentsList(); //constructor
    ~StudentsList(); //destructor

    void addStudent(int);
    void removeStudent(int);
    bool studentInList(int);
};


class BaseEvent 
{

private:
    DateWrap date;
    string name;
    StudentsList students;

public:
    BaseEvent(const DateWrap&, const string&); //constructor
    BaseEvent(const BaseEvent&); //copy constructor



};

