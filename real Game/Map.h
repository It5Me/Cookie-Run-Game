#include"AllInOne.h"
class MAP
{
public:
	MAP();
	void DRAW(RenderWindow* window);
	bool checkSpwan();
private:
	Sprite map1;
	Texture map1Texture;
	Sprite floor1;
	Texture floor1Texture;
	void MOVE();
};

