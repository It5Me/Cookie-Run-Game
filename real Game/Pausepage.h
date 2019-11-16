#pragma once
#include"AllInOne.h"
class Pausepage
{
public:
	Pausepage();
	void draw(RenderWindow* window);
	void setpointer(bool *state);
	bool checkclickforward();
	void reset();

private:
	bool clickforward = false;
	bool *pausestate;
	Texture texture_pausegame,texture_forward,texture_back;
	Sprite spri_pausegame,spri_forward,spri_back;

	
};

