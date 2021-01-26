#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "event_container.h"

namespace mtm 
{
    //A subclass which represents a festival management which occurs on a specific date.
    class Festival : public EventContainer 
    {

    private:
        DateWrap date_of_festival;

    public:
        Festival(const DateWrap&);
        ~Festival() = default;

        //Adds the given event to the festival only if they occur on the same date.
        void add(const BaseEvent&) override;

    };
}

#endif


