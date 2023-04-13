#include "Ludo.h"
#include"Dice.h"
#include"player.h"
#include"board.h"
#include"piece.h"
#include"home.h"
#include<fstream>
#include<string>
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

	Ps[0] = new player("Amna", maroon);
	Ps[1] = new player("Moqeet", purple);
	Ps[2] = new player("Abaid", dark_green);
	Ps[3] = new player("Mahnoor", golden_yellow);
	Ps[4] = new player("Minahil", dark_grey);
	Ps[5] = new player("Fahira", navy_blue);
	B = new board();
	dice = new Dice(1150, 500);
	dice->setDiceValue(2);
	Ds[0] = new Dice(1100,100);
	Ds[1] = new Dice(1200,100);
	Ds[2] = new Dice(1300,100);
	Turn = 0;
	sri = 0, sci = 0;
}

void Ludo::turnChange()
{
	if (Turn == 5)
	{
		Turn = 0;
	}
	else
	{
		Turn++;
	}
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

bool Ludo::isValidSc(int &indx)
{
	for (int i = Turn * 4; i < (Turn * 4) + 4; i++)
	{
		if (B->getPiece(i)->Contains(sri, sci))
		{
			indx = i;
			return true;
		}
	}
	return false;
}

void Ludo::RollDice(sf::RenderWindow& window, int& di)
{
	dice->rollDice(B, window);
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
		else
			break;
	}
	dice->drawDice(window);
}

void Ludo::Move(int indx,int DiceIndx)
{
	if (Ds[DiceIndx]->getDiceValue() == 6 && B->getPiece(indx)->getInitialRow()==sri && B->getPiece(indx)->getInitialCol() == sci)
	{
		B->getPiece(indx)->setPosition(B->getCellCol(B->getHome(Turn)->getInitialPos()) + 38, B->getCellRow(B->getHome(Turn)->getInitialPos()) + 42);
		B->getPiece(indx)->setCellIndex(B->getHome(Turn)->getInitialPos());
	}
	else
	{
		B->getPiece(indx)->setCellIndex(B->getPiece(indx)->getCellIndex() + Ds[DiceIndx]->getDiceValue());
		B->getPiece(indx)->setPosition(B->getCellCol(B->getPiece(indx)->getCellIndex()) + 38, B->getCellRow(B->getPiece(indx)->getCellIndex()) + 42);
	}
}

bool Ludo::clickedDice()
{
	if (dice->isClicked(sri,sci))
		return true;
	return false;
}

bool Ludo::canMove()
{
	if (!Ps[Turn]->canMove() && Ds[0]->getDiceValue() == 6)
	{
		Ps[Turn]->setCanMove(true);
		return true;
	}
	else if (Ps[Turn]->canMove())
		return true;
	else
		return false;
}

void Ludo::selectDiceValue(int& DiceIndx)
{
	for (int i = 0; i < 3; i++)
	{
		if (Ds[i] != 0 && Ds[i]->isClicked(sri, sci))
			DiceIndx = i;
	}
}

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
			if (event.type == Event::MouseButtonPressed)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sri = mousePos.y;
				sci = mousePos.x;
				selected = true;
				if (rollingDice)
				{
					if (clickedDice())
					{
						RollDice(window, di);
						if (Ds[di]->getDiceValue() != 6)
							rollingDice = false, diceRolled = true;
						else if (di == 2 && Ds[di]->getDiceValue() == 6)
							rollingDice = false;
						else
							di++;
					}
				}
				if (diceRolled)
				{
					selectDiceValue(DiceIndx);
					di--;
					if (di == 0)
						diceRolled = false;
					selected = false;
					canSelect = true;
				}
				if (canSelect)
				{
					if (selected)
					{
						if (canMove())
						{
							if (isValidSc(indx))
							{
								//B->getPiece(indx)->setPosition(B->getHome(Turn)->getInitialPos());
								//B->setCellColor(B->getHome(Turn)->getSafeSpot());
								//RollDice(window);
								Move(indx, DiceIndx);
								turnChange();
								selected = false;
								indx = -1;
								di = 0;
							}
						}
						else
						{
							turnChange();
							selected = false;
							indx = -1;
							di = 0;
						}
					}
				}
			}
		}
		window.clear();
		B->drawBoard(window);
		DrawDice(window);
		window.display();
	}
}
