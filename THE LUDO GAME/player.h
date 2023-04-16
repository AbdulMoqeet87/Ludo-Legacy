#pragma once
#include<fstream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include<string>
using namespace sf;
using namespace std;

 class player
{
private:
	Color C;
	string Name;
	bool IsWin;
	bool HasKilled;
	bool CanMove;
public:
	player(string _name, Color, bool _isWin = false, bool _isKill = false, bool _CanMove = false);
	Color getColor();
	string getName();
	bool isWin();
	bool hasKilled();
	void setIsWin(bool _win);
	void setHasKilled(bool _kill);
	bool canMove();
	void setCanMove(bool _Move);
};

