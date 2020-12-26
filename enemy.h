class enemy{//未完成 
	enum enemytype{e1,e2,boss};//三種敵人種類(要加要刪都可) 
	//初步構想是e1只會直射兩排asteroid
	//e2 會直射一排+斜射左右各一排
	//boss再設計 可能會放技能 可以配合技能class 
private:
	enemytype t;
	int hp;
	int x;
	int y;
	bool imDead;
		
public:
	int X()  { return x; }
	int Y()  { return y; }
	int HP() { return hp; }
	enemy(int x,int y,int hp,enemytype t):x(x),y(y),hp(hp),t(t){}//constructor
	void draw();//在x,y畫出敵機圖案 
	void erase();//清除圖案 
	void randmove();//先隨便設計三種move要加要刪都可3-1 
	void lmove();//先隨便設計三種move要加要刪都可3-2 
	void rmove();//先隨便設計三種move要加要刪都可3-3 
	void shoot();//發射子彈(asteroid) 

	
	
};
