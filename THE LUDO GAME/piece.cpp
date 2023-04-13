#include "piece.h"
#include<iostream>
#include<fstream>
using namespace std;

piece::piece(istream&Rdr, sf::Color _C,string Cn)
{
	Rdr >> ci;
	Rdr>> ri;
	this->C = _C;
	this->P.loadFromFile(Cn);
	this->Pc.setTexture(P);
	Pc.setPosition(ci, ri);
}
piece::piece(int c,int r, sf::Color _C,string Cn)
{
	this->ci = c, this->ri = r;
	this->C = _C;
	this->P.loadFromFile(Cn);
	this->Pc.setTexture(P);
	Pc.setPosition(ci, ri);
}

void piece::Draw(sf::RenderWindow& window)
{	
	window.draw(Pc);
}

Color piece::getColor()
{
	return C;
}
bool piece::Contains(int r, int c)
{
	if (this->Pc.getGlobalBounds().contains(c, r))
		return true;
	return false;
}

void piece::setPosition(int ci, int ri)
{
	Pc.setPosition(ci, ri);
}