#ifndef __admin
#define __admin
#include<string>
#include "user.h"
using namespace std;
class Admin:public User{
    public:
    int password; //PASSWORD FOR  ADMIN
    Admin(string name1,int password1,string address="-1",string phone="-1"){
        name=name1;
        password=password1;
        address="-1";
        phone="-1";
    }
};
#endif
