#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

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

// BaseEvent class
class BaseEvent 
{

private:
    DateWrap date;
    string name;

// is protected fine?
protected:
    StudentsList students;


public:
    BaseEvent(const DateWrap&, const string&); //constructor
    BaseEvent(const BaseEvent&); //copy constructor 
    virtual ~BaseEvent(); //does destructor need to be virtual?

    virtual void registerParticpant(int);
    virtual void unregisterParticipant(int);

    ostream& printShort(ostream&);
    ostream& printLong(ostream&);

    virtual BaseEvent* clone() const = 0; //pure virtual

    bool operator== (const BaseEvent&);
    DateWrap& getDate();
    string getName();

};



#endif


