#ifndef FESTIVAL_H_
#define FESTIVAL_H_

#include "event_container.h"


class Festival : public EventContainer 
{

private:
    DateWrap date_of_festival;

public:
    Festival(const DateWrap&); //TODO: & or not???
    ~Festival();

    void add(const BaseEvent&) override;

};

#endif

