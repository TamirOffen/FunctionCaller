
#include "event_container.h"


EventContainer::EventContainer() : head(NULL)
{
}

EventContainer::~EventContainer() {
    while(head != NULL) {
        EventNode *temp = head->next;
        delete head->event;
        delete head;
        head = temp;
    }
}

void EventContainer::add(const BaseEvent& event) {
    // BaseEvent* event_copy = event.clone();

    EventNode *new_event = new EventNode();
    new_event->event = event.clone();
    
    //if list is empty:
    if(head == NULL) {
        head = new_event;
        new_event->next = NULL;
        return;
    }

    //if there is only one event in the list:
    if(head->next == NULL) {
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
            new_event->next = NULL;
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
            new_event->next = NULL;
            return;
        }
    }

    //if list has >1 event, and event is the smallest one:
    if(this->head->event->getDate() > event.getDate()) {
        EventNode *temp_node = head;
        head = new_event;
        new_event->next = temp_node;
        return;
    }
    if(this->head->event->getDate() == event.getDate()) {
        if(this->head->event->getName() <= event.getName()) { //here
            new_event->next = head->next;
            head->next = new_event;
        } else if(this->head->event->getName() > event.getName()){
            EventNode *temp_node = head;
            head = new_event;
            new_event->next = temp_node;
        } else {
            //SAME EXACT EVENT, what to do???
        }
        return;
    }

    //for every other case:
    for(EventNode* elem = head; elem != NULL; elem = elem->next) {
        if(elem->next == NULL) {
            if(event.getDate() > this->head->event->getDate()) {
                new_event->next = NULL;
                elem->next = new_event;
            } 
            if(event.getDate() == this->head->event->getDate() && event.getName() >= this->head->event->getName()) { //here
                new_event->next = NULL;
                elem->next = new_event;
            }
            return;
        }
        if(this->head->event->getDate() == event.getDate()) {
            if(this->head->event->getName() >= event.getName()) { //here
                new_event->next = elem->next;
                elem->next = new_event;
                return;
            }
        }
        if(event.getDate() == this->head->event->getDate()) {
            //same date, but event's name comes after elem's name
            if(this->head->event->getName() <= event.getName()) { //here
                new_event->next = elem->next;
                elem->next = new_event;
                return;
            }
        }
        if(event.getDate() > this->head->event->getDate() && event.getDate() < this->head->event->getDate()) {
            new_event->next = elem->next;
            elem->next = new_event;
            return;
        }
        
        
    }
}




/////////////////////////////////////
// Implementation of EventIterator //
/////////////////////////////////////

EventContainer::EventIterator::EventIterator(EventContainer& eventContainer, bool is_end)
{
    if(is_end) {
        current_node = NULL;
    } else {
        current_node = eventContainer.head;
    }
}

EventContainer::EventIterator& EventContainer::EventIterator::operator++() {
    //if ++iter goes out of bounds, throw exeption?
    if(current_node == NULL) {
        current_node = NULL;
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

bool EventContainer::EventIterator::operator== (const EventIterator& iter) {
    if(iter.current_node == NULL) {
        return false;
    }
    return this->current_node->event == iter.current_node->event;
}
bool EventContainer::EventIterator::operator!= (const EventIterator& iter) {
    return !(*this == iter);
}

EventContainer::EventIterator EventContainer::begin() {
    return EventIterator(*this, false);
}
EventContainer::EventIterator EventContainer::end() {
    return EventIterator(*this, true);
}




