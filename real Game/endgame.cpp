#include "endgame.h"

endgame::endgame(Event* event)
{
	this->event = event;
	this->textureendgame.loadFromFile("Texture/menu/bgendgame.png");
	this->bgendgame.setTexture(this->textureendgame);
	this->bgendgame.setPosition(550, 200);
	this->texturebtn.loadFromFile("Texture/menu/btnendgame.png");
	this->btn.setTexture(this->texturebtn);
	this->btn.setPosition(650, 600);
	this->font.loadFromFile("font\\SOV_monomon-hinted.ttf");
	this->textscore.setFont(this->font);
	this->textscore.setCharacterSize(80);
	this->textscore.setFillColor(Color::Black);
	this->textscore.setStyle(Text::Bold);
	this->textscore.setString("99999999");
	this->textscore.setPosition(600,400);

	object.setSize(sf::Vector2f(300.0f, 70.0f));
	object.setOrigin(sf::Vector2f(150.0f, 35.0f));
	object.setPosition(sf::Vector2f(800, 350.0f));
	cursor.setSize(sf::Vector2f(5.0f, 64.0f));
	cursor.setOrigin(sf::Vector2f(2.5f, 32.0f));
	cursor.setPosition(sf::Vector2f(655, 350.0f));
	cursor.setFillColor(sf::Color::Black);
	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);
	text.setPosition(650, 325);

	
}

void endgame::draw(RenderWindow* window)
{
	if (event->type == sf::Event::EventType::TextEntered)
	{

		if (last_char != event->text.unicode && event->text.unicode == 8 &&
			input.length() > 0) // delete
		{

			last_char = event->text.unicode;
			input.erase(input.length() - 1);
			text.setString(input);
			cursor.setPosition(650.0f + text.getGlobalBounds().width + 5, 350.0f);
			std::cout << input << std::endl;

		}
		else if (last_char != event->text.unicode &&
			(event->text.unicode >= 'a' && event->text.unicode <= 'z' ||
				event->text.unicode >= 'A' && event->text.unicode <= 'Z' ||
				event->text.unicode >= '0' && event->text.unicode <= '9')&&input.length()<8)
		{
			//std::cout << event.text.unicode << std::endl;
			last_char = event->text.unicode;

			input += event->text.unicode;

			text.setString(input);

			cursor.setPosition(650.0f + text.getGlobalBounds().width + 5, 350.0f);

			//std::cout << input << std::endl;
		}

	}

	if (event->type == sf::Event::EventType::KeyReleased && last_char != ' ')
	{
		last_char = ' ';
	}

	

	loadscore();
	checkbtn(window);
	this->textscore.setString(this->tempscore);
	window->draw(this->bgendgame);
	window->draw(this->btn);
	window->draw(this->textscore);
	window->draw(object);

	totalTime += clocka.restart().asSeconds();
	if (totalTime >= 0.5)
	{
		totalTime = 0;
		statea = !state;
	}
	if (statea == true)
	{
		window->draw(cursor);
	}

	window->draw(text);
}

void endgame::setstatus(bool state)
{
	if (state == false) {
		this->statemenu=false;
		this->loadscorecomplete = false;
		this->tempscore = "        ";
		this->index = 0;
		this->input.clear();
		this->scorea.clear();
		this->input.clear();
		this->text.setString(this->input);
		statea = false;
		tempInt = 0;
		P = 1;
		cursor.setPosition(sf::Vector2f(655, 350.0f));
	}
	else
	{
		//cout << "kdfkfgkf" << endl;
		*this->score *= 1.20;
		this->mainscore = to_string(*this->score);
		reverse(this->mainscore.begin(),this->mainscore.end());
		
		//cout << this->mainscore << endl;
	}
	this->status = state;
}

bool endgame::getstatus()
{
	return this->status;
}

bool endgame::ismenustart()
{
	return this->statemenu;
}

void endgame::setpointscore(unsigned long* t)
{
	this->score = t;
}

void endgame::loadscore()
{
	if (this->loadscorecomplete == false) {
		this->totaltime += clock.restart().asSeconds();
		this->tempscore[this->index] = '0'+rand()%10;
		if (this->totaltime > 0.5) {
			this->totaltime = 0;
			//if(this->mainscore)
			if (this->mainscore[7 - index] >= '0' && this->mainscore[7 - index] <= '9') {
				this->tempscore[this->index] = this->mainscore[7 - index];
			}
			else {
				this->tempscore[this->index] = '#';
			}
			this->index++;
			if (this->index == 8) {
				
				this->loadscorecomplete = true;
			}
		}
	}
}

void endgame::checkbtn(RenderWindow* window)
{
	if (Mouse::getPosition(*window).x > 650 &&
		Mouse::getPosition(*window).x < 950 &&
		Mouse::getPosition(*window).y>600 &&
		Mouse::getPosition(*window).y < 680) {
		//cout << "dlld" << endl;
		this->hold = true;
		if (Mouse::isButtonPressed(Mouse::Left)&& this->statemenu==false&&this->input.length()>0) {
			myFile.open("database/score.txt",ios::in);
			while (getline(myFile, temp))
			{
				if (state == false)
				{
					cout << temp << endl;
					tempString = temp;
				}
				else
				{
					for (int i = temp.length() - 1; i >= 0; i--, P *= 10)
					{
						tempInt += (temp[i] - '0') * P;
					}
					scorea.push_back(make_pair(tempInt, tempString));
					P = 1;
					tempInt = 0;
				}
				state = !state;
				//cout << Temp << endl;
			}
			for (int i = 0; i < 5; i++) {
				cout << scorea[i].first << " " << scorea[i].second << endl;
			}
			myFile.close();
			scorea.push_back(make_pair(*score, input));
			sort(scorea.begin(), scorea.end());
			cout << "AFTER" << endl;
			for (int i = 0; i < 6; i++) {
				cout << scorea[i].first << " " << scorea[i].second << endl;
			}
			myFile.open("database/score.txt",ios::out);
			for (int i = 5; i >= 1; i--)
			{
				myFile << scorea[i].second << "\n" << scorea[i].first << endl;
				//cout << scorea[i].first << " -- " << scorea[i].second << endl;
			}
			cout << scorea.size() << endl;
			myFile.close();
			this->statemenu = true;
			cout << "Click" << endl;
		}
	}
	else {
		this->hold = false;
	}
}
