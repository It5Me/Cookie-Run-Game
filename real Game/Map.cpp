#include "Map.h"

MAP::MAP()
{
	this->map1Texture.loadFromFile("Texture\\map1\\firemap.jpg");
	this->floor1Texture.loadFromFile("Texture\\map1\\firefloor.png");
	this->floor1.setTexture(floor1Texture);
	this->map1.setTexture(map1Texture);

}

void MAP::DRAW(RenderWindow* window)
{
	MOVE();
	window->draw(map1);
	window->draw(floor1);

}

void MAP::MOVE()
{
	this->floor1.move(-0.5f, 0.0f);
	this->map1.move(-0.1f, 0.0f);
}

