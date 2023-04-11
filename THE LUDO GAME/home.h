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
	Color C;
	Sprite Pic;
public:
	home(istream& rdr, int IP,int SP, Color _C,string FileName);
	void Draw(RenderWindow& window);
	int getSafeSpot();
	int getInitialPos();
};

