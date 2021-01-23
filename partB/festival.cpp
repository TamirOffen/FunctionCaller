

#include "festival.h"
#include "../partA/exceptions.h"

using mtm::Festival;

Festival::Festival(const DateWrap& date) :
    EventContainer(),
    date_of_festival(date) 
{
}

void Festival::add(const BaseEvent& event) 
{
    if(event.getDate() != date_of_festival) 
    {
        throw mtm::DateMismatch();
    }
    add_event(event);
}







