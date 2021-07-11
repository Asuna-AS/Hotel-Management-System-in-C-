#include<bits/stdc++.h>
using namespace std;
#include "customer.h"
#include "room.h"
#include "hotel.h"
#include "admin.h"

int main()
{
	Hotel KANA;		//CREATING OBJECT OF CLASS HOTEL
	Admin HOTEL("KANA",123456); //SETTING ADMIN
	char ch;
    bool flag=true;
    cout<<"\t\t\t\t"<<"*************************************"<<endl;
	cout<<"\t\t\t\t"<<"*************************************"<<endl;
	cout<<"\t\t\t\t"<<"**                                 **"<<endl;
	cout<<"\t\t\t\t"<<"**       WELCOME TO THE KANA       **"<<endl;
	cout<<"\t\t\t\t"<<"**                                 **"<<endl;
	cout<<"\t\t\t\t"<<"*************************************"<<endl;
	cout<<"\t\t\t\t"<<"*************************************"<<endl;
	do
	{		//MENU TO USE AS EITHER ADMIN OR WHEN A CUSTOMER ENTERS
		cout<<endl<<"\t\t\t\t"
				"MENU:\n\t\t\t\t"<<endl<<
				"\t\t\t\t1.OPERATE AS ADMIN\n\t\t\t\t"
				"2.OPERATE AS CUSTOMER\n\t\t\t\t"
				"3.EXIT\n\t\t\t\t"<<endl<<
				"\t\t\t\tEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
		case '1':
            
            cout<<"Enter Password : "; // ADMIN PASSWORD
            int password;
            cin>>password;
            if(password==HOTEL.password){
				cout<<"Hello "<<HOTEL.getName()<<endl;  
            cout<<"\t\t\t\t1.Add database of rooms in the hotel:"<<endl; // ADDING DATABASE OF ROOMS
            cout<<"\t\t\t\t2.Guest List"<<endl; //DISPLAYING LIST OF GUESTS
            cout<<"\t\t\t\t3.Search Room"<<endl; //SEARCHING ROOMS
            cout<<"\t\t\t\t4.Search Customar"<<endl; //SEARCHING CUSTOMERS
            char ch3;
            cin>>ch3;
            switch(ch3){
               case '1':
              KANA.addRooms();
			cout<<"\t\t\t\tDatabase updated. Going back to main menu."<<endl;
			break;
               case '2':
            cout<<"\t\t\t\tGuest List"<<endl;
            KANA.List();
            break;
               case '3':
            KANA.searchroom();
            break;
               case '4':
            KANA.search_customer();
            break;
            default:
            cout<<"\t\t\t\tEnter Valid Option"<<endl;
            break;
            }
            }
            else{
                cout<<"\t\t\t\tWrong Password!!!"<<endl;
                break;
            }
		case '2':
			char ch1;
			do
			{
				//MENU 2 TO USE WHEN A CUSTOMER WANTS TO CHECK IN
				cout<<"WELCOME TO KANA GROUP OF HOTELS"<<endl;
				cout<<"\n"
						"Menu:\n"
						"1.Check Availability of rooms.\n"
						"2.Check In\n"
						"3.Checkout.\n"
						"4.Go back to Main Menu.\n"
						"Enter your choice:";
				cin>>ch1;
				switch(ch1)
				{
				case '1':
					KANA.availability();
                if(!KANA.get_no_of_rooms())flag=false;
					break;
				case '2':
					KANA.CheckIn();
					break;
				case '3':
					KANA.CheckOut();
					break;
				case '4':
					break;
				default:
					cout<<"Invalid Choice."<<endl;
					break;
				}
			}while(ch1!='4'&&flag);
			break;
		case '3':
			cout<<"Thank you!";
			exit(0);
		default:
			cout<<"Invalid Choice."<<endl;
			break;
		}
	}while(ch!='3');
	return 0;
}

