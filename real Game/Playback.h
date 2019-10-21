#include"AllInOne.h"
class Playback
{
public:
	Playback();
	void playEffect();
private:
	Music _music;
	SoundBuffer _effect;
	Sound _Effect;
};

