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
  Bullet(int _x, int _y)//不指定子彈的方向，預設為直的子彈 
  {
    x = _x;
    y = _y;
    type=bstraight;
  }
  Bullet(int _x, int _y,bullettype t)//指定方向的子彈 
  {
    x = _x;
    y = _y;
    type=t;
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
  
  void Move()
  {
  	if(type==1){//走直線 
  		gotoxy(x,y); printf(" ");
    	y--;
    	gotoxy(x,y); printf("."); // 子彈的圖案是"." 
	}
    else if(type==0){//走對角線(左)
    	gotoxy(x,y); printf(" ");
  		x--;y--;
  		gotoxy(x,y); printf(".");
	}
	else if(type==2){//走對角線(右)
		gotoxy(x,y); printf(" ");
  		x++;y--;
  		gotoxy(x,y); printf(".");
	}
  }
   
};
