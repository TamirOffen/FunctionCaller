

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
    StudentsList(const StudentsList&); //copy constructor
    ~StudentsList(); //destructor

    void addStudent(int);
    void removeStudent(int);
    bool studentInList(int) const;
    void printStudents(ostream&) const;
    StudentsList copy() const; // not needed
};


class BaseEvent 
{

private:
    DateWrap date;
    string name;
    StudentsList students;

public:
    BaseEvent(const DateWrap&, const string&); //constructor
    BaseEvent(const BaseEvent&); //copy constructor TODO
    virtual ~BaseEvent();

    virtual void registerParticpant(int);
    virtual void unregisterParticipant(int);

    ostream& printShort(ostream&);
    ostream& printLong(ostream&);

    virtual BaseEvent* clone() const = 0; 

};

