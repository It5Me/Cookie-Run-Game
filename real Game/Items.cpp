#include "Items.h"

Items::Items(Texture texture, int score,int countx, Vector2f pos)
{
	this->Texturebody = texture;
	this->score = score;
	this->countx = countx;
	this->body.setPosition(pos);
	this->body.setTexture(Texturebody);
	this->rec.top = 0;
	this->rec.left = 0;
	this->rec.width = this->Texturebody.getSize().x / countx;
	this->rec.height = this->Texturebody.getSize().y;
}

void Items::DRAW(RenderWindow* window)
{
	this->body.move(-3.0f, 0.0f);
	update();
	window->draw(body);
}

void Items::update()
{
	totaltime += clock.restart().asSeconds();
	if (totaltime >= 0.1) {
		x++;
		totaltime = 0;
		if (x > countx) {
			x = 0;

		}
	}
	rec.left = x * rec.width;
	this->body.setTextureRect(rec);
}
