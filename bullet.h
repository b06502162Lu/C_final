#ifndef BULLET
#define BULLET
#include"drawing.h"
#include"stdio.h"
#endif
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
    { // �p�G�l�u�I��e������ 
      gotoxy(x,y); printf(" "); // �l�u�N����
      return true; // �i�D�{���l�u�X��
    }
    else
    {
      return false;
    }
  }
  
  void Move()//�����u 
  {
    gotoxy(x,y); printf(" ");
    y--;
    gotoxy(x,y); printf("."); // �l�u���Ϯ׬O"." 
  }
  void lMove()//���﨤�u(��)
  {
  	gotoxy(x,y); printf(" ");
  	x--;y--;
  	gotoxy(x,y); printf(".");
  }
  void rMove()//���﨤�u(�k) 
  {
  	gotoxy(x,y); printf(" ");
  	x++;y--;
  	gotoxy(x,y); printf(".");
  }
   
};
