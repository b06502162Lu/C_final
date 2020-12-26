/*
* 
* Space Shooter - a simple C++ game for Windows
* developed by Carlos Hernandez Castaneda - 2016
*
*/
#include <stdio.h>
#include <list>
#include "bullet.h" 
#include "drawing.h" 
#include "space ship.h"
#include "asteroid.h"
#include "enemy.h"
using namespace std;
#define UP    72 // ��VŲ��Ascii 
#define LEFT  75
#define RIGHT 77
#define DOWN  80
int main()
//���n
//1.�ŧi�C������A������list�p:�l�u�B�ĤH�l�u
//2.�bwhile�j�餺 
// A)�ˬd��J���g���T�� 
// B)�ˬd����O�_�I���ΥX��
// C)�ˬd��J������ʰT��
{
HideCursor();//����cursor 
WelcomeMessage();//�w��e�� 
getch();//���N��}�l 
DrawGameLimits();//�e�C���ƭ� 

list<Bullet*> Bullets; //��dynamic list�����b�����l�u
list<Bullet*>::iterator bullet; 

list<Asteroid*> Asteroids; //�Ĥ�l�u�]�@�˥�list����
list<Asteroid*>::iterator asteroid;
 
for(int i = 0; i < 10; i++) // ��dynamic���覡�[�J�@���U�����p��P��list 
{ 
  Asteroids.push_back(new Asteroid(rand()%78 + 1, rand()%4 + 3));
}
  
SpaceShip ss = SpaceShip(40,20); // �Ыبê�l�ƪ��a�������
int score = 0; // ����score

while(!ss.isDead() && score != 10000) // �����ιL�����e�A�C�����b�o�Ӱj��̶i��
{//endwhile�B��Sleep()����j��t�� (�쬰30) 
  if(kbhit())//Ū���o�g���O�A�T�{kbhit�O���F�����{���bgetch()���U�ӵ��ݿ�J 
  {
    char key = getch();
    if(key == ' ')
    { // �ť���o�g
      Bullets.push_back(new Bullet(ss.X() + 2, ss.Y() - 1));//dynamic���覡�blist�[�J�@���l�u 
    }
  }//Ū���o�g���O���� 
  
  for(bullet = Bullets.begin(); bullet != Bullets.end(); bullet++)//��list���C���l�u���ʤ@�� 
  { 
    (*bullet)->Move();//�V�W���� 
    if((*bullet)->isOut())
    { // �p�G�l�u�X��
      delete(*bullet); // �qlist�M���o���l�u�A�O�����ٵ��q��
      bullet = Bullets.erase(bullet);//��bullet���V���m (���V�Q������element���쥻�U�@��element) 
    }//�ڷPı��@�̳o�̼g���A���ӭnbullet = --Bullets.erase(bullet);
  }
  
  for(asteroid = Asteroids.begin(); asteroid != Asteroids.end(); asteroid++)
  { // list���C�Ӥp��P�T�{�O�_�X�ɡB���쪱�a�����A�_�h�U�� 
    (*asteroid)->Collision(ss);//Collision()���\��O�A�缾�a�����y���ˮ`�í���(���ͭn�ﱼ)�A�Ω��U�ʤ@�� 
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
        //list::erase() returns an iterator pointing to the element that followed the last element erased by the function call.
        delete(*asteroid);// And delete the asteroid
        asteroid = Asteroids.erase(asteroid);
        Asteroids.push_back(new Asteroid(rand()%78 + 1, rand()%4 + 3)); // in order to not reduce the number of asteroids I add one everytime one is destroyed
        score += 10; // And you get 10 points for a job well done :3
      }
    }
  }
  ss.Move();
  gotoxy(56,1); printf("%d", score);
  Sleep(30); // This is essential, otherwise the game would be unplayable
}//end while
  
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
