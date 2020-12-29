#ifndef ENEMY
#define ENEMY
#include"enemy.h"
#include"drawing.h"
#endif
#include<stdio.h>
#include<windows.h>

using namespace std;
void Enemy::draw()//在x,y畫出敵機圖案 
{
	gotoxy(x,y);     printf("%c%c%c%c%c",65, 65, 65, 65, 65);
	gotoxy(x,y + 1); printf( " %c%c%c ", 65,65,65);
	gotoxy(x,y + 2); printf( "  %c  ", 65 );
}

void Enemy::erase()//清除圖案
{
	gotoxy(x,y);     printf("     ");
	gotoxy(x,y + 1); printf("     ");
	gotoxy(x,y + 2); printf("     ");
}

void Enemy::move8()
{
	erase();
	static int step=0;
	switch (step%40)
	{
		case 0:x++;y--;break;
		case 1:x++;y--;break;
		case 2:x++;break;
		case 3:x++;y--;break;
		case 4:x++;break;
		case 5:x++;break;
		case 6:x++;break;
		case 7:x++;y++;break;
		case 8:x++;y++;break;
		case 9:y++;break;
		case 10:y++;break;
		case 11:x--;y++;break;
		case 12:x--;y++;break;
		case 13:x--;break;
		case 14:x--;break;
		case 15:x--;break;
		case 16:x--;y--;break;
		case 17:x--;break;
		case 18:x--;y--;break;
		case 19:x--;y--;break;//back to origin
		case 20:x--;y--;break;
		case 21:x--;y--;break;
		case 22:x--;break;
		case 23:x--;y--;break;
		case 24:x--;break;
		case 25:x--;break;
		case 26:x--;break;
		case 27:x--;y++;break;
		case 28:x--;y++;break;
		case 29:y++;break;
		case 30:y++;break;
		case 31:x++;y++;break;
		case 32:x++;y++;break;
		case 33:x++;break;
		case 34:x++;break;
		case 35:x++;break;
		case 36:x++;y--;break;
		case 37:x++;break;
		case 38:x++;y--;break;
		case 39:x++;y--;break;		
	}
	step++;
	draw();
	
} 

void Enemy::lmove(){
	Enemy::erase();
	if(x > 2)
	{x -= 1;} 
	Enemy::draw();
} 

void Enemy::rmove(){
	Enemy::erase();
	if(x + 4 < 77)
	{x += 1;} 
	Enemy::draw();
}

void Enemy::dmove() {
	Enemy::erase();
	if(y + 2 < 22)
	{y += 1;} 
	Enemy::draw();
}

void Enemy::umove(){
	Enemy::erase();
	if(y > 3)
	{y -= 1;} 
	Enemy::draw();
}

void Enemy::move()
{
	int bosshp=100;
	if(t!=boss)
	{
		static int m=0;
		if(m==0){
			if(x<73){
			rmove();
			}
			if(x>=73){
				m=1;
			}
		}
		
		else if (m==1){
			if(x>2){
			lmove();
			}
			if(x<=2){
				m=0;
			}
			
		}
	}
	if(t==boss)
	{
		static int m=0;
		static int top=6;
		if (y>top){
			move8();
			top=3;
		}
		else if(hp<=inithp/2&&x==39)//如果血量少於一半 又回到中間  
		{
			dmove();
		}
		
		else if(m==0){
			if(x<73){
			rmove();
			}
			if(x>=73){
				m=1;
			}
		}
		
		else if (m==1){
			if(x>2){
			lmove();
			}
			if(x<=2){
				m=0;
			}
			
		}
	}
}

void Enemy::Explosion()
{
	Enemy::erase();
	gotoxy(x,y);     printf("*****");
	gotoxy(x,y + 1); printf("  *  ");
	gotoxy(x,y + 2); printf("  *  ");
	Sleep(50);
	Enemy::erase();
	gotoxy(x,y);     printf(" * * ");
	gotoxy(x,y + 1); printf("* * *");
	gotoxy(x,y + 2); printf(" * * ");
	Sleep(50);
	Enemy::erase();
	gotoxy(x,y);     printf("* * *");
	gotoxy(x,y + 1); printf(" * * ");
	gotoxy(x,y + 2); printf("*   *");
	Sleep(50);
}
void Enemy::Damage(int damagehp){
	hp-=damagehp;
	if(hp<=0)
	{
		imDead=true;//在main裡寫damge();if(enemy.imDead){delete} 
		Explosion();
	}
}
 



