#pragma once
#include<SFML/Graphics.hpp>

class home;
class Cell;
class board
{
	private:

		Cell**Cs;

	public:
		board();
		void drawBoard(sf::RenderWindow& window);
		bool isValidMove(int sri, int sci);
		void Move(int sri, int sci);
		void drawHome();
	

};

