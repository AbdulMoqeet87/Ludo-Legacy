#include<iostream>
#include<SFML/Graphics.hpp>
#include"board.h"
using namespace std;
//using namespace sf;

int main1()
{
    //AMNA
    //-------------------------
    sf::Color greyish_green(64, 96, 64);
    sf::Color dark_yellow(153, 153, 0);
    sf::Color dark_green(0, 100, 0);
    sf::Color maroon(128, 0, 0);
    sf::Color navy_blue(0, 0, 128);
    sf::Color mustard(204, 187, 68);
    sf::Color metallic_grey(139, 139, 131);
    sf::Color dark_grey(64, 64, 64);
    sf::Color golden_yellow(255, 215, 0);
    sf::Color more_yellowish_yellow(255, 255, 51);
    sf::Color purple(128, 0, 128);
    //------------------------------
    sf::ConvexShape head;
    head.setPointCount(3);
    head.setPoint(0, sf::Vector2f(0, 0));
    head.setPoint(1, sf::Vector2f(20, 10));
    head.setPoint(2, sf::Vector2f(0, 20));
    head.setFillColor(maroon);
    head.setPosition(10,292);
    //head.setRotation(180);
    //-------------------------------------------------
    
    sf::CircleShape C1(22);
    C1.setFillColor(sf::Color::White);
    C1.setPosition(20, 15);
   
    sf::CircleShape C2(22);
    C2.setFillColor(sf::Color::White);
    C2.setPosition(180, 15);
    
    sf::CircleShape C3(22);
    C3.setFillColor(sf::Color::White);
    C3.setPosition(20, 180);
    
    sf::CircleShape C4(22);
    C4.setFillColor(sf::Color::White);
    C4.setPosition(180, 180);


    //-------------------------------------------------
    sf::RenderWindow window(sf::VideoMode(1375, 696), "Abdul SFML", sf::Style::Close | sf::Style::Resize);
    window.setPosition(sf::Vector2i(-10, 0));
    //-----------------------------------------
    sf::Texture Wolf;
    Wolf.loadFromFile("Player1_bg.png");
    sf::Sprite P1(Wolf);
    P1.setPosition(-15, 10);
    P1.setScale(0.7, 0.7);

    sf::Texture Horse;
    Horse.loadFromFile("p2.png");
    sf::Sprite P2(Horse);
    P2.setPosition(-35, 390);
    P2.setScale(0.7, 0.7);
 
    sf::Texture shark;
    shark.loadFromFile("shark.png");
    sf::Sprite P3(shark);
    P3.setPosition(720, 380);
    P3.setScale(0.7, 0.7);
    
    sf::Texture lion;
    lion.loadFromFile("lionC.png");
    sf::Sprite P4(lion);
    P4.setPosition(350, 380);
    P4.setScale(0.7, 0.7);
   
    sf::Texture Elephant;
    Elephant.loadFromFile("elephantfront.png");
    sf::Sprite P5(Elephant);
    P5.setPosition(350,10);
    P5.setScale(0.7, 0.7);
    
    sf::Texture Tiger;
    Tiger.loadFromFile("tiger2.png");
    sf::Sprite P6(Tiger);
    P6.setPosition(700,10);
    P6.setScale(0.8, 0.8);


    //------------------------------------------------
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(235, 235));
    shape.setPosition(5, 0);

    shape.setFillColor(maroon);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(5);

    sf::RectangleShape shape1;
    shape1.setSize(sf::Vector2f(40, 40));
    shape1.setFillColor(sf::Color::White);
    shape1.setPosition(0,241);
    
    sf::RectangleShape shape2;
    shape2.setSize(sf::Vector2f(40, 40));
    shape2.setFillColor(sf::Color::White);
    shape2.setPosition(0, 282);

    sf::RectangleShape shape3;
    shape3.setSize(sf::Vector2f(40,40));
    shape3.setFillColor(sf::Color::White);
    shape3.setPosition(0, 323);

    sf::RectangleShape shape4;
    shape4.setSize(sf::Vector2f(235, 235));
    shape4.setFillColor(navy_blue);
    shape4.setPosition(5, 369);
    shape4.setOutlineColor(sf::Color::White);
    shape4.setOutlineThickness(5);
    //----------------------------


    sf::RectangleShape shape6;
    shape6.setSize(sf::Vector2f(40, 40));
    shape6.setFillColor(maroon);
    shape6.setPosition(246, 0);

    sf::RectangleShape shape7;
    shape7.setSize(sf::Vector2f(40, 40));
    shape7.setFillColor(sf::Color::White);
    shape7.setPosition(287, 0);

    sf::RectangleShape shape8;
    shape8.setSize(sf::Vector2f(40, 40));
    shape8.setFillColor(sf::Color::White);
    shape8.setPosition(328, 0);

    sf::RectangleShape shape9;
    shape9.setSize(sf::Vector2f(235, 235));
    shape9.setFillColor(purple);
    shape9.setPosition(374, 0);
    shape9.setOutlineColor(sf::Color::Red);
    shape9.setOutlineThickness(5);
    
   //-------------------------------
    
    sf::RectangleShape shape10;
    shape10.setSize(sf::Vector2f(40, 40));
    shape10.setFillColor(sf::Color::White);
    shape10.setPosition(615, 0);

    sf::RectangleShape shape11;
    shape11.setSize(sf::Vector2f(40, 40));
    shape11.setFillColor(sf::Color::White);
    shape11.setPosition(656, 0);

    sf::RectangleShape shape12;
    shape12.setSize(sf::Vector2f(40, 40));
    shape12.setFillColor(sf::Color::White);
    shape12.setPosition(697, 0);

    sf::RectangleShape shape13;
    shape13.setSize(sf::Vector2f(235, 235));
    shape13.setFillColor(dark_green);
    shape13.setPosition(743, 0);
    shape13.setOutlineColor(sf::Color::White);
    shape13.setOutlineThickness(5);
    //-------------------------------------
    
    sf::RectangleShape shape14;
    shape14.setSize(sf::Vector2f(40, 40));
    shape14.setFillColor(sf::Color::White);
    shape14.setPosition(943, 241);

    sf::RectangleShape shape15;
    shape15.setSize(sf::Vector2f(40, 40));
    shape15.setFillColor(sf::Color::White);
    shape15.setPosition(943, 282);

    sf::RectangleShape shape16;
    shape16.setSize(sf::Vector2f(40, 40));
    shape16.setFillColor(sf::Color::White);
    shape16.setPosition(943, 323);

    sf::RectangleShape shape17;
    shape17.setSize(sf::Vector2f(235, 235));
    shape17.setPosition(743, 369);
    shape17.setFillColor(golden_yellow);
    shape17.setOutlineColor(sf::Color::White);
    shape17.setOutlineThickness(5);
//------------------------------------------

    sf::RectangleShape shape18;
    shape18.setSize(sf::Vector2f(40, 40));
    shape18.setFillColor(sf::Color::White);
    shape18.setPosition(697, 569);
    
    sf::RectangleShape shape19;
    shape19.setSize(sf::Vector2f(40, 40));
    shape19.setFillColor(sf::Color::White);
    shape19.setPosition(656, 569);

    sf::RectangleShape shape20;
    shape20.setSize(sf::Vector2f(40, 40));
    shape20.setFillColor(sf::Color::White);
    shape20.setPosition(615, 569);
//-------------------------------------------
    sf::RectangleShape shape21;
    shape21.setSize(sf::Vector2f(40, 40));
    shape21.setFillColor(sf::Color::White);
    shape21.setPosition(246, 569);

    sf::RectangleShape shape22;
    shape22.setSize(sf::Vector2f(40, 40));
    shape22.setFillColor(sf::Color::White);
    shape22.setPosition(287, 569);

    sf::RectangleShape shape23;
    shape23.setSize(sf::Vector2f(40, 40));
    shape23.setFillColor(sf::Color::White);
    shape23.setPosition(328, 569);

    sf::RectangleShape shape24;
    shape24.setSize(sf::Vector2f(235, 235));
    shape24.setFillColor(sf::Color::Black);
    shape24.setPosition(374, 369);
    shape24.setOutlineColor(sf::Color::White);
    shape24.setOutlineThickness(5);




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /*window.clear();
        window.draw(shape);
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
        window.draw(shape4);
        window.draw(shape6);
        window.draw(shape7);
        window.draw(shape8);
        window.draw(shape9);
        window.draw(shape10);
        window.draw(shape11);
        window.draw(shape12);
        window.draw(shape13);
        window.draw(shape14);
        window.draw(shape15);
        window.draw(shape16);
        window.draw(shape17);
        window.draw(shape18);
        window.draw(shape19);
        window.draw(shape20);
         window.draw(shape21);
        window.draw(shape22);
        window.draw(shape23);
        window.draw(shape24);
        window.draw(head);
        window.draw(P1);
        window.draw(P2);
        window.draw(P3);
        window.draw(P4);
        window.draw(P5);
        window.draw(P6);
        window.draw(C1);
        window.draw(C2);
        window.draw(C3);
        window.draw(C4);*/







        window.display();
    }

    return 0;
}

int main()
{
    sf::Texture awai;
    awai.loadFromFile("BluePiece.png");
    
    sf::RenderWindow window(sf::VideoMode(1375, 696), "Ludo Game", sf::Style::Close | sf::Style::Resize);
    window.setPosition(sf::Vector2i(-10, 0));
    board B;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        B.drawBoard(window);
        B.drawHome(window);
       
        window.display();
    }

    return 0;
}

