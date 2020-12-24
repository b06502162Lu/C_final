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
    { // 如果子彈碰到畫面頂端 
      gotoxy(x,y); printf(" "); // 子彈就消失
      return true; // 告訴程式子彈出界
    }
    else
    {
      return false;
    }
  }
  
  void Move()//走直線 
  {
    gotoxy(x,y); printf(" ");
    y--;
    gotoxy(x,y); printf("."); // 子彈的圖案是"." 
  }
  void lMove()//走對角線(左)
  {
  	gotoxy(x,y); printf(" ");
  	x--;y--;
  	gotoxy(x,y); printf(".");
  }
  void rMove()//走對角線(右) 
  {
  	gotoxy(x,y); printf(" ");
  	x++;y--;
  	gotoxy(x,y); printf(".");
  }
   
};
