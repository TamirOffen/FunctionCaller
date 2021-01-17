

#include "base_event.h"

class EventIterator
{

public:
    EventIterator();
    EventIterator(const EventIterator&);
    ~EventIterator();

    EventIterator& operator= (const EventIterator&); // i1 = i2 = i3 etc.
    EventIterator& operator++ (); //++i
    BaseEvent& operator* (); //*i (dereference)

    // maybe 2 param ???
    // returns T/F if the iterators are pointing to the same event?
    bool operator== (const EventIterator& iter); // iter1 == iter2
    bool operator!= (const EventIterator& iter); // iter1 != iter2


};


class EventContainer 
{

private:


public:
    EventContainer();


    void add(const BaseEvent& base_event);

    void begin();

};

