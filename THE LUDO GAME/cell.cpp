#include<SFML/Graphics.hpp>
using namespace sf;
#include "cell.h"

Cell::Cell(int _ri, int _ci, int _s, Color _C)
{
    this->ri = _ri;
    this->ci = _ci;
    this->size = _s;
    this->C = _C;
    Rec.setSize(sf::Vector2f(size, size));
    Rec.setFillColor(C);
    Rec.setPosition(ri, ci);
}

void Cell::Draw(RenderWindow& window)
{
    window.draw(Rec);
}

void Cell::Highlight(RenderWindow& window,Color _C)
{
    Rec.setFillColor(sf::Color::Cyan);
}

void Cell::UnHighlight(RenderWindow& window)
{
    Rec.setFillColor(C);
}