

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
        //throw exeption
    }
    EventContainer::add(event); //add func from event_contianer
}







