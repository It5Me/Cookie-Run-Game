#include"AllInOne.h"
#include<fstream>
class Menu
{
public:
	Menu();
	void DRAW(RenderWindow* window);
	void loadfile();


private:
	Texture texture[15];
	Sprite spri_bg, spri_showname, spri_highscore,spri_btn_animalleft, spri_btn_animalright, spri_btn_playerleft,
		spri_btn_playerright,spri_player,spri_animal;
	Sprite spri_button;
	void colition(RenderWindow* window, Sprite *spri, Texture *nm, Texture *ho,bool *p);
	bool onhold[5] = { 0,0,0,0,0 };
	bool click = false;
	Font font;
	Text text[5];
	fstream myfile;



};

