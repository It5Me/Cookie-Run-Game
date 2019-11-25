#include "Bartop.h"

Bartop::Bartop()
{
	
	this->font.loadFromFile("font\\SOV_monomon-hinted.ttf");
	this->text_score.setFont(this->font);
	this->text_score.setCharacterSize(45);
	this->text_score.setFillColor(Color::Yellow);
	this->text_score.setString("0");
	this->text_score.setPosition(1550, 30);
	this->texture_bgblood.loadFromFile("Texture/bar/bgblood.png");
	this->texture_blood[0].loadFromFile("Texture/bar/blood.png");
	this->texture_blood[1].loadFromFile("Texture/bar/bloodimmor.png");
	this->texture_heart.loadFromFile("Texture/bar/heart.png");
	this->texture_immortal[0].loadFromFile("Texture/bar/font_I.png");
	this->texture_immortal[1].loadFromFile("Texture/bar/font_M.png");
	this->texture_immortal[2].loadFromFile("Texture/bar/font_O.png");
	this->texture_immortal[3].loadFromFile("Texture/bar/font_R.png");
	this->texture_immortal[4].loadFromFile("Texture/bar/font_T.png");
	this->texture_immortal[5].loadFromFile("Texture/bar/font_A.png");
	this->texture_immortal[6].loadFromFile("Texture/bar/font_L.png");
	this->texture_BGimmortal.loadFromFile("Texture/bar/IMMORTAL.png");
	this->spri_immortal[0].setTexture(this->texture_immortal[0]);
	this->spri_immortal[1].setTexture(this->texture_immortal[1]);
	this->spri_immortal[2].setTexture(this->texture_immortal[1]);
	this->spri_immortal[3].setTexture(this->texture_immortal[2]);
	this->spri_immortal[4].setTexture(this->texture_immortal[3]);
	this->spri_immortal[5].setTexture(this->texture_immortal[4]);
	this->spri_immortal[6].setTexture(this->texture_immortal[5]);
	this->spri_immortal[7].setTexture(this->texture_immortal[6]);
	this->spri_BGimmortal.setTexture(this->texture_BGimmortal);
	this->spri_bgblood.setTexture(this->texture_bgblood);
	this->spri_blood.setTexture(this->texture_blood[0]);
	this->spri_heart.setTexture(this->texture_heart);
	this->rect = IntRect(0, 0, this->texture_blood[0].getSize().x, this->texture_blood[0].getSize().y);
	this->spri_heart.setPosition(20, 30);
	this->spri_bgblood.setPosition(70, 83);
	this->spri_blood.setPosition(85, 90);
	this->spri_BGimmortal.setPosition(220, 30);
	this->spri_immortal[0].setPosition(220, 30);
	this->spri_immortal[1].setPosition(245, 30);
	this->spri_immortal[2].setPosition(245+50, 30);
	this->spri_immortal[3].setPosition(234+108, 30); //O
	this->spri_immortal[4].setPosition(234 + 100 + 62, 30); //R
	this->spri_immortal[5].setPosition(445, 30); // T
	this->spri_immortal[6].setPosition(486, 30); // A
 	this->spri_immortal[7].setPosition(486+60, 30); // L
	this->spri_BIG.setPosition(300, 400);
}

void Bartop::DRAW(RenderWindow* window)
{	
	//cout << Mouse::getPosition(*window).x << endl;
	window->draw(this->spri_bgblood);
	window->draw(this->spri_blood);
	window->draw(this->spri_heart);
	window->draw(this->spri_BGimmortal);
	window->draw(this->spri_BIG);
	for (int i = 0; i < 8; i++) {
		if (this->bool_immortal[i] == true) {
			window->draw(this->spri_immortal[i]);
		}
	}
	window->draw(this->text_score);
}

void Bartop::update_hp(float hp)
{	
	//cout << float(hp / 100.0f) << endl;
	if (hp > 100) {
		hp = 100;
	}
	if (hp >= 0 && hp <= 100) {
		this->rect.width = float(hp / 100.0f) * this->texture_blood[0].getSize().x;
		this->spri_blood.setTextureRect(this->rect);
	}
	
	
}

void Bartop::pair(bool* P)
{
	this->bool_immortal = P;
}

void Bartop::drawscore(unsigned long* P)
{
	string temp = to_string(*P);
	this->text_score.setPosition(1575- temp.length()*25, 30);
	this->text_score.setString(temp);

}

void Bartop::setimmortal(bool state)
{
	//cout << "settttt" << " " << state <<endl;
	if (state) {
		this->spri_blood.setTexture(this->texture_blood[1]);
	}
	else {
		this->spri_blood.setTexture(this->texture_blood[0]);
	}
	
}

