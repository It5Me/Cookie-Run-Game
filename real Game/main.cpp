#include"AllInOne.h"
#include"Playback.h"
#include"Map.h"
#include"Player.h"
#include"Items.h"
void collis(Player* P, Items* I)
{
	if (abs(P->getposition().x - I->getposition().x) <= P->gethalfsize().x + I->gethalfsize().x/2
		&& abs(P->getposition().y - I->getposition().y) <= P->gethalfsize().y + I->gethalfsize().y/2) {
		cout << "chon" << endl;
		I->hide();
	}
}
int main() {
	RenderWindow window(VideoMode(size_width, size_height), name_game, Style::Close);
	window.setFramerateLimit(120);
	Playback sound;
	Event event;
	MAP map;
	Player player1;
	Texture ITEM1;
	ITEM1.loadFromFile("Texture\\item\\item1.png");
	//cout << "EIEI" << endl;
	vector<Items> item1;
	Items* temp;
	for (int i = 0; i < 10; i++)
	{
		temp = new Items(ITEM1, 200, 9, Vector2f(1000.0 + (i*500), 500.0f));
		item1.push_back(*temp);
		//cout << item1[i].getposition().x << endl;
	}

	//Items item2(ITEM1, 100,9,Vector2f(1500.0f,500.0f));

	
	while (window.isOpen()) {
		if (Keyboard::isKeyPressed(Keyboard::T)) {
			sound.playEffect();
		}
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		
		window.clear();
		map.DRAW(&window);
		player1.DRAW(&window);
		for (int i = 0; i < 10; i++)
		{
			item1[i].DRAW(&window);
			//cout << player1.getposition().x << " " << player1.getposition().y << endl;
			//cout << item1[i].gethalfsize().x/2 << " " << item1[i].gethalfsize().y/2 << endl;
			collis(&player1,&item1[i]);
			
		}
		//item2.DRAW(&window);
		window.display();
	}



}