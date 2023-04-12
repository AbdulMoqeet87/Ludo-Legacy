#include "Dice.h"
#include"board.h"
#include<SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
using namespace sf;
using namespace std;
//
//Dice::Dice()
//{
//	this->DiceValue = 0;
//	Tex.loadFromFile("diceroll.png");
//	dice.setSize(Vector2f(100, 100));
//	dice.setPosition(1150, 500);
//	dice.setTexture(&Tex);
//	TextureSize = Tex.getSize();
//	TextureSize.x /= 15;
//	TextureSize.y /= 6;
//}
int Dice::getDiceValue()
{
	return this->DiceValue;
}
//void Dice::rollDice(board* B,RenderWindow& window)
//{
//	srand(time(0));
//	this->DiceValue = rand() % 6 + 1;
//	int r= rand() % 4;
//	for (int c = 0; c < 15; c++)
//	{
//		window.clear();
//		if (c <= 7)
//			dice.setPosition(1050 + (c * 8), 530 - (c * 8));
//		else
//			dice.setPosition(1060 + (c * 8), 410 + (c * 8));
//		dice.setTextureRect(IntRect(TextureSize.x * c, TextureSize.y * r, TextureSize.x, TextureSize.y));
//		window.draw(dice);
//		B->drawBoard(window);
//		window.display();
//		for (long long i = 0; i < 100000000; i++);
//	}
//	window.clear();
//}
//
//void Dice::drawDice(RenderWindow& window)
//{
//	switch (this->DiceValue)
//	{
//	case 1:
//		dice.setTextureRect(IntRect(TextureSize.x * 14, TextureSize.y * 1, TextureSize.x, TextureSize.y));
//		break;
//	case 2:
//		dice.setTextureRect(IntRect(TextureSize.x * 10, TextureSize.y * 1, TextureSize.x, TextureSize.y));
//		break;
//	case 3:
//		dice.setTextureRect(IntRect(TextureSize.x * 14, TextureSize.y * 2, TextureSize.x, TextureSize.y));
//		break;
//	case 4:
//		dice.setTextureRect(IntRect(TextureSize.x * 12, TextureSize.y * 5, TextureSize.x, TextureSize.y));
//		break;
//	case 5:
//		dice.setTextureRect(IntRect(TextureSize.x * 2, TextureSize.y * 1, TextureSize.x, TextureSize.y));
//		break;
//	case 6:
//		dice.setTextureRect(IntRect(TextureSize.x * 6, TextureSize.y * 1, TextureSize.x, TextureSize.y));
//		break;
//	}
//	dice.setPosition(1150, 500);
//	window.draw(dice);
//	cout << DiceValue << endl;
//}


Dice::Dice()
{
	this->DiceValue = 0;
	Tex.loadFromFile("rollDice.png");
	dice.setSize(Vector2f(120, 120));
	dice.setPosition(1150, 500);
	dice.setTexture(&Tex);
	TextureSize = Tex.getSize();
	TextureSize.x /= 3;
	TextureSize.y /= 3;
}

void Dice::rollDice(board* B, RenderWindow& window)
{
	srand(time(0));
	this->DiceValue = rand() % 6 + 1;
	//int r= rand() % 4;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			for (long long i = 0; i < 100000000; i++);
			window.clear();
			if (r < 2)
				dice.setPosition(1150 , 530 - (c * 30));
			else
				dice.setPosition(1150 , 500 + (c * 8));
			dice.setTextureRect(IntRect(TextureSize.x * c, TextureSize.y * r, TextureSize.x, TextureSize.y));
			window.draw(dice);
			B->drawBoard(window);
			window.display();
		}
	}
	window.clear();
}

void Dice::drawDice(RenderWindow& window)
{
	string filename;
	switch (this->DiceValue)
	{
	case 1:
		filename = "dice1.png";
		break;
	case 2:
		filename = "dice2.png";
		break;
	case 3:
		filename = "dice3.png";
		break;
	case 4:
		filename = "dice4.png";
		break;
	case 5:
		filename = "dice5.png";
		break;
	case 6:
		filename = "dice6.png";
		break;
	}
	TexPic.loadFromFile(filename);
	D.setTexture(TexPic);
	D.setScale(0.2, 0.2);
	//dice.setSize(Vector2f(100, 100));
	D.setPosition(1150, 500);
	window.draw(D);
}