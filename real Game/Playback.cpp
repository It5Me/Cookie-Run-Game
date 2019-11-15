#include "Playback.h"

Playback::Playback()
{
	this->coin_e.loadFromFile("sound/coin.wav");
	this->_music.openFromFile("sound\\Battle1.ogg");
	this->_music.setVolume(50);
	this->_music.setLoop(true);
	this->_music.play();
	this->_effect.loadFromFile("sound\\potion3.wav");
	this->_Effect.setBuffer(this->_effect);
	this->Coin_s.setBuffer(this->coin_e);
	this->Coin_s.setVolume(30);
}

void Playback::playEffect()
{
	this->_Effect.play();
}

void Playback::playcoin()
{
	this->Coin_s.play();
}
