#ifndef __nonac
#define __nonac
#include "room.h"
class NonAC:public Room{
    public:
    NonAC(char ac='N'):Room(ac){};
    friend class Hotel;
};
#endif
