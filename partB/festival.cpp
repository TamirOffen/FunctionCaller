

#include "festival.h"

Festival::Festival(const DateWrap& date) :
    EventContainer(),
    date_of_festival(date) //works???
{
}

Festival::~Festival() 
{

}


void Festival::add(BaseEvent& event) {
    if(event.getDate() != date_of_festival) {
        //Throw exeption:  DateMismatch
        std::cout << "Exeption: DateMismatch" << std::endl;
    }
    BaseEvent *event_copy = event.clone();
    events.addEvent(*event_copy);
}


void Festival::printEvents() {
    events.printEvents();
}



