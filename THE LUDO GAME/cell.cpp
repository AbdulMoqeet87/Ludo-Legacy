#include<SFML/Graphics.hpp>
#include<fstream>
using namespace std;
using namespace sf;
#include "cell.h"

Cell::Cell(int _ri, int _ci, int _s, Color _C)
{
    this->ri = _ri;
    this->ci = _ci;
    this->size = _s;
    this->C = _C;
    this->P = nullptr;
    Rec.setSize(sf::Vector2f(size, size));
    Rec.setFillColor(C);
    Rec.setPosition(ci+40, ri+40);
}

Cell::Cell(istream& rdr, Color _C) :C{ _C }
{
    rdr >> ci;
    rdr >> ri;
    size = 40;
    Rec.setSize(sf::Vector2f(size, size));
    Rec.setFillColor(C);
    Rec.setPosition(ci+40, ri+40);
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
void Cell:: setOutlClr(sf::Color C)
{
    this->Rec.setOutlineColor(C);
}
void Cell::setOutlSize(int size)
{
    this->Rec.setOutlineThickness(5);
}
int Cell::getRow()
{
    return ri;
}
int Cell::getCol()
{
    return ci;
}
void Cell::setPiece(piece* NP)
{
    P = NP;
}
bool Cell::isClicked(int ri, int ci)
{
    return Rec.getLocalBounds().contains(ci, ri);

}
//piece* Cell::getPiece()
//{
//    return P;
//}

