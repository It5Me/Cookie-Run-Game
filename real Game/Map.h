
#include"Obstacle.h"
#include"AllInOne.h"
#include"heart.h"
#include"Items.h"

#include<stdlib.h>
#include<time.h>


class MAP
{
public:
	MAP(int *P, bool* poniter);
	void DRAW(RenderWindow* window);
	bool checkSpwan();
	bool checkHole();
	//void sendposplayer(float *Y);
	void reset();
	bool checkonhole();
	void setdie(bool state);
	void setpointerhp(float* hp);
	void setpointerstatusplayer(int *status);
	void setpointergamepause(bool* state);
	void setpointerpositionplayer(Vector2f* pos);
	unsigned long* main_score;
	void setpointerim(bool*im);
private:

	bool* im;
	int calcIM();

	//immmmmmm
	Texture immortal[8];
	bool* bool_im;

	//
	void checkJKL();

	void addBear(int indexMap);

	vector<Items*>itemlist;
	
	//sound
	Texture bear[9];
	Vector2f* positionplayer;
	bool* gamepause;
	heart Heart;
	void checkcolisionheart();
	int *statusplayer;
	float *hpplayer;
	Texture objecttexture[21]; /// << ----
	vector <Obstacle*> obstacleList;
	bool b_onhole = false;
	bool die = false;
	//float* y;
	RectangleShape hole;
	void setpositionmapall();
	int* indexMap;
	////////////////////////////////////////////////////////////////////////////////////////////////
	float val_effect = 1;
	bool beareffect=false;
	Font font;
	Text textJKL;

	int intJKL = -1;
	bool bool_j=false;
	bool bool_k = false;
	bool bool_l = false;
	int valJ=100;
	int valK = 100;
	int valL = 100;
	Clock clockJ;
	Clock clockK;
	Clock clockL;
	double totalTimeJ = 0;
	double totalTimeK = 0;
	double totalTimeL = 0;
	Sprite spri_box;
	Texture texture_box;
	Sprite spri_j;
	Texture texture_j;
	Sprite spri_k;
	Texture texture_k;
	Sprite spri_l;
	Texture texture_l;

	///////////////////////////////////////////////////////////////////////////////////////////////
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

