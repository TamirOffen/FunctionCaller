
#include "event_container.h"

using mtm::EventContainer;
using mtm::BaseEvent;

EventContainer::EventContainer() : head(nullptr)
{
}

EventContainer::~EventContainer() {
    while(head != nullptr) {
        EventNode *temp = head->next;
        delete head->event;
        delete head;
        head = temp;
    }
}

void EventContainer::add_event(const BaseEvent& event) {
    EventNode *new_event = new EventNode();
    new_event->event = event.clone();
    
    //if list is empty:
    if(head == nullptr) {
        head = new_event;
        new_event->next = nullptr;
        return;
    }

    //if there is only one event in the list:
    if(head->next == nullptr) {
        //if event's date comes before the head's date
        if(event.getDate() < this->head->event->getDate()) {
            EventNode *temp_node = head;
            head = new_event;
            new_event->next = temp_node;
            return;
        }
        //if event's date comes after the head's date
        if(event.getDate() > this->head->event->getDate()) {
            head->next = new_event;
            new_event->next = nullptr;
            return;
        }
        // else: event's date is equal to head's date:
        if(event.getName() <= this->head->event->getName()) { //here
            EventNode *temp_node = head;
            head = new_event;
            new_event->next = temp_node;
            return;
        } else {
            head->next = new_event;
            new_event->next = nullptr;
            return;
        }
    }

    //if list has >1 event, and event is the smallest one:
    if(this->head->event->getDate() == event.getDate()) {
        if(this->head->event->getName() <= event.getName()) { //here
            new_event->next = head->next;
            head->next = new_event;
        } else if(this->head->event->getName() > event.getName()){
            EventNode *temp_node = head;
            head = new_event;
            new_event->next = temp_node;
        }
        return;
    }

    //for every other case:
    for(EventNode* elem = head; elem != nullptr; elem = elem->next) {
        if(elem->next == nullptr) {
            if(event.getDate() > this->head->event->getDate()) {
                new_event->next = nullptr;
                elem->next = new_event;
            } 
            if(event.getDate() == this->head->event->getDate() && event.getName() >= this->head->event->getName()) { //here
                new_event->next = nullptr;
                elem->next = new_event;
            }
            return;
        }
        if(this->head->event->getDate() == event.getDate()) {
            if(this->head->event->getName() >= event.getName()) {
                new_event->next = elem->next;
                elem->next = new_event;
                return;
            }
        }
        if(event.getDate() == this->head->event->getDate()) {
            //same date, but event's name comes after elem's name
            if(this->head->event->getName() <= event.getName()) {
                new_event->next = elem->next;
                elem->next = new_event;
                return;
            }
        }        
    }
}

EventContainer::EventIterator EventContainer::begin() const {
    return EventIterator(*this, false);
}
EventContainer::EventIterator EventContainer::end() const {
    return EventIterator(*this, true);
}


/////////////////////////////////////
// Implementation of EventIterator //
/////////////////////////////////////
EventContainer::EventIterator::EventIterator(const EventIterator& iterator) :
    current_node(iterator.current_node)
{
    
}

EventContainer::EventIterator::EventIterator(const EventContainer& eventContainer, bool is_end)
{
    if(is_end) {
        current_node = nullptr;
    } else {
        current_node = eventContainer.head;
    }
}

EventContainer::EventIterator& EventContainer::EventIterator::operator++() {
    if(current_node == nullptr) {
        current_node = nullptr;
    }
    else {
        current_node = current_node->next;
    }
    return *this;
}

BaseEvent& EventContainer::EventIterator::operator* () {
    return *(current_node->event);
}

EventContainer::EventIterator& EventContainer::EventIterator::operator= (const EventIterator& iter) {
    current_node = iter.current_node;
    return *this;
}

bool EventContainer::EventIterator::operator== (const EventIterator& iter) const {
    return this->current_node == iter.current_node;
}
bool EventContainer::EventIterator::operator!= (const EventIterator& iter) const {
    return !(*this == iter);
}






