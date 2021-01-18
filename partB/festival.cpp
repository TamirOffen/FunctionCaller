

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
        std::cout << "Exeption: DateMismatch" << std::endl;
    }
    EventContainer::add(event); //add func from event_contianer
}







