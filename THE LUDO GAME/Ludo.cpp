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
	Ds[0] = new Dice(1000,300);
	Ds[1] = new Dice(1100,300);
	Ds[2] = new Dice(1200,300);
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
void Ludo::RollDice(sf::RenderWindow& window)
{
	int di = 0;
	Ds[di]->rollDice(B, window);
	if (Ds[di]->getDiceValue() == 6)
	{
		di++;
	}
}

void Ludo::Move()
{

}

void Ludo::play(sf::RenderWindow& window)
{
	int indx = -1;
	bool selected = false;
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
			/*	sri = mousePos.y+40;
				sci = mousePos.x+40;
			*/
				sri = mousePos.y ;
				sci = mousePos.x;
				selected = true;

			
			}
			if (selected)
			{
				if (isValidSc(indx))
				{
					//B->getPiece(indx)->setPosition(B->getHome(Turn)->getInitialPos());
					B->setCellColor(B->getHome(Turn)->getSafeSpot());

					turnChange();
					selected = false;
					indx = -1;
				}
				
			
			}
			
		}


		window.clear();
		B->drawBoard(window);
		window.display();
	}
}