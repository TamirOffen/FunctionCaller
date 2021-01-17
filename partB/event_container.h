#ifndef BASE_CONTAINER_H_
#define BASE_CONTAINER_H_

#include "base_event.h"


struct EventNode 
{
    BaseEvent *event;
    EventNode *next;
};

class EventContainer 
{
private:
    EventNode *head;

public:
    EventContainer();
    // ~EventContainer();

    virtual void add(BaseEvent&); // = 0 ???
    //exeption: NotSupported, TODO!

    class EventIterator
    {
    private:
        BaseEvent *current_event;
        bool is_end;

    public:
        EventIterator();
        EventIterator(const EventIterator&);
        // ~EventIterator();

        EventIterator& operator= (const EventIterator&); // i1 = i2 = i3 etc.
        EventIterator& operator++ (); //++i
        BaseEvent& operator* (); //*i (dereference)

        // maybe 2 param ???
        // returns T/F if the iterators are pointing to the same event?
        bool operator== (const EventIterator& iter); // iter1 == iter2
        bool operator!= (const EventIterator& iter); // iter1 != iter2
    };


    EventIterator begin();

};


#endif


