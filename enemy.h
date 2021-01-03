enum enemytype{e1,e2,boss};//三種敵人種類(要加要刪都可) 
class Enemy{
	
	//初步構想是e1只會直射兩排asteroid
	//e2 會直射一排+斜射左右各一排
	//boss再設計 可能會放技能 可以配合技能class 
private:
	enemytype t;
	int hp;
	int inithp;
	int x;
	int y;
	int speed;//speed是2就是每兩個while loop動一次。暫定 
	bool imDead=false;
		
public:
	enemytype type(){return t;} 
	int &X()  { return x; }
	int &Y()  { return y; }
	int &HP() { return hp; }
	Enemy(int x,int y,int hp,enemytype t):x(x),y(y),hp(hp),t(t){inithp=hp;}//constructor
	void draw();//在x,y畫出敵機圖案 //
	void erase();//清除圖案 //
	void move8();//
	void lmove();//
	void rmove();//
	void dmove();//
	void umove();//
	void move();
	//void shoot();發射子彈(asteroid) 應該要在main執行  因為要在list新增asteroid 
	void Explosion();//
	void Animation_damage();
	bool &isDead(){
		return imDead;
	}
	void Damage(int);
	
	
	
};
