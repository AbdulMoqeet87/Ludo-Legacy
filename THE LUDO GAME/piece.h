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
};
