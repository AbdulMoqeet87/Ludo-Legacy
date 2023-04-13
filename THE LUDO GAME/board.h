#pragma once
#include<SFML/Graphics.hpp>

class home;
class Cell;
class piece;
class board
{
	private:

		Cell**Cs;
		home** Hs;
		piece** Ps;
	public:
		board();
		void drawBoard(sf::RenderWindow& window);
		bool isValidMove(int sri, int sci);
		void Move(int sri, int sci,int DValue);
		void drawHome(sf::RenderWindow& window);
	

};

