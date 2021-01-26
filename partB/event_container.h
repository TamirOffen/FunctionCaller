#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_

#include "base_event.h"

namespace mtm 
{
    //A stuct which represents each event and knows the event which occurs after it.
    struct EventNode 
    {
        BaseEvent *event;
        EventNode *next;
    };

    //A head class which represents a container of multiple events.
    class EventContainer 
    {
    private:
        EventNode *head = NULL;

    protected:
        void add_event(const BaseEvent&); //todo delete and move to festival

    public:
        EventContainer();
        ~EventContainer();
        //Gets a BaseEvent and adds it to the current events container if possible.
        virtual void add(const BaseEvent&) = 0;

        //An events iterator.
        class EventIterator
        {
        private:
            EventNode *current_node;

        public:
            
            EventIterator(const EventIterator&);
            EventIterator(const EventContainer&, bool is_end);
            ~EventIterator() = default;

            EventIterator& operator= (const EventIterator&); // i1 = i2 = i3 etc.
            EventIterator& operator++ (); //++i
            BaseEvent& operator* (); //*i (dereference)

           
            bool operator== (const EventIterator& iter); // iter1 == iter2
            bool operator!= (const EventIterator& iter); // iter1 != iter2
        };

        //Returns the first event in the events container.
        EventIterator begin() const;
        //Returns the last event in the events container.
        EventIterator end() const;

    };
}


#endif

