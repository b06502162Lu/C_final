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
#include "bomb.h"
#include "Health.h"
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

list<Enemy*> Enemies;
list<Enemy*>::iterator enemy;

list<Bomb*> Bombs; //list of the bomb
list<Bomb*>::iterator bomb;

list<Health*> Healths; //list of the power
list<Health*>::iterator health;


for(int i = 0; i < 3; i++) //build a new bomb
{
	Bombs.push_back(new Bomb(rand()%78 + 1, rand()%4 + 3));
}
  
for(int i = 0; i < 3; i++) // build a new power
{
	Healths.push_back(new Health(rand()%78 + 1, rand()%4 + 3));
}
SpaceShip ss = SpaceShip(40,20); // 創建並初始化玩家控制的飛機
int score = 0; // 分數score
int count_t =0;
bool done1=false,done2=false,done3=false,done4=false,done5=false,done6=false;
while(!ss.isDead() && score <99999999) // 死掉或過關之前，遊戲都在這個迴圈裡進行
{//endwhile處有Sleep()控制迴圈速度 (原為30) 
  if(score==300&&done1==false)
  {Enemies.push_back(new Enemy(40,4,50,e1));
  done1=true;
  }
  if(score>100000&&done2==false)
  {Enemies.push_back(new Enemy(40,4,50,e2));done2=true;
  }
  if(score>400000&&done3==false)
  {
  	Enemies.push_back(new Enemy(30,4,50,e1));
  Enemies.push_back(new Enemy(50,4,50,e1));done3=true;
  }
  if(score>600000&&done4==false){
  	Enemies.push_back(new Enemy(30,4,100,e2));
  Enemies.push_back(new Enemy(50,4,100,e2));done4=true;
  }
  if(score>1200000&&done5==false){
  	Enemies.push_back(new Enemy(20,4,50,e1));
  Enemies.push_back(new Enemy(40,4,100,e2));
  Enemies.push_back(new Enemy(60,4,50,e1));done5=true;
  }
  if(score>1700000&&done6==false){
  	Enemies.push_back(new Enemy(40,4,200,boss));done6=true;
  }
  
  
  count_t++; 
  if(count_t%5==0){
  	score+=10;
  }
  if(kbhit())//讀取發射指令，確認kbhit是為了不讓程式在getch()停下來等待輸入 
  {
    char key = getch();
    if(key == ' ')
    { // 空白鍵發射
      Bullets.push_back(new Bullet(ss.X() + 2, ss.Y() - 1));//dynamic的方式在list加入一顆子彈 
    }
    if(key == 'b'||key == 'B')
    { // 空白鍵發射
      ss.usebomb();
      for(enemy = Enemies.begin(); enemy != Enemies.end(); enemy++){
      	(*enemy)->Damage(9999);
      	
	  }
    }
  }//讀取發射指令結束 
  
  //敵人發射子彈
  if(count_t%16==1)
  for(enemy = Enemies.begin(); enemy != Enemies.end(); enemy++)
  {
  	if((*enemy)->type()==e1&&(*enemy)->HP()>0)//HP>0防BUG 可以不加 
	  {
  		Asteroids.push_back(new Asteroid((*enemy)->X() + 2, (*enemy)->Y() + 2));
	  }
	if((*enemy)->type()==e2&&(*enemy)->HP()>0)
	  {
  		Asteroids.push_back(new Asteroid((*enemy)->X() + 2, (*enemy)->Y() + 2,aleft));
  		Asteroids.push_back(new Asteroid((*enemy)->X() + 2, (*enemy)->Y() + 2,aright));
	  }
	if((*enemy)->type()==boss&&(*enemy)->HP()>0)
	  {
  		Asteroids.push_back(new Asteroid((*enemy)->X() + 2, (*enemy)->Y() + 2,aleft));
  		Asteroids.push_back(new Asteroid((*enemy)->X() + 2, (*enemy)->Y() + 2));
  		Asteroids.push_back(new Asteroid((*enemy)->X() + 2, (*enemy)->Y() + 2,aright));
	  }
  }
  //敵人移動 
  if(count_t%2==1)
  for(enemy = Enemies.begin(); enemy != Enemies.end(); enemy++)
  {
  	if((*enemy)->HP()>0)
  	(*enemy)->move();
  	if((*enemy)->isDead()){
  		if((*enemy)->type()==e1)
  		score+=100000;
  		else if((*enemy)->type()==e2)
  		score+=300000;
  		else if((*enemy)->type()==boss)
  		score=999999999;
  		(*enemy)->erase();
  		delete(*enemy); // 從list清除這顆子彈，記憶體還給電腦
      	enemy = Enemies.erase(enemy);
      	
	  }
  }
  
  //子彈打敵人 
  for(bullet = Bullets.begin(); bullet != Bullets.end(); bullet++)//讓list中每顆子彈移動一格 
  { 
  	bool needmove=true;
    for(enemy = Enemies.begin(); enemy != Enemies.end(); enemy++){
    if((*bullet)->Collision((*enemy)->X(),(*enemy)->Y())){
    	(**enemy).Damage(5);
    	needmove=false;
	}//向上移動 
	}
	
	if(needmove)
    (*bullet)->Move();
    if((*bullet)->isOut())
    { // 如果子彈出界
      delete(*bullet); // 從list清除這顆子彈，記憶體還給電腦
      bullet = Bullets.erase(bullet);
    }
  }
  
  
  for(asteroid = Asteroids.begin(); asteroid != Asteroids.end(); asteroid++)
  { // list中每個小行星確認是否出界、撞到玩家飛機，否則下降 
    (*asteroid)->Collision(ss);//Collision()的功能是，對飛機造成傷害，或動一格 
    if((*asteroid)->Y() >= 23||(*asteroid)->X() <= 2||(*asteroid)->X() >= 78){
    	delete((*asteroid)) ;
    	asteroid = Asteroids.erase(asteroid) ;
	}
  }
  for(bomb = Bombs.begin(); bomb != Bombs.end(); bomb++)
  { 
    (*bomb)->Collision(ss);//bomb's collision
    if((*bomb)->Y() >= 23){
    	delete((*bomb)) ;
    	bomb = Bombs.erase(bomb) ;
	}
  }
  
  for(health = Healths.begin(); health != Healths.end(); health++)
  { 
    (*health)->Collision(ss);//power's collision
    if((*health)->Y() >= 23){
    	delete((*health)) ;
    	health = Healths.erase(health) ;
	}
  }
  
  /*for(asteroid = Asteroids.begin(); asteroid != Asteroids.end(); asteroid++) 
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
  }*/
  ss.Move();
  //ss.usebomb();// press'b' then use bomb
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

