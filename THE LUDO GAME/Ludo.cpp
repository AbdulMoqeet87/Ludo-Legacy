#include "Ludo.h"
#include"Dice.h"
#include"player.h"
#include"board.h"
#include"piece.h"
#include"home.h"
#include<fstream>
#include<string>
//#include<vector>
using namespace sf;
using namespace std;

Ludo::Ludo()
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

	BG.loadFromFile("StarryBack.jpg");
	BackG.setTexture(BG);

	Ps = new player * [6];
	Ps[0] = new player("Amna", maroon);
	Ps[1] = new player("Moqeet", purple);
	Ps[2] = new player("Abaid", dark_green);
	Ps[3] = new player("Mahnoor", golden_yellow);
	Ps[4] = new player("Minahil", dark_grey);
	Ps[5] = new player("Fahira", navy_blue);
	//Ps[0]->setHasKilled(true);
	//Ps[1]->setHasKilled(true);
	//Ps[1]->setIsWin(true);
	B = new board(2);
	dice = new Dice(1140, 500);
	dice->setDiceValue(2);
	Ds[0] = new Dice(1070, 180);
	Ds[1] = new Dice(1160, 180);
	Ds[2] = new Dice(1250, 180);
	NOP = 6;
	Turn = 0;
	sri = 0, sci = 0;
}

Ludo::Ludo(int _NOP)
{
	NOP = _NOP;
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

	BG.loadFromFile("StarryBack.jpg");
	BackG.setTexture(BG);
	BackG.setScale(0.7,0.7);
	Ps = new player * [NOP];
	if (NOP == 6)
	{
		Ps[0] = new player("Amna", maroon);
		Ps[1] = new player("Moqeet", purple);
		Ps[2] = new player("Abaid", dark_green);
		Ps[3] = new player("Mahnoor", golden_yellow);
		Ps[4] = new player("Minahil", dark_grey);
		Ps[5] = new player("Fahira", navy_blue);
	}
	else if (NOP == 4)
	{
		Ps[0] = new player("Amna", maroon);
		Ps[1] = new player("Moqeet", dark_green);
		Ps[2] = new player("Abaid", golden_yellow);
		Ps[3] = new player("Mahnoor", navy_blue);
	}
	else if (NOP == 2)
	{
		Ps[0] = new player("Amna", maroon);
		Ps[1] = new player("Moqeet", golden_yellow);
	}
	//Ps[0]->setHasKilled(true);
	//WinPs.push_back(Ps[0]);
	//Ps[1]->setHasKilled(true);
	//Ps[1]->setIsWin(true);
	S = new sf::SoundBuffer[3];
	sounds = new sf::Sound[3];
	S[0].loadFromFile("PunchSound.wav");
	sounds[0].setBuffer(S[0]);
	
	S[1].loadFromFile("OhYeah.wav");
	sounds[1].setBuffer(S[1]);
	S[2].loadFromFile("pop.wav");
	sounds[2].setBuffer(S[2]);

	B = new board(NOP);
	dice = new Dice(1140, 500);
	dice->setDiceValue(2);
	Ds[0] = new Dice(1070, 180);
	Ds[1] = new Dice(1160, 180);
	Ds[2] = new Dice(1250, 180);

	Turn = 0;
	sri = 0, sci = 0;
}


void Ludo::turnChange()
{
	if (Turn == (NOP-1))
	{
		Turn = 0;
	}
	else
	{
		Turn++;
	}
	if (isWin())
		turnChange();
}

//bool Ludo::isValidSc()
//{
//	int pi;
//	if (B->getPiece(sri, sci) != nullptr)
//	{
//		if (B->getPiece(sri, sci)->getColor() == Ps[Turn]->getColor())
//		{
//			return true;
//		}
//	}
//	else if (B->getHome(Turn)->clickedHomePiece(sri,sci,pi))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

bool Ludo::isValidSc(int& indx, int DiceIndx)
{
	for (int i = Turn * 4; i < (Turn * 4) + 4; i++)
	{
		if (B->getPiece(i)->Contains(sri, sci))
		{
			indx = i;
			//return true;
		}
	}
	if (indx != -1)
	{
		if (B->getPiece(indx)->getCellIndex() == -2)
			return false;
		if ((B->getPiece(indx)->getCellIndex() > 90)  && (B->getPiece(indx)->getCellIndex() + Ds[DiceIndx]->getDiceValue()) > 96)
			return false;
		return true;
	}
	return false;
}

void Ludo::RollDice(sf::RenderWindow& window, int di)
{
	dice->rollDice(B, window,BackG,NOP);
	Ds[di]->setDiceValue(dice->getDiceValue());
	/*if (Ds[di]->getDiceValue() == 6)
		di++;*/
}

void Ludo::DrawDice(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		if (Ds[i]->getDiceValue() != 0)
			Ds[i]->drawDice(window);

	}
	dice->drawDice(window);
}

void Ludo::Move(int indx, int DiceIndx,sf::RenderWindow &window)
{
	bool canEnterHome = false;
	int enterHomeAt = 0, HomeCellri, HomeCellci;
	bool isSafeSpot = false;
	int Temp_indx = B->getPiece(indx)->getCellIndex() - 1;
	int NewCell_indx = B->getPiece(indx)->getCellIndex() + Ds[DiceIndx]->getDiceValue();
		//int Temp_indx = indx;
	//int ir = B->getPiece(indx)->getInitialRow();
	//int ic = B->getPiece(indx)->getInitialCol();
	int curr_r = B->getPiece(indx)->GetRow();
	int curr_c = B->getPiece(indx)->GetCol();

	if (Ds[DiceIndx]->getDiceValue() == 6 && B->getPiece(indx)->atIntialPos(curr_r, curr_c))//ir==curr_r && ic == curr_c)
	{
		sounds[1].play();
		B->getPiece(indx)->setPosition(B->getCellCol(B->getHome(Turn)->getInitialPos()) + 38, B->getCellRow(B->getHome(Turn)->getInitialPos()) + 42);
		B->getPiece(indx)->setCellIndex(B->getHome(Turn)->getInitialPos());
		//---------------------------------setting row col of piece
		//B->getPiece(indx)->setRow(B->getCellRow(B->getHome(Turn)->getInitialPos()) + 42);
		//B->getPiece(indx)->setCol(B->getCellCol(B->getHome(Turn)->getInitialPos()) + 38);

	}
	else if (B->getPiece(indx)->getCellIndex() > 90)
	{
		if ((Ds[DiceIndx]->getDiceValue() + (B->getPiece(indx)->getCellIndex())) == 96)
		{
			for (int ci = B->getPiece(indx)->getCellIndex(); ci <= NewCell_indx - 1; ci++)
			{

				B->getHome(Turn)->getHomeCellPos(ci - 90 - 1, HomeCellri, HomeCellci);
				sounds[2].play();
				B->getPiece(indx)->setPosition(HomeCellci + 38, HomeCellri + 42);
				window.clear();
				window.draw(BackG);
				B->drawBoard(window, NOP);
				DrawDice(window);
				window.display();
				sleep(sf::seconds(0.05));
				sounds[2].stop();

			}
			B->getHome(Turn)->getHomeCellPos(4, HomeCellri, HomeCellci);
			B->getPiece(indx)->setPosition(HomeCellci + 78, HomeCellri + 82);
			B->getPiece(indx)->setCellIndex(-2);
		}
		else
		{
			//B->getHome(Turn)->getHomeCellPos(Ds[DiceIndx]->getDiceValue() + (B->getPiece(indx)->getCellIndex()) - 90 - 1, HomeCellri, HomeCellci);
			//B->getPiece(indx)->setPosition(HomeCellci + 38, HomeCellri + 42);
			for (int ci = B->getPiece(indx)->getCellIndex(); ci <= NewCell_indx; ci++)
			{

				B->getHome(Turn)->getHomeCellPos(ci - 90 - 1, HomeCellri, HomeCellci);
				sounds[2].play();

				B->getPiece(indx)->setPosition(HomeCellci + 38, HomeCellri + 42);
				window.clear();
				window.draw(BackG);

				B->drawBoard(window, NOP);
				DrawDice(window);
				window.display();

				sleep(sf::seconds(0.05));
				sounds[2].stop();

			}
			//B->getPiece(indx)->setCellIndex(NewCell_indx);
			B->getPiece(indx)->setCellIndex(Ds[DiceIndx]->getDiceValue() + (B->getPiece(indx)->getCellIndex()));

		}
	}
	else if (!B->getPiece(indx)->atIntialPos(curr_r, curr_c))//(ir != curr_r || ic != curr_c))
	{
		for (int i = 0; i < Ds[DiceIndx]->getDiceValue(); i++)
		{
			Temp_indx += 1;
			if (Temp_indx > 89)
				Temp_indx -= 90;
			if (B->getHome(Turn)->IsTurningSpot(Temp_indx))
			{
				enterHomeAt = i;
				canEnterHome = true;
				break;
			}
		}
		if (Ps[Turn]->hasKilled() && canEnterHome)
		{
			//B->getHome(Turn)->getHomeCellPos(Ds[DiceIndx]->getDiceValue() - enterHomeAt - 1, HomeCellri, HomeCellci);
			//B->getPiece(indx)->setPosition(HomeCellci + 38, HomeCellri + 42);
			//B->getPiece(indx)->setCellIndex((Ds[DiceIndx]->getDiceValue() - enterHomeAt) + 90);
			cout << "Amna pagal k bahir " << enterHomeAt<<endl;
			int Nind = B->getPiece(indx)->getCellIndex() + enterHomeAt;
			for (int ci = B->getPiece(indx)->getCellIndex(); ci <=Nind ; ci++)
			{
				if (ci > 89)
					ci = 0,Nind-=90;
				cout << "Moqeet k dimagh ma \n";
				sounds[2].play();

				B->getPiece(indx)->setPosition(B->getCellCol(ci) + 38, B->getCellRow(ci) + 42);
				window.clear();
				window.draw(BackG);
				B->drawBoard(window, NOP);
				DrawDice(window);
				window.display();
				sounds[2].stop();
				sleep(sf::seconds(0.05));
				sounds[2].stop();

			}
			cout << "Amna k dimagh k bahir \n";
			B->getHome(Turn)->getHomeCellPos(0, HomeCellri, HomeCellci);
			sounds[2].play();

			B->getPiece(indx)->setPosition(HomeCellci + 38, HomeCellri + 42);
			window.clear();
			window.draw(BackG);
			B->drawBoard(window, NOP);
			DrawDice(window);
			window.display();
			sleep(sf::seconds(0.05));
			sounds[2].stop();
			for (int ci = 92 ; ci <= (Ds[DiceIndx]->getDiceValue() - enterHomeAt) + 90; ci++)
			{

				B->getHome(Turn)->getHomeCellPos(ci - 90 - 1, HomeCellri, HomeCellci);
			
				sounds[2].play();
				B->getPiece(indx)->setPosition(HomeCellci + 38, HomeCellri + 42);
				window.clear();
				window.draw(BackG);
				B->drawBoard(window,NOP);
				DrawDice(window);
				window.display();
				sleep(sf::seconds(0.05));
				sounds[2].stop();

			}
			//B->getPiece(indx)->setCellIndex(NewCell_indx);
			B->getPiece(indx)->setCellIndex((Ds[DiceIndx]->getDiceValue() - enterHomeAt) + 90);
		}
		else
		{
	        /*if (NewCell_indx > 89)
				NewCell_indx -= 90;*/
			

			for (int ci = B->getPiece(indx)->getCellIndex(); ci <= NewCell_indx; ci++)
			{
				cout << "entered Move Loop\n";
				if(ci>89)
				{			
					ci = 0;
					NewCell_indx -= 90;
				}
				sounds[2].play();

				B->getPiece(indx)->setPosition(B->getCellCol(ci) + 38, B->getCellRow(ci) + 42);
				
				window.clear();
				window.draw(BackG);
				B->drawBoard(window,NOP);
				DrawDice(window);
				window.display();
				sleep(sf::seconds(0.05));
				sounds[2].stop();
			}
			B->getPiece(indx)->setCellIndex(NewCell_indx);
			
			
			
			//B->getPiece(indx)->setPosition(B->getCellCol(B->getPiece(indx)->getCellIndex()) + 38, B->getCellRow(B->getPiece(indx)->getCellIndex()) + 42);
			
			//-----Checking for safe spot
			for (int i = 0; i < 6; i++)
			{
				if (B->getHome(i)->IsSafeSpot(B->getPiece(indx)->getCellIndex()) || B->getHome(i)->IsInitSpot(B->getPiece(indx)->getCellIndex()))
				{
					isSafeSpot = true;
				}
			}

			//------Checking if piece is killed
			if(!isSafeSpot)
			{
				int id=-4;
				for (int _i = 0; _i < NOP*4; _i++)
				{
					if (B->getPiece(_i)->getCellIndex() == B->getPiece(indx)->getCellIndex())
					{
						if (B->getPiece(_i)->getClr() != B->getPiece(indx)->getClr())
						{
							 id = _i;
							Ps[Turn]->setHasKilled(true);
							sounds[0].play();
							break;
						}
					}
				}
			
			
				if(Ps[Turn]->hasKilled()&&id!=-4)
				{
					int init_r = B->getPiece(id)->getInitialRow(), init_c = B->getPiece(id)->getInitialCol();
					for (int kr = B->getPiece(id)->GetRow(), kc = B->getPiece(id)->GetCol(); kr != B->getPiece(id)->getInitialRow() || kc != B->getPiece(id)->getInitialCol();)
					{
						//window.clear();
						B->getPiece(id)->setPosition(kc, kr);
						if ( abs(kr - init_r) < 20)
						{
							if (kr > init_r)
								kr--; else if (kr < init_r) kr++;
						}
						else
						{
								if (kr > init_r)
									kr -= 19; else if (kr < init_r) kr += 19;
						}
							
						if(abs(kc - init_c) < 20)
						{

							if (kc > init_c)
								kc--; else if (kc < init_c) kc++;
						}
						else
						{

							if (kc > init_c)
								kc -= 19; else if (kc < init_c) kc += 19;
						}
					
						window.clear();
						window.draw(BackG);
						B->drawBoard(window, NOP);
						DrawDice(window);
						window.display();
						//sleep(sf::seconds(-0.03));
					}

					B->getPiece(id)->setPosition(B->getPiece(id)->getInitialCol(), B->getPiece(id)->getInitialRow());
					B->getPiece(id)->setCellIndex(-1);
					B->getHome(Turn)->Blink(window, B, this, BackG, NOP);

				}
			
			
			}
		}
	}
}

bool Ludo::clickedDice()
{
	if (dice->isClicked(sri, sci))
		return true;
	return false;
}

bool Ludo::canMove()
{
	bool AllatHomee = true;
	bool Sixspotted = false;
	for (int i = Turn * 4; i < (Turn * 4) + 4; i++)
	{
		int init_r = B->getPiece(i)->getInitialRow();
		int init_c = B->getPiece(i)->getInitialCol();
		int Curr_r = B->getPiece(i)->GetRow();
		int Curr_c = B->getPiece(i)->GetCol();

		if (init_r != Curr_r || init_c != Curr_c)
			AllatHomee = false;
	}
	if (Ds[0]->getDiceValue() == 6)
		Sixspotted = true;
	/*for (int j = 0; j < 3; j++)
	{
		if (Ds[j]->getDiceValue() == 6)
			Sixspotted = true;
	}*/


	if ((AllatHomee) && (!Sixspotted))
		return false;
	return true;

	//if (!Ps[Turn]->canMove() && Ds[0]->getDiceValue() == 6)
	//{
	//	Ps[Turn]->setCanMove(true);
	//	return true;
	//}
	//else if (Ps[Turn]->canMove())
	//	return true;
	//else
	//	return false;
}

void Ludo::selectDiceValue(int& DiceIndx)
{
	cout << "Entered Select Value\n";
	//bool breakAll = false;
	//while (window.isOpen())
	//{
	//
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//		if (event.type == Event::MouseButtonPressed)
	//		{
	//			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	//			sri = mousePos.y;
	//			sci = mousePos.x;
	//
	//			for (int i = 0; i < 3; i++)
	//			{
	//				cout << "Dice value  " << Ds[i]->getDiceValue() << endl;
	//				if (Ds[i]->isClicked(sri, sci))
	//				{
	//					DiceIndx = i;
	//					breakAll = true;
	//					break;
	//					cout << " \n\nValueSelected\n";
	//				}
	//			}
	//		
	//		
	//		}
	//		if (breakAll)break;
	//	}
	//	if (breakAll)break;
	//	window.clear();
	//	B->drawBoard(window);
	//	DrawDice(window);
	//	window.display();
	//}

	for (int i = 0; i < 3; i++)
	{
		cout << "Dice value  " << Ds[i]->getDiceValue() << endl;
		if (Ds[i]->isClicked(sri, sci))
		{
			DiceIndx = i;
			cout << " \n\nValueSelected\n";
		}
	}
	cout << "sri" << sri << endl;
	cout << "sci" << sci << endl;

	//if ((sri >= 99 && sri < 200) && (sci >= 1098 && sri < 1200))
	//{
	//	DiceIndx = 0;
	//}
	//else if ((sri >= 99 && sri < 200) && (sri >= 1201 && sri < 1303))
	//{
	//	DiceIndx = 1;
	//}
	//else if ((sri >= 99 && sri < 200) && (sri >= 1304 && sri < 1406))
	//{
	//	DiceIndx = 2;
	//}

	cout << "Exit Selected Value\n";

	//void Ludo::play(sf::RenderWindow& window)
	//{
	//	int indx = -1;
	//	int DiceIndx = 0;
	//	bool selected = false;
	//	bool diceRolled = false;
	//	int di = 0;
	//	bool canSelect = false;
	//	while (window.isOpen())
	//	{
	//		sf::Event event;
	//		while (window.pollEvent(event))
	//		{
	//			if (event.type == sf::Event::Closed)
	//				window.close();
	//			if (event.type == Event::MouseButtonPressed)
	//			{
	//				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	//				sri = mousePos.y;
	//				sci = mousePos.x;
	//				selected = true;
	//				if (!canSelect)
	//				{
	//					if (clickedDice())
	//					{
	//						RollDice(window, di);
	//						if (Ds[di]->getDiceValue() != 6)
	//							diceRolled = true, canSelect = true;
	//						else
	//							di++,diceRolled = false;
	//						selected = false;
	//					}
	//				}
	//				else
	//				{
	//					if (diceRolled)
	//					{
	//						selectDiceValue(DiceIndx);
	//						diceRolled = false;
	//						selected = false;
	//					}
	//					if (selected)
	//					{
	//						if (canMove())
	//						{
	//							if (isValidSc(indx))
	//							{
	//								//B->getPiece(indx)->setPosition(B->getHome(Turn)->getInitialPos());
	//								//B->setCellColor(B->getHome(Turn)->getSafeSpot());
	//								//RollDice(window);
	//								Move(indx, DiceIndx);
	//								turnChange();
	//								selected = false;
	//								indx = -1;
	//								di = 0;
	//							}
	//						}
	//						else
	//						{
	//							turnChange();
	//							selected = false;
	//							indx = -1;
	//							di = 0;
	//						}
	//					}
	//				}
	//			}
	//		}
	//		window.clear();
	//		B->drawBoard(window);
	//		DrawDice(window);
	//		window.display();
	//	}
	//}
}

bool Ludo::DiceIsEmpty()
{

	if ((Ds[0]->getDiceValue() == 0) && (Ds[1]->getDiceValue() == 0) && (Ds[2]->getDiceValue() == 0))
		return true;
	return false;
}

bool Ludo::AllSix()
{
	for (int i = 0; i < 3; i++)
	{
		if (Ds[i]->getDiceValue() != 6)
			return false;
	}
	return true;
}

void Ludo::EraseDice()
{
	Ds[0]->setDiceValue(0);
	Ds[1]->setDiceValue(0);
	Ds[2]->setDiceValue(0);

	//Ds[0] = 0; Ds[1] = 0; Ds[2] = 0;
}

bool Ludo::isWin()
{
	if (Ps[Turn]->isWin())
		return true;
	for (int i = Turn * 4; i < (Turn * 4) + 4; i++)
	{
		if (B->getPiece(i)->getCellIndex() != -2)
			return false;
	}
	Ps[Turn]->setIsWin(true);
	WinPs.push_back(Ps[Turn]);
	return true;
}

void Ludo::DrawWinner(sf::RenderWindow& window)
{
	string fn;
	for (int i = 0; i < WinPs.size(); i++)
	{
		switch (i)
		{
		case 0:
			fn = "first.png";
			break;
		/*case 1:
			fn = "second.png";
			break;*/
		}
		WinTex.loadFromFile(fn);
		Win.setTexture(WinTex);
		Win.setScale(0.4, 0.4);
		Win.setPosition(B->getHome(i)->getCol()+50, B->getHome(i)->getRow()+50);
		window.draw(Win);
	}
}

bool Ludo::GameEnded()
{
	if (WinPs.size() == NOP - 2)
		return true;
	return false;
}

void Ludo::play(sf::RenderWindow& window)
{
	int indx = -1;
	int DiceIndx = 0;
	bool selected = false;
	bool diceRolled = false;
	int di = 0;
	bool canSelect = false;
	bool rollingDice = true;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			B->getHome(Turn)->HighlightHome();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sri = mousePos.y;
				sci = mousePos.x;
				if (rollingDice)
				{
					cout << "rollingDice\n";
					if (clickedDice())
					{
						cout << "isclickedDice\n";
						/*int s = 0;
						cin >> s;
						Ds[di]->setDiceValue(s);
						*/
						RollDice(window, di);
						cout << "getDiceValue :" << Ds[di]->getDiceValue() << endl;

						if (Ds[di]->getDiceValue() == 6 && di != 2)
						{
							cout << "di++\n";
							di++;
						}
						else
						{
							cout << "no ++\n";
							rollingDice = false, diceRolled = true;
						}
						
					}
				}

				if (diceRolled)
				{
					cout << "ifDiceRolled\n";
					selectDiceValue(DiceIndx);
					if (canMove())
					{
						cout << "canMOve\n";

						if (isValidSc(indx, DiceIndx))
						{
							Move(indx, DiceIndx,window);
							indx = -1;
							Ds[DiceIndx]->setDiceValue(0);
							if (DiceIsEmpty())
							{
								B->getHome(Turn)->UnHighlightHome();

								turnChange();
								di = 0;
								rollingDice = true;
								diceRolled = false;
								indx = -1;
							}
						}
					}
					else
					{
						cout << "CanNotMove\n";
						B->getHome(Turn)->UnHighlightHome();
						turnChange();
						di = 0;
						rollingDice = true;
						diceRolled = false;
						indx = -1;
						//EraseDice();
					}
				}
				/*	if (diceRolled)
					{
						if (DiceIsEmpty())
						{
							diceRolled = false;
							rollingDice = true;
							canSelect = false;
						}
						if (!canMove())
						{
							cout << "cannotMove\n";
							diceRolled = false;
							rollingDice = true;
							turnChange();
							di = 0;
						}
						else
						{
							cout << "CanMove\n";
							if (!DiceIsEmpty())
								cout << "Dice index Before " << DiceIndx<<endl;
							selectDiceValue(DiceIndx, window);
							cout << "Dice index After " << DiceIndx<< endl;
							diceRolled = false;
							canSelect = true;
						}
					}

					if (canSelect)
					{
						cout << "Entered CanSelect\n";
						if (isValidSc(indx))
						{
							cout << "isValidSource\n";

							if (Move(indx, DiceIndx))
								Ds[DiceIndx]->setDiceValue(0);

							if (!DiceIsEmpty())
							{
								diceRolled = true;
							}
							else
							{
								turnChange();
								canSelect = false;
								diceRolled = false;
								rollingDice = true;
							}
						}
						else if(DiceIsEmpty())
						{
							turnChange();
							canSelect = false;
							diceRolled = false;
							rollingDice = true;
						}
					}*/
			}
		}
		window.clear();
		window.draw(BackG);
		B->drawBoard(window,NOP);
		DrawWinner(window);
		DrawDice(window);
		window.display();
		if (AllSix())
		{
			//DrawDice(window);
			//window.display();
			sleep(seconds(1));
			EraseDice();
			B->getHome(Turn)->UnHighlightHome();
			turnChange();
			di = 0;
			rollingDice = true;
			diceRolled = false;
			indx = -1;
		}
		if (GameEnded())
		{
			//some graphics
		}
	}
}

//bool Ludo::isValidSc(int& indx)
//{
//	for (int i = Turn * 4; i < (Turn * 4) + 4; i++)
//	{
//		if (B->getPiece(i)->Contains(sri, sci))
//		{
//			indx = i;
//			return true;
//		}
//	}
//	return false;
//}