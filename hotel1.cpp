#include<bits/stdc++.h>
using namespace std;

			                    //Class Customer
class Customer{

	string name;	   		    //CUSTOMER FULL NAME
	string address;				//CUSTOMER ADDRESS
	string phone;				//CONTACT NUMBER
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
	friend class room;
	friend class Hotel;

};
void Customer::accept()		//ACCEPTING CUSTOMER DETAILS
{
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
    //CLASS ROOM
	//TO STORE DATA OF ALL ROOMS IN THE HOTEL
class Room
{
	char type;				//COMFORT SUITE OR NORMAL ROOM
	char size;				//BIG SIZE OR SMALL SIZED ROOM
	char ac;				//AC OR NON AC
	int roomNumber;			//ROOM NUMBER
	double rent;			//DAILY RENT OF ROOM
	int status=0;			//ROOM IS BOOKED OR NOT
public:
	friend class Hotel;
	void acceptroom(int room_no);		//ADD ROOMS TO HOTEL DATABASE
	void displayroom();		//DISPLAY ROOMS
	Room()					//DEFAULT CONSTRUCTOR
	{
		type='\0';
		size='\0';
		ac='\0';
		roomNumber=0;
		rent=0;
		status=0;
	}
};
void Room::acceptroom(int room_no)		//ACCEPTING ALL ROOM DETAILS
{
	roomNumber=room_no;	//ROOM NUMBER
	cout<<"Type AC/Non-AC (A/N) : ";
	cin>>ac;
	while(ac!='A'&& ac!='N')		//VALIDATIONS
	{
		cout<<"Please Re-Enter Type: AC/Non-AC (A/N) : ";
		cin>>ac;
	}
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
//class Hotel
class Hotel
{
	Room rooms[100];			//ARRAY OF ROOMS
	Customer customers[100];			//ARRAY OF CUSTOMERS
    int random=0;
	int no_of_rooms=0, no_of_customars=0;	//NO OF ROOMS AND CUSTOMERS
public:
	void addRooms();		//ADD ROOMS TO DATABASE
	void searchroom();		//SEARCH FOR A PARTICULAR ROOM
	void CheckIn();			//FOR CUSTOMER CHECKIN
	void search_customer();		//SEARCH WHETHER A PARTICULAR CUSTOMER IS STAYING AT THE HOTEL
	void availability();	//CHECK AVAILABILITY OF ROOMS
	void CheckOut();		//CHECKOUT AND BILLING PROCEDURE
	void List();			//GUEST List
    int get_no_of_rooms();
};
int Hotel::get_no_of_rooms(){
    return no_of_rooms;
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
	for(int i=0;i<no_of_rooms;i++)
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
		for(int i=0; i<no_of_rooms;i++)	//VALIDATIONS FOR REPETITIVE ROOM NUMBERS
		{
			if(rooms[i].roomNumber==room_no)
			{
				cout<<"Invalid. Repetitive room numbers."<<endl;
				goto flag;
			}
		}
		rooms[i].acceptroom(room_no);		//CALLING FUNCTION ACCEPT ROOM FROM CLASS ROOM
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
	for(int i=0;i<no_of_rooms;i++)
	{
		rooms[i].displayroom();	//DISPLAYING ROOM DETAILS
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
	for(int i=0;i<no_of_rooms;i++)
	{
		if(rooms[i].ac==ac && rooms[i].type==type && rooms[i].size==size)		//MAKING SURE ALL CONDITIONS ARE SATISFIED
		{
			room_found=1;
			cout<<"Room found"<<endl;
			rooms[i].displayroom();
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
		customers[no_of_customars].booking_id=no_of_customars+1;	//ALLOTING CUSTOMER ID TO THE CUSTOMER
		flag:
		int valid_room_no=0;
        availability();
        cout<<"Enter The room Number"<<endl;
		cin>>room_no;
		for(i=0;i<no_of_rooms; i++){
			if(room_no==rooms[i].roomNumber)
			{
				valid_room_no=1;
				break;
			}
		}
		if(!valid_room_no){
			cout<<"Invalid room number. Please Enter again.\n";
			goto flag;
		}
		if(!rooms[i].status)		//CHECKING IF ROOM IS UNOCCUPIED
		{
			char confirm;
			cout<<"Do you wish to continue? Press(Y/y)";		//CONFIRMATION
			cin>>confirm;
			if(confirm=='Y'||confirm=='y')
			{
				customers[no_of_customars].accept();		//ACCEPTING CUSTOMER DETAILS
				cout<<"Enter number of days of stay: ";
				cin>>customers[no_of_customars].days;
				customers[no_of_customars].bill = customers[no_of_customars].days*rooms[i].rent;		//generating bill. bill= No. of days * rent per day.
				cout<<"Your total bill will approx be Rs."<<(customers[no_of_customars].bill)<<"."<<endl;
                int paid;
                cout<<"Your Total Bill: "<<customers[no_of_customars].bill<<" "<<endl;
               
				cout<<"Thank you. Booking confirmed."<<endl;		//confirmed booking
				cout<<"--------------------------------------------------------------"<<endl;		//printing booking details
				cout<<"Booking Id: "<<customers[no_of_customars].booking_id<<"\nName: "<<customers[no_of_customars].name<<"\nRoom no.: "<<room_no<<"\nDate: ";
				rooms[i].status=1;		//changing room status to booked
				customers[no_of_customars].room=room_no;		//alloting room to customer
				customers[no_of_customars].status=1;
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
		if(customers[i].booking_id==id)
		{
			cout<<"\t\t\t Name"<<setw(20);
			cout<<"\t\t\t Phone"<<setw(20);
			cout<<"\t\t\t Address"<<setw(20);
			cout<<"\t\t\tRoom no: "<<setw(20)<<endl;
			customers[i].display();
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
	int room_no, i, j;
	cout<<"Enter room number= ";
	cin>>room_no;
	for(j=0;j<no_of_rooms; j++){
		if(room_no==rooms[j].roomNumber)
		{
			break;
		}
	}
	if(rooms[j].status==0)		//IF ROOM NOT FOUND OCCUPIED
	{
		cout<<"Invalid."<<endl;
	}
	for(i=0;i<no_of_customars;i++)	//CHECKING CUSTOMER DETAILS
	{
		if(customers[i].room==room_no)
		{
			cout<<"CHECKING OUT."<<endl;
			customers[i].display();		//CUSTOMER DETAILS		
			cout<<endl<<"Thank you! Visit Again :)"<<endl;
			rooms[j].status=0;	//CHANGING STATUS OF ROOM TO UNOCCUPIED
			customers[i].status=0;	//CHECKED OUT
			break;
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
		customers[i].display();
	}
}

int main()
{
	Hotel KANA;		//CREATING OBJECT OF CLASS HOTEL
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
            if(password==123456){  
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
