#include "Map.h"

#include"positionhole.h"

MAP::MAP(int* P)
{ 
	this->indexMap = P;
	this->texture_mapfire.loadFromFile("Texture/map1/mapfire.jpg");
	this->texture_mapice.loadFromFile("Texture/map1/mapice.jpg");
	this->texture_mapforest.loadFromFile("Texture/map1/mapforest4.jpg");
	this->texture_mapdesert.loadFromFile("Texture/map1/mapdesert.jpg");
	this->texture_floorfire.loadFromFile("Texture/map1/floorfire.png");
	this->texture_floorice.loadFromFile("Texture/map1/floorice.png");
	this->texture_floorforest.loadFromFile("Texture/map1/floorforest.png");
	this->texture_floordesert.loadFromFile("Texture/map1/floordesert.png");	
	this->spri_mapfire.setTexture(this->texture_mapfire);
	this->spri_mapice.setTexture(this->texture_mapice);
	this->spri_mapforest.setTexture(this->texture_mapforest);
	this->spri_floorfire.setTexture(this->texture_floorfire);
	this->spri_floorice.setTexture(this->texture_floorice);
	this->spri_floorforest.setTexture(this->texture_floorforest);
	this->spri_mapdesert.setTexture(this->texture_mapdesert);
	this->spri_floordesert.setTexture(this->texture_floordesert);
	

	this->objecttexture[0].loadFromFile("Texture/map1/A.png"); //1
	this->objecttexture[1].loadFromFile("Texture/map1/B.png"); //2
	this->objecttexture[2].loadFromFile("Texture/map1/1.png"); //3
	this->objecttexture[3].loadFromFile("Texture/map1/2.png"); //4
	this->objecttexture[4].loadFromFile("Texture/map1/3.png");
	this->objecttexture[5].loadFromFile("Texture/map1/4.png");
	this->objecttexture[6].loadFromFile("Texture/map1/5.png");
	this->objecttexture[7].loadFromFile("Texture/map1/6.png");
	this->objecttexture[8].loadFromFile("Texture/map1/7.png");
	this->objecttexture[9].loadFromFile("Texture/map1/8.png");
	this->objecttexture[10].loadFromFile("Texture/map1/9.png");
	this->objecttexture[11].loadFromFile("Texture/map1/10.png");
	this->objecttexture[12].loadFromFile("Texture/map1/11.png");
	this->objecttexture[13].loadFromFile("Texture/map1/12.png");
	this->objecttexture[14].loadFromFile("Texture/map1/13.png");
	this->objecttexture[15].loadFromFile("Texture/map1/14.png");
	this->objecttexture[16].loadFromFile("Texture/map1/15.png");
	this->objecttexture[17].loadFromFile("Texture/map1/16.png");
	this->objecttexture[18].loadFromFile("Texture/map1/17.png");
	this->objecttexture[19].loadFromFile("Texture/map1/18.png");
	this->objecttexture[20].loadFromFile("Texture/map1/19.png");
	setpositionmapall();
	

	this->hole.setSize(Vector2f(400, 200));
	this->hole.setPosition(1200, 700);
	/*
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0) {
				this->Hole[i][j].setPosition(positionstart[i][j], 700);
			}
			if (i == 1) {
				this->Hole[i][j].setPosition(positionstart[i][j]+12300, 700);
			}
			if (i == 2) {
				this->Hole[i][j].setPosition(positionstart[i][j]+12300*2, 700);
			}
			this->Hole[i][j].setSize(Vector2f(lengthhole[i][j], 200));
			//cout << " HOLELELELELE" << " " << positionstart[i][j] << " " << lengthhole[i][j] << endl;
		}
	}*/
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
				this->indexhole = 0;
				cout << "LOADMAP1" << endl;
				*this->indexMap = 1;
				this->indexmap = *this->indexMap;
				this->spri_mapfire.setPosition(0, 0);
				this->spri_floorfire.setPosition(1600, 0);
				for (int i = 0; i < this->obstacleList.size(); i++) {
					Obstacle* P = this->obstacleList[i];
					delete P;
					//this->obstacleList.erase(this->obstacleList.begin() + i);
				}
				this->obstacleList.clear();
				for (int i = 0; i < 10; i++) {
					cout << "SET" << endl;
					obstacleList.push_back(new Obstacle(objecttexture[indexobmap2[i] - 1], positionobmap2[i], typeobmap2[i]));
				}
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
				this->indexhole = 0;
				cout << "LOADMAP2" << endl;
				*this->indexMap = 2;
				this->indexmap = *this->indexMap;
				this->spri_mapice.setPosition(0, 0);
				this->spri_floorice.setPosition(1600, 0);
				for (int i = 0; i < this->obstacleList.size(); i++) {
					Obstacle* P = this->obstacleList[i];
					delete P;
					//this->obstacleList.erase(this->obstacleList.begin() + i);
				}
				this->obstacleList.clear();
				for (int i = 0; i < 10; i++) {
					cout << "SET" << endl;
					obstacleList.push_back(new Obstacle(objecttexture[indexobmap3[i] - 1], positionobmap3[i], typeobmap3[i]));
				}
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
				this->indexhole = 0;
				cout << "LOADMAP" << endl;
				*this->indexMap = 3;
				this->indexmap = *this->indexMap;
				this->spri_mapdesert.setPosition(0, 0);
				this->spri_floordesert.setPosition(1600, 0); // setnewmap///////
				for (int i = 0; i < this->obstacleList.size(); i++) {
					Obstacle* P = this->obstacleList[i];
					delete P;
					//this->obstacleList.erase(this->obstacleList.begin() + i);
				}
				this->obstacleList.clear();
				for (int i = 0; i < 10; i++) {
					cout << "SET" << endl;
					obstacleList.push_back(new Obstacle(objecttexture[indexobmap3[i] - 1], positionobmap3[i], typeobmap3[i]));
				}
			}
			window->draw(spri_mapice);
			window->draw(spri_floorice);
		}
		
		break;
	case 3:
		if (this->spri_floordesert.getPosition().x > 0) {
			
			window->draw(spri_mapice);
			window->draw(spri_mapdesert);
			window->draw(spri_floordesert);
			window->draw(spri_floorice);
		}
		else {
			if (int(fabs(this->spri_floordesert.getPosition().x)) + 1600 == 12200)
			{
				this->indexhole = 0;
				cout << "LOADMAP" << endl;
				*this->indexMap = 0;
				this->indexmap = *this->indexMap;
				this->spri_mapforest.setPosition(0, 0);
				this->spri_floorforest.setPosition(1600, 0);
				for (int i = 0; i < this->obstacleList.size(); i++) {
					Obstacle* P = this->obstacleList[i];
					delete P;
					//this->obstacleList.erase(this->obstacleList.begin() + i);
				}
				this->obstacleList.clear();
				for (int i = 0; i < 10; i++) {
					cout << "SET" << endl;
					obstacleList.push_back(new Obstacle(objecttexture[indexobmap1[i] - 1], positionobmap1[i], typeobmap1[i]));
				}
			}
			window->draw(spri_mapdesert);
			window->draw(spri_floordesert);
		}
		break;
		
	}
	for (int i = 0; i < obstacleList.size(); i++) {
		this->obstacleList[i]->draw(window);
		if ( *this->statusplayer==1 &&abs(321 - this->obstacleList[i]->getposition().x) < this->obstacleList[i]->gethalfsize().x*0.8 + 121 * 0.8 &&
			abs(*y+121 - this->obstacleList[i]->getposition().y) < this->obstacleList[i]->gethalfsize().y * 0.8 + 121 * 0.8) {
			//cout << "CHECKKKK" << endl;
			*this->hpplayer -= 5;
			*this->statusplayer = 2;
		}
		if (this->die == false) {
			this->obstacleList[i]->move();
		}
		/*if (this->obstacleList[i]->isDelete()) {
			Obstacle* P;
			P = this->obstacleList[i];
			delete P;
			this->obstacleList.erase(this->obstacleList.begin() + i);
			break;
		}*/
		//cout << "DRAW" << endl;
	}
	if (this->die == false)
	{
		/*for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->Hole[i][j].move(-8, 0);     ////////////////////////////////hole///////////////
				//window->draw(this->Hole[i][j]);
			}
		}*/
	}

	//window->draw(this->hole);

}

bool MAP::checkSpwan()
{
	if (this->die == false)
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
	case 3:
		return (int(this->spri_floordesert.getPosition().x) % 200) == 0;
		break;
	}
	return 0;
}

bool MAP::checkHole()
{
	//cout << fabs(this->spri_floorforest.getPosition().x) << endl;
	//return fabs(this->spri_floorforest.getPosition().x)+300>1200&& fabs(this->spri_floorforest.getPosition().x)+300<1600;
//cout << "indexmap" << this->indexmap << "  HOLE" << this->indexhole << endl;  
	if (this->die == false)
	switch (*this->indexMap)
	{
	case 0:
		if (fabs(this->spri_floorforest.getPosition().x) + 300 > positionstart[this->indexmap][this->indexhole]+70
			&& fabs(this->spri_floorforest.getPosition().x) + 300 < positionstart[this->indexmap][this->indexhole] + lengthhole[this->indexmap][this->indexhole]-50
			//&& *this->y == 490
			)
		{ 
			this->b_onhole = true;
			//cout << "DIE" << endl;
			//this->die = true;
			return 1;
		}
		else {
			this->b_onhole = false;
		}
		if (this->indexmap==0&&fabs(this->spri_floorforest.getPosition().x) + 300 > positionstart[this->indexmap][this->indexhole] + lengthhole[this->indexmap][this->indexhole]) {
			cout << this->indexhole << " <-- UP index1" << endl;
			this->indexhole++;
			
		}
			break;
	case 1:
		//cout << this->indexhole << endl;
		if (fabs(this->spri_floorfire.getPosition().x) + 300 > positionstart[this->indexmap][this->indexhole]+60
			&& fabs(this->spri_floorfire.getPosition().x) + 300 < positionstart[this->indexmap][this->indexhole] + lengthhole[this->indexmap][this->indexhole]-50
			//&& *this->y == 490
			)
		{
			//cout << "DIE" << endl;
			//this->die = true;
			this->b_onhole = true;
			return 1;
		}
		else {
			this->b_onhole = false;
		}
		//cout << fabs(this->spri_floorfire.getPosition().x + 300) << endl;
		if (this->indexmap == 1 &&fabs(this->spri_floorfire.getPosition().x) + 300 > positionstart[this->indexmap][this->indexhole] + lengthhole[this->indexmap][this->indexhole]) {
			cout << this->indexhole << " <-- UP index2 :: " << this->indexmap << " <--indexMap" << endl;
			this->indexhole++;
			
		}
		break;
	case 2:
		if (fabs(this->spri_floorice.getPosition().x) + 300 > positionstart[this->indexmap][this->indexhole]+50
			&& fabs(this->spri_floorice.getPosition().x) + 300 < positionstart[this->indexmap][this->indexhole] + lengthhole[this->indexmap][this->indexhole]-50
			//&& *this->y == 490
			)
		{
			this->b_onhole = true;
			//cout << "DIE" << endl;
			//this->die = true;
			return 1;
		}
		else {
			this->b_onhole = false;
		}
		if (this->indexmap == 2 && fabs(this->spri_floorice.getPosition().x) + 300 > positionstart[this->indexmap][this->indexhole] + lengthhole[this->indexmap][this->indexhole]) {
			
			cout << this->indexhole << " <-- UP index3" << endl;
			this->indexhole++;
		}
		break;
	case 3:
		if (fabs(this->spri_floordesert.getPosition().x) + 300 > positionstart[this->indexmap][this->indexhole] + 50
			&& fabs(this->spri_floordesert.getPosition().x) + 300 < positionstart[this->indexmap][this->indexhole] + lengthhole[this->indexmap][this->indexhole] - 50
			//&& *this->y == 490
			)
		{
			this->b_onhole = true;
			//cout << "DIE" << endl;
			//this->die = true;
			return 1;
		}
		else {
			this->b_onhole = false;
		}
		if (this->indexmap == 3 && fabs(this->spri_floordesert.getPosition().x) + 300 > positionstart[this->indexmap][this->indexhole] + lengthhole[this->indexmap][this->indexhole]) {

			cout << this->indexhole << " <-- UP index3" << endl;
			this->indexhole++;
		}
		break;
	}

	return 0;

}

void MAP::sendposplayer(float* Y)
{
	this->y = Y;
	//cout << "Map Address Y par:" << Y << endl;
	//cout << "Map Address Y in class:" << this->y << endl;
	
}

 

void MAP::reset()///////////////////////////////////////////////////
{
	for (int i = 0; i < this->obstacleList.size(); i++) {
		Obstacle* P = this->obstacleList[i];
		delete P;
		//this->obstacleList.erase(this->obstacleList.begin() + i);
	}
	this->obstacleList.clear();
	this->die = false;
	setpositionmapall();
	*this->indexMap = 0;
	this->indexhole = 0;
	this->indexmap = 0;
	//เดี๋ยวมาลบนา้จ้า้าาาาาาา
	//this->hole.setSize(Vector2f(400, 200));
	//this->hole.setPosition(1200, 700);
	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0) {
				this->Hole[i][j].setPosition(positionstart[i][j], 700);
			}
			if (i == 1) {
				this->Hole[i][j].setPosition(positionstart[i][j] + 12300, 700);
			}
			if (i == 2) {
				this->Hole[i][j].setPosition(positionstart[i][j] + 12300 * 2, 700);
			}
			if (i == 3) {
				this->Hole[i][j].setPosition(positionstart[i][j] + 12300 * 3, 700);
			}

			this->Hole[i][j].setSize(Vector2f(lengthhole[i][j], 200));
			//cout << " HOLELELELELE" << " " << positionstart[i][j] << " " << lengthhole[i][j] << endl;
		}
	}*/
}

bool MAP::checkonhole()
{
	return this->b_onhole;
}

void MAP::setdie(bool state)
{
	this->die = state;
}

void MAP::setpointerhp(float* hp)
{
	this->hpplayer = hp;
}

void MAP::setpointerstatusplayer(int* status)
{
	this->statusplayer = status;
}


void MAP::setpositionmapall()
{
	for (int i = 0; i < 10; i++) {  ////
		//cout << "SET" << endl;
		obstacleList.push_back(new Obstacle(objecttexture[indexobmap1[i] - 1], positionobmap1[i], typeobmap1[i]));
		//cout << indexobmap1[i] - 1 << " " << positionobmap1[i] << " " << typeobmap1[i] << endl;
	}
	this->spri_mapforest.setPosition(0, 0);
	this->spri_floorforest.setPosition(0, 0);
	this->spri_mapfire.setPosition(0, 0);
	this->spri_floorfire.setPosition(1600, 0);
	this->spri_mapice.setPosition(0, 0);
	this->spri_floorice.setPosition(1600, 0);
	this->spri_mapdesert.setPosition(-5000, 0);
	this->spri_floordesert.setPosition(-13000, 0);

}


void MAP::MOVE()
{
	//cout << " " << map1.getPosition().x << endl;
	if (this->die == false)
	switch (*this->indexMap)
	{
	case 0:
		this->indexmap = 0;
		if (this->spri_mapice.getPosition().x + this->texture_mapice.getSize().x > 0) {
			this->spri_floorice.move(-8.0f, 0.0f);
			this->spri_mapice.move(-0.6f, 0.0f);
		}
		this->hole.move(-8.0f, 0.0f);
		this->spri_floorforest.move(-8.0f, 0.0f);
		this->spri_mapforest.move(-0.6f, 0.0f);
		break;
	case 1:
		this->indexmap = 1;
		if (this->spri_mapforest.getPosition().x + this->texture_mapforest.getSize().x > 0) {
			this->spri_floorforest.move(-8.0f, 0.0f);
			this->spri_mapforest.move(-0.6f, 0.0f);
		}
		this->spri_floorfire.move(-8.0f, 0.0f);
		this->spri_mapfire.move(-0.6f, 0.0f);
		break;
	case 2:
		this->indexmap = 2;
		if (this->spri_mapfire.getPosition().x + this->texture_mapfire.getSize().x > 0) {
			this->spri_floorfire.move(-8.0f, 0.0f);
			this->spri_mapfire.move(-0.6f, 0.0f);
		}
		this->spri_floorice.move(-8.0f, 0.0f);
		this->spri_mapice.move(-0.6f, 0.0f);
		break;
	case 3:
		this->indexmap = 3;
		if (this->spri_mapice.getPosition().x + this->texture_mapice.getSize().x > 0) {
			this->spri_floorice.move(-8.0f, 0.0f);
			this->spri_mapice.move(-0.6f, 0.0f);
		}
		this->spri_floordesert.move(-8.0f, 0.0f);
		this->spri_mapdesert.move(-0.6f, 0.0f);
		break;
	}
}

