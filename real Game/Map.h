
#include"Obstacle.h"
#include"AllInOne.h"


class MAP
{
public:
	MAP(int *P);
	void DRAW(RenderWindow* window);
	bool checkSpwan();
	bool checkHole();
	void sendposplayer(float *Y);
	void reset();
	bool checkonhole();
	void setdie(bool state);
	void setpointerhp(float* hp);
	void setpointerstatusplayer(int *status);
	void setpointergamepause(bool* state);
private:
	
	//sound
	

	//
	bool* gamepause;

	int *statusplayer;
	float *hpplayer;
	Texture objecttexture[21]; /// << ----
	vector <Obstacle*> obstacleList;
	bool b_onhole = false;
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
	Texture texture_mapdesert;
	Sprite spri_mapdesert;
	Texture texture_floordesert;
	Sprite spri_floordesert;
	void MOVE();
	int indexmap=0;
	int indexhole = 0;
	//RectangleShape Hole[4][3];
};

