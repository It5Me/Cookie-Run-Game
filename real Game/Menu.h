#include"AllInOne.h"
#include<fstream>
class Menu
{
public:
	Menu();
	void DRAW(RenderWindow* window);
	void loadfile();
	bool check();
	int select_player();
	int select_animal();


private:
	Texture texture_animal[4];
	Texture texture_player[2];
	Sprite  showplayer;
	Sprite  showanimal;
	Texture texture[15];
	Sprite spri_bg, spri_showname, spri_highscore,spri_btn_animalleft, spri_btn_animalright, spri_btn_playerleft,
		spri_btn_playerright,spri_player,spri_animal;
	Sprite spri_button;
	void colition(RenderWindow* window, Sprite *spri, Texture *nm, Texture *ho,bool *p,int index);
	bool onhold[5] = { 0,0,0,0,0 };
	bool click = false;
	Font font;
	Text text[5];
	fstream myfile;
	void update();
	float totaltime = 0.0;
	float totaltime1 = 0.0;
	Clock clock;
	Clock clock1;
	IntRect rect_player;
	IntRect rect_animal;
	int x=0, x1=0;
	int index_animal = 0;
	int index_player = 0;
	bool start = false; //0



};

