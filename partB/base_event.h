#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include <iostream>
#include "../partA/date_wrap.h"

namespace mtm 
{

    const int MIN_STUDENT = 1;
    const int MAX_STUDENT = 1234567890;

    //linked list for the students:
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
        void printStudents(std::ostream&) const;
    };

    class BaseEvent 
{
    private:
        DateWrap date;
        std::string name;

    protected:
        StudentsList students;

    public:
        BaseEvent(const DateWrap&, const std::string&); //constructor
        BaseEvent(const BaseEvent&); //copy constructor 
        virtual ~BaseEvent() = default; 

        virtual void registerParticipant(int);
        virtual void unregisterParticipant(int);

        std::ostream& printShort(std::ostream&);
        std::ostream& printLong(std::ostream&);

        virtual BaseEvent* clone() const = 0; //pure virtual

        bool operator== (const BaseEvent&) const;
        DateWrap getDate() const ;
        std::string getName() const ;
        bool isSameEvent(const DateWrap&, const std::string&) const;
        bool isInMonth(const int month, const int year) const;

    };
}


#endif


