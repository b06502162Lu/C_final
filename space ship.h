class SpaceShip{
private:
	int x; // x coordinate
	int y; // y coordinate
	int hp; // �X���R 
	int energy; // �@���R�X�w��
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
