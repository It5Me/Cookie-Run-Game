#include "Player.h"

Player::Player()
{
	this->bodyTexture.loadFromFile("Texture\\player\\playerlong-01.png");
	this->body.setTexture(this->bodyTexture);
	this->body.setPosition(200.0f, 490.0f);
	this->rec.top = 0;
	this->rec.left = 0;
	this->rec.width = bodyTexture.getSize().x/10;
	this->rec.height = bodyTexture.getSize().y / 10;
	this->body.setScale(0.9f, 1.0f);
}

void Player::DRAW(RenderWindow* window)
{
	jump();
	control();
	update(stateanimation);
	window->draw(this->body);
}

Vector2f Player::getposition()
{
	
	return body.getPosition()+gethalfsize();
}

void Player::update(int row)
{
	this->totaltime += clock.restart().asSeconds();
	if (totaltime > 0.08f) {
		totaltime = 0;
		this->count++;
		if (count > 9) {
			count = 0;
		}
	}
	this->rec.left = rec.width * count;
	this->rec.top = rec.height * row;
	this->body.setTextureRect(rec);
}

void Player::control()
{
	if (Keyboard::isKeyPressed(Keyboard::Space) && stateanimation!=3) { ////////////////// jump
		jumpdelta += clockjump.restart().asSeconds();
		if (this->statejump == 0) {
			this->statejump = 1;
			cout << "jump" << endl;
			jumpdelta = 0;
			this->stateanimation = 2;
		}
		else if ((this->statejump == 1 || this->statejump == 2) && this->jumphight==false && jumpdelta>0.3) {
			cout << A << endl;
			this->A = 12;
			this->statejump = 1;
			this->jumphight = true;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) && stateanimation!=2) {
		this->stateanimation = 3;
		this->body.setScale(0.7f,0.8f);
		this->body.setPosition(200.0f, 530.0f);
	}
	else if(statejump==0){
		stateanimation = 0;
		this->body.setScale(0.9f, 1.0f);
		this->body.setPosition(200.0f, 490.0f);
	}
}

void Player::jump()
{
	if (this->statejump == 1) {
		this->body.setPosition(this->body.getPosition().x, this->body.getPosition().y - this->A);
		A -= 0.3;
		if (A <= 0) {
			this->statejump = 2;
		}
	}
	else if (this->statejump == 2) {
		this->body.setPosition(this->body.getPosition().x, this->body.getPosition().y +	 this->A);
		A += 0.3;

		if (this->body.getPosition().y > 500) {
			this->body.setPosition(200.0f, 490.0f);
			this->stateanimation = 0;
			this->A = 10;
			this->statejump = 0;
			this->jumphight = false;
		}
	}
	
}
