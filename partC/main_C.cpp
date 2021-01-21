
#include "schedule.h"
#include "../partB/open_event.h"
#include "../partB/festival.h"
#include "../partB/open_event.h"
#include "../partB/closed_event.h"
#include "../partB/recurring_event.h"
#include "../partB/one_time_event.h"
#include <iostream>
using namespace std; 
using namespace mtm;

typedef EventContainer::EventIterator Iter;
void printEventsShort(EventContainer& events) {
    for(Iter iter = events.begin(); iter != events.end(); ++iter) {
        mtm::BaseEvent& event = *iter;
        event.printShort(cout);
    }
}

int main() {

    Festival festival(mtm::DateWrap(21,10,2020));
    festival.add(OpenEvent(mtm::DateWrap(21,10,2020), "Performance 1")); //duplicate events
    mtm::ClosedEvent closed(mtm::DateWrap(21,10,2020), "Performance 2");
    closed.addInvitee(1);
    closed.addInvitee(500);
    festival.add(closed);
    // festival.add(OpenEvent(DateWrap(21,10,2020), "Performance 1")); //duplicate events
    // printEventsShort(festival);

    
    RecurringEvent<OpenEvent> recurring(mtm::DateWrap(21,10,2020), "Wednesday Noon", 17, 3);
    // printEventsShort(recurring);

    OneTimeEvent<ClosedEvent> one_time(mtm::DateWrap(21,10,2000), "start of the semester");
    // printEventsShort(one_time); 

    cout << endl;

    Schedule s;
    s.addEvents(festival);
    s.addEvents(recurring);
    // s.addEvents(recurring);
    s.addEvents(one_time);
    s.printAllEvents();

    s.registerToEvent(mtm::DateWrap(21,10,2020), "Performance 2", 1);
    // s.unregisterFromEvent(DateWrap(21,10,2020), "Performance 1", 1);

    closed.registerParticipant(500);

    s.printEventDetails("Performance 1", mtm::DateWrap(21,10,2020));



    return 0;
}

