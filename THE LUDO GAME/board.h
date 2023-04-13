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
		//piece* getPiece(int ri,int ci);
		piece* getPiece(int indx);
		void drawBoard(sf::RenderWindow& window);
		bool isValidMove(int sri, int sci);
		void Move(int sri, int sci,int DValue);
		void drawHome(sf::RenderWindow& window);
		void setPiece(piece* P, int i);
		home* getHome(int i);
		void setCellColor(int ind);

};

