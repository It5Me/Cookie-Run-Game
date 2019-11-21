#pragma once
#include"AllInOne.h"
class heart
{
public:
	heart();
	void draw(RenderWindow* window);
	void setposition(Vector2f pos);
	bool getstatus();
	Vector2f gethalfsize();
	Vector2f getposition();

private:
	Texture object;
	Sprite body;
	bool visible=false;

};

