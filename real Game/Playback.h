#include"AllInOne.h"
class Playback
{
public:
	Playback();
	void playEffect();
	void playcoin();
private:
	Music _music;
	SoundBuffer _effect,coin_e;
	Sound _Effect,Coin_s;
};

