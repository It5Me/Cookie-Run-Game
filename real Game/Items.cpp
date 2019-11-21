#include "Items.h"

Items::Items(Texture texture, int score,int countx, Vector2f pos, int type)
{
	this->type = type;
	this->Texturebody = texture;
	this->score = score;
	this->countx = countx;
	this->body.setPosition(pos);
	this->body.setTexture(Texturebody);
	this->rec.top = 0;
	this->rec.left = 0;
	this->rec.width = this->Texturebody.getSize().x / countx;
	this->rec.height = this->Texturebody.getSize().y;
	this->body.setOrigin(this->rec.width/2, this->rec.height/2);
}

void Items::DRAW(RenderWindow* window)
{
	this->body.move(-8.0f, 0.0f);
	update();
	window->draw(body);
}

void Items::hide()
{
	this->body.setPosition(-200.0f, -200.0f);
}

int Items::gettype()
{
	return this->type;
}

int Items::getscore()
{
	return this->score;
}

Vector2f Items::getposition()
{
	return body.getPosition();
}

void Items::update()
{
	totaltime += clock.restart().asSeconds();
	if (totaltime >= 0.3) {
		x++;
		totaltime = 0;
		if (x >= countx) {
			x = 0;

		}
	}
	rec.left = x * rec.width;
	this->body.setTextureRect(rec);
}
