#include"AllInOne.h"
#include<algorithm>
#include<vector>
#include<fstream>

class endgame
{
public: 
	endgame(Event *event);
	void draw(RenderWindow* window);
	void setstatus(bool state);
	bool getstatus();
	bool ismenustart();
	void setpointscore(unsigned long* t);
private:
	vector<pair<int, string> > scorea;
	fstream myFile;
	string temp;
	string tempString;
	int tempInt = 0, P = 1;
	bool statea = false;
	Event* event;
	sf::RectangleShape object;
	sf::RectangleShape cursor;
	float totalTime = 0;
	sf::Clock clocka;
	Text text;
	bool state = false;
	char last_char = ' ';
	std::string input;


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
