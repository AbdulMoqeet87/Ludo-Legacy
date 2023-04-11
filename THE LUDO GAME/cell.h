#pragma once
#include<SFML/Graphics.hpp>
#include<fstream>
using namespace std;
using namespace sf;

class Cell
{
private:
	Color C;
	int ri, ci;
	int size;
	RectangleShape Rec;
public:
	Cell(istream& rdr);
	Cell(int _ri, int _ci, int _s, Color _C);
	void Draw(RenderWindow& window);
	void Highlight(RenderWindow& window, Color _C);
	void UnHighlight(RenderWindow& window);
};

