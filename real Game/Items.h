#include"AllInOne.h"
class Items
{	
public:
	Items(Texture texture,int score,int countx,Vector2f pos,int type);
	void DRAW(RenderWindow* window);
	void hide();
	int gettype();
	int getscore();
	Vector2f getposition();
	Vector2f gethalfsize() { return Vector2f(this->Texturebody.getSize().x/ this->countx / 4.0f, this->Texturebody.getSize().y / 4.0f); };
private:
	int type;
	Texture Texturebody;
	Sprite body;
	int score;
	void update();
	float totaltime = 0;
	IntRect rec;
	Clock clock;
	int x=0;
	int countx;
};

