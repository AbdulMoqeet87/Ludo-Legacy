#pragma once
#include<SFML/Graphics.hpp>

class home;

class board
{
	private:

	public:
		board();
		void drawBoard(sf::RenderWindow& window);
		bool isValidMove(int sri, int sci, int dri, int dci);
		void Move(int sri, int sci, int dri, int dci);
		void drawHome();
	

};

