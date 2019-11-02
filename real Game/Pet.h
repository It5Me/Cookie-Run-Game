#include"AllInOne.h"

class Pet
{
public:
	Pet();
	void DRAW(RenderWindow *window);
	void selectcharacteranimal(int index);
	void SETposition(Vector2f pos);
private:
	void update();
	int selectanimal;
	float a = 3000;
	Texture texture_animal[4];
	Sprite spri_body;
	IntRect rect;
	float totaltime = 0;
	Clock clock;
	int x=0;

};

