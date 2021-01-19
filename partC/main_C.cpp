
#include "schedule.h"
#include "../partB/open_event.h"
#include "../partB/festival.h"
#include "../partB/open_event.h"
#include "../partB/closed_event.h"
#include "../partB/recurring_event.h"
#include "../partB/one_time_event.h"
#include <iostream>
using namespace std;

typedef EventContainer::EventIterator Iter;
void printEventsShort(EventContainer& events) {
    for(Iter iter = events.begin(); iter != events.end(); ++iter) {
        BaseEvent& event = *iter;
        event.printShort(cout);
    }
}

int main() {

    Festival festival(DateWrap(21,10,2020));
    festival.add(OpenEvent(DateWrap(21,10,2020), "Performance 1")); //duplicate events
    ClosedEvent closed(DateWrap(21,10,2020), "Performance 2");
    closed.addInvitee(1);
    closed.addInvitee(500);
    festival.add(closed);
    festival.add(OpenEvent(DateWrap(21,10,2020), "Performance 1")); //duplicate events
    printEventsShort(festival);

    
    RecurringEvent<OpenEvent> recurring(DateWrap(21,10,2020), "Wednesday Noon", 13, 7);
    printEventsShort(recurring);

    OneTimeEvent<OpenEvent> one_time(DateWrap(21,10,2000), "start of the semester");
    printEventsShort(one_time); 

    cout << endl;

    Schedule s;
    s.addEvents(festival);
    s.addEvents(recurring);
    s.addEvents(recurring);
    s.addEvents(one_time);
    s.printAllEvents();



    return 0;
}

