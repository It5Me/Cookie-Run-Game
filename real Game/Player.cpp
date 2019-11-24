#include "Player.h"

Player::Player()
{
	this->womenTexture.loadFromFile("Texture\\player\\playerwomanall-01.png");
	this->manTexture.loadFromFile("Texture\\player\\manplayer.png");
	//cout << womenTexture.getSize().x / 10 << " " << womenTexture.getSize().y / 10 << endl;
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
	*this->positionplayer = body.getPosition()+Vector2f(this->womenTexture.getSize().x/10/2, this->womenTexture.getSize().y /10/ 2);
	//*this->y = body.getPosition().y;
	jump();
	if (*this->status != 0)control();
	else {
		body.setPosition(0, -1000);
	}
	update(stateanimation);
	
	if (*this->status == 2) {

		this->timeplayer += clockplayer.restart().asSeconds();
		if (this->timeplayer >= 0.2) {
			this->timeplayer = 0;
			this->countdraw++;
			//cout << countdraw << endl;////////////////////////////////// กระพริบ
		}
		if (this->countdraw % 2 == 0) {
			window->draw(this->body);
		}
		if (this->countdraw==8) {
			*this->status = 1;
			this->countdraw = 0;
		}
	}
	else {
		window->draw(this->body);
	}
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



void Player::reset()
{
	//this->die = false;
	*this->status = 1;
	this->body.setPosition(200.0f, 490.0f);
}

void Player::checkhole(bool state)
{
	this->onhole = state;
}

bool Player::checkdie()
{
	return *this->status==0;
}

void Player::setpointerstatusplayer(int* status)
{
	this->status = status;
}

void Player::setpointerpositionplayer(Vector2f* pos)
{
	this->positionplayer = pos;
}

void Player::gamepause(bool* state)
{
	this->Gamepause = state;
}

void Player::setPointerIM(bool* im)
{
	this->im = im;
}

void Player::statusplayer()
{
	switch (*this->status)
	{
	case 0:
		// ตาย
		break;
		
	case 1:
		// รอด
		break;
	case 2:
		// กระพริบ
		break;
	case 3:
		break;
		//อมตะ
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
	if (*this->Gamepause == false)
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
		this->body.setScale(0.9f,1.0f);
		
		if (this->onhole == true && *this->status==1&& *this->im==false) {
			this->body.move(0, 14);
		}
		else
		{
			this->body.setPosition(200.0f, 510.0f);
		}
		if (this->body.getPosition().y > 800 ) {
			//this->die = true;
		
			*this->status = 0;
			//cout << "DIE" << endl;
		}
	}
	else if(statejump==0){
		//cout << "do" << endl;
		stateanimation = 0;
		this->body.setScale(0.9f, 1.0f);
		if (this->status != 0 && this->onhole==false) {
			this->body.setPosition(200.0f, 490.0f);
		}
		else if (this->onhole == true && *this->status==1 && *this->im == false){
			this->body.move(0, 15); //// สั่งให้ตก แต่ว่าไม่ได้
		}
		if (this->body.getPosition().y > 800) {
			*this->status = 0;
		//	cout << "DIE" << endl;
		}
		
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
		if (this->onhole==true && *this->status==1 && *this->im == false) {
			//cout << "ONHOLE" << endl;
			if (this->body.getPosition().y > 800) {
				//this->body.setPosition(200.0f, 490.0f);
				*this->status = 0;
				this->stateanimation = 0;
				this->A = 10;
				this->statejump = 0;
				this->jumphight = false;
			}
		}
		else {
			if (this->body.getPosition().y > 500) {
				this->body.setPosition(200.0f, 490.0f);
				this->stateanimation = 0;
				this->A = 10;
				this->statejump = 0;
				this->jumphight = false;
			}
		}

	}
	
}
