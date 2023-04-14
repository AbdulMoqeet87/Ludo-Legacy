#pragma once
#include"utility.h"
#include<SFML/Graphics.hpp>
#include<fstream>;
#include<iostream>
using namespace sf;
using namespace std;
class piece
{
	int ri, ci;
	int InitialRow, InitialCol;
	int CellIndx;
	Texture P;
	Sprite Pc;
	Color C;
public:
	piece(int ci,int ri,Color,string Cn);
	piece(istream& Rdr,Color,string Cn);
	void Draw(RenderWindow& window);
	Color getColor();
	bool Contains(int ri, int ci);
	void setPosition(int ci, int ri);
	int getInitialRow();
	int getInitialCol();
	void setCellIndex(int ci);
	int getCellIndex();
	void setRow(int r);
	void setCol(int c);
	int  GetRow();
	int GetCol();

};
