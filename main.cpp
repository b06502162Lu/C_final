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
#define UP    72 // 方向鑑的Ascii 
#define LEFT  75
#define RIGHT 77
#define DOWN  80
int main()
//概要
//1.宣告遊戲物件，有的用list如:子彈、敵人子彈
//2.在while迴圈內 
// A)檢查輸入的射擊訊號 
// B)檢查物件是否碰撞或出界
// C)檢查輸入的飛船移動訊號
{
HideCursor();//隱藏cursor 
WelcomeMessage();//歡迎畫面 
getch();//任意鍵開始 
DrawGameLimits();//畫遊戲數值 

list<Bullet*> Bullets; //用dynamic list紀錄在場的子彈
list<Bullet*>::iterator bullet; 

list<Asteroid*> Asteroids; //敵方子彈也一樣用list紀錄
list<Asteroid*>::iterator asteroid;
 
for(int i = 0; i < 10; i++) // 用dynamic的方式加入一顆下降的小行星到list 
{ 
  Asteroids.push_back(new Asteroid(rand()%78 + 1, rand()%4 + 3));
}
  
SpaceShip ss = SpaceShip(40,20); // 創建並初始化玩家控制的飛機
int score = 0; // 分數score

while(!ss.isDead() && score != 10000) // 死掉或過關之前，遊戲都在這個迴圈裡進行
{//endwhile處有Sleep()控制迴圈速度 (原為30) 
  if(kbhit())//讀取發射指令，確認kbhit是為了不讓程式在getch()停下來等待輸入 
  {
    char key = getch();
    if(key == ' ')
    { // 空白鍵發射
      Bullets.push_back(new Bullet(ss.X() + 2, ss.Y() - 1));//dynamic的方式在list加入一顆子彈 
    }
  }//讀取發射指令結束 
  
  for(bullet = Bullets.begin(); bullet != Bullets.end(); bullet++)//讓list中每顆子彈移動一格 
  { 
    (*bullet)->Move();//向上移動 
    if((*bullet)->isOut())
    { // 如果子彈出界
      delete(*bullet); // 從list清除這顆子彈，記憶體還給電腦
      bullet = Bullets.erase(bullet);//讓bullet指向原位置 (指向被消除的element的原本下一個element) 
    }//我感覺原作者這裡寫錯，應該要bullet = --Bullets.erase(bullet);
  }
  
  for(asteroid = Asteroids.begin(); asteroid != Asteroids.end(); asteroid++)
  { // list中每個小行星確認是否出界、撞到玩家飛機，否則下降 
    (*asteroid)->Collision(ss);//Collision()的功能是，對玩家飛機造成傷害並重生(重生要改掉)，或往下動一格 
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
