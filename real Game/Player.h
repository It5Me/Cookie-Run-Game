#include"AllInOne.h"
class Player
{
public:
	Player();
	void DRAW(RenderWindow* window);



private:
	Sprite body;
	Texture bodyTexture;
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

