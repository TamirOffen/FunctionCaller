

#include "festival.h"

Festival::Festival(const DateWrap& date) :
    EventContainer(),
    date_of_festival(date) //works???
{
}


void Festival::add(BaseEvent& event) {
    if(event.getDate() != date_of_festival) {
        //Throw exeption:  DateMismatch
        std::cout << "Exeption: DateMismatch" << std::endl;
    }
    events.addEvent(event);
}
