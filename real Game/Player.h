#include"AllInOne.h"
class Player
{
public:
	Player();
	void DRAW(RenderWindow* window);
	Vector2f getposition();
	Vector2f gethalfsize();
	void selectcharacter(int index);
	void setBig();
	//void getposplayer(float *Y);
	void reset();
	void checkhole(bool state);
	bool checkdie();
	void setpointerstatusplayer(int* status);
	void setpointerpositionplayer(Vector2f *pos);
	void gamepause(bool* state);
private:
	Vector2f* positionplayer;
	bool* Gamepause;
	Clock clockplayer;
	float timeplayer = 0;
	int countdraw=0;
	int* status;  
	void statusplayer();
	bool onhole=false;
	//bool die=false;
	//float* y;
	Sprite body;
	Texture manTexture;
	Texture womenTexture;
	int select=0;
	void update(int row);
	Clock clock;
	IntRect rec;
	int count=0;
	float totaltime;
	void control();
	float A = 10;
	void jump();
	int statejump=0;
	bool jumphight=false;
	Clock clockjump;
	float jumpdelta=0;
	int stateanimation = 0;
	

	

};

