#pragma once
#include"board.h"
#include<SFML/Graphics.hpp>


class board;
class player;
class Dice;

class Ludo
{
private:
	Dice* dice;
	Dice* Ds[3];
	board* B;
	player* Ps[6];
	int Turn;
	int sri;
	int sci;
public:
	Ludo();
	void turnChange();
	bool isValidSc(int &indx);
	void play(sf::RenderWindow& window);
	void RollDice(sf::RenderWindow& window, int& di);
	void DrawDice(sf::RenderWindow& window);
	void Move(int indx, int DiceIndx);
	bool clickedDice();
	bool canMove();
	void selectDiceValue(int& DiceIndx);

};

