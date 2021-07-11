#include<bits/stdc++.h>
using namespace std;
#include "hotel.h"
#include "customer.h"
#include "room.h"
int Hotel::get_no_of_rooms(){
    return no_of_rooms;
}
int Hotel::get_no_of_customers(){
    return no_of_customars;
}
void Hotel::addRooms()
{
	int room_no;
	cout<<"Enter number of rooms: ";
	cin>>no_of_rooms;		//ACCEPTING NUMBER OF ROOMS
	while(no_of_rooms<=0)
	{
		cout<<"Invalid. Enter valid number of rooms.";
		cin>>no_of_rooms;
	}
	cout<<"Enter number of Ac rooms: ";
	cin>>no_of_acrooms;
	while(no_of_acrooms<0||no_of_acrooms>no_of_rooms){
		cout<<"Invalid. Enter valid number of rooms.";
		cin>>no_of_acrooms;
	}
	for(int i=0;i<no_of_acrooms;i++)
	{
		cout<<"ROOM "<<(i+1)<<endl;
		flag:
		cout<<endl<<"Enter room number : ";
		cin>>room_no;
		if(room_no<=0)		//VALIDATIONS
		{
			cout<<endl<<"This room number is invalid! Please Re-enter the room number : ";
			goto flag;
		}
		for(int i=0; i<no_of_acrooms;i++)	//VALIDATIONS FOR REPETITIVE ROOM NUMBERS
		{
			if(acrooms[i].roomNumber==room_no)
			{
				cout<<"Invalid. Repetitive room numbers."<<endl;
				goto flag;
			}
		}
		acrooms[i].acceptroom(room_no);		//CALLING FUNCTION ACCEPT ROOM FROM CLASS ROOM
	}
	int no_of_nonacrooms=no_of_rooms-no_of_acrooms;
	for(int i=0;i<no_of_nonacrooms;i++)
	{
		cout<<"ROOM "<<(i+1)<<endl;
		flag1:
		cout<<endl<<"Enter room number : ";
		cin>>room_no;
		if(room_no<=0)		//VALIDATIONS
		{
			cout<<endl<<"This room number is invalid! Please Re-enter the room number : ";
			goto flag1;
		}
		for(int i=0; i<no_of_nonacrooms;i++)	//VALIDATIONS FOR REPETITIVE ROOM NUMBERS
		{
			if(nonacrooms[i].roomNumber==room_no)
			{
				cout<<"Invalid. Repetitive room numbers."<<endl;
				goto flag1;
			}
		}
		nonacrooms[i].acceptroom(room_no);		//CALLING FUNCTION ACCEPT ROOM FROM CLASS ROOM
	}
}

void Hotel::availability()		//CHECKING AVAILABILITY OF THE ROOMS
{
	if(no_of_rooms==0)
	{
		cout<<"Please add rooms."<<endl;
		return;
	}
	cout<<"The list of all available rooms:"<<endl;
	cout<<"| Room No.\t|\tAC/Non-AC\t|\tType\t\t|\tsize\t\t|\tRent\t\t|\tAvailability  \t|"<<endl;
	for(int i=0;i<no_of_acrooms;i++)
	{
		acrooms[i].displayroom();	//DISPLAYING ROOM DETAILS
	}
	for(int i=0;i<no_of_rooms-no_of_acrooms;i++){
		nonacrooms[i].displayroom ();
	}
}
void Hotel::searchroom()	//SEARCH FOR A PARTICULAR TYPE OF A ROOM
{
	if(no_of_rooms==0)
	{
		cout<<"Please add rooms."<<endl;
		return;
	}
	int room_found=0;
	char ac, type, size;
	cout<<"Do you want AC or Non-AC? (A/N): "<<endl;
	cin>>ac;
	cout<<"Do you want suite or normal room? (S/N)"<<endl;
	cin>>type;
	cout<<"Size? (B/S)"<<endl;
	cin>>size;
	if(ac=='A'){
		for(int i=0;i<no_of_acrooms;i++){
			if(acrooms[i].type==type&&acrooms[i].size==size){
				room_found=1;
				cout<<"Room found"<<endl;
				acrooms[i].displayroom ();
			}
		}
	}
	else{
		for(int i=0;i<no_of_rooms-no_of_acrooms;i++){
			if(acrooms[i].type==type&&acrooms[i].size==size){
				room_found=1;
				cout<<"Room found"<<endl;
				acrooms[i].displayroom ();
			}
		}
	}
	if(!room_found)
	{
		cout<<"No such room is available."<<endl;
	}
}
void Hotel::CheckIn()		//CHECK IN OF A CUSTOMER
{     
	if(!no_of_rooms)
	{
		cout<<"Please add rooms."<<endl;
		return;
	}
	int i, room_no;
	if(no_of_customars<=no_of_rooms){	//CHECKING CONDITION IF HOTEL HAS EMPTY ROOMS
        customers_list[no_of_customars].changeBookingId(no_of_customars+1);	//ALLOTING CUSTOMER ID TO THE CUSTOMER
		flag:
		int valid_room_no=0;
        availability();
		char ac;
		cout<<"Do you want Ac or nonAc room:(A/N) "<<endl;
		cin>>ac;
        cout<<"Enter The room Number"<<endl;
		cin>>room_no;
		if(ac=='A'){
			for(i=0;i<no_of_acrooms;i++){
				if(room_no==acrooms[i].roomNumber){
					valid_room_no=1;
					break;
				}
			}
		}
		else{
		for(i=0;i<no_of_rooms-no_of_acrooms;i++){
				if(room_no==nonacrooms[i].roomNumber){
					valid_room_no=1;
					break;
				}
			}	
		}
		if(!valid_room_no){
			cout<<"Invalid room number. Please Enter again.\n";
			goto flag;
		}
		if(ac=='A'){
		if(!acrooms[i].status)		//CHECKING IF ROOM IS UNOCCUPIED
		{
			char confirm;
			cout<<"Do you wish to continue? Press(Y/y)";		//CONFIRMATION
			cin>>confirm;
			if(confirm=='Y'||confirm=='y')
			{
                customers_list[no_of_customars].Runaccept();		//ACCEPTING CUSTOMER DETAILS
				cout<<"Enter number of days of stay: ";
				int days;
				cin>>days;
				cin.ignore();
				customers_list[no_of_customars].setDays(days);
                customers_list[no_of_customars].setBill(customers_list[no_of_customars].getDays()*acrooms[i].rent);	//generating bill. bill= No. of days * rent per day.
				cout<<"Your total bill will approx be Rs."<<customers_list[no_of_customars].getBill()<<"."<<endl;
                int paid;
                cout<<"Your Total Bill: "<<customers_list[no_of_customars].getBill()<<" "<<endl;
               
				cout<<"Thank you. Booking confirmed."<<endl;		//confirmed booking
				cout<<"--------------------------------------------------------------"<<endl;		//printing booking details
				cout<<"Booking Id: "<<customers_list[no_of_customars].getId()<<"\nName: "<<customers_list[no_of_customars].getName()<<"\nRoom no.: "<<room_no<<"\n";
				acrooms[i].status=1;		//changing room status to booked
                customers_list[no_of_customars].setRoomNo(room_no);		//alloting room to customer
                customers_list[no_of_customars].changeStatus();
				no_of_customars++;
			}
			else		//if needs to change room number
			{
				goto flag;
			}
		}
		else		//if room is occupied
		{
			cout<<"Room Occupied. Please choose another room."<<endl;
		}
		}
		else{
			if(!nonacrooms[i].status)		//CHECKING IF ROOM IS UNOCCUPIED
		{
			char confirm;
			cout<<"Do you wish to continue? Press(Y/y)";		//CONFIRMATION
			cin>>confirm;
			if(confirm=='Y'||confirm=='y')
			{
                customers_list[no_of_customars].Runaccept();		//ACCEPTING CUSTOMER DETAILS
				cout<<"Enter number of days of stay: ";
				int days;
				cin>>days;
				cin.ignore();
				customers_list[no_of_customars].setDays(days);
                customers_list[no_of_customars].setBill(customers_list[no_of_customars].getDays()*nonacrooms[i].rent);	//generating bill. bill= No. of days * rent per day.
				cout<<"Your total bill will approx be Rs."<<customers_list[no_of_customars].getBill()<<"."<<endl;
                int paid;
                cout<<"Your Total Bill: "<<customers_list[no_of_customars].getBill()<<" "<<endl;
               
				cout<<"Thank you. Booking confirmed."<<endl;		//confirmed booking
				cout<<"--------------------------------------------------------------"<<endl;		//printing booking details
				cout<<"Booking Id: "<<customers_list[no_of_customars].getId()<<"\nName: "<<customers_list[no_of_customars].getName()<<"\nRoom no.: "<<room_no<<"\nDate: ";
				nonacrooms[i].status=1;		//changing room status to booked
                customers_list[no_of_customars].setRoomNo(room_no);		//alloting room to customer
                customers_list[no_of_customars].changeStatus();
				no_of_customars++;
			}
			else		//if needs to change room number
			{
				goto flag;
			}
		}
		else		//if room is occupied
		{
			cout<<"Room Occupied. Please choose another room."<<endl;
		}
		}
		
	}
	else		//CONDITION ALL ROOMS ARE BOOKED
	{
		cout<<"Sorry! Hotel is Full."<<endl;
	}
}
void Hotel::search_customer()
{
	int id, found_customer=0;
	cout<<"Enter booking id of customer.";
	cin>>id;
	for(int i=0;i<=no_of_customars;i++)		//SEARCHING FOR CUSTOMER
	{
		if(customers_list[i].getId()==id)
		{
			cout<<"\t\t\t Name"<<setw(20);
			cout<<"\t\t\t Phone"<<setw(20);
			cout<<"\t\t\t Address"<<setw(20);
			cout<<"\t\t\tRoom no: "<<setw(20)<<endl;
            customers_list[i].Rundisplay();
			found_customer=1;
		}
	}
	if(!found_customer)		//case not found
	{
		cout<<"No customer found."<<endl;
	}
}
void Hotel::CheckOut()		//CHECKING OUT
{
	int room_no, i, j;char ac;
	cout<<"Enter room type:(A/N):";
	cin>>ac;
	cout<<"Enter room number= ";
	cin>>room_no;
	if(ac=='A'){
    for(j=0;j<no_of_acrooms;j++){
		if(room_no==acrooms[j].roomNumber){
			break;
		}
	}
	}
	else{
	for(j=0;j<no_of_rooms-no_of_acrooms;j++){
		if(room_no==nonacrooms[j].roomNumber){
			break;
		}
	}	
	}
	if(ac=='A'){
    if(acrooms[j].status==0)		//IF ROOM NOT FOUND OCCUPIED
	{
		cout<<"Invalid."<<endl;
	}
	for(i=0;i<no_of_customars;i++)	//CHECKING CUSTOMER DETAILS
	{
		if(customers_list[i].getRoomNo()==room_no)
		{
			cout<<"CHECKING OUT."<<endl;
            customers_list[i].Rundisplay();		//CUSTOMER DETAILS
			cout<<endl<<"Thank you! Visit Again :)"<<endl;
			acrooms[j].status=0;	//CHANGING STATUS OF ROOM TO UNOCCUPIED
            customers_list[i].changeStatus();	//CHECKED OUT
			break;
		}
	}
	}
	else{
		if(nonacrooms[j].status==0)		//IF ROOM NOT FOUND OCCUPIED
	{
		cout<<"Invalid."<<endl;
	}
	for(i=0;i<no_of_customars;i++)	//CHECKING CUSTOMER DETAILS
	{
		if(customers_list[i].getRoomNo()==room_no)
		{
			cout<<"CHECKING OUT."<<endl;
            customers_list[i].Rundisplay();		//CUSTOMER DETAILS
			cout<<endl<<"Thank you! Visit Again :)"<<endl;
			nonacrooms[j].status=0;	//CHANGING STATUS OF ROOM TO UNOCCUPIED
            customers_list[i].changeStatus();	//CHECKED OUT
			break;
		}
	}
	}
}
void Hotel::List()		//PRINTING LIST OF ALL CUSTOMERS
{
	if(no_of_rooms==0)
	{
		cout<<"No customers as yet."<<endl;
		return;
	}
	cout<<"Guest List:"<<endl;
	cout<<"Id.\t\t";
	cout<<"|	Name	\t\t";
	cout<<"|	Phone	\t\t";
	cout<<"|	Address	\t\t";
	cout<<"|	Room no	: \t";
	cout<<"|	Status	\t\t|"<<endl;
	for(int i=0;i<no_of_customars;i++)
	{
        customers_list[i].Rundisplay();
	}
}
