#include "board.h"
#include<fstream>
#include"cell.h"
#include"home.h"
using namespace std;
board::board()
{
	ifstream rdr("Cells.txt");
	Cs = new Cell * [90];
	for (int i = 0; i < 90; i++)
	{
		Cs[i] = new Cell(rdr,sf::Color::White);
	}
	Hs = new home*[6];
	for (int i = 0; i < 6; i++)
	{


	}
}



void board::drawBoard(sf::RenderWindow& window)
{

	for (int i = 0; i < 90; i++)
	{
		Cs[i]->Draw(window);
	}


}

void board::drawHome()
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





}