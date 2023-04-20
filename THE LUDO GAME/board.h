#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

class home;
class Cell;
class piece;
class board
{
	private:

		Cell**Cs;
		home** Hs;
		piece** Ps;
		sf::RectangleShape BigBox3;
		sf::RectangleShape BigBox2;
		sf::RectangleShape BigBox;
public:
		board(int NOP);
		//piece* getPiece(int ri,int ci);
		piece* getPiece(int indx);
		void drawBoard(sf::RenderWindow& window, int NOP);
		bool isValidMove(int sri, int sci);
		void Move(int sri, int sci,int DValue);
		void drawHome(sf::RenderWindow& window, int NOP);
		void setPiece(piece* P, int i);
		home* getHome(int i);
		void setCellColor(int ind);
		int getCellRow(int indx);
		int getCellCol(int indx);
};

