#include "board.h"
#include<fstream>
#include"cell.h"
#include"home.h"
#include"piece.h"
using namespace std;

board::board(int NOP)
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
	
	//-------------initializing homes
	Hs = new home*[6];
	if(NOP==6)
	{
		Hs[0] = new home(rdr, 3, 88, 1, maroon, "Wolf_White.png", "Wolf_Green.png", -15, 15);
		Hs[1] = new home(rdr, 16, 11, 14, purple, "Eleph_White.png", "Eleph_green.png", 350, 15);
		Hs[2] = new home(rdr, 35, 30, 33, dark_green, "TheWhiteTiger.png", "TheGreenTiger.png", 720, 15);
		Hs[3] = new home(rdr, 48, 43, 46, golden_yellow, "shark.png", "TheGreeShark.png", 720, 380);
		Hs[4] = new home(rdr, 61, 56, 59, dark_grey, "Lion_White.png", "Lion_Green.png", 350, 385);
		Hs[5] = new home(rdr, 80, 75, 78, navy_blue, "p2.png", "GreenHorse_.png", -35, 395);
	}
	else if (NOP == 2)
	{
		Hs[0] = new home(rdr, 3, 88, 1, maroon, "Wolf_White.png", "Wolf_Green.png", -15, 15);
		Hs[2] = new home(rdr, 16, 11, 14, purple, "Eleph_White.png", "Eleph_green.png", 350, 15);
		Hs[3] = new home(rdr, 35, 30, 33, dark_green, "TheWhiteTiger.png", "TheGreenTiger.png", 720, 15);
		Hs[1] = new home(rdr, 48, 43, 46, golden_yellow, "shark.png", "TheGreeShark.png", 720, 380);
		Hs[4] = new home(rdr, 61, 56, 59, dark_grey, "Lion_White.png", "Lion_Green.png", 350, 385);
		Hs[5] = new home(rdr, 80, 75, 78, navy_blue, "p2.png", "GreenHorse_.png", -35, 395);
	}
	else if (NOP == 4)
	{
		Hs[0] = new home(rdr, 3, 88, 1, maroon, "Wolf_White.png", "Wolf_Green.png", -15, 15);
		Hs[4] = new home(rdr, 16, 11, 14, purple, "Eleph_White.png", "Eleph_green.png", 350, 15);
		Hs[1] = new home(rdr, 35, 30, 33, dark_green, "TheWhiteTiger.png", "TheGreenTiger.png", 720, 15);
		Hs[2] = new home(rdr, 48, 43, 46, golden_yellow, "shark.png", "TheGreeShark.png", 720, 380);
		Hs[5] = new home(rdr, 61, 56, 59, dark_grey, "Lion_White.png", "Lion_Green.png", 350, 385);
		Hs[3] = new home(rdr, 80, 75, 78, navy_blue, "p2.png", "GreenHorse_.png", -35, 395);
	}

	//-------initializing cells
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

	//---------------intializing pieces
	Ps = new piece * [4*NOP];
	string fn; sf::Color C; int _r = 0, _c = 0;
	int x = 0;
	for (int i = 0; i < NOP * 4; i += 4)
	{
		if (x == 0)
		{
			fn = "MaroonPc.png";
			C = maroon;
			_r = Hs[x]->getRow();
			_c = Hs[x]->getCol();
			x++;
		}
		else if (NOP == 6 && x == 1)
		{
			fn = "PurplePc.png";
			C = purple;
			_r = Hs[x]->getRow();
			_c = Hs[x]->getCol();
			x++;
		}
		else if ((NOP == 6 && x == 2) || (NOP == 4 && x == 1))
		{
			{
				fn = "GreenPc.png";
				C = dark_green;
				_r = Hs[x]->getRow();
				_c = Hs[x]->getCol();
			}
			x++;
		}
		else if ((x == 1 && NOP == 2) || (x == 3 && NOP == 6) || (x == 2 && NOP == 4))
		{
			fn = "YellowPc.png";
			C = golden_yellow;
			_r = Hs[x]->getRow();
			_c = Hs[x]->getCol();
			x++;
		}
		else if (NOP == 6 && x == 4)
		{
			{
				fn = "GreyPc.png";
				C = dark_grey;
				_r = Hs[x]->getRow();
				_c = Hs[x]->getCol();
			}
			x++;
		}
		else if ((NOP == 4 && x == 3) || (NOP == 6 && x == 5))
		{
			{
				fn = "BluePiece.png";
				C = navy_blue;
				_r = Hs[x]->getRow();
				_c = Hs[x]->getCol();
				x++;
			}
		}
		Ps[i] = new piece(_c + 55, _r + 59, C, fn);
		Ps[i + 1] = new piece(_c + 215, _r + 59, C, fn);
		Ps[i + 2] = new piece(_c + 55, _r + 220, C, fn);
		Ps[i + 3] = new piece(_c + 215, _r + 220, C, fn);
	}
	//if (NOP == 2)
	//{
	//	for (int i = 0; i < NOP*4; i += 4)
	//	{
	//		if (i >= 0 && i < 4)
	//		{
	//			fn = "MaroonPc.png";
	//			C = maroon;
	//			_r = Hs[0]->getRow();
	//			_c = Hs[0]->getCol();
	//		}
	//		if (i >= 4 && i < 8)
	//		{
	//			fn = "YellowPc.png";
	//			C = golden_yellow;
	//			_r = Hs[1]->getRow();
	//			_c = Hs[1]->getCol();
	//		}
	//		Ps[i] = new piece(_c + 55, _r + 59, C, fn);
	//		Ps[i + 1] = new piece(_c + 215, _r + 59, C, fn);
	//		Ps[i + 2] = new piece(_c + 55, _r + 220, C, fn);
	//		Ps[i + 3] = new piece(_c + 215, _r + 220, C, fn);
	//	}
	//}
	//else if (NOP == 4)
	//{
	//	for (int i = 0; i < 24; i += 4)
	//	{
	//		if (i >= 0 && i < 4)
	//		{
	//			fn = "MaroonPc.png";
	//			C = maroon;
	//			_r = Hs[0]->getRow();
	//			_c = Hs[0]->getCol();
	//		}
	//		if (i >= 4 && i < 8)
	//		{
	//			fn = "GreenPc.png";
	//			C = dark_green;
	//			_r = Hs[2]->getRow();
	//			_c = Hs[2]->getCol();
	//		}
	//		if (i >= 8 && i < 12)
	//		{
	//			fn = "YellowPc.png";
	//			C = golden_yellow;
	//			_r = Hs[3]->getRow();
	//			_c = Hs[3]->getCol();
	//		}
	//		if (i >= 12 && i < 16)
	//		{
	//			fn = "BluePiece.png";
	//			C = navy_blue;
	//			_r = Hs[5]->getRow();
	//			_c = Hs[5]->getCol();
	//		}
	//		Ps[i] = new piece(_c + 55, _r + 59, C, fn);
	//		Ps[i + 1] = new piece(_c + 215, _r + 59, C, fn);
	//		Ps[i + 2] = new piece(_c + 55, _r + 220, C, fn);
	//		Ps[i + 3] = new piece(_c + 215, _r + 220, C, fn);
	//	}
	//}
	//else if(NOP==6)
	//{
	//	for (int i = 0; i < 24; i += 4)
	//	{
	//		if (i >= 0 && i < 4)
	//		{
	//			fn = "MaroonPc.png";
	//			C = maroon;
	//			_r = Hs[0]->getRow();
	//			_c = Hs[0]->getCol();
	//		}
	//		if (i >= 4 && i < 8)
	//		{
	//			fn = "PurplePc.png";
	//			C = purple;
	//			_r = Hs[1]->getRow();
	//			_c = Hs[1]->getCol();
	//		}
	//		if (i >= 8 && i < 12)
	//		{
	//			fn = "GreenPc.png";
	//			C = dark_green;
	//			_r = Hs[2]->getRow();
	//			_c = Hs[2]->getCol();
	//		}
	//		if (i >= 12 && i < 16)
	//		{
	//			fn = "YellowPc.png";
	//			C = golden_yellow;
	//			_r = Hs[3]->getRow();
	//			_c = Hs[3]->getCol();
	//		}
	//		if (i >= 16 && i < 20)
	//		{
	//			fn = "GreyPc.png";
	//			C = dark_grey;
	//			_r = Hs[4]->getRow();
	//			_c = Hs[4]->getCol();
	//		}
	//		if (i >= 20 && i < 24)
	//		{
	//			fn = "BluePiece.png";
	//			C = navy_blue;
	//			_r = Hs[5]->getRow();
	//			_c = Hs[5]->getCol();
	//		}
	//		Ps[i] = new piece(_c + 55, _r + 59, C, fn);
	//		Ps[i + 1] = new piece(_c + 215, _r + 59, C, fn);
	//		Ps[i + 2] = new piece(_c + 55, _r + 220, C, fn);
	//		Ps[i + 3] = new piece(_c + 215, _r + 220, C, fn);
	//	}
	//}


	//Ps[1]->setCellIndex(86);
	//Ps[1]->setPosition(Cs[86]->getCol() + 38, Cs[86]->getRow() + 42);
	
	Ps[1]->setCellIndex(57);
	Ps[1]->setPosition(Cs[57]->getCol() + 38, Cs[57]->getRow() + 42);
	Ps[6]->setCellIndex(54);
	Ps[6]->setPosition(Cs[54]->getCol() + 38, Cs[54]->getRow() + 42);
}

void board::drawBoard(sf::RenderWindow& window,int NOP)
{

	for (int i = 0; i < 90; i++)
	{
		Cs[i]->Draw(window);
	}
	drawHome(window,NOP);

}

void board::drawHome(sf::RenderWindow& window,int NOP)
{

	for (int i = 0; i < 6; i++)
	{
		Hs[i]->Draw(window);
	}
	for (int i = 0; i < 4*NOP; i++)
	{
		Ps[i]->Draw(window);
	}
}

//piece* board::getPiece(int ri, int ci)
//{
//	for (int i = 0; i < 90; i++)
//	{
//		if (Cs[i]->isClicked(ri, ci))
//			return Cs[i]->getPiece();
//	}
//}

void board::setPiece(piece* P,int i)
{
	Cs[i]->setPiece(P);
}

home* board::getHome(int i)
{
	return Hs[i];
}

piece* board::getPiece(int indx)
{
	return Ps[indx];
}

void board::setCellColor(int ind)
{
	Cs[ind]->setOutlSize(3);
	Cs[ind]->setOutlClr(sf::Color::Green);
}

int board::getCellRow(int indx)
{
	return this->Cs[indx]->getRow();
}

int board::getCellCol(int indx)
{
	return this->Cs[indx]->getCol();

}