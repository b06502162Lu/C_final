/*
* Space Shooter - a simple C++ game for Windows
* developed by Carlos Hernandez Castaneda - 2016
*
*/
#include <stdlib.h> //Standard c and c++ libraries
#include <conio.h>
#include <stdio.h>
#include <windows.h> // To take control over the terminal
#include <list>
#include "drawing.h" 
#include "space ship.h"
#include "asteroid.h"
using namespace std;
#define UP    72 // arrow keys' ascii numbers
#define LEFT  75
#define RIGHT 77
#define DOWN  80//80808080808080808


class Bullet
{
private:
int x;
int y;
public:
int X()  { return x; }
int Y()  { return y; }
Bullet(int _x, int _y)
{
x = _x;
y = _y;
}
bool isOut()
{
if(y <= 3)
{ // If the bullet reaches the top of the map
gotoxy(x,y); printf(" "); // It disappears
return true; // And informs the ame that it should no longer exist :c
}
else
{
return false;
}
}
void Move()
{
gotoxy(x,y); printf(" ");
y--;
gotoxy(x,y); printf("."); // The shape of the bullet
}
};










int main()
{

HideCursor();
WelcomeMessage();
getch();
DrawGameLimits();

list<Bullet*> Bullets; // We will use a dynamic list for the bullets in the game
list<Bullet*>::iterator bullet; // And an iterator for the list

list<Asteroid*> Asteroids; // The same goes for the asteroids
list<Asteroid*>::iterator asteroid;

for(int i = 0; i < 10; i++) // Pick as many asteroids as you want
{ // They are randomly placed in the map but not too low
Asteroids.push_back(new Asteroid(rand()%78 + 1, rand()%4 + 3));
}
SpaceShip ss = SpaceShip(40,20); // Here our adventure begins
int score = 0; // Your score :3

while(!ss.isDead() && score != 100) // If you die or reach 100 points the game ends
{
if(kbhit())
{
char key = getch();
if(key == ' ')
{ // If you press the space bar you add a bullet to the bullet list
Bullets.push_back(new Bullet(ss.X() + 2, ss.Y() - 1));
}
}
for(bullet = Bullets.begin(); bullet != Bullets.end(); bullet++)
{ // For every bullet that is in space
(*bullet)->Move();
if((*bullet)->isOut())
{ // If the bullet reached the end of the map
delete(*bullet); // It gets deleted
bullet = Bullets.erase(bullet);
}
}
for(asteroid = Asteroids.begin(); asteroid != Asteroids.end(); asteroid++)
{ // Every asteroid checks if the spaceship shares it's coordinates :3
(*asteroid)->Collision(ss);
}
for(asteroid = Asteroids.begin(); asteroid != Asteroids.end(); asteroid++)
{
for(bullet = Bullets.begin(); bullet != Bullets.end(); bullet++)
{ // asteroid-bullet collision
int astX = (*asteroid)->X(); //Coordinates of the asteroid
int astY = (*asteroid)->Y();
int bulX = (*bullet)->X(); // Coordinates of the bullet
int bulY = (*bullet)->Y();
if((astX == bulX) && ((astY == bulY) || (astY + 1 == bulY)))
{ //Chances are that in the Y axis they never reach the same value, that case must be considered
gotoxy(bulX,bulY); printf(" "); // Makes the bullet invisible
gotoxy(astX,astY); printf("X"); printf(" "); // I still have my doubts in this part, but it tries to signal a collision, sometimes the X remains theme...
delete(*bullet); // You delete the bullet
bullet = Bullets.erase(bullet);
delete(*asteroid);// And the asteroid
asteroid = Asteroids.erase(asteroid);
Asteroids.push_back(new Asteroid(rand()%78 + 1, rand()%4 + 3)); // in order to not reduce the number of asteroids I add one everytime one is destroyed
score += 10; // And you get 10 points for a job well done :3
}
}
}
ss.Move();
gotoxy(56,1); printf("%d", score);
Sleep(30); // This is essential, otherwise the game would be unplayable
}
if(!ss.isDead())
{ // If you died
GameOverVictoryMessage();
}
else
{ // If you won
GameOverDefeatMessage();
}
Sleep(5000);
SpecialMessage(); // Surprise
Sleep(5000);
return 0;
}
