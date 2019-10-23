#include"AllInOne.h"
class Player
{
public:
	Player();
	void DRAW(RenderWindow* window);
	Vector2f getposition();
	Vector2f gethalfsize() { return Vector2f(this->bodyTexture.getSize().x /10 / 4.0f, this->bodyTexture.getSize().y /10/ 4.0f); };



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

