#include "board.h"
#include<fstream>
#include"cell.h"
using namespace std;
board::board()
{
	ifstream rdr("Cells.txt");

	for (int i = 0; i < 90; i++)
	{
		Cs[i] = new Cell(rdr);
	}

}



void board::drawBoard(sf::RenderWindow& window)
{

	for (int i = 0; i < 90; i++)
	{
		Cs[i]->Draw(window);
	}


}