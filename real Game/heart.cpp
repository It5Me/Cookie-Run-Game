#include "heart.h"

heart::heart()
{
	object.loadFromFile("Texture/item/heart.png");
	body.setTexture(this->object);
	this->body.setOrigin(this->object.getSize().x / 2, this->object.getSize().y / 2);
}

void heart::draw(RenderWindow* window)
{
	
	if (this->body.getPosition().x < -200) {
		this->visible = false;
	}
	if (this->visible == true) {
		window->draw(this->body);
		
	}
}

void heart::setposition(Vector2f pos)
{
	if (pos.x < -200) {
		this->visible = false;
	}
	else {
		this->body.setPosition(pos);
		this->visible = true;
	}
}

bool heart::getstatus()
{
	return this->visible;
}

Vector2f heart::gethalfsize()
{
	return Vector2f(this->object.getSize().x / 2, this->object.getSize().y / 2);
}

Vector2f heart::getposition()
{
	return this->body.getPosition();
}

void heart::move()
{
	this->body.move(-8.0f, 0.0f);
}
