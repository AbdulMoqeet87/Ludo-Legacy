#include "board.h"
#include<fstream>
#include"cell.h"
#include"home.h"
#include"piece.h"
using namespace std;
board::board()
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


	ifstream rdr("Cells.txt");
	
	Hs = new home*[6];
	Hs[0] = new home(rdr, 88,3,maroon, "Player1_bg.png",-15,15);
	Hs[1] = new home(rdr,16,11,purple,"elephantfront.png",350,15);
	Hs[2] = new home(rdr, 35,30,dark_green, "tiger2.png",720,15);
	Hs[3] = new home(rdr, 48,43,golden_yellow, "shark.png",720,380);
	Hs[4] = new home(rdr, 61,56,dark_grey, "lionC.png",350,385);
	Hs[5] = new home(rdr,80,75,navy_blue,"p2.png", -35, 395);

	int j = 0; bool clrHai = false;
	Cs = new Cell * [90];
	for (int i = 0; i < 90; i++)
	{	
		for (j = 0; j < 6; j++)
		{
			if (Hs[j]->IsInitSpot(i) || Hs[j]->IsSafeSpot(i))
			{
				clrHai = true; break;
			}
		}
		if(clrHai)
		Cs[i] = new Cell(rdr, Hs[j]->getHOmeColor());
		else Cs[i] = new Cell(rdr, sf::Color::White);
		clrHai = false;
	}
//------------------------------
	Ps = new piece*[24];
	string fn; sf::Color C; int _r=0, _c=0;
	for (int i = 0; i < 24; i+=4)
	{
		if (i >= 0 && i < 4)
		{
			fn = "MaroonPc.png";
			C = maroon;
			_r = Hs[0]->getRow();
			_c = Hs[0]->getCol();
		}
		if (i >= 4 && i < 8)
		{
			fn = "PurplePc.png";
			C = purple;
			_r = Hs[1]->getRow();
			_c = Hs[1]->getCol();
		}
		if (i >= 8 && i < 12)
		{
			fn = "GreenPc.png";
			C = dark_green;
			_r = Hs[2]->getRow();
			_c = Hs[2]->getCol();
		}
		if (i >= 12 && i < 16)
		{
			fn = "YellowPc.png";
			C = golden_yellow;
			_r = Hs[3]->getRow();
			_c = Hs[3]->getCol();
		}
		if (i >= 16 && i < 20)
		{
			fn = "GreyPc.png";
			C = dark_grey;
			_r = Hs[4]->getRow();
			_c = Hs[4]->getCol();
		}
		if (i >= 20 && i < 24)
		{
			fn = "BluePiece.png";
			C = navy_blue;
			_r = Hs[5]->getRow();
			_c = Hs[5]->getCol();
		}						
		Ps[i] = new piece(_c+55, _r+59, C, fn);
		Ps[i+1] = new piece(_c+215, _r+59, C, fn);
		Ps[i+2] = new piece(_c+55, _r+220, C, fn);
		Ps[i+3] = new piece(_c+215, _r+220, C, fn);
	
	}

	
}



void board::drawBoard(sf::RenderWindow& window)
{

	for (int i = 0; i < 90; i++)
	{
		Cs[i]->Draw(window);
	}


}

void board::drawHome(sf::RenderWindow& window)
{

	for (int i = 0; i < 6; i++)
	{
		Hs[i]->Draw(window);
	}
	for (int i = 0; i < 24; i++)
	{
		Ps[i]->Draw(window);
	}
}