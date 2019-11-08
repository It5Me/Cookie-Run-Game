#include"AllInOne.h"

class endgame
{
public: 
	endgame();
	void draw(RenderWindow* window);
	void setstatus(bool state);
	bool getstatus();
	bool ismenustart();
private:
	void checkbtn(RenderWindow *window);
	bool hold = false,statemenu=false;
	bool status=false;
	Sprite bgendgame,btn;
	Texture textureendgame,texturebtn;

};
