#ifndef hotel
#define hotel
#include "room.h"
#include "customer.h"
#include "acroom.h"
#include "nonac.h"
class Hotel
{
    AC acrooms[100];			//ARRAY OF ROOMS
	NonAC nonacrooms[100];
    Customer customers_list[100];			//ARRAY OF CUSTOMERS
	int no_of_rooms=0;
	 int no_of_customars=0;	//NO OF ROOMS AND CUSTOMERS
	 int no_of_acrooms=0;
public:
	void addRooms();		//ADD ROOMS TO DATABASE
	void searchroom();		//SEARCH FOR A PARTICULAR ROOM
	void CheckIn();			//FOR CUSTOMER CHECKIN
	void search_customer();		//SEARCH WHETHER A PARTICULAR CUSTOMER IS STAYING AT THE HOTEL
	void availability();	//CHECK AVAILABILITY OF ROOMS
	void CheckOut();		//CHECKOUT AND BILLING PROCEDURE
	void List();			//GUEST List
    int get_no_of_rooms();  //GET NUMBER OF ROOMS
	int get_no_of_customers(); //GET NUMBER OF CUSTOMERS
};
#endif