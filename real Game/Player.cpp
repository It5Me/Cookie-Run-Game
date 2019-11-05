#include "Player.h"

Player::Player()
{
	this->womenTexture.loadFromFile("Texture\\player\\playerwomanall-01.png");
	this->manTexture.loadFromFile("Texture\\player\\manplayer.png");
	//this->body.setTexture(this->bodyTexture);
	//this->body.setPosition(200.0f, 490.0f);
	this->body.setPosition(200.0f, 490.0f);
	this->rec.top = 0;
	this->rec.left = 0;
	this->rec.width = manTexture.getSize().x/10;
	this->rec.height = manTexture.getSize().y / 10;
	this->body.setScale(0.9f, 1.0f);
	
}

void Player::DRAW(RenderWindow* window)
{
	*this->y = body.getPosition().y;
	jump();
	control();
	update(stateanimation);
	window->draw(this->body);
}

Vector2f Player::getposition()
{
	
	return body.getPosition()+gethalfsize();
}

Vector2f Player::gethalfsize()
{
	 //return Vector2f(this->bodyTexture.getSize().x / 10 / 4.0f, this->bodyTexture.getSize().y / 10 / 4.0f); };

	if (this->select == 1) {
		return Vector2f(this->manTexture.getSize().x / 10 / 4.0f, this->manTexture.getSize().y / 10 / 4.0f);
	}
	else
	{
		return Vector2f(this->womenTexture.getSize().x / 10 / 4.0f, this->womenTexture.getSize().y / 10 / 4.0f);

	}

}
	
void Player::selectcharacter(int index)
{
	this->select = index;
	if (this->select == 1) {
		this->body.setTexture(this->manTexture);
	}
	else {
		this->body.setTexture(this->womenTexture);
	}
}

void Player::setBig()
{
	//this->body.setScale(1.5, 1.5);
}

void Player::getposplayer(float* Y)
{
	this->y = Y;
	//cout << "Player Address Y par:" << Y << endl;
	//cout << "Player Address Y in class:" << this->y << endl;
}

void Player::checkdie(bool die)
{
	if (die) {
		//cout << "hHAAHAHAHHA" << endl;
		this->body.move(0, 10);
	}
}

void Player::update(int row)
{
	this->totaltime += clock.restart().asSeconds();
	if (row == 5) {
		if (totaltime > 0.036f) {
			totaltime = 0;
			this->count++;
			if (count > 9) {
				count = 0;
			}
		}
		
	}
	else {
		if (totaltime > 0.03f) {
			totaltime = 0;
			this->count++;
			if (count > 9) {
				count = 0;
			}
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
			//cout << "jump" << endl;
			jumpdelta = 0;
			this->stateanimation = 2;
		}
		else if ((this->statejump == 1 || this->statejump == 2) && this->jumphight==false && jumpdelta>0.3) {
			//cout << A << endl;
			this->A = 12;
			this->statejump = 1;
			this->jumphight = true;
			this->stateanimation = 5;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) && stateanimation!=2 && stateanimation!=5) {
		this->stateanimation = 3;
		this->body.setScale(0.7f,0.8f);
		this->body.setPosition(200.0f, 530.0f);
	}
	else if(statejump==0){
		//cout << "do" << endl;
		stateanimation = 0;
		this->body.setScale(0.9f, 1.0f);
		//cout << *this->y << endl;
		//this->body.setPosition(200.0f, 490.0f);
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
