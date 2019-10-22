#include"AllInOne.h"
#include"Playback.h"
#include"Map.h"
#include"Player.h"
#include"Items.h"
int main() {
	RenderWindow window(VideoMode(size_width, size_height), name_game, Style::Close);
	window.setFramerateLimit(120);
	Playback sound;
	Event event;
	MAP map;
	Player player1;
	Texture ITEM1;
	ITEM1.loadFromFile("Texture\\item\\item1.png");

	vector<Items> item1;
	Items* temp;
	for (int i = 0; i < 20; i++)
	{
		temp = new Items(ITEM1, 200, 9, Vector2f(1000.0 + (i*500), 500.0f));
		item1.push_back(*temp);
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
		}
		//item2.DRAW(&window);
		window.display();
	}



}