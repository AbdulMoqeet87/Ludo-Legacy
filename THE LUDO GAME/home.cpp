#include "home.h"
#include"cell.h"
#include<SFML/Graphics.hpp>
#include<string>
using namespace sf;
using namespace std;

home::home(istream& rdr, int IP, int SP,Color _C,string fileName,int pic_c,int pic_r)
{
	this->InitialPos = IP;
	this->SafeSpot = SP;
	this->C = _C;
		

	rdr >> ci >> ri;
	Background = new Cell(ri, ci, 235,_C);
	Background->setOutlSize(5);
	Background->setOutlClr(sf::Color::Blue);
	//sf::Texture Tex;
	Tex.loadFromFile(fileName);
	Pic.setTexture(Tex);
	Pic.setPosition(pic_c+40, pic_r+40);
	Pic.setScale(0.7, 0.7);
	Cs = new Cell * [5];
	for (int i = 0; i < 5; i++)
	{
		Cs[i] = new Cell(rdr, C);
	}
	Circ.loadFromFile("WhiteCircle.png");
	Circles = new Sprite[4];
	for(int i=0;i<4;i++)
	Circles[i].setTexture(Circ);
		
	
	Circles[0].setPosition(ci + 53, ri + 52);
	Circles[1].setPosition(ci + 213, ri + 52);
	Circles[2].setPosition(ci + 53, ri + 213);
	Circles[3].setPosition(ci + 213, ri + 213);
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
	Background->Draw(window);
	window.draw(Pic);
	window.draw(Circles[0]);
	window.draw(Circles[1]);
	window.draw(Circles[2]);
	window.draw(Circles[3]);

	for (int i = 0; i < 5; i++)
	{
		Cs[i]->Draw(window);
	}

}

bool home::IsSafeSpot(int indx)
{
	if (indx == SafeSpot)
		return true;
	return false;
}
bool home::IsInitSpot(int indx)
{
	if (indx == InitialPos)
		return true;
	return false;
}
sf::Color home::getHOmeColor()
{
	return this->C;
}
int home::getRow()
{
	return ri;
}
int home::getCol()
{
	return ci;
}

bool home::clickedHomePiece(int ri,int ci,int& pi)
{
	for (int i = 0; i < 4; i++)
	{
		if (Circles[i].getLocalBounds().contains(ri, ci));
	}
	return 0;
}

