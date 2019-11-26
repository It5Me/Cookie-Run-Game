#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
using namespace std;
using namespace sf;

class Playback
{
public:
	Playback();
	void playEffect();
	void playcoin();
	void playclick();
private:
	Music _music;
	SoundBuffer _effect,coin_e,click;
	Sound _Effect, Coin_s,click_s;
};

