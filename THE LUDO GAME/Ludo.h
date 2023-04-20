#pragma once
#include"board.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include<vector>

class board;
class player;
class Dice;

class Ludo
{
private:
	Dice* dice;
	Dice* Ds[3];
	board* B;
	player** Ps;
	int NOP;
	int Turn;
	int sri;
	int sci;
	bool hasmoved;
	sf::SoundBuffer* S;
	sf::Sound *sounds;
	sf::Sprite BackG;
	sf::Texture BG;
	std::vector<player*> WinPs;
	sf::Sprite Win;
	sf::Texture WinTex;
	sf::RectangleShape DHi;

	std::vector<int> JootaIndx;
public:
	Ludo();
	Ludo(int _NOP);
	void turnChange();
	bool isValidSc(int &indx, int DiceIndx);
	bool isLegalMove(int indx, int DiceIndx,bool& isCancelled);
	//bool isValidSc(int &indx);
	void play(sf::RenderWindow& window, int &ending);
	void RollDice(sf::RenderWindow& window, int di);
	void DrawDice(sf::RenderWindow& window);
	void  Move(int indx, int DiceIndx, sf::RenderWindow &winidow);
	bool clickedDice();
	bool canMove();
	void selectDiceValue(int& DiceIndx);
	bool DiceIsEmpty();
	void EraseDice();
	bool AllSix();
	bool isWin();
	bool GameEnded();
};

