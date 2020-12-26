#ifndef BULLET
#define BULLET
#include"drawing.h"
#include"stdio.h"
#endif
class Bullet
{
	enum bullettype{bleft,bstraight,bright};
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
  Bullet(int _x, int _y,bullettype t)//���w��V���l�u 
  {
    x = _x;
    y = _y;
    type=t;
  }
  
  bool isOut()
  {
    if(y <= 3)
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
  	if(type==1){//�����u 
  		gotoxy(x,y); printf(" ");
    	y--;
    	gotoxy(x,y); printf("."); // �l�u���Ϯ׬O"." 
	}
    else if(type==0){//���﨤�u(��)
    	gotoxy(x,y); printf(" ");
  		x--;y--;
  		gotoxy(x,y); printf(".");
	}
	else if(type==2){//���﨤�u(�k)
		gotoxy(x,y); printf(" ");
  		x++;y--;
  		gotoxy(x,y); printf(".");
	}
  }
   
};
