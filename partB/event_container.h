#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_

#include "base_event.h"

namespace mtm 
{
    struct EventNode 
    {
        BaseEvent *event;
        EventNode *next;
    };

    class EventContainer 
    {
    private:
        EventNode *head = NULL;

    protected:
        void add_event(const BaseEvent&); 

    public:
        EventContainer();
        ~EventContainer();

        virtual void add(const BaseEvent&) = 0;

        class EventIterator
        {
        private:
            EventNode *current_node;

        public:
            // EventIterator();
            EventIterator(const EventIterator&);
            EventIterator(const EventContainer&, bool is_end);
            ~EventIterator() = default;

            EventIterator& operator= (const EventIterator&); // i1 = i2 = i3 etc.
            EventIterator& operator++ (); //++i
            BaseEvent& operator* (); //*i (dereference)

            // returns T/F if the iterators are pointing to the same event
            bool operator== (const EventIterator& iter) const; // iter1 == iter2
            bool operator!= (const EventIterator& iter) const; // iter1 != iter2
        };


        EventIterator begin() const;
        EventIterator end() const;

    };
}


#endif


