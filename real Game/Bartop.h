#include"AllInOne.h"
class Bartop
{
public:
	Bartop();
	void DRAW(RenderWindow *window);
	void update_hp(float hp);
	void pair(bool* P);
	void drawscore(unsigned long *P);
	void setimmortal(bool state);
private:

	Font font;
	Text text_score;
	Texture texture_immortal[7];
	Sprite spri_immortal[8];
	Texture texture_BGimmortal;
	Sprite spri_BGimmortal;
	Texture texture_bgblood;
	Sprite spri_bgblood;
	Texture texture_blood[2];
	Sprite spri_blood;
	Texture texture_heart;
	Sprite spri_heart;
	Texture texture_BIG;
	Sprite spri_BIG;
	IntRect rect;
	bool* bool_immortal;
};

