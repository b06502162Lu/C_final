#include <stdlib.h> //Standard c and c++ libraries
#include <conio.h>
#include <stdio.h>
#include <windows.h> // To take control over the terminal
#include <list>
using namespace std;

class Asteroid
{
private:
	int x;
	int y;
		
public:
	int X()  { return x; }
	int Y()  { return y; }

	Asteroid(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	
	void Draw()
	{
		gotoxy(x,y); printf("*"); // Fear the asteroids!!
	}
	
	void Collision(SpaceShip &ss) // The asteroid finds the spaceship
	{
		if(((x >= ss.X()) && (x <= ss.X() + 5)) && ((y >= ss.Y()) && (y <= ss.Y() + 2)))
		{ // Depending on the shape of the spaceship you have to tinker when the asteroid really hits you
			ss.Damage(); // The asteroid hurts
			gotoxy(x,y); printf(" "); // And the asteroid is "destroyed"
			x = rand()%74 + 3; // The truth is it just teleports to the top of the map
			y = 4;
		}
		else
		{
			gotoxy(x,y); printf(" ");
			y++;
			if(y > 22)
			{ // If the asteroid goes too down in the map
				x = rand()%74 + 3; // It will be teleported to the top
				y = 4;
			}
			Draw();
		}
	}
};
