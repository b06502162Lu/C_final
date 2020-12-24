class enemy{//¥¼§¹¦¨ 
private:
	int hp;
	int x;
	int y;
	bool imDead=false;	
public:
	int X()  { return x; }
	int Y()  { return y; }
	int HP() { return hp; }
	enemy(int x,int y,int hp):x(x),y(y),hp(hp){}
	
	
};
