#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "event_container.h"

namespace mtm 
{
    class Festival : public EventContainer 
    {

    private:
        DateWrap date_of_festival;

    public:
        Festival(const DateWrap&);
        ~Festival() = default;

        void add(const BaseEvent&) override;

    };
}

#endif

