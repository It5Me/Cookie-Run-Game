#include"AllInOne.h"
#include"Playback.h"
#include"Map.h"
int main() {
	RenderWindow window(VideoMode(size_width, size_height), name_game, Style::Close);
	window.setFramerateLimit(120);
	Playback sound;
	Event event;
	MAP map;
	
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
		window.display();
	}



}