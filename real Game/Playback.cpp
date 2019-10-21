#include "Playback.h"

Playback::Playback()
{
	this->_music.openFromFile("sound\\Battle1.ogg");
	this->_music.setVolume(20);
	this->_music.setLoop(true);
	this->_music.play();
	this->_effect.loadFromFile("sound\\potion3.wav");
	this->_Effect.setBuffer(this->_effect);
}

void Playback::playEffect()
{
	this->_Effect.play();
}
