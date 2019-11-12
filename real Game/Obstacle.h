#pragma once
#include"SFML/Graphics.hpp"
using namespace sf;
#include<iostream>
using namespace std;


class Obstacle
{
public:
	Obstacle(Texture texture, float x, int type);
	~Obstacle();
	void draw(RenderWindow* window);
	bool isDelete();
	void move();
	Vector2f getposition();
	Vector2f gethalfsize();
private:
	
	int type;
	Sprite spribody;
	Texture texturebody;
};


