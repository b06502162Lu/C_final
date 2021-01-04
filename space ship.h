class SpaceShip{
private:
	int x; 
	int y; 
	int hp;
	int energy; 
	int bomb;
	
	bool imDead; 
	
public:
	int state;
	int X()  { return x; }
	int Y()  { return y; }
	int HP() { return hp; }
	
	bool isDead();
	
	SpaceShip(int _x, int _y);
	
	void DrawSpaceShipInfo();
	
	void Draw();
	
	void Erase();
	
	void Damage();
	
	void Explosion();
	
	void getBomb();//get boom
	
	void usebomb();//use boom
	
	void gethealth();//get health
	
	void getpower();
	
	void Move();
	
};
