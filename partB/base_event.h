

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


// linked list for the events
struct EventNode 
{
    BaseEvent& event;
    EventNode *next;
    EventNode(BaseEvent&);
};

class EventsList 
{
private:
    EventNode *head;

public:
    EventsList();
    EventsList(const EventsList&);
    // ~EventsList();

    //add by order of increasing date / increasing event name
    void addEvent(BaseEvent&); 
    bool eventInList(BaseEvent&);
    void printEvents();
};

