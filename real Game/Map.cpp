#include "Map.h"

MAP::MAP(int* P)
{ 
	this->indexMap = P;
	this->texture_mapfire.loadFromFile("Texture/map1/mapfire.jpg");
	this->texture_mapice.loadFromFile("Texture/map1/mapice.jpg");
	this->texture_mapforest.loadFromFile("Texture/map1/mapforest.jpg");
	this->texture_floorfire.loadFromFile("Texture/map1/floorfire.png");
	this->texture_floorice.loadFromFile("Texture/map1/floorice.png");
	this->texture_floorforest.loadFromFile("Texture/map1/floorforest.png");
	this->spri_mapfire.setTexture(this->texture_mapfire);
	this->spri_mapice.setTexture(this->texture_mapice);
	this->spri_mapforest.setTexture(this->texture_mapforest);
	this->spri_floorfire.setTexture(this->texture_floorfire);
	this->spri_floorice.setTexture(this->texture_floorice);
	this->spri_floorforest.setTexture(this->texture_floorforest);
	setpositionmapall();

	this->hole.setSize(Vector2f(400, 200));
	this->hole.setPosition(1200, 700);
	//this->floor1Texture.setRepeated(true);
	//this->floor1.setTextureRect(IntRect(0, 0, 20000, 900));
}

void MAP::DRAW(RenderWindow* window)
{
	//cout << *this->y << endl;
	checkHole();
	//cout << floor1.getPosition().x << endl;
	MOVE();
	switch (*this->indexMap)
	{
	case 0:
		//cout << int(fabs(this->spri_floorforest.getPosition().x)) << endl;
		if (this->spri_floorforest.getPosition().x > 0) {
			window->draw(spri_mapice);
			window->draw(spri_mapforest);
			window->draw(spri_floorice);
			window->draw(spri_floorforest);
			//cout << " ddfgkg" << endl;
		}
		else
		{
			if (int(fabs(this->spri_floorforest.getPosition().x)) + 1600 == 12200)
			{
				cout << "LOADMAP1" << endl;
				*this->indexMap = 1;
				this->spri_mapfire.setPosition(0, 0);
				this->spri_floorfire.setPosition(1600, 0);
			}
			window->draw(spri_mapforest);
			window->draw(spri_floorforest);
		}	
		break;
	case 1:
		if (this->spri_floorfire.getPosition().x > 0) {
			window->draw(spri_mapforest);
			window->draw(spri_mapfire);
			window->draw(spri_floorforest);
			window->draw(spri_floorfire);
			//cout << "sal" << endl;
		}
		else {
			if (int(fabs(this->spri_floorfire.getPosition().x)) + 1600 == 12200)
			{
				cout << "LOADMAP2" << endl;
				*this->indexMap = 2;
				this->spri_mapice.setPosition(0, 0);
				this->spri_floorice.setPosition(1600, 0);
			}
			window->draw(spri_mapfire);
			window->draw(spri_floorfire);
		}
		break;
	case 2:
		
		if (this->spri_floorice.getPosition().x > 0) {
			window->draw(spri_mapice);
			window->draw(spri_mapfire);
			window->draw(spri_floorice);
			window->draw(spri_floorfire);
		}
		else {
			if (int(fabs(this->spri_floorice.getPosition().x)) + 1600 == 12200)
			{
				cout << "LOADMAP" << endl;
				*this->indexMap = 0;
				this->spri_mapforest.setPosition(0, 0);
				this->spri_floorforest.setPosition(1600, 0);
			}
			window->draw(spri_mapice);
			window->draw(spri_floorice);
		}
		
		break;
	}
	
	window->draw(this->hole);

}

bool MAP::checkSpwan()
{
	switch (*this->indexMap)
	{
	case 0:
		return (int(this->spri_floorforest.getPosition().x) % 200) == 0;
		break;
	case 1:
		return (int(this->spri_floorfire.getPosition().x) % 200) == 0;
		break;
	case 2:
		return (int(this->spri_floorice.getPosition().x) % 200) == 0;
		break;
	}
	return 0;
}

bool MAP::checkHole()
{
	//cout << fabs(this->spri_floorforest.getPosition().x) << endl;
	//return fabs(this->spri_floorforest.getPosition().x)+300>1200&& fabs(this->spri_floorforest.getPosition().x)+300<1600;
	if (fabs(this->spri_floorforest.getPosition().x) + 300 > 1200 && fabs(this->spri_floorforest.getPosition().x) + 300 < 1600 &&
		*this->y==490
		)
	{
		cout << "DIE" << endl;
		this->die = true;
		return 1;
	}
	else
	{
		return 0;
	}
}

void MAP::sendposplayer(float* Y)
{
	this->y = Y;
	//cout << "Map Address Y par:" << Y << endl;
	//cout << "Map Address Y in class:" << this->y << endl;
	
}

bool MAP::checkdie()
{
	return this->die;
}

void MAP::setpositionmapall()
{
	this->spri_mapforest.setPosition(0, 0);
	this->spri_floorforest.setPosition(0, 0);
	this->spri_mapfire.setPosition(0, 0);
	this->spri_floorfire.setPosition(1600, 0);
	this->spri_mapice.setPosition(-5000, 0);
	this->spri_floorice.setPosition(-13000, 0);
}


void MAP::MOVE()
{
	//cout << " " << map1.getPosition().x << endl;
	switch (*this->indexMap)
	{
	case 0:
		if (this->spri_mapice.getPosition().x + this->texture_mapice.getSize().x > 0) {
			this->spri_floorice.move(-8.0f, 0.0f);
			this->spri_mapice.move(-0.6f, 0.0f);
		}
		this->hole.move(-8.0f, 0.0f);
		this->spri_floorforest.move(-8.0f, 0.0f);
		this->spri_mapforest.move(-0.6f, 0.0f);
		break;
	case 1:
		if (this->spri_mapforest.getPosition().x + this->texture_mapforest.getSize().x > 0) {
			this->spri_floorforest.move(-8.0f, 0.0f);
			this->spri_mapforest.move(-0.6f, 0.0f);
		}
		this->spri_floorfire.move(-8.0f, 0.0f);
		this->spri_mapfire.move(-0.6f, 0.0f);
		break;
	case 2:
		if (this->spri_mapfire.getPosition().x + this->texture_mapfire.getSize().x > 0) {
			this->spri_floorfire.move(-8.0f, 0.0f);
			this->spri_mapfire.move(-0.6f, 0.0f);
		}
		this->spri_floorice.move(-8.0f, 0.0f);
		this->spri_mapice.move(-0.6f, 0.0f);
		break;
	}
}

