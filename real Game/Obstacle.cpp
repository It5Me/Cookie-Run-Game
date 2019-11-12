
#include "Obstacle.h"


Obstacle::Obstacle(Texture texture, float x, int type)
{
	this->texturebody = texture;
	this->type = type;

	this->spribody.setTexture(this->texturebody);
	switch (this->type)
	{
	case 1:this->spribody.setOrigin(this->texturebody.getSize().x / 2, 0); // 
		this->spribody.setPosition(x, 0);
		break;
	case 2:this->spribody.setOrigin(this->texturebody.getSize().x / 2, 0);
		this->spribody.setPosition(x, 0);
		break;
	case 3:this->spribody.setOrigin(this->texturebody.getSize().x / 2, this->texturebody.getSize().y);
		this->spribody.setPosition(x, 1100);
		break;
	case 4:this->spribody.setOrigin(this->texturebody.getSize().x / 2, this->texturebody.getSize().y);
		this->spribody.setPosition(x, 740);
		break;

	}
}

Obstacle::~Obstacle()
{
	cout << "delete obstacle complete" << endl;
}

void Obstacle::draw(RenderWindow* window)
{
	//this->move();
	window->draw(this->spribody);
}

bool Obstacle::isDelete()
{
	return this->spribody.getPosition().x < -200;
}

void Obstacle::move()
{
	switch (this->type)
	{
	case 2: case 4:this->spribody.move(-8, 0);
		break;

	case 1:
		if (this->spribody.getPosition().x < 1400) {           // พุ่งลง
			if (this->spribody.getPosition().y < 200) {
				this->spribody.move(-8, 150);
				//cout << "b" << endl;
			}
			else {
				this->spribody.move(-8, 0);
				//cout << "c" << endl;
			}
		}
		else
		{
			this->spribody.move(-8, 0);
			//cout << "a" << endl;
		}
		break;


	case 3:
		if (this->spribody.getPosition().x < 1400) {
			if (this->spribody.getPosition().y >= 740) {
				this->spribody.move(-8, -20);
			}
			else {
				this->spribody.move(-8, 0);
			}
		}
		else {
			this->spribody.move(-8, 0);
		}
		break;
	}
}

Vector2f Obstacle::getposition()
{
	switch (this->type)
	{
	case 1:
		return Vector2f(spribody.getPosition().x, spribody.getPosition().y + gethalfsize().y);
		break;
	case 2:
		return Vector2f(spribody.getPosition().x, spribody.getPosition().y + gethalfsize().y);
		break;
	case 3:
		return Vector2f(spribody.getPosition().x, spribody.getPosition().y - gethalfsize().y);
		break;
	case 4:
		return Vector2f(spribody.getPosition().x, spribody.getPosition().y - gethalfsize().y);
		break;

	}
	
}

Vector2f Obstacle::gethalfsize()
{
	return Vector2f(this->texturebody.getSize().x / 2, this->texturebody.getSize().y / 2);
}


/*
if (this->spribody.getPosition().x < 800) {
			if (this->spribody.getPosition().y < 400) {
				this->spribody.move(-8, 50);
				//cout << "d" << endl;
			}
			else {
				this->spribody.move(-8, 0);
				//cout << "e" << endl;
			}
		}
		else if (this->spribody.getPosition().x < 1200) {
			if (this->spribody.getPosition().y < 200) {
				this->spribody.move(-8, 50);
				//cout << "b" << endl;
			}
			else {
				this->spribody.move(-8, 0);
				//cout << "c" << endl;
			}
		}
		else
		{
			this->spribody.move(-8, 0);
			cout << "a" << endl;
		}*/