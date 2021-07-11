#include<bits/stdc++.h>
#include "customer.h"
using namespace std;
void Customer::changeBookingId(int x){
	booking_id=x;
}
void Customer::accept(){
cout<<"Enter name: ";
	getline(cin, name);
	getline(cin, name);
	cout<<"Enter address: ";
	getline(cin,address);
	flag:
	cout<<"Enter mobile number: ";
	cin>>phone;
	for(int i=0;i<(phone.length());i++)	//PHONE NUMBER VALIDATIONS
  	{									//PHONE NUMBER NEEDS TO BE ALL DIGITS AND 10 IN LENGTH
		if(!isdigit(phone[i]))
		{
			cout<<"Phone number has to be in digits.\n";
			goto flag;
		}
  	}
  	if(phone.length()!=10)		//PHONE LENGTH VALIDATIONS
  	{
  	  cout<<"Phone number should be 10 digits.\n";
  	  goto flag;
 	 }
}
void Customer::display()		//DISPLAYING CUSTOMER DETAILS
{
	cout<<booking_id<<"\t\t";
	cout<<"| "<<left<<setfill(' ')<<setw(30)<<name;
	cout<<"| "<<phone<<"\t\t\t";
	cout<<"| "<<left<<setfill(' ')<<setw(30)<<address;
	cout<<"| "<<room<<"\t\t\t";
	if(status==1){cout<<"|\t\t-\t\t|"<<endl;}
	else{cout<<"|\tCHECKED OUT.\t\t|"<<endl;}
}
void Customer::Runaccept(){
	accept();
}
void Customer::setDays(int x){
	days=x;
}
void Customer::setBill(int x){
	bill=x;
}
int Customer::getDays(){
	return days;
}
int Customer::getBill(){
	return bill;
}
void Customer::changeStatus(){
	status^=1;
}
void Customer::setRoomNo(int x){
    room=x;
}
int Customer::getId(){
	return booking_id;
}
void Customer::Rundisplay(){
	display();
}
int Customer::getRoomNo(){
	return room;
}
