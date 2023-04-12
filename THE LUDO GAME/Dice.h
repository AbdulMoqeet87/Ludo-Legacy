#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class board;

class Dice
{
private:
	int DiceValue;
	Texture Tex;
	RectangleShape dice;
	Texture TexPic;
	Sprite D;
	Vector2u TextureSize;
public:
	Dice();
	int getDiceValue();
	void rollDice(board* B, RenderWindow& window);
	void drawDice(RenderWindow& window);
};

