#include "Playback.h"

Playback::Playback()
{
	
	this->click.loadFromFile("sound/click.wav");
	this->coin_e.loadFromFile("sound/coin.wav");
	this->_music.openFromFile("sound\\Battle1.ogg");
	this->_music.setVolume(50);
	this->_music.setLoop(true);
	this->_music.play();
	this->_effect.loadFromFile("sound\\potion3.wav");
	this->_Effect.setBuffer(this->_effect);
	this->Coin_s.setBuffer(this->coin_e);
	this->Coin_s.setVolume(30);
	this->click_s.setBuffer(this->click);
	this->click_s.setVolume(40);
}

void Playback::playEffect()
{
	this->_Effect.play();
}

void Playback::playcoin()
{
	this->Coin_s.play();
}

void Playback::playclick()
{
	this->click_s.play();
}
