#include "home.h"
#include"cell.h"
#include<SFML/Graphics.hpp>
#include<string>
using namespace sf;
using namespace std;

home::home(istream& rdr, int IP, int SP,Color _C,string fileName)
{
	this->InitialPos = IP;
	this->SafeSpot = SP;
	this->C = _C;
	int ci, ri;

	rdr >> ri >> ci;
	Background = new Cell(ci, ri, 235,_C);
	Background->setOutlClr(sf::Color::White);
	Background->setOutlSize(5);
	sf::Texture Tex;
	Tex.loadFromFile(fileName);
	Pic.setTexture(Tex);
	Pic.setPosition(350, 10);
	Pic.setScale(0.7, 0.7);
	Cs = new Cell * [5];
	for (int i = 0; i < 5; i++)
	{
		Cs[i] = new Cell(rdr, C);
	}



}

int home::getSafeSpot()
{
	return SafeSpot;
}

int home::getInitialPos()
{
	return InitialPos;
}
void home::Draw(RenderWindow& window)
{
	window.draw(Pic);
	for (int i = 0; i < 5; i++)
	{
		Cs[i]->Draw(window);
	}

}