#include "Pet.h"

Pet::Pet()
{
	this->texture_animal[0].loadFromFile("Texture/menu/animal1.png");
	this->texture_animal[1].loadFromFile("Texture/menu/animal2.png");
	this->texture_animal[2].loadFromFile("Texture/menu/animal3.png");
	this->texture_animal[3].loadFromFile("Texture/menu/animal4.png");
	this->rect.top = 0;
	this->rect.width = this->texture_animal[0].getSize().x / 4;
	this->rect.height = this->texture_animal[0].getSize().y;
	this->rect.left = 0;
	this->spri_body.setOrigin(this->rect.width / 2, this->rect.height / 2);
	this->spri_body.setScale(0.5f, 0.5f);
	this->spri_body.setTexture(this->texture_animal[0]);
}

void Pet::DRAW(RenderWindow *window)
{
	//cout << sin(a) << endl;
	//this->spri_body.move(0, sin(a));
	//cout << spri_body.getPosition().x << endl;
	//a -= 0.1;
	update();
	window->draw(this->spri_body);
}

void Pet::selectcharacteranimal(int index)
{
	this->selectanimal = index;
	this->spri_body.setTexture(this->texture_animal[selectanimal]);
}

void Pet::SETposition(Vector2f pos)
{
	this->spri_body.setPosition(pos-Vector2f(30,20+sin(a)*4));
	a -= 0.1;
}

void Pet::update()
{
	totaltime += clock.restart().asSeconds();
	if (totaltime > 0.1) {
		
		totaltime = 0;
		x++;
		if (x >= 4) {
			x = 0;
		}
	}
	rect.left = rect.width * x;
	this->spri_body.setTextureRect(rect);
}
