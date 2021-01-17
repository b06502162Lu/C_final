#include <conio.h>
#include <stdio.h>
#include <windows.h> // To take control over the terminal

using namespace std;

class Health
{
	enum astertype{aleft,astraight,aright};
private:
	int x;
	int y;
	astertype type; 
		
public:
	int X()  { return x; }
	int Y()  { return y; }

	Health(int _x, int _y)
	{
		x = _x;
		y = _y;
		type=astraight;	
	}
	Health(int _x, int _y,astertype t)
	{
		x = _x;
		y = _y;
		type=t;	
	}
	
	void Draw()
	{
		x = rand()%74 + 3;
		y = 28;
		gotoxy(x,y); printf("+"); // Get the health!!
	}
	
	void Collision(SpaceShip &ss) // The health finds the spaceship
	{
		if(((x >= ss.X()) && (x <= ss.X() + 5)) && ((y >= ss.Y()) && (y <= ss.Y() + 2)))
		{ // Depending on the shape of the spaceship you have to tinker when you get health
			ss.gethealth(); // get thealth
			gotoxy(x,y); printf(" "); // And the health is "destroyed"
			x = rand()%74 + 3; // The truth is it just teleports to the top of the map
			y = 28;
		}
		else
		{
			gotoxy(x,y); printf(" ");
			if(type==astraight){y++;}
			else if(type==aleft){y++;x--;}
			else if(type==aright){y++;x++;}
		//	if(y > 22||x<2||x>78){gotoxy(x,y); printf(" ");}
		//	{ // If the health goes too down in the map
				//~Power() ;
			//	x = rand()%74 + 3; // It will be teleported to the top
			//	y = 4;
		//	}
			Draw();
		}
	}
};
