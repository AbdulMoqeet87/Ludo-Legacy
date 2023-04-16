#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

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
	SoundBuffer DR;
	Sound DiceRoll;
	Vector2u TextureSize;
	int ri, ci;
public:
	Dice(int r, int c);
	int getDiceValue();
	void rollDice(board* B, RenderWindow& window,Sprite BG,int NOP);
	void drawDice(RenderWindow& window);
	void setDiceValue(int d);
	bool isClicked(int ri, int ci);
	//void drawDiceNum(RenderWindow& window, int ri, int ci);

};

