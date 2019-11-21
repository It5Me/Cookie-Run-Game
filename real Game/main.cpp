﻿#include"AllInOne.h"
#include"Playback.h"
#include"Map.h"
#include"Player.h"
#include"Menu.h"
#include "Pet.h"
#include"Bartop.h"	
#include<stdlib.h>
#include<time.h>
#include"endgame.h"
#include"Pausepage.h"




int collis(Player* P, Items* I)
{
	if (abs(P->getposition().x - I->getposition().x) <= P->gethalfsize().x + I->gethalfsize().x/2
		&& abs(P->getposition().y - I->getposition().y) <= P->gethalfsize().y + I->gethalfsize().y/2) {
		//cout << "chon" << endl;
		I->hide();
		return I->gettype();
	}
	return -1;
}
int main() {

	
	bool gamepause = false;
	srand(time(NULL));
	RenderWindow window(VideoMode(size_width, size_height), name_game, Style::Close);
	window.setFramerateLimit(120);
	Pausepage pausepage;
	pausepage.setpointer(&gamepause);
	Playback sound;
	Pet pet;
	Event event;
	int indexMap = 0;
	float HP = 100;
	int statusplayer = 1;
	MAP map(&indexMap);
	map.setpointergamepause(&gamepause);
	Player player1;
	player1.gamepause(&gamepause);
	player1.setpointerstatusplayer(&statusplayer);
	map.setpointerstatusplayer(&statusplayer);
	map.setpointerhp(&HP);
	endgame END(&event);
	
	Bartop bartop;
	
	//float posy; // player.position.y
	//cout << "main Address :" << &posy << endl;
	Vector2f positionplayer;
	//player1.getposplayer(&posy);
	//map.sendposplayer(&posy);
	player1.setpointerpositionplayer(&positionplayer);
	map.setpointerpositionplayer(&positionplayer);
	Texture ITEM1;
	Texture ITEM2;
	Texture ITEM3; // test object
	Texture immortal[8];
	immortal[0].loadFromFile("Texture\\item\\font_I.png");
	immortal[1].loadFromFile("Texture\\item\\font_M.png");
	immortal[2].loadFromFile("Texture\\item\\font_M.png");
	immortal[3].loadFromFile("Texture\\item\\font_O.png");
	immortal[4].loadFromFile("Texture\\item\\font_R.png");
	immortal[5].loadFromFile("Texture\\item\\font_T.png");
	immortal[6].loadFromFile("Texture\\item\\font_A.png");
	immortal[7].loadFromFile("Texture\\item\\font_L.png");
	int index_immortal=0;
	bool bool_immortal[8] = { 0,0,0,0,0,0,0,0 };
	bool bool_big = false;
	bartop.pair(bool_immortal);
	Menu menu;	
	unsigned long main_score=0; // ************score********
	map.main_score = &main_score;
	int tempcolision = 0;
	END.setpointscore(&main_score);
	Clock clock_runaway;
	float totalrunaway = 0;
	ITEM1.loadFromFile("Texture\\item\\testbear-01.png"); //////////////////////////////////
	//ITEM2.loadFromFile("Texture/item/objecttest.png");
	//ITEM3.loadFromFile("Texture\\item\\objecttest.png");
	
	//cout << "EIEI" << endl;
	
	vector<Items> item1;
	vector<Items>::iterator it;
	vector<Items>::iterator tempit;
	bool haveDel = false;
	Clock clockSpawn;
	float totalSpawn = 0.0;
	Items* temp;
	float j = 20;
	/*for (int i = 0; i < 4; i++)
	{
		//cout << 590.0 - abs(sin(j) * 100) << endl;
		if (i % 3 == 0) {
			index_immortal = rand()%7;
			temp = new Items(immortal[index_immortal], 49, 1, Vector2f(1000.0 + (i * 100), 590.0 - abs(sin(j / 2) * 250)), index_immortal);
//
		}
		else {
			temp = new Items(ITEM1, 123, 4, Vector2f(1000.0 + (i * 100), 590.0 - abs(sin(j / 2) * 250)), ID_testbear);
		}
		item1.push_back(*temp);
		j = (j < 0 ? 0 : j -0.5);
		//cout << item1[i].getposition().x << endl;
	}
	temp = new Items(ITEM2, 123, 1, Vector2f(1000.0 + (5 * 100), 590.0 - abs(sin(j / 2) * 250)), ID_BIG);
	item1.push_back(*temp);
	int tempi = 8;
	//Items item2(ITEM1, 100,9,Vector2f(1500.0f,500.0f));
	*/
	///////////////////////TESTJAAAAAAA
	

	
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
		pet.selectcharacteranimal(menu.select_animal());
		pet.SETposition(player1.getposition());
		player1.selectcharacter(menu.select_player());
		player1.checkhole(map.checkonhole());
		window.clear();
		if (menu.check() == true) { // in game

			if (Keyboard::isKeyPressed(Keyboard::Escape) && gamepause==false ) {
				cout << "PRESSESC" << endl;
				gamepause = true;
			}

			if (player1.checkdie() && END.getstatus() == false) {//playerdie/////////////
				map.setdie(true);
				END.setstatus(true);
				//endgame-> 0 1 
			}
			
			bartop.drawscore(&main_score);
			totalrunaway += clock_runaway.restart().asSeconds();
			
			if (totalrunaway > 0.01 && END.getstatus()==false&&gamepause==false) {
				totalrunaway = 0;
				HP -= 0.01;     ///////////////// เลือดลด
				main_score++;                  //////////// score + alltime
				//cout << main_score << endl;
			}
			map.DRAW(&window);
			player1.DRAW(&window);
			pet.DRAW(&window);
			bartop.DRAW(&window);
			bartop.update_hp(HP);
			if (Keyboard::isKeyPressed(Keyboard::Z)) {
				HP += 10;
				if (HP > 100) {
					HP = 100;
				}
				//cout << "sdsdsdsd" << endl;
				
			}
			/*if (map.checkSpwan())
			{

				temp = new Items(ITEM1, 123, 4, Vector2f(1000.0 + (tempi * 100), 590.0 - abs(sin(j / 2) * 250)), ID_testbear);
				item1.push_back(*temp);
				j = (j < 0 ? 0 : j - 0.5);
				//cout << "Add" << endl;
			}*/

			// start stop step
			if (END.getstatus() == false&&gamepause==false)
			{
				
				for (it = item1.begin(); it != item1.end(); ++it)
				{
					it->DRAW(&window);     //
					//cout << player1.getposition().x << " " << player1.getposition().y << endl;
					//cout << item1[i].gethalfsize().x/2 << " " << item1[i].gethalfsize().y/2 << endl;
					tempcolision = collis(&player1, &*it);
					if (tempcolision != -1)
					{
						sound.playcoin();
						switch (tempcolision) // ตรวจสอบการชน
						{
						case ID_i: //cout << "I" << endl;
							bool_immortal[ID_i] = true;
							break;
						case ID_m://cout << "M" << endl;
							if (bool_immortal[ID_m] == false) {
								bool_immortal[ID_m] = true;
							}
							else {
								bool_immortal[ID_m + 1] = true;
							}
							break;
						case ID_o://cout << "O" << endl;
							bool_immortal[ID_o] = true;
							break;
						case ID_r://cout << "R" << endl;
							bool_immortal[ID_r] = true;
							break;
						case ID_t://cout << "T" << endl;
							bool_immortal[ID_t] = true;
							break;
						case ID_a://cout << "A" << endl;
							bool_immortal[ID_a] = true;
							break;
						case ID_l://cout << "L" << endl;
							bool_immortal[ID_l] = true;
							break;
						case ID_BIG:
							bool_big = true;
							cout << "big" << endl;
							break;

						}
						main_score += it->getscore(); // chon!!
						haveDel = true;
						tempit = it;
						//cout << "size item : " <<item1.size() << endl;
						//cout << main_score << endl;
					}
					if (it->getposition().x < 0)
					{
						haveDel = true;
						tempit = it;
						//cout << "Del" << endl;
					}
				}
			}
			
			if (haveDel == true) // ต้องลบสักตัว
			{
				haveDel = false;
				item1.erase(tempit);
			}
			if (bool_big == true) {
				player1.setBig();
			}
			if (gamepause == true&&END.getstatus()==false) {
				pausepage.draw(&window);
				if (pausepage.checkclickforward() == true) {
					pausepage.reset();
					END.setstatus(true);
					// gamepause = false;
				}
			}
			if (END.getstatus()==true){
				
				END.draw(&window);
				if (END.ismenustart() == true) {
					menu.setstart();
					END.setstatus(false);
					player1.reset();
					map.reset();
					main_score = 0;
					gamepause = false;
					menu.loadfile();
				}
			}
		}
		else {
			menu.DRAW(&window);
		}

		

		//item2.DRAW(&window);*/
		window.display();
	}



}