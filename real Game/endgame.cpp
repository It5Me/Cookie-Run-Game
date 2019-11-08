#include "endgame.h"

endgame::endgame()
{
	this->textureendgame.loadFromFile("Texture/menu/bgendgame.png");
	this->bgendgame.setTexture(this->textureendgame);
	this->bgendgame.setPosition(550, 200);
	this->texturebtn.loadFromFile("Texture/menu/btnendgame.png");
	this->btn.setTexture(this->texturebtn);
	this->btn.setPosition(650, 600);
}

void endgame::draw(RenderWindow* window)
{
	checkbtn(window);
	window->draw(this->bgendgame);
	window->draw(this->btn);
}

void endgame::setstatus(bool state)
{
	if (state == false) {
		this->statemenu=false;
	}
	this->status = state;
}

bool endgame::getstatus()
{
	return this->status;
}

bool endgame::ismenustart()
{
	return this->statemenu;
}

void endgame::checkbtn(RenderWindow* window)
{
	if (Mouse::getPosition(*window).x > 650 &&
		Mouse::getPosition(*window).x < 950 &&
		Mouse::getPosition(*window).y>600 &&
		Mouse::getPosition(*window).y < 680) {
		//cout << "dlld" << endl;
		this->hold = true;
		if (Mouse::isButtonPressed(Mouse::Left)&& this->statemenu==false) {
			this->statemenu = true;
			cout << "Click" << endl;
		}
	}
	else {
		this->hold = false;
	}
}
