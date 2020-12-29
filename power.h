#include <conio.h>
#include <stdio.h>
#include <windows.h> // To take control over the terminal

using namespace std;

class power
{
	enum astertype{aleft,astraight,aright};
private:
	int x;
	int y;
	astertype type; 
		
public:
	int X()  { return x; }
	int Y()  { return y; }

	power(int _x, int _y)//�����w��V �w�]���� 
	{
		x = _x;
		y = _y;
		type=astraight;	
	}
	power(int _x, int _y,astertype t = astraight)//���w��V��asteriod 
	{
		x = _x;
		y = _y;
		type=t;	
	}
	
	void Draw()
	{
        
		gotoxy(x,y); printf("-----"); // Fear the asteroids!!
        gotoxy(x,y+1);printf("| P |");
        gotoxy(x,y+2);printf("|___|");
        gotoxy(x,y) ;
	}
	
	void Collision(SpaceShip &ss) // The asteroid finds the spaceship
	{
		if(((x >= ss.X()) && (x <= ss.X() + 5)) && ((y >= ss.Y()) && (y <= ss.Y() + 2)))
		{ // Depending on the shape of the spaceship you have to tinker when the asteroid really hits you
			//ss.Damage(); // The asteroid hurts
            ss.get_power() ; //陸亮宇 12/29
			gotoxy(x,y); printf(" "); // And the asteroid is "destroyed"
			x = rand()%74 + 3; // The truth is it just teleports to the top of the map
			y = 4;
		}
		else
		{
			gotoxy(x,y); printf(" ");
			if(type==astraight){y++;}
			else if(type==aleft){y++;x--;}
			else if(type==aright){y++;x++;}
			if(y > 22||x<2||x>78)
			{ // If the asteroid goes too down in the map
				x = rand()%74 + 3; // It will be teleported to the top
				y = 4;
			}
			Draw();
		}
	}
};