class enemy{//������ 
	enum enemytype{e1,e2,boss};//�T�ؼĤH����(�n�[�n�R���i) 
	//��B�c�Q�Oe1�u�|���g���asteroid
	//e2 �|���g�@��+�׮g���k�U�@��
	//boss�A�]�p �i��|��ޯ� �i�H�t�X�ޯ�class 
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
	void draw();//�bx,y�e�X�ľ��Ϯ� 
	void erase();//�M���Ϯ� 
	void randmove();//���H�K�]�p�T��move�n�[�n�R���i3-1 
	void lmove();//���H�K�]�p�T��move�n�[�n�R���i3-2 
	void rmove();//���H�K�]�p�T��move�n�[�n�R���i3-3 
	void shoot();//�o�g�l�u(asteroid) 

	
	
};
