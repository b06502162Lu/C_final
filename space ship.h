class SpaceShip{
private:
	int x; // x coordinate
	int y; // y coordinate
	int hp; // 幾條命 
	int energy; // 一條命幾滴血
	bool imDead; // is the ship dead?
	
public:
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
	
	void Move();
	
};
