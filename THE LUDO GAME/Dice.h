#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<vector>
using namespace sf;

class board;
class player;
class Dice
{
private:
	int DiceValue;
	Texture Tex;
	RectangleShape dice;
	Texture TexPic;
	Sprite D;
	Texture Dh;
	Sprite DiceHigh;
	SoundBuffer DR;
	Sound DiceRoll;
	Vector2u TextureSize;
	int ri, ci;
public:
	Dice(int r, int c);
	int getDiceValue();
	void rollDice(board* B, RenderWindow& window,Sprite BG,int NOP,std::vector<int> JootaIndx, std::vector<player*> WinPs);
	void drawDice(RenderWindow& window);
	void setDiceValue(int d);
	bool isClicked(int ri, int ci);
	void HighlightDice(sf::RenderWindow& window);
	bool Contains(int ri, int ci);

	//void drawDiceNum(RenderWindow& window, int ri, int ci);

};

