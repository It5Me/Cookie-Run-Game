#include"AllInOne.h"
class MAP
{
public:
	MAP(int *P);
	void DRAW(RenderWindow* window);
	bool checkSpwan();
	bool checkHole();
	void sendposplayer(float *Y);
	bool checkdie();
private:
	bool die = false;
	float* y;
	RectangleShape hole;
	void setpositionmapall();
	int* indexMap;
	Sprite spri_mapice;
	Texture texture_mapice;
	Sprite spri_floorice;
	Texture texture_floorice;
	Sprite spri_mapfire;
	Texture texture_mapfire;
	Sprite spri_floorfire;
	Texture texture_floorfire;
	Sprite spri_mapforest;
	Texture texture_mapforest;
	Sprite spri_floorforest;
	Texture texture_floorforest;
	void MOVE();
};

