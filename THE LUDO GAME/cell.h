#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Cell
{
private:
	Color C;
	int ri, ci;
	int size;
	RectangleShape Rec;
public:
	Cell(int _ri, int _ci, int _s, Color _C);
	void Draw(RenderWindow& window);
	void Highlight(RenderWindow& window, Color _C);
	void UnHighlight(RenderWindow& window);
};

