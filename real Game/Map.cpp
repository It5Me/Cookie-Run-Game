#include "Map.h"

MAP::MAP()
{
	//this->map1Texture.loadFromFile("Texture\\map1\\firemap.jpg");
	//this->floor1Texture.loadFromFile("Texture\\map1\\firefloor.png");
	this->map1Texture.loadFromFile("Texture\\map1\\mappppppppppppp-01.jpg");
	this->floor1Texture.loadFromFile("Texture\\map1\\flooriceee-01.png");
	this->floor1.setTexture(floor1Texture);
	this->map1.setTexture(map1Texture);
	this->floor1Texture.setRepeated(true);
	this->floor1.setTextureRect(IntRect(0, 0, 20000, 900));
}

void MAP::DRAW(RenderWindow* window)
{
	//cout << floor1.getPosition().x << endl;
	MOVE();
	window->draw(map1);
	window->draw(floor1);

}

bool MAP::checkSpwan()
{
	return (int(this->floor1.getPosition().x)%200)==0;
}


void MAP::MOVE()
{
	this->floor1.move(-5.0f, 0.0f);
	this->map1.move(-0.8f, 0.0f);
}

