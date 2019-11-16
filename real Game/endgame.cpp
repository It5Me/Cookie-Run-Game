#include "endgame.h"

endgame::endgame()
{
	this->textureendgame.loadFromFile("Texture/menu/bgendgame.png");
	this->bgendgame.setTexture(this->textureendgame);
	this->bgendgame.setPosition(550, 200);
	this->texturebtn.loadFromFile("Texture/menu/btnendgame.png");
	this->btn.setTexture(this->texturebtn);
	this->btn.setPosition(650, 600);
	this->font.loadFromFile("font\\SOV_monomon-hinted.ttf");
	this->textscore.setFont(this->font);
	this->textscore.setCharacterSize(80);
	this->textscore.setFillColor(Color::Black);
	this->textscore.setStyle(Text::Bold);
	this->textscore.setString("99999999");
	this->textscore.setPosition(600,400);
}

void endgame::draw(RenderWindow* window)
{
	loadscore();
	checkbtn(window);
	this->textscore.setString(this->tempscore);
	window->draw(this->bgendgame);
	window->draw(this->btn);
	window->draw(this->textscore);
}

void endgame::setstatus(bool state)
{
	if (state == false) {
		this->statemenu=false;
		this->loadscorecomplete = false;
		this->tempscore = "        ";
		this->index = 0;
	}
	else
	{
		//cout << "kdfkfgkf" << endl;
		*this->score *= 1.20;
		this->mainscore = to_string(*this->score);
		reverse(this->mainscore.begin(),this->mainscore.end());
		//cout << this->mainscore << endl;
	}
	this->status = state;
}

bool endgame::getstatus()
{
	return this->status;
}

bool endgame::ismenustart()
{
	return this->statemenu;
}

void endgame::setpointscore(unsigned long* t)
{
	this->score = t;
}

void endgame::loadscore()
{
	if (this->loadscorecomplete == false) {
		this->totaltime += clock.restart().asSeconds();
		this->tempscore[this->index] = '0'+rand()%10;
		if (this->totaltime > 0.5) {
			this->totaltime = 0;
			//if(this->mainscore)
			if (this->mainscore[7 - index] >= '0' && this->mainscore[7 - index] <= '9') {
				this->tempscore[this->index] = this->mainscore[7 - index];
			}
			else {
				this->tempscore[this->index] = '#';
			}
			this->index++;
			if (this->index == 8) {
				
				this->loadscorecomplete = true;
			}
		}
	}
}

void endgame::checkbtn(RenderWindow* window)
{
	if (Mouse::getPosition(*window).x > 650 &&
		Mouse::getPosition(*window).x < 950 &&
		Mouse::getPosition(*window).y>600 &&
		Mouse::getPosition(*window).y < 680) {
		//cout << "dlld" << endl;
		this->hold = true;
		if (Mouse::isButtonPressed(Mouse::Left)&& this->statemenu==false) {
			this->statemenu = true;
			cout << "Click" << endl;
		}
	}
	else {
		this->hold = false;
	}
}
