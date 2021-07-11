#ifndef __Room
#define __Room
class Room
{
	char type;				//COMFORT SUITE OR NORMAL ROOM
	char size;				//BIG SIZE OR SMALL SIZED ROOM
	int roomNumber;			//ROOM NUMBER
	double rent;			//DAILY RENT OF ROOM
	int status=0;			//ROOM IS BOOKED OR NOT
public:
	friend class Hotel;
	void acceptroom(int room_no);		//ADD ROOMS TO HOTEL DATABASE
	void displayroom();		//DISPLAY ROOMS 
	Room(char ac1)					//DEFAULT CONSTRUCTOR
	{
		type='\0';
		size='\0';
		roomNumber=0;
		ac=ac1;
		rent=0;
		status=0;
	}
	protected:
    char ac;				//AC OR NON AC
};
#endif