

#include "schedule.h"


Schedule::Schedule()
{

}

// test:
bool Schedule::isInEvents(BaseEvent& event) {
    set<BaseEvent*>::iterator iter;
    for(iter = events.begin(); iter != events.end(); ++iter) {
        //compares events: dates and names are equal
        if(event == **iter) {
            return true;
        }
    }
    return false;
}

// test:
bool Schedule::canAddEventContainer(const EventContainer& events_to_be_added) {
    EventContainer::EventIterator iter = events_to_be_added.begin();
    for( ; iter != events_to_be_added.end(); ++iter) {
        if(isInEvents(*iter)) {
            return false;
        }
    }
    return true;
}

bool Schedule::eventContainerIsLegal(const EventContainer& event_container) {
    EventContainer::EventIterator iter1 = event_container.begin();
    EventContainer::EventIterator iter2 = event_container.begin();
    for( ; iter1 != event_container.end(); ++iter1) {
        for( ; iter2 != event_container.end(); ++iter2) {
            if(iter1 == iter2) {
                continue;
            }
            if(*iter1 == *iter2) {
                return false;
            }
        }
    }
    return true;
}


void Schedule::addEvents(const EventContainer& event_container) {
    if(!eventContainerIsLegal(event_container) || !canAddEventContainer(event_container)) {
        // throw exeption: EventAlreadyRegistered
        std::cout << "Exeption: EventAlreadyRegistered" << std::endl;
        return;
    }

    EventContainer::EventIterator iter = event_container.begin();
    for( ; iter != event_container.end(); ++iter) {
        events.insert((*iter).clone());
    }

}

void Schedule::printAllEvents() {
    set<BaseEvent*>::iterator iter;
    for(iter = events.begin(); iter != events.end(); ++iter) {
        (**iter).printShort(std::cout);
        std::cout << std::endl;
    }
}

bool compare::operator() (const BaseEvent* lhs, const BaseEvent* rhs) const
    {
        if(lhs->getDate() < rhs->getDate()) {
            return true;
        } else if (lhs->getDate() > rhs->getDate()) {
            return false;
        } else {
            // dates are equal, therefore we'll compare the names of the events
            if(lhs->getName() <= rhs->getName()) {
                return true;
            } else {
                return false;
            }
        }
    }




