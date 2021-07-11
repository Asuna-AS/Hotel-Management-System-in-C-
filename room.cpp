#include<bits/stdc++.h>
#include "room.h"
using namespace std;
void Room::acceptroom(int room_no)		//ACCEPTING ALL ROOM DETAILS
{
	roomNumber=room_no;	//ROOM NUMBER
	cout<<"Type Comfort Suite or Normal (S/N) : ";
	cin>>type;
	while(type!='S' && type!='N')
	{
		cout<<"Please Re-enter Type Comfort Suite or Normal (S/N) : ";
		cin>>type;
	}
	cout<<"Type Size (B/S) : ";
	cin>>size;
	while(size!='B'&& size!='S')
	{
		cout<<"Please Re-enter Type Size (B/S) : ";
		cin>>size;
	}
	cout<<"Daily Rent : ";
	cin>>rent;
	while(rent<0 || rent>20000)
	{
		cout<<"Please enter valid rent.";
		cin>>rent;
	}
	status=0;	//BOOKING STATUS OF THE ROOM
	cout<<"\nRoom Added Successfully!"<<endl;
}
void Room::displayroom()
{
	cout<<"| "<<roomNumber<<".\t\t|\t"<<ac<<"\t\t|\t"<<type<<"\t\t|\t"<<size<<"\t\t|\t"<<rent<<"\t\t|\t";
	if(status==0){cout<<"Available.\t|";}
	else{cout<<"Booked.\t\t|";}
	cout<<endl;
}
