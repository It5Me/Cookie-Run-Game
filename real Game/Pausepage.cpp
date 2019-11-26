#include "Pausepage.h"

Pausepage::Pausepage()
{
	this->texture_back.loadFromFile("Texture\\menu\\btnback.png");
	this->texture_forward.loadFromFile("Texture\\menu\\btnforward.png");
	this->texture_pausegame.loadFromFile("Texture\\menu\\bgpausegame.png");
	this->spri_pausegame.setTexture(this->texture_pausegame);
	this->spri_forward.setTexture(this->texture_forward);
	this->spri_back.setTexture(this->texture_back);
	this->spri_back.setPosition(670, 400);
	this->spri_forward.setPosition(820, 400);
	this->spri_pausegame.setPosition(550, 200);
}

void Pausepage::draw(RenderWindow* window)
{
	if (Mouse::getPosition(*window).x >= 670 && Mouse::getPosition(*window).x <= 670 + this->texture_forward.getSize().x
		&& Mouse::getPosition(*window).y >= 400 && Mouse::getPosition(*window).y <= 400 + this->texture_forward.getSize().y) {
		if (Mouse::isButtonPressed(Mouse::Left)&& *this->pausestate==true) {
			*this->pausestate = false;
			this->sound->playclick();
		}
	}
	if (Mouse::getPosition(*window).x >= 820 && Mouse::getPosition(*window).x <= 820 + this->texture_forward.getSize().x
		&& Mouse::getPosition(*window).y >= 400 && Mouse::getPosition(*window).y <= 400 + this->texture_forward.getSize().y) {
		if (Mouse::isButtonPressed(Mouse::Left) && this->clickforward == false) {
			this->sound->playclick();
			this->clickforward = true;
			//cout<<
		}
	}
	window->draw(this->spri_pausegame);
	window->draw(this->spri_back);
	window->draw(this->spri_forward);
}

void Pausepage::setpointer(bool* state)
{
	this->pausestate = state;
}

bool Pausepage::checkclickforward()
{
	return this->clickforward;
}

void Pausepage::reset()
{
	this->clickforward = false;
}

