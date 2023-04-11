#include "board.h"
#include<fstream>
#include"cell.h"
using namespace std;
board::board()
{
	ifstream rdr("Cells.txt");

	Cs = new Cell*[90];
	for (int i = 0; i < 90; i++)
	{
		Cs[i] = new Cell(rdr,sf::Color::White);
	}

}



void board::drawBoard(sf::RenderWindow& window)
{

	for (int i = 0; i < 90; i++)
	{
		Cs[i]->Draw(window);
	}


}