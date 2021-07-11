#ifndef __ac
#define __ac
#include "room.h"
class AC:public Room{
    public:
    AC(char ac='A'):Room(ac){};
    friend class Hotel;
};
#endif
