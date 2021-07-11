#ifndef customer
#define customer
#include <string>
#include "user.h"
class Customer:public User{
    int days=0;	    			//DURATION OF STAY
    double bill=0;				//BILL AMT
    int booking_id;				//BOOKING ID
    int room;					//ROOM NO
    int status;

  public:

    Customer(){
		days=0;
		bill=0;
		booking_id=0;
		status=0;
		room=0;
}
	
	void accept();				//ACCEPT CUSTOMER DETAILS
	void display();				//DISPLAY CUSTOMER DETAILS
  void changeBookingId(int x);
  void Runaccept();
  void setDays(int x);
  void setBill(int x);
  int getDays();
  int getBill();
  void changeStatus();
  void setRoomNo(int x);
  int getId();
  void Rundisplay();
  int getRoomNo();
	

};
#endif