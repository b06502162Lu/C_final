enum enemytype{e1,e2,boss};//�T�ؼĤH����(�n�[�n�R���i) 
class Enemy{
	
	//��B�c�Q�Oe1�u�|���g���asteroid
	//e2 �|���g�@��+�׮g���k�U�@��
	//boss�A�]�p �i��|��ޯ� �i�H�t�X�ޯ�class 
private:
	enemytype t;
	int hp;
	int inithp;
	int x;
	int y;
	int speed;//speed�O2�N�O�C���while loop�ʤ@���C�ȩw 
	bool imDead=false;
		
public:
	enemytype type(){return t;} 
	int &X()  { return x; }
	int &Y()  { return y; }
	int &HP() { return hp; }
	Enemy(int x,int y,int hp,enemytype t):x(x),y(y),hp(hp),t(t){inithp=hp;}//constructor
	void draw();//�bx,y�e�X�ľ��Ϯ� //
	void erase();//�M���Ϯ� //
	void move8();//
	void lmove();//
	void rmove();//
	void dmove();//
	void umove();//
	void move();
	//void shoot();�o�g�l�u(asteroid) ���ӭn�bmain����  �]���n�blist�s�Wasteroid 
	void Explosion();//
	void Animation_damage();
	bool &isDead(){
		return imDead;
	}
	void Damage(int);
	
	
	
};
