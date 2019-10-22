#include"AllInOne.h"
class Items
{	
public:
	Items(Texture texture,int score,int countx,Vector2f pos);
	void DRAW(RenderWindow* window);
private:
	Texture Texturebody;
	Sprite body;
	int score;
	void update();
	float totaltime = 0;
	IntRect rec;
	Clock clock;
	int x=0;
	int countx;
};

