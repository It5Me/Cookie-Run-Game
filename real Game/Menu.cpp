#include "Menu.h"

Menu::Menu()
{
	//this->loadfile();
	this->texture[0].loadFromFile("Texture\\menu\\bgfront-01.jpg");
	this->texture[1].loadFromFile("Texture\\menu\\bg_highscore.png");
	this->texture[2].loadFromFile("Texture\\menu\\showname.png");
	this->texture[3].loadFromFile("Texture\\menu\\btn_start_normal.png");
	this->texture[4].loadFromFile("Texture\\menu\\btn_start_hold.png");
	this->texture[5].loadFromFile("Texture\\menu\\btn_animalleft.png");
	this->texture[6].loadFromFile("Texture\\menu\\btn_animalleft_normal.png");
	this->texture[7].loadFromFile("Texture\\menu\\btn_animalright.png");
	this->texture[8].loadFromFile("Texture\\menu\\btn_animalright_normal.png");
	this->texture[9].loadFromFile("Texture\\menu\\btn_playerleft.png");
	this->texture[10].loadFromFile("Texture\\menu\\btn_playerleft_normal.png");
	this->texture[11].loadFromFile("Texture\\menu\\btn_playerright.png");
	this->texture[12].loadFromFile("Texture\\menu\\btn_playerright_normal.png");
	this->texture[13].loadFromFile("Texture\\menu\\player.png");
	this->texture[14].loadFromFile("Texture\\menu\\animal.png");
	this->texture_animal[0].loadFromFile("Texture\\menu\\animal1.png");
	this->texture_animal[1].loadFromFile("Texture\\menu\\animal2.png");
	this->texture_animal[2].loadFromFile("Texture\\menu\\animal3.png");
	this->texture_animal[3].loadFromFile("Texture\\menu\\animal4.png");
	this->texture_player[0].loadFromFile("Texture\\player\\playerwomanall-01.png");
	this->texture_player[1].loadFromFile("Texture\\player\\manplayer.png");
	this->spri_bg.setTexture(this->texture[0]);
	this->spri_highscore.setTexture(this->texture[1]);
	this->spri_showname.setTexture(this->texture[2]);
	this->spri_button.setTexture(this->texture[3]);
	this->spri_btn_animalleft.setTexture(this->texture[5]);
	//this->spri_btn_animalleft.setTexture(this->texture[6]);
	this->spri_btn_animalright.setTexture(this->texture[7]);
	/////this->spri_btn_animalright.setTexture(this->texture[8]);
	this->spri_btn_playerleft.setTexture(this->texture[9]);
	//this->spri_btn_playerleft.setTexture(this->texture[10]);
	this->spri_btn_playerright.setTexture(this->texture[11]);
	//this->spri_btn_playerright.setTexture(this->texture[12]);

	this->spri_player.setTexture(this->texture[13]);
	this->showplayer.setTexture(this->texture_player[0]);
	this->spri_animal.setTexture(this->texture[14]);
	this->showanimal.setTexture(this->texture_animal[0]);
	this->spri_highscore.setPosition(30.0f, 45.0f);
	this->spri_button.setPosition(1000.0f, 770.0f);
	this->spri_showname.setPosition(1000.0f, 45.0f);
	this->spri_animal.setPosition(773.0f, 167.0f);
	this->showanimal.setPosition(773.0f, 167.0f);
	this->showplayer.setPosition(1064.3f, 167.0f);
	this->spri_player.setPosition(1064.3f, 167.0f);
	this->spri_btn_animalleft.setPosition(800.0f, 451.0f);
	this->spri_btn_animalright.setPosition(931.0f, 451.0f);
	this->spri_btn_playerleft.setPosition(1145.0f, 664.0f);
	this->spri_btn_playerright.setPosition(1334.0f, 664.0f);
	this->showplayer.setScale(2, 2);


	this->font.loadFromFile("font\\SOV_monomon-hinted.ttf");
	for (int i = 0; i < 5; i++)
	{
		this->text[i].setFont(this->font);
		this->text[i].setCharacterSize(45);
		this->text[i].setFillColor(Color::Black);
		//this->text[i].setString("TEST 1234567891011" + to_string(i));
		this->text[i].setPosition(75.0f, 290.0f+i*100);
	}
	this->rect_animal = IntRect(0, 0, this->texture_animal[0].getSize().x / 4, this->texture_animal[0].getSize().y / 1);
	this->rect_player = IntRect(0, 0*this->texture_player[0].getSize().y / 10, this->texture_player[0].getSize().x / 10, this->texture_player[0].getSize().y / 10);
	this->showplayer.setTextureRect(this->rect_player);
	this->showanimal.setTextureRect(this->rect_animal);
}

void Menu::DRAW(RenderWindow* window)
{
	update();
	this->colition(window,&spri_button, &this->texture[3], &this->texture[4],&this->onhold[0],0);
	this->colition(window, &spri_btn_animalleft, &this->texture[5], &this->texture[6],&this->onhold[1],1);
	this->colition(window, &spri_btn_animalright, &this->texture[7], &this->texture[8], &this->onhold[2],2);
	this->colition(window, &spri_btn_playerleft, &this->texture[9], &this->texture[10], &this->onhold[3],3);
	this->colition(window, &spri_btn_playerright, &this->texture[11], &this->texture[12], &this->onhold[4],4);
	window->draw(this->spri_bg);
	window->draw(this->spri_highscore);
	window->draw(this->spri_showname);
	window->draw(this->spri_button);
	window->draw(this->spri_btn_animalleft);
	window->draw(this->spri_btn_animalright);
	window->draw(this->spri_btn_playerleft);
	window->draw(this->spri_btn_playerright);
	window->draw(this->spri_player);
	window->draw(this->spri_animal);
	window->draw(this->showanimal);
	window->draw(this->showplayer);
	

	for (int i = 0; i < 5; i++) {
		window->draw(this->text[i]);

	}
	//cout << "mouse: " << Mouse::getPosition(*window).x << " " << Mouse::getPosition(*window).y << endl;
}

void Menu::loadfile()
{
	string t;
	int i = 0;
	this->myfile.open("database\\score.txt",ios::in);
	while (!this->myfile.eof()) {
		getline(this->myfile,t);
		cout << t << endl;
		this->text[i++].setString(t);
		if (i == 5) {
			break;
		}

	}
	this->myfile.close();
}

bool Menu::check()
{
	return this->start;
}

int Menu::select_player()
{
	return index_player;
}

int Menu::select_animal()
{
	return this->index_animal;
}

void Menu::colition(RenderWindow* window,Sprite *spri,Texture *nm,Texture *ho, bool* p,int index)
{
	if (Mouse::getPosition(*window).x >= spri->getPosition().x &&
		Mouse::getPosition(*window).y >= spri->getPosition().y &&
		Mouse::getPosition(*window).x <= spri->getPosition().x + ho->getSize().x &&
		Mouse::getPosition(*window).y <= spri->getPosition().y + ho->getSize().y) {
		//cout << "Check!" << endl;
		if (*p == false) {
			*p = true;
			spri->setTexture(*ho);
			//cout << "on hold" << endl;
		}
		if (Mouse::isButtonPressed(Mouse::Left) == true && this->click==false) {
			this->click = true;
			//cout << "click" << endl;
			switch (index)
			{
			case 0:this->start = true;
				break;//start
			case 1:index_animal = (index_animal > 0 ? index_animal - 1 : index_animal);
				break;//animalleft
			case 2:index_animal = (index_animal < 3 ? index_animal + 1 : index_animal);
				break;//animalright
			case 3:index_player = (index_player > 0 ? index_player -1  : index_player);
				break;//playerleft
			case 4:index_player = (index_player < 1 ? index_player + 1 : index_player);
				break;//playerright
			}
			this->showplayer.setTexture(this->texture_player[index_player]);
			this->showanimal.setTexture(this->texture_animal[index_animal]);
			
			if (index_player == 1) {
				this->showplayer.setScale(1.8f, 1.8f);
				this->showplayer.setPosition(1084.3f, 207.0f);
			}
			else {
				this->showplayer.setScale(2.0f, 2.0f);
				this->showplayer.setPosition(1064.3f, 167.0f);
			}

		}
		else if (Mouse::isButtonPressed(Mouse::Left) == false && this->click == true) {
			this->click = false;
			//cout << "NO click" << endl;
		}
	}
	else if(*p==true){
		spri->setTexture(*nm);
		*p = false;
		//cout << " NO on hold" << endl;
	}
}

void Menu::update()
{
	//cout << "index" << index_animal << endl;
	this->totaltime += this->clock.restart().asSeconds();
	this->totaltime1 += this->clock1.restart().asSeconds();
	if (this->totaltime >= 0.2) {
		this->totaltime = 0;
		x++;
		if (x == 4) {
			x = 0;
		}
	}
	if (this->totaltime1 >= 0.1) {
		this->totaltime1 = 0;
		x1++;
		if (x1 == 10) {
			x1 = 0;
		}
	}
	this->rect_player.left = x1 * this->rect_player.width;
	this->rect_animal.left = x * this->rect_animal.width;
	this->showplayer.setTextureRect(this->rect_player);
	this->showanimal.setTextureRect(this->rect_animal);

}
