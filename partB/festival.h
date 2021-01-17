

#include "event_container.h"


class Festival : public EventContainer 
{

private:
    DateWrap date_of_festival;

public:
    Festival(const DateWrap&); //& or not???
    
    void add(BaseEvent&) override;

};

