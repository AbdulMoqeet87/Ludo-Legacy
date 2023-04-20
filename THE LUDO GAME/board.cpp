#include "board.h"
#include<fstream>
#include"cell.h"
#include"home.h"
#include"piece.h"
#include"player.h"
#include<vector>
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
	sf::Color neonPurple(205, 0, 205);
	sf::Color neonBlue(0, 246, 255);

	BC_.loadFromFile("ButtonPressed.wav");
	ButtonClick.setBuffer(BC_);

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
	//-----------initializing board Outline boxes
	sf::Color blur = sf::Color(255, 255, 255, 128);
	sf::Color neon_red(255, 38, 0);
	
	BigBox.setSize(sf::Vector2f(997, 629));
	BigBox.setFillColor(sf::Color::Transparent);
	BigBox.setOutlineColor(sf::Color::White);
	BigBox.setOutlineThickness(2);
	BigBox.setPosition(33, 33);

	BigBox2.setSize(sf::Vector2f(991, 623));
	BigBox2.setFillColor(sf::Color::Transparent);
	BigBox2.setOutlineColor(navy_blue);
	BigBox2.setOutlineThickness(9);
	BigBox2.setPosition(36, 36);
	
	BigBox3.setSize(sf::Vector2f(991, 623));
	BigBox3.setFillColor(sf::Color::Transparent);
	BigBox3.setOutlineColor(blur);
	BigBox3.setOutlineThickness(9);
	BigBox3.setPosition(36, 36);


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
	PB.loadFromFile("P-Butt_N.png");
	PowerButton.setTexture(PB);
	PowerButton.setPosition(sf::Vector2f(1230,30));
	Bi.loadFromFile("BlurrBoard.png");
	BlurrImage.setTexture(Bi);
	BlurrImage.setScale(1, 1);
	BlurrImage.setPosition(0, 0);

	DialougeBox.setFillColor(sf::Color::Black);
	DialougeBox.setOutlineColor(neonPurple);
	DialougeBox.setOutlineThickness(10);
	DialougeBox.setSize(sf::Vector2f(700, 500));
	DialougeBox.setPosition(sf::Vector2f(300, 80));

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
	
	/*Ps[1]->setCellIndex(47);
	Ps[1]->setPosition(Cs[47]->getCol() + 38, Cs[47]->getRow() + 42);
	Ps[6]->setCellIndex(44);
	Ps[6]->setPosition(Cs[44]->getCol() + 38, Cs[44]->getRow() + 42);*/
}

//void board::drawBoard(sf::RenderWindow& window,int NOP)
//{
//
//	for (int i = 0; i < 90; i++)
//	{
//		Cs[i]->Draw(window);
//	}
//	drawHome(window,NOP);
//
//}

void board::DrawRestart(sf::RenderWindow& window, int& Ending)
{
	sf::Font GOT;
	sf::Font Lato;
	sf::Color neonPurple(205, 0, 205);
	Lato.loadFromFile("Lato.ttf");
	GOT.loadFromFile("GameOfThrones.ttf");
	sf::Text RESTART("RESTART ", GOT, 50);
	sf::Text QUIT("QUIT ", GOT, 50);
	RESTART.setPosition(sf::Vector2f(515,230));
	QUIT.setPosition(sf::Vector2f(565,380));
	bool Break = false;
	

	while(window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseMoved)
			{
				sf::Vector2i P = sf::Mouse::getPosition(window);

				if ((P.x >= 515 && P.x < 800) && (P.y >= 230 && P.y < 281))
					RESTART.setFillColor(neonPurple);
				else
					RESTART.setFillColor(sf::Color::White);

				if ((P.x >= 565 && P.x < 700) && (P.y >= 380 && P.y < 431))
					QUIT.setFillColor(neonPurple);
				else
					QUIT.setFillColor(sf::Color::White);
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i P = sf::Mouse::getPosition(window);

				if ((P.x >= 515 && P.x < 800) && (P.y >= 230 && P.y < 281))  //Pressed Restart
				{
					Break = true;
					ButtonClick.play();
					Ending = 1;
					break;
				}
				if ((P.x >= 565 && P.x < 700) && (P.y >= 380 && P.y < 431))  //Pressed Quit 
				{
					ButtonClick.play();
					Break = true;
					Ending = 0;
					break;
				}
				
				else if ((P.x < 300 || P.x > 1000) || (P.y <80 || P.y> 580))   // clicked anywhere dialouge outside dialouse box
				{
					Break = true;
					Ending = -1;
					break;
				}
			
			}
		

		}

		if (Break)
			break;
		window.clear();
		window.draw(BlurrImage);
		window.draw(DialougeBox);
		window.draw(RESTART);
		window.draw(QUIT);
		window.display();
	}

}

void board::drawBoard(sf::RenderWindow& window, int NOP, vector<int> JootaIndx, vector<player*> WinPs)
{
	sf::Color blur= sf::Color(255, 255, 255, 128); // White with alpha 128

	sf::Color transparentLightGrey = sf::Color(128, 128, 128, 128);
	sf::Color transparent_gray(128, 128, 128, 160);
	sf::Color maroon(128, 0, 0);
	sf::Color navy_blue(0, 0, 128);
	sf::RectangleShape B3;
	
	B3.setSize(sf::Vector2f(1600, 950));
	B3.setFillColor(transparent_gray);
	B3.setPosition(0,0);

	for (int i = 0; i < 90; i++)
	{
		Cs[i]->Draw(window);
	}
	drawHome(window, NOP, JootaIndx);
	DrawWinner(WinPs, window);
	
	window.draw(BigBox2);
	//window.draw(BigBox3);
	window.draw(BigBox);
	window.draw(PowerButton);
	//window.draw(B3);

}

//void board::drawHome(sf::RenderWindow& window, int NOP)
//{
//
//	for (int i = 0; i < 6; i++)
//	{
//		Hs[i]->Draw(window);
//	}
//	for (int i = 0; i < 4 * NOP; i++)
//	{
//		Ps[i]->Draw(window);
//	}
//}

void board::drawHome(sf::RenderWindow& window,int NOP, vector<int> JootaIndx)
{

	for (int i = 0; i < 6; i++)
	{
		Hs[i]->Draw(window);
	}
	vector<vector<int>> Js;
	bool foundJ = false;
	int jp1, jp2, j = 0;
	for (int i = 0; i < 4*NOP; i++)
	{
		bool isJoota = false;
		for(int x=0;x< JootaIndx.size();x++)
		{
			if (Ps[i]->getCellIndex() == JootaIndx[x])
			{
				if (j == 0)
					jp1 = i,j++;
				else if (j == 1)
				{
					jp2 = i;
					Js.push_back({ jp1,jp2 });
					j = 0;
				}
				isJoota = true; foundJ = true;
			}
		}
		if (!isJoota)
			Ps[i]->Draw(window);
	}
	if(foundJ)
	{
		for (int j = 0; j < Js.size(); j++)
		{
			Ps[Js[j][0]]->setPosition(Ps[Js[j][0]]->GetCol(), Ps[Js[j][0]]->GetRow());
			Ps[Js[j][0]]->Draw(window);

			Ps[Js[j][1]]->setPosition(Ps[Js[j][1]]->GetCol(), Ps[Js[j][1]]->GetRow());
			Ps[Js[j][1]]->Draw(window);
		}
	}
}

void board::DrawWinner(std::vector<player*> WinPs,sf::RenderWindow& window)
{
	string fn;
	for (int i = 0; i < WinPs.size(); i++)
	{
		switch (i)
		{
		case 0:
			fn = "first.png";
			break;
		case 1:
			fn = "second.png";
			break;
		case 2:
			fn = "third.png";
			break;
		case 3:
			fn = "medal.png";
			break;
		case 4:
			fn = "medal.png";
			break;
		case 5:
			fn = "medal.png";
			break;
		}
		WinTex.loadFromFile(fn);
		Win.setTexture(WinTex);
		Win.setScale(0.4, 0.4);
		for (int hi = 0; hi < 4; hi++)
		{
			if (WinPs[i]->getColor() == Hs[hi]->getHOmeColor())
			{
				Win.setPosition(Hs[hi]->getCol() + 50, Hs[hi]->getRow() + 50);
				break;
			}
		}
		window.draw(Win);
	}
}

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

bool board::PowerButtonClicked(int r, int c)
{
	if (PowerButton.getGlobalBounds().contains(c, r))
		return true;
	return false;
}
