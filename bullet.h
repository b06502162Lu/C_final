#ifndef BULLET
#define BULLET
#include"drawing.h"
#include"stdio.h"


#endif
enum bullettype{bleft,bstraight,bright};

class Bullet
{

private:
  int x;
  int y;
  bullettype type;
public:
  int X()  { return x; }
  int Y()  { return y; }
  Bullet(int _x, int _y)//�����w�l�u����V�A�w�]�������l�u 
  {
    x = _x;
    y = _y;
    type=bstraight;
  }
  /*Bullet(int _x, int _y,bullettype t)//���w��V���l�u 
  {
    x = _x;
    y = _y;
    type=t;
  }
  */
  Bullet(int _x, int _y,char t)//���w��V���l�u 
  {
    x = _x;
    y = _y;
    if(t == 'L'){
    	type = bleft;
	}
	if(t == 'S'){
		type = bstraight;
	}
	if(t == 'R'){
		type = bright;
	}
  }
  
  bool isOut()
  {
    if(y <= 3||x<2||x>78)
    { // �p�G�l�u�I��e������ 
      gotoxy(x,y); printf(" "); // �l�u�N����
      return true; // �i�D�{���l�u�X��
    }
    else
    {
      return false;
    }
  }
  
  void Move()
  {
  			gotoxy(x,y); printf(" ");
			if(type==bstraight){y--;}
			else if(type==bleft){y--;x--;}
			else if(type==bright){y--;x++;}
			gotoxy(x,y); printf(".");
  }
  
  bool Collision(int X,int Y) 
  {
  	if (x >= X && (x <= X + 5) && ((y >= Y && (y <= Y + 2))))
		{ 
			
			gotoxy(x,y); printf(" "); 

			y = -1;
			return true;
		}
		else
		{
			/*gotoxy(x,y); printf(" ");
			if(type==bstraight){y--;}
			else if(type==bleft){y--;x--;}
			else if(type==bright){y--;x++;}
			gotoxy(x,y); printf(".");*/
			/*if(y > 22||x<2||x>78)
			{ // If the asteroid goes too down in the map
				x = rand()%74 + 3; // It will be teleported to the top
				y = 4;
			}*/
			
			return false;
		}
  }
};
