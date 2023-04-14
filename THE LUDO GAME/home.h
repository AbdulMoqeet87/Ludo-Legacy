#pragma once
#include<fstream>
#include<SFML/Graphics.hpp>
#include<string>
using namespace sf;
using namespace std;


class Cell;

class home
{
private:
	int InitialPos;
	int SafeSpot;
	Cell** Cs;
	int ri, ci;
	Cell* Background;
	Color C;
	Texture Tex;
	Sprite Pic;
	Texture Circ;
	Sprite* Circles;
	public:
	home(istream& rdr, int IP,int SP, Color _C,string FileName,int pc,int pr);
	void Draw(RenderWindow& window);
	int getSafeSpot();
	int getInitialPos();
	bool IsSafeSpot(int indx);
	bool IsInitSpot(int indx);
	sf::Color getHOmeColor();
	int getRow();
	int getCol();
	bool clickedHomePiece(int ri, int ci,int &pi);
};

