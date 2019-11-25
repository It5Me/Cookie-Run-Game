#include "Map.h"
#include"Positionitem.h"
#include"positionhole.h"


MAP::MAP(int* P, bool* poniter)
{ 

	this->bool_im = poniter;
	//immmmmmmm
	this->immortal[0].loadFromFile("Texture\\item\\font_I.png");
	this->immortal[1].loadFromFile("Texture\\item\\font_M.png");
	this->immortal[2].loadFromFile("Texture\\item\\font_M.png");
	this->immortal[3].loadFromFile("Texture\\item\\font_O.png");
	this->immortal[4].loadFromFile("Texture\\item\\font_R.png");
	this->immortal[5].loadFromFile("Texture\\item\\font_T.png");
	this->immortal[6].loadFromFile("Texture\\item\\font_A.png");
	this->immortal[7].loadFromFile("Texture\\item\\font_L.png");


	//////immm
	///////////////////////////////////////////////////////////////////////////////
	this->texture_box.loadFromFile("Texture/map1/box.png");
	this->spri_box.setTexture(this->texture_box);
	this->texture_j.loadFromFile("Texture/map1/j.png");
	this->spri_j.setTexture(this->texture_j);
	this->texture_k.loadFromFile("Texture/map1/k.png");
	this->spri_k.setTexture(this->texture_k);
	this->texture_l.loadFromFile("Texture/map1/l.png");
	this->spri_l.setTexture(this->texture_l);
	this->spri_box.setPosition(1250, 790);
	this->spri_j.setPosition(1270, 795);
	this->spri_k.setPosition(1350, 795);
	this->spri_l.setPosition(1430, 795);
	this->font.loadFromFile("font\\SOV_monomon-hinted.ttf");
	this->textJKL.setFont(this->font);
	this->textJKL.setCharacterSize(55);
	this->textJKL.setFillColor(Color::Red);
	

	//////////////////////////////////////////////////////////////////////////////
	this->indexMap = P;
	this->texture_mapfire.loadFromFile("Texture/map1/mapfire.jpg");
	this->texture_mapice.loadFromFile("Texture/map1/mapice.jpg");
	this->texture_mapforest.loadFromFile("Texture/map1/mapforest4.jpg");
	this->texture_mapdesert.loadFromFile("Texture/map1/mapdesert.jpg");
	this->texture_floorfire.loadFromFile("Texture/map1/floorfire.png");
	this->texture_floorice.loadFromFile("Texture/map1/floorice.png");
	this->texture_floorforest.loadFromFile("Texture/map1/floorforest.png");
	this->texture_floordesert.loadFromFile("Texture/map1/floordesert.png");	
	this->bear[0].loadFromFile("Texture/bear/bearblue.png");
	this->bear[1].loadFromFile("Texture/bear/bearbrown.png");
	this->bear[2].loadFromFile("Texture/bear/bearpink.png");
	this->bear[3].loadFromFile("Texture/bear/bearyellow.png");
	this->bear[4].loadFromFile("Texture/bear/bearblue2.png");
	this->bear[5].loadFromFile("Texture/bear/bearbrown2.png");
	this->bear[6].loadFromFile("Texture/bear/bearpink2.png");
	this->bear[7].loadFromFile("Texture/bear/bearyellow2.png");
	this->bear[8].loadFromFile("Texture/bear/bearextra.png");

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

	if ((*this->hpplayer) <= 0) {
		*this->statusplayer = 0;   //isus
	}

	checkcolisionheart();
	//cout << *this->y << endl;
	checkHole();
	
	//cout << floor1.getPosition().x << endl;
	MOVE();
	switch (*this->indexMap)
	{
	case 0:
		//cout << int(fabs(this->spri_floorforest.getPosition().x)) << endl;
		if (this->spri_floorforest.getPosition().x > 0) {      
			window->draw(spri_mapdesert);
			window->draw(spri_mapforest);
			window->draw(spri_floordesert);
			window->draw(spri_floorforest);
			//cout << " ddfgkg" << endl;
		}
		else
		{
			if (int(fabs(this->spri_floorforest.getPosition().x)) + 1600 == 12200 - 800) {
				Heart.setposition(Vector2f(1900, 500));
			}
			if (int(fabs(this->spri_floorforest.getPosition().x)) + 1600 == 12200)
			{
				this->addBear(1); //bearnextmap
				//cout << "LOADHEART" << endl;
				this->indexhole = 0;
			//	cout << "LOADMAP1" << endl;
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
					// cout << "SET" << endl;
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
			if (int(fabs(this->spri_floorfire.getPosition().x)) + 1600 == 12200 - 800) {
				Heart.setposition(Vector2f(1900, 500));
			}
			if (int(fabs(this->spri_floorfire.getPosition().x)) + 1600 == 12200)
			{
				this->addBear(2); // <-------- load bear
				this->indexhole = 0;
				//cout << "LOADMAP2" << endl;
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
				//	cout << "SET" << endl;
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
			if (int(fabs(this->spri_floorice.getPosition().x)) + 1600 == 12200 - 800) {
				Heart.setposition(Vector2f(1900, 500));
			}
			if (int(fabs(this->spri_floorice.getPosition().x)) + 1600 == 12200)
			{
				this->addBear(3); // <---- Call function 

				this->indexhole = 0;
				//cout << "LOADMAP" << endl;
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
					//cout << "SET" << endl;
					obstacleList.push_back(new Obstacle(objecttexture[indexobmap4[i] - 1], positionobmap4[i], typeobmap4[i]));
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
			window->draw(spri_floorice);
			window->draw(spri_floordesert);
			
		}
		else {
			if (int(fabs(this->spri_floordesert.getPosition().x)) + 1600 == 12200 - 800) {
				Heart.setposition(Vector2f(1900, 500));
			}
			if (int(fabs(this->spri_floordesert.getPosition().x)) + 1600 == 12200)
			{
				this->addBear(0);
				this->indexhole = 0;
				//cout << "LOADMAP" << endl;
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
				//	cout << "SET" << endl;
					obstacleList.push_back(new Obstacle(objecttexture[indexobmap1[i] - 1], positionobmap1[i], typeobmap1[i]));
				}
			}
			window->draw(spri_mapdesert);
			window->draw(spri_floordesert);
		}
		break;
		
	}
	for (int i = 0; i < obstacleList.size(); i++) { ///////////////colistionobject
		this->obstacleList[i]->draw(window);
   		if (*this->im==false && *this->statusplayer==1 &&abs((*positionplayer).x - this->obstacleList[i]->getposition().x) < this->obstacleList[i]->gethalfsize().x*0.6 + 121 * 0.6 &&
			abs((*positionplayer).y - this->obstacleList[i]->getposition().y) < this->obstacleList[i]->gethalfsize().y * 0.8 + 121 * 0.8) {
			//cout << "CHECKKKK" << endl;
			*this->hpplayer -= 10;
			*this->statusplayer = 2;
		}
		if (this->die == false && *this->gamepause==false) {
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
	for (int i = 0; i < this->itemlist.size(); i++) {
		if(*this->statusplayer!=0 &&*this->gamepause==false)this->itemlist[i]->DRAW(window);
		if (fabs((*positionplayer).x - this->itemlist[i]->getposition().x) < (this->itemlist[i]->gethalfsize().x * 0.3 + 121 * 0.3) *this->val_effect&&
			fabs((*positionplayer).y - this->itemlist[i]->getposition().y) < (this->itemlist[i]->gethalfsize().y * 0.6 + 121 * 0.6) * this->val_effect) {
			this->itemlist[i]->hide();
			*main_score += this->itemlist[i]->getscore();

			switch (this->itemlist[i]->gettype()) // ตรวจสอบการชน
			{
			case ID_i: //cout << "I" << endl;
				this->bool_im[ID_i] = true;
				break;
			case ID_m:
				if (this->bool_im[ID_m] == false) {
					this->bool_im[ID_m] = true;
				}
				else {
					this->bool_im[ID_m + 1] = true;
				}
				break;
			case ID_m+1:
				if (this->bool_im[ID_m] == false) {
					this->bool_im[ID_m] = true;
				}
				else {
					this->bool_im[ID_m + 1] = true;
				}
				break;
			case ID_o://cout << "O" << endl;
				this->bool_im[ID_o] = true;
				break;
			case ID_r://cout << "R" << endl;
				this->bool_im[ID_r] = true;
				break;
			case ID_t://cout << "T" << endl;
				this->bool_im[ID_t] = true;
				break;
			case ID_a://cout << "A" << endl;
				this->bool_im[ID_a] = true;
				break;
			case ID_l://cout << "L" << endl;
				this->bool_im[ID_l] = true;
				break;

			}
		}
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
	checkJKL();
	Heart.draw(window);
	window->draw(this->spri_box);
	if (this->bool_j == false) {
		window->draw(this->spri_j);

	}
	if (this->bool_k == false) {
		window->draw(this->spri_k);
	}
	if (this->bool_l == false) {
		window->draw(this->spri_l);
	}
	if (this->intJKL > 0) {
		window->draw(this->textJKL);
	}

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
			//cout << this->indexhole << " <-- UP index1" << endl;
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
			//cout << this->indexhole << " <-- UP index2 :: " << this->indexmap << " <--indexMap" << endl;
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
			
			//cout << this->indexhole << " <-- UP index3" << endl;
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

			//cout << this->indexhole << " <-- UP index3" << endl;
			this->indexhole++;
		}
		break;
	}


	return 0;

}


 

void MAP::reset()///////////////////////////////////////////////////
{
	this->beareffect = false;
	this->intJKL = -1;
	this->totalTimeJ = 0;
	this->totalTimeK = 0;
	this->totalTimeL = 0;
	this->valJ = 100;
	this->valK = 100;
	this->valL = 100;
	this->bool_l = false;
	this->bool_j = false;
	this->bool_k = false;
	for (int i = 0; i < this->obstacleList.size(); i++) {
		Obstacle* P = this->obstacleList[i];
		delete P;
		//this->obstacleList.erase(this->obstacleList.begin() + i);
	}
	for (int i = 0; i < this->itemlist.size(); i++) {
		Items* P = this->itemlist[i];
		delete P;
		//this->obstacleList.erase(this->obstacleList.begin() + i);
	}
	this->itemlist.clear();
	this->obstacleList.clear();
	this->die = false;
	setpositionmapall();
	*this->indexMap = 0;
	this->indexhole = 0;
	this->indexmap = 0;
	*this->hpplayer = 100;
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
	for (int i = 0; i < 8; i++) {
		bool_im[i] = 0;
	}
	*this->im = false;
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

void MAP::setpointergamepause(bool* state)
{
	this->gamepause = state;
}

void MAP::setpointerpositionplayer(Vector2f* pos)
{
	
	this->positionplayer = pos;

}

void MAP::setpointerim(bool* im)
{
	this->im = im;
}

int MAP::calcIM()
{
	//cout << this->bool_im[0] << endl;
	if (this->bool_im[0] == 0) {
		return 0;
	}
	else if (this->bool_im[1] == 0) {
		return 1;
	}
	else if (this->bool_im[2] == 0) {
		return 2;
	}
	else if (this->bool_im[3] == 0) {
		return 3;
	}
	else if (this->bool_im[4] == 0) {
		return 4;
	}
	else if (this->bool_im[5] == 0) {
		return 5;
	}
	else if (this->bool_im[6] == 0) {
		return 6;
	}
	else if (this->bool_im[7] == 0) {
		return 6;
	}

	return -1;
}

void MAP::checkJKL()
{
	if (Keyboard::isKeyPressed(Keyboard::J) && this->bool_j == false&&this->intJKL<0 && * this->gamepause == false) {
		this->bool_j = true;
		this->valJ = 0;
		this->intJKL = 4;
		this->textJKL.setPosition(this->spri_j.getPosition());
	}
	if (Keyboard::isKeyPressed(Keyboard::K) && this->bool_k == false && this->intJKL < 0 && *this->gamepause == false) {
		this->val_effect = 7;
		this->intJKL = 10;
		this->valK = 0;
		this->bool_k = true;
		this->textJKL.setPosition(this->spri_k.getPosition());
	}
	if (Keyboard::isKeyPressed(Keyboard::L) && this->bool_l == false && this->intJKL < 0 && *this->gamepause == false) {
		this->bool_l = true;
		this->valL = 0;
		if (*this->main_score % 2 == 0) {
			this->beareffect = true;
			cout << "......" << endl;
		}
	}
	if (this->intJKL >= 0 && this->valJ <= 20) {
		//cout << "a" << endl;
		this->totalTimeJ += clockJ.restart().asSeconds();
		if (this->totalTimeJ > 0.2) {
			this->totalTimeJ = 0;
			this->valJ++;
			(*this->hpplayer)++;
			if (this->valJ % 5 == 0) {
				this->intJKL--;
			}
			if (this -> intJKL <= 0) {
				//cout << "reset" << endl;
				this->intJKL = -1;
			}
			//cout << this->intJKL << endl;
			this->textJKL.setString(to_string((intJKL)));
			//cout << fixed << setprecision(1) << intJKL << endl;
		}
	}

	if (this->intJKL >= 0 && this->valK <= 10) {
		//cout << "b" << endl;
		this->totalTimeK+= clockK.restart().asSeconds();
		//cout << totalTimeK << endl;
		if (this->totalTimeK > 1.0f) {
			this->totalTimeK = 0;
			this->valK++;
			this->intJKL--;
			this->textJKL.setString(to_string((intJKL)));
			if (this -> intJKL <= 0) {
				this->intJKL = -1;
			}
			//cout << fixed << setprecision(1) << intJKL << endl;
		}
	}
	else if (this->val_effect!=1){
		this->val_effect = 1;
	}
}

void MAP::addBear(int indexMap)
{
	//cout << itemlist.size() << endl;
	for (int i = 0; i < itemlist.size(); i++)
	{
		Items* p = itemlist[i];
		delete p;
	}
	this->itemlist.clear();
	srand(time(NULL));
	int randbear=rand()%3;
	int tempim;
	tempim = calcIM();

	//cout << tempim << endl; // THIS
		switch (indexMap)
	{
	case 0: // map1
		for (int i = 0; i < 84; i++) {
			randbear = rand() %15;
			
			if (type1[i] != -1) {
				if(randbear==0 || this->beareffect==true) this->itemlist.push_back(new Items(this->bear[8], rand() % 200 + 300, 4, itemposition1[i], type1[i]));
				else if(i%2==0) 
				{
					if(tempim != -1)
					this->itemlist.push_back(new Items(this->immortal[tempim], rand() % 200 + 200, 1, itemposition1[i], tempim));
					tempim=(tempim+1)%8;
					//cout << tempim << endl;
				}
				else
				switch (type1[i])
				{
				case 10: this->itemlist.push_back(new Items(this->bear[0], rand() % 200 + 100, 4, itemposition1[i], type1[i]));
					break;													/// กำหนดช่วงคะแนนของแต่ละหมีด้วย
				case 11: this->itemlist.push_back(new Items(this->bear[1], rand() % 200 + 100, 4, itemposition1[i], type1[i]));
					break;
				case 12: this->itemlist.push_back(new Items(this->bear[2], rand() % 200 + 100, 4, itemposition1[i], type1[i]));
					break;
				case 13: this->itemlist.push_back(new Items(this->bear[3], rand() % 200 + 100, 4, itemposition1[i], type1[i]));
					break;
				case 14: this->itemlist.push_back(new Items(this->bear[4], rand() % 200 + 100, 4, itemposition1[i], type1[i]));
					break;
				case 15: this->itemlist.push_back(new Items(this->bear[5], rand() % 200 + 100, 4, itemposition1[i], type1[i]));
					break;
				case 16: this->itemlist.push_back(new Items(this->bear[6], rand() % 200 + 100, 4, itemposition1[i], type1[i]));
					break;
				case 17: this->itemlist.push_back(new Items(this->bear[7], rand() % 200 + 100, 4, itemposition1[i], type1[i]));
					break;
				
				}
				
			}
		}
		break;
	case 1: // Map 2
		for (int i = 0; i < 84; i++) {
			randbear = rand() % 15;
			if (type2[i] != -1) {
				if (randbear == 0 || this->beareffect == true) this->itemlist.push_back(new Items(this->bear[8], rand() % 200 + 300, 4, itemposition2[i], type2[i]));
				else if (i % 20 == 0)
				{
					if (tempim != -1)
					this->itemlist.push_back(new Items(this->immortal[tempim], rand() % 200 + 200, 1, itemposition2[i], tempim));
					tempim = (tempim + 1) % 8;
				}
				else
				switch (type2[i])
				{
				case 10: this->itemlist.push_back(new Items(this->bear[0], rand() % 200 + 100, 4, itemposition2[i], type2[i]));
					break;													/// กำหนดช่วงคะแนนของแต่ละหมีด้วย
				case 11: this->itemlist.push_back(new Items(this->bear[1], rand() % 200 + 100, 4, itemposition2[i], type2[i]));
					break;
				case 12: this->itemlist.push_back(new Items(this->bear[2], rand() % 200 + 100, 4, itemposition2[i], type2[i]));
					break;
				case 13: this->itemlist.push_back(new Items(this->bear[3], rand() % 200 + 100, 4, itemposition2[i], type2[i]));
					break;
				case 14: this->itemlist.push_back(new Items(this->bear[4], rand() % 200 + 100, 4, itemposition2[i], type2[i]));
					break;
				case 15: this->itemlist.push_back(new Items(this->bear[5], rand() % 200 + 100, 4, itemposition2[i], type2[i]));
					break;
				case 16: this->itemlist.push_back(new Items(this->bear[6], rand() % 200 + 100, 4, itemposition2[i], type2[i]));
					break;
				case 17: this->itemlist.push_back(new Items(this->bear[7], rand() % 200 + 100, 4, itemposition2[i], type2[i]));
					break;
				}

			}
		}
		break;
	case 2: // Map 3
		for (int i = 0; i < 85; i++) {
			randbear = rand() % 15;
			if (type3[i] != -1) {
				if (randbear == 0 || this->beareffect == true) this->itemlist.push_back(new Items(this->bear[8], rand() % 200 + 300, 4, itemposition3[i], type3[i]));
				else if (i % 20 == 0)
				{
					if (tempim != -1)
					this->itemlist.push_back(new Items(this->immortal[tempim], rand() % 200 + 200, 1, itemposition3[i], tempim));
					tempim = (tempim + 1) % 8;
				}
				else
				switch (type3[i])
				{
				case 10: this->itemlist.push_back(new Items(this->bear[0], rand() % 200 + 100, 4, itemposition3[i], type3[i]));
					break;													 // score
				case 11: this->itemlist.push_back(new Items(this->bear[1], rand() % 200 + 100, 4, itemposition3[i], type3[i]));
					break;
				case 12: this->itemlist.push_back(new Items(this->bear[2], rand() % 200 + 100, 4, itemposition3[i], type3[i]));
					break;
				case 13: this->itemlist.push_back(new Items(this->bear[3], rand() % 200 + 100, 4, itemposition3[i], type3[i]));
					break;
				case 14: this->itemlist.push_back(new Items(this->bear[4], rand() % 200 + 100, 4, itemposition3[i], type3[i]));
					break;
				case 15: this->itemlist.push_back(new Items(this->bear[5], rand() % 200 + 100, 4, itemposition3[i], type3[i]));
					break;
				case 16: this->itemlist.push_back(new Items(this->bear[6], rand() % 200 + 100, 4, itemposition3[i], type3[i]));
					break;
				case 17: this->itemlist.push_back(new Items(this->bear[7], rand() % 200 + 100, 4, itemposition3[i], type3[i]));
					break;

				}

			}
		}
		break;
	case 3: // Map 4
		for (int i = 0; i < 90; i++) {
			randbear = rand() % 15;
			if (type4[i] != -1) {
				if (randbear == 0 || this->beareffect == true) this->itemlist.push_back(new Items(this->bear[8], rand() % 200 + 300, 4, itemposition4[i], type4[i]));
				else if (i % 20 == 0)
				{
					if (tempim != -1)
					this->itemlist.push_back(new Items(this->immortal[tempim], rand() % 200 + 200, 1, itemposition4[i], tempim));
					tempim = (tempim + 1) % 8;
				}
				else
				switch (type4[i])
				{
				case 10: this->itemlist.push_back(new Items(this->bear[0], rand() % 200 + 100, 4, itemposition4[i], type4[i]));
					break;													/// score
				case 11: this->itemlist.push_back(new Items(this->bear[1], rand() % 200 + 100, 4, itemposition4[i], type4[i]));
					break;
				case 12: this->itemlist.push_back(new Items(this->bear[2], rand() % 200 + 100, 4, itemposition4[i], type4[i]));
					break;
				case 13: this->itemlist.push_back(new Items(this->bear[3], rand() % 200 + 100, 4, itemposition4[i], type4[i]));
					break;
				case 14: this->itemlist.push_back(new Items(this->bear[4], rand() % 200 + 100, 4, itemposition4[i], type4[i]));
					break;
				case 15: this->itemlist.push_back(new Items(this->bear[5], rand() % 200 + 100, 4, itemposition4[i], type4[i]));
					break;
				case 16: this->itemlist.push_back(new Items(this->bear[6], rand() % 200 + 100, 4, itemposition4[i], type4[i]));
					break;
				case 17: this->itemlist.push_back(new Items(this->bear[7], rand() % 200 + 100, 4, itemposition4[i], type4[i]));
					break;
				}

			}
		}
		break;
	}
	this->beareffect = false;
}


void MAP::checkcolisionheart()
{
	//cout << (*positionplayer).x << endl;
	if (Heart.getstatus()&&
		fabs((*positionplayer).x - Heart.getposition().x) < Heart.gethalfsize().x * 0.6 + 121 * 0.6 &&
		fabs((*positionplayer).y - Heart.getposition().y) < Heart.gethalfsize().y * 0.6 + 121 * 0.6) {
		//cout << "CHONNN" << endl;
		this->Heart.setposition(Vector2f(-500, 0));
		*this->hpplayer += 20;
	}
}

void MAP::setpositionmapall()
{
	srand(time(NULL));

	 // call function for map 1 
	/*if (first == false) {
		this->addBear(0);
	}*/
	int randbear = rand() % 3;
	int tempim;
	tempim = calcIM();
	for (int i = 0; i < 84; i++) {
		randbear = rand() % 15;

		if (type1[i] != -1) {
			if (randbear == 0 || this->beareffect == true) this->itemlist.push_back(new Items(this->bear[8], rand() % 200 + 300, 4, itemposition1[i] - Vector2f(1600, 0), type1[i]));
			else if (i % 2 == 0)
			{
				if (tempim != -1)
					this->itemlist.push_back(new Items(this->immortal[tempim], rand() % 200 + 200, 1, itemposition1[i] - Vector2f(1600, 0), tempim));
				tempim = (tempim + 1) % 8;
				cout << tempim << endl;
			}
			else
			switch (type1[i])
			{
			case 10 : this->itemlist.push_back(new Items(this->bear[0], rand() % 200 + 200, 4, itemposition1[i]-Vector2f(1600,0), type1[i]));
				break;													/// กำหนดช่วงคะแนนของแต่ละหมี
			case 11: this->itemlist.push_back(new Items(this->bear[1], rand() % 200 + 200, 4, itemposition1[i] - Vector2f(1600, 0), type1[i]));
				break;
			case 12: this->itemlist.push_back(new Items(this->bear[2], rand() % 200 + 200, 4, itemposition1[i] - Vector2f(1600, 0), type1[i]));
				break;
			case 13: this->itemlist.push_back(new Items(this->bear[3], rand() % 200 + 200, 4, itemposition1[i] - Vector2f(1600, 0), type1[i]));
				break;
			case 14: this->itemlist.push_back(new Items(this->bear[4], rand() % 200 + 200, 4, itemposition1[i] - Vector2f(1600, 0), type1[i]));
				break;
			case 15: this->itemlist.push_back(new Items(this->bear[5], rand() % 200 + 200, 4, itemposition1[i] - Vector2f(1600, 0), type1[i]));
				break;
			case 16: this->itemlist.push_back(new Items(this->bear[6], rand() % 200 + 200, 4, itemposition1[i] - Vector2f(1600, 0), type1[i]));
				break;
			case 17: this->itemlist.push_back(new Items(this->bear[7], rand() % 200 + 200, 4, itemposition1[i] - Vector2f(1600, 0), type1[i]));
				break;
			case 18: this->itemlist.push_back(new Items(this->bear[8], rand() % 200 + 200, 4, itemposition1[i] - Vector2f(1600, 0), type1[i]));
				break;
			}
			
		}
	}
	for (int i = 0; i < 10; i++) {  ////
		//cout << "SET" << endl;
		obstacleList.push_back(new Obstacle(objecttexture[indexobmap1[i] - 1], positionobmap1[i]-1600, typeobmap1[i]));
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
	if (this->die == false && *this->gamepause==false)
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

