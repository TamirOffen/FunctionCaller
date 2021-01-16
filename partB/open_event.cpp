


#include "open_event.h"


OpenEvent::OpenEvent(const DateWrap& date, const string& name): BaseEvent(date, name) {

}

OpenEvent* OpenEvent::clone() const{
    // BaseEvent* new_event = clone(); 
    // ?????? TODO
}