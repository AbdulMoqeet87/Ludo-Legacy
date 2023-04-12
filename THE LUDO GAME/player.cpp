#include "player.h"
#include<fstream>
#include<SFML/Graphics.hpp>
#include<string>
using namespace sf;
using namespace std;

player::player(string _name, Color _C, bool _isWin, bool _isKill)
{
	this->Name = _name;
	this->C = _C;
	this->IsWin = _isWin;
	this->HasKilled = _isKill;
}
Color player::getColor()
{
	return this->C;
}

string player::getName()
{
	return this->Name;
}

bool player::isWin()
{
	return IsWin;
}

bool player::hasKilled()
{
	return HasKilled;
}

void player::setIsWin(bool _win)
{
	this->IsWin = _win;
}

void player::setHasKilled(bool _kill)
{
	this->HasKilled = _kill;
}