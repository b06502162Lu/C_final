class SpaceShip{
private:
	int x; // x coordinate
	int y; // y coordinate
	int hp; // �X���R 
	int energy; // �@���R�X�w��
	bool imDead; // is the ship dead?
	int state ; // 0 :代表往前方射一顆bullet , 1 :代表朝前方射三顆  ,2:代表同時朝斜方射 //陸亮宇12/29
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
	
	void get_power() ; //陸亮宇12/29
	
	void Explosion();
	
	void Move();
	
};
