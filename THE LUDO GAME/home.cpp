#include "home.h"
#include "board.h"
#include "Ludo.h"
#include"cell.h"
#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
using namespace sf;
using namespace std;

home::home(istream& rdr, int IP, int SP,int TP,Color _C,string fileName1, string fileName2,int _pic_c,int _pic_r)
{
	sf::Color greyish_green(64, 96, 64);
	sf::Color dark_yellow(153, 153, 0);
	sf::Color dark_green(0, 100, 0);
	sf::Color maroon(128, 0, 0);
	sf::Color navy_blue(0, 0, 128);
	sf::Color mustard(204, 187, 68);
	sf::Color metallic_grey(139, 139, 131);
	sf::Color dark_grey(64, 64, 64);
	sf::Color golden_yellow(255, 215, 0);
	sf::Color more_yellowish_yellow(255, 255, 51);
	sf::Color purple(128, 0, 128);
	//--------------------------------
	this->InitialPos = IP;
	this->SafeSpot = SP;
	this->TurningPos = TP;
	this->C = _C;
	this->hasKilled = false;
	this->pic_c = _pic_c;
	this->pic_r = _pic_r;
	rdr >> ci >> ri;
	Background = new Cell(ri, ci, 235,_C);
	Background->setOutlSize(5);
	Background->setOutlClr(sf::Color::White);
	//sf::Texture Tex;
	GU.loadFromFile("GateUnlocked_.wav");
	GateUnlocked.setBuffer(GU);
	U.loadFromFile("UfoSound.wav");
	ufo.setBuffer(U);
	Tex.loadFromFile(fileName1);
	Tex2.loadFromFile(fileName2);
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
	//-----------------------------------
	Circles[0].setPosition(ci + 53, ri + 52);
	Circles[1].setPosition(ci + 213, ri + 52);
	Circles[2].setPosition(ci + 53, ri + 213);
	Circles[3].setPosition(ci + 213, ri + 213);
//------------------------------------------
	Arrow.setPointCount(3);
	WinTri.setPointCount(3);

	if(C==maroon)
	{
		int r =Cs[0]->getRow(), c = Cs[0]->getCol();
		Arrow.setPoint(0, sf::Vector2f(c+10, r+10));
		Arrow.setPoint(1, sf::Vector2f(c+30, r+20));
		Arrow.setPoint(2, sf::Vector2f(c+10, r+30));
		Arrow.setFillColor(maroon);
		Arrow.setPosition(0, 40);
		WinTri.setPoint(0, sf::Vector2f(c+245, r));
		WinTri.setPoint(1, sf::Vector2f(c + 307.5, r + 61.5));
		WinTri.setPoint(2, sf::Vector2f(c + 245, r + 123));
		WinTri.setFillColor(maroon);
		
	}
	else if(C==purple)
	{
		int r =Cs[0]->getRow(), c = Cs[0]->getCol();
		Arrow.setPoint(0, sf::Vector2f(c+10, r+10));
		Arrow.setPoint(1, sf::Vector2f(c+20, r+30));
		Arrow.setPoint(2, sf::Vector2f(c+30, r+10));
		Arrow.setFillColor(purple);
		Arrow.setPosition(40, 0);
		
		WinTri.setPoint(0, sf::Vector2f(c-2, r+245));
		WinTri.setPoint(1, sf::Vector2f(c+60.5, r+306.5));
		WinTri.setPoint(2, sf::Vector2f(c+121, r+245));
		WinTri.setFillColor(purple);
	
	}
	else if(C==dark_green)
	{
		int r = Cs[0]->getRow(), c = Cs[0]->getCol();
		Arrow.setPoint(0, sf::Vector2f(c + 10, r + 10));
		Arrow.setPoint(1, sf::Vector2f(c + 20, r + 30));
		Arrow.setPoint(2, sf::Vector2f(c + 30, r + 10));
		Arrow.setPosition(40, 0);
		Arrow.setFillColor(dark_green);
		
		WinTri.setPoint(0, sf::Vector2f(c, r + 245));
		WinTri.setPoint(1, sf::Vector2f(c + 61.5, r + 306.5));
		WinTri.setPoint(2, sf::Vector2f(c + 123, r + 245));
		WinTri.setFillColor(dark_green);

	}
	else if(C==golden_yellow)
	{
		int r =Cs[0]->getRow(), c = Cs[0]->getCol();
		Arrow.setPoint(0, sf::Vector2f(c+30, r+10));
		Arrow.setPoint(1, sf::Vector2f(c+10, r+20));
		Arrow.setPoint(2, sf::Vector2f(c+30, r+30));
		Arrow.setFillColor(golden_yellow);
		Arrow.setPosition(80, 40);
		WinTri.setPoint(0, sf::Vector2f(c - 125, r));
		WinTri.setPoint(1, sf::Vector2f(c - 185.5, r + 61.5));
		WinTri.setPoint(2, sf::Vector2f(c - 125, r + 123));
		WinTri.setFillColor(golden_yellow);
	}
	else if(C==dark_grey)
	{
		int r =Cs[0]->getRow(), c = Cs[0]->getCol();
		Arrow.setPoint(0, sf::Vector2f(c+10, r+30));
		Arrow.setPoint(1, sf::Vector2f(c+20, r+10));
		Arrow.setPoint(2, sf::Vector2f(c+30, r+30));
		Arrow.setFillColor(dark_grey);
		Arrow.setPosition(40, 80);
		WinTri.setPoint(0, sf::Vector2f(c, r - 125));
		WinTri.setPoint(1, sf::Vector2f(c + 61.5, r - 186.5));
		WinTri.setPoint(2, sf::Vector2f(c + 123, r - 125));
		WinTri.setFillColor(dark_grey);

	}
	else if (C == navy_blue)
	{
		int r = Cs[0]->getRow(), c = Cs[0]->getCol();
		Arrow.setPoint(0, sf::Vector2f(c + 10, r + 30));
		Arrow.setPoint(1, sf::Vector2f(c + 20, r + 10));
		Arrow.setPoint(2, sf::Vector2f(c + 30, r + 30));
		Arrow.setFillColor(navy_blue);
		Arrow.setPosition(40, 80);

		WinTri.setPoint(0, sf::Vector2f(c-1, r - 125));
		WinTri.setPoint(1, sf::Vector2f(c + 60.5, r - 185.5));
		WinTri.setPoint(2, sf::Vector2f(c + 122, r - 125));
		WinTri.setFillColor(navy_blue);
		//Arrow.setPosition(40, 80);

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
	window.draw(WinTri);
	if (hasKilled)
		window.draw(Arrow);
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
bool home::IsTurningSpot(int indx)
{
	if (indx == TurningPos)
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

bool home::isHomeCell(int r, int c)
{
	for (int i = 0; i < 5; i++)
	{
		if (Cs[i]->getRow() == r && Cs[i]->getCol() == c)
			return true;
	}
	return false;
}

void home::getHomeCellPos(int i,int& r, int& c)
{
	r = Cs[i]->getRow();
	c = Cs[i]->getCol();
	//r = ri, c = ci;
}

void home::HighlightHome()
{
	sf::Color dark_green(0, 100, 0);
	sf::Color navy_blue(0, 0, 128);
	sf::Color maroon(128, 0, 0);
	if (C == navy_blue)
		Pic.setScale(0.8, 0.8);
	this->Pic.setTexture(this->Tex2);
	if (C == maroon)
	Pic.setPosition(pic_c+34 , pic_r+42 );
	if (C == navy_blue)
	Pic.setPosition(pic_c+20 , pic_r+24 );
	if (C == dark_green)
		Pic.setPosition(pic_c + 36, pic_r + 45);
	this->Background->setOutlClr(sf::Color::Green);
}
void home::UnHighlightHome()
{
	sf::Color navy_blue(0, 0, 128);
	sf::Color dark_green(0, 100, 0);
	if (C == navy_blue)
		Pic.setScale(0.7, 0.7);
	sf::Color maroon(128, 0, 0);
	this->Pic.setTexture(this->Tex);
	if (C == maroon||C==navy_blue||C==dark_green)
	Pic.setPosition(pic_c + 40, pic_r + 40);
	this->Background->setOutlClr(sf::Color::White);
}

void home::Blink(sf::RenderWindow & window,board *b,Ludo *L,Sprite BG,int NOP)
{
	if(!hasKilled)
	{
		ufo.play();
		int j = 0;
		for (int i = 0; i < 10; i++)
		{
			window.clear();
			if (i % 2 == 0)
				Cs[j]->setFill_Cl(sf::Color::Green);
			else
			{
				Cs[j]->setFill_Cl(this->C);
				j++;
			}
			sleep(sf::seconds(0.01));
			window.clear();
			window.draw(BG);
			b->drawBoard(window,NOP);
			L->DrawDice(window);
			window.display();

		}
		j--;
		for (int i = 0; i < 10; i++)
		{
			window.clear();
			if (i % 2 == 0)
				Cs[j]->setFill_Cl(sf::Color::Green);
			else
			{
				Cs[j]->setFill_Cl(this->C);
				j--;
			}
			sleep(sf::seconds(0.01));
			window.clear();
			window.draw(BG);
			b->drawBoard(window,NOP);
			L->DrawDice(window);
			window.display();
		}
		hasKilled = true;
		for (int i = 0; i < 10; i++)
		{
			window.clear();
			if (i % 2 == 0)
				Arrow.setFillColor(sf::Color::Green);
			else
				Arrow.setFillColor(C);
			sleep(sf::seconds(0.02));
			window.clear();
			window.draw(BG);
			b->drawBoard(window,NOP);
			L->DrawDice(window);
			window.display();
		}
		GateUnlocked.play();
	}
}
