#pragma once
#include<fstream>
#include<SFML/Graphics.hpp>
#include<string>
using namespace sf;
using namespace std;

class board;
class Cell;
class Ludo;
class home
{
private:
	int InitialPos;
	int SafeSpot;
	int pic_r, pic_c;
	int TurningPos;
	Cell** Cs;
	int ri, ci;
	Cell* Background;
	Color C;
	Texture Tex;
	Texture Tex2;
	Sprite Pic;
	Texture Circ;
	Sprite* Circles;
	sf::ConvexShape Arrow;
	sf::ConvexShape WinTri;
	bool hasKilled;
public:
	home(istream& rdr, int IP, int SP, int TP, Color _C, string FileName, string FileName2, int pc, int pr);
	void Draw(RenderWindow& window);
	int getSafeSpot();
	int getInitialPos();
	bool IsSafeSpot(int indx);
	bool IsInitSpot(int indx);
	bool IsTurningSpot(int indx);
	sf::Color getHOmeColor();
	int getRow();
	int getCol();
	bool clickedHomePiece(int ri, int ci, int& pi);
	bool isHomeCell(int r, int c);
	void getHomeCellPos(int i, int& r, int& c);
	void HighlightHome();
	void UnHighlightHome();
	void Blink(sf::RenderWindow& window, board* b, Ludo* L, Sprite BG,int NOP);

};

