#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include <iostream>
#include "../partA/date_wrap.h"

namespace mtm 
{
    //The minimum and maximum number of students available.
    const int MIN_STUDENT = 1;
    const int MAX_STUDENT = 1234567890;

    //linked list for the students:
    //StudentNode represents each student (his ID) and knows the student next to him.
    struct StudentNode
    {
        int id;
        StudentNode *next;
    };
    //A students list class.
    class StudentsList 
    {
    private:
        StudentNode *head;

    public:
        StudentsList(); //constructor
        StudentsList(const StudentsList&); //copy constructor
        ~StudentsList() = default; //destructor

        void addStudent(int);//Adds a student to the StudentNode list of students.
        void removeStudent(int);//Removes a student from the list of students.
        bool studentInList(int) const;//Checks whether the given student is in the list.
        void printStudents(std::ostream&) const;//Prints the ID for each student in the list.
    };

    //A head class of all the events, which has the date, name and a list of students for the event.
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

        //Registers a participant to the event.
        virtual void registerParticipant(int);
        //Unregisters a participant from the event
        virtual void unregisterParticipant(int);

        //Prints to the output stream a brief explanation about the event.
        std::ostream& printShort(std::ostream&) const;
        //Prints to the output stream a longer explanation about the event.
        std::ostream& printLong(std::ostream&) const;

        //Copies the current event to a new one and return it.
        virtual BaseEvent* clone() const = 0; 

        bool operator== (const BaseEvent&) const;
        //Returns the date of the event.
        DateWrap getDate() const ;
        //Returns the date of the event.
        std::string getName() const ;
        //Checks whether the current event has the same information as the given ones.
        bool isSameEvent(const DateWrap&, const std::string&) const;
        
        bool isInMonth(const int month, const int year) const;

    };
}


#endif
