#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<vector>

class home;
class Cell;
class piece;
class player;
class board
{
	private:

		Cell**Cs;
		home** Hs;
		piece** Ps;
		sf::Sprite Win;
		sf::Texture WinTex;
	public:
		board(int NOP);
		//piece* getPiece(int ri,int ci);
		piece* getPiece(int indx);
		//void drawBoard(sf::RenderWindow& window, int NOP);
		void drawBoard(sf::RenderWindow& window, int NOP, std::vector<int> JootaIndx, std::vector<player*> WinPs);
		bool isValidMove(int sri, int sci);
		void Move(int sri, int sci,int DValue);
		//void drawHome(sf::RenderWindow& window, int NOP);
		void drawHome(sf::RenderWindow& window, int NOP, std::vector<int> JootaIndx);
		void setPiece(piece* P, int i);
		home* getHome(int i);
		void setCellColor(int ind);
		int getCellRow(int indx);
		int getCellCol(int indx);
		void DrawWinner(std::vector<player*> WinPs,sf::RenderWindow& window);

};

