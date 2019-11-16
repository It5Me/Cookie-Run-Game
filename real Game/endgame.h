#include"AllInOne.h"

class endgame
{
public: 
	endgame();
	void draw(RenderWindow* window);
	void setstatus(bool state);
	bool getstatus();
	bool ismenustart();
	void setpointscore(unsigned long* t);
private:
	int index = 0;
	unsigned long* score;
	string tempscore = "        ",mainscore;
	Clock clock;
	double totaltime = 0;
	void loadscore();
	bool loadscorecomplete = false;
	Font font;
	Text textscore;
	void checkbtn(RenderWindow *window);
	bool hold = false,statemenu=false;
	bool status=false;
	Sprite bgendgame,btn;
	Texture textureendgame,texturebtn;

};
