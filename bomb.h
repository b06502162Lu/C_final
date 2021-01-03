#include <conio.h>
#include <stdio.h>
#include <windows.h> 

using namespace std;

class Bomb
{
	enum astertype{aleft,astraight,aright};
private:
	int x;
	int y;
	astertype type; 
		
public:
	int X()  { return x; }
	int Y()  { return y; }
	Bomb(int _x, int _y)
	{
		x = _x;
		y = _y;
		type=astraight;	
	}
	Bomb(int _x, int _y,astertype t)
	{
		x = _x;
		y = _y;
		type=t;	
	}
	
	void Draw()
	{
		if(y<0){
		return ;
		}
		gotoxy(x,y); printf("B"); // Get the Bomb!!!
	}
	
	void Collision(SpaceShip &ss) // The Bomb finds the spaceship
	{
		if(((x >= ss.X()) && (x <= ss.X() + 5)) && ((y >= ss.Y()) && (y <= ss.Y() + 2)))
		{ // Depending on the shape of the spaceship you have to tinker when you get the Bomb
			ss.getBomb();
			gotoxy(x,y); printf(" "); // And the Bomb is "destroyed"
			x = rand()%74 + 3; // The truth is it just teleports to the top of the map
			y = 28;
		}
		else
		{
			gotoxy(x,y); printf(" ");
			if(type==astraight){y++;}
			else if(type==aleft){y++;x--;}
			else if(type==aright){y++;x++;}
		//	if(y > 22||x<2||x>78)
		//	{ // If the Bomb goes too down in the map
		//		x = rand()%74 + 3; // It will be teleported to the top
		//		y = 4;
				//~power();
		//	}
			Draw();
		}
	}
};
