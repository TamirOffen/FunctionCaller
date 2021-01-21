

#include "schedule.h"

using mtm::Schedule;
using mtm::BaseEvent;

Schedule::Schedule()
{
}

Schedule::~Schedule() {
    set<BaseEvent*>::iterator iter;
    for(iter = events.begin(); iter != events.end(); ++iter) {
        delete *iter;
    }
}

// private funcs:
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

BaseEvent* Schedule::getBaseEvent(const DateWrap& date, const string& name) const {
    set<BaseEvent*>::iterator iter = events.begin();
    for( ; iter != events.end(); ++iter) {
        //compares events: dates and names are equal
        if((**iter).isSameEvent(date, name)) {
            return *iter;
        }
    }
    return NULL;
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


bool mtm::compare::operator() (const BaseEvent* lhs, const BaseEvent* rhs) const
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

void Schedule::registerToEvent(const DateWrap& date, const string& name, const int student) {
    BaseEvent* event = getBaseEvent(date, name);
    if(event == NULL) {
        // Exeption: EventDoesNotExist
        std::cout << "Exeption: EventDoesNotExist" << std::endl;
        return;
    }

    try
    {
        (*event).registerParticipant(student);
        std::cout<<"registred student (delete this)\n";
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
        //Exeptions : 2, see paper!
        std::cout << "can't add student: either Registration Blocked / Already Registred" <<std::endl;
    }
}

void Schedule::unregisterFromEvent(const DateWrap& date, const string& name, const int student) {
    BaseEvent* event = getBaseEvent(date, name);
    if(event == NULL) {
        // Exeption: EventDoesNotExist
        std::cout << "Exeption: EventDoesNotExist" << std::endl;
        return;
    }

    try
    {
        (*event).unregisterParticipant(student);
        std::cout<<"unregistred student (delete this)\n";
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
        //Exeptions : NotRegistred
        std::cout << "can't add student: NotRegistred Exeption" <<std::endl;
    }

}


// print funcs:

void Schedule::printAllEvents() const {
    set<BaseEvent*>::iterator iter;
    for(iter = events.begin(); iter != events.end(); ++iter) {
        (**iter).printShort(std::cout);
        std::cout << std::endl;
    }
}

void Schedule::printMonthEvents(const int month, const int year) const {
    set<BaseEvent*>::iterator iter = events.begin();
    for( ; iter != events.end(); ++iter) {
        if((**iter).isInMonth(month, year)) {
            (**iter).printShort(std::cout);
            std::cout << std::endl;
        }
    }
}

void Schedule::printEventDetails(const string& name, const DateWrap& date) const {
    BaseEvent* event = getBaseEvent(date, name);
    if(event == NULL) {
        // Exeption: EventDoesNotExist
        std::cout << "Exeption: EventDoesNotExist" << std::endl;
        return;
    }
    (*event).printLong(std::cout);
    std::cout << std::endl;
}

