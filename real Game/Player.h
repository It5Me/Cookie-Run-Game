#include"AllInOne.h"
class Player
{
public:
	Player();
	void DRAW(RenderWindow* window);
	Vector2f getposition();
	Vector2f gethalfsize();
	void selectcharacter(int index);

private:

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

