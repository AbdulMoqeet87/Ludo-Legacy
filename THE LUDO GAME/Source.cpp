#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"board.h"
#include"Dice.h"
#include"Ludo.h"
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
int main2()
{
    sf::Texture awai;
    awai.loadFromFile("BluePiece.png");
    
    sf::RenderWindow window(sf::VideoMode(1375, 696), "Ludo Game", sf::Style::Close | sf::Style::Resize);
    window.setPosition(sf::Vector2i(-10, 0));
    board B(2);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        B.drawBoard(window,2);
        B.drawHome(window,2);
       
        window.display();
    }

    return 0;
}

void Amna_Moqeet(sf::RenderWindow& window, sf::Text& RG, sf::Text &A_M, sf::Sound &StrangerT,  sf::Sprite Neonsky)
{
    sf::Color neonPurple(205, 0, 205);
    sf::Color neonBlue(0, 246, 255);
    StrangerT.play();
    
         RG.setOutlineThickness(4);
         RG.setOutlineColor(neonPurple);
    RG.setFillColor(sf::Color::White);
    A_M.setFillColor(neonBlue);
      int r = 0;
          
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (r == 1000)break;
        window.clear();
        r++;
     

         window.draw(Neonsky);
         window.draw(RG);
         window.draw(A_M);
         window.display();
     
    }
   sf::sleep(sf::seconds(1));

}
void RisingGeeks(sf::RenderWindow& window,sf::Text &RG,sf::Sound Glitch)
{

    int j = 0;
    Glitch.play();
    while (window.isOpen())
    {
     
       sf::Event event;
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
    }
       if (j % 7 == 0)
           RG.setFillColor(sf::Color::White);
       else
           RG.setFillColor(sf::Color::Black);
      if (j == 2200)
          break;
      window.clear();
        j++;
       
        //window.clear(navy_blue);
       
        window.draw(RG);
      
      //window.draw(A_M);
      window.display();
    }
   RG.setFillColor(sf::Color::Black);
   Glitch.stop();
  sf:: sleep(sf::seconds(1.5));

}
void MajesticMoves(sf::RenderWindow& window, sf::Text& Majestic, sf::Text& Moves,sf::Sprite Neon, sf::ConvexShape _PlayButton, sf::ConvexShape PlayButton2)
{
    //StrangerT.play();
    Majestic.setFillColor(sf::Color::White);
    sf::Color neonPurple(205, 0, 205);
    sf::Color neonBlue(0, 246, 255);
    int r = 0; bool Button_pressed = false;;
    //_PlayButton.setScale(1.5, 1.5);

    while (window.isOpen())
    {
        sf::Event evnt;
        window.clear();
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
            if (evnt.type == Event::MouseMoved)
            {
                sf::Vector2i P = sf::Mouse::getPosition(window);
              
                if (_PlayButton.getLocalBounds().contains(P.x, P.y))
                {
                    _PlayButton.setPoint(0, sf::Vector2f(645, 530));
                    _PlayButton.setPoint(1, sf::Vector2f(725, 570));
                    _PlayButton.setPoint(2, sf::Vector2f(645, 610));
                    //----------------------------------------------
                    PlayButton2.setPoint(0, sf::Vector2f(650, 535));
                    PlayButton2.setPoint(1, sf::Vector2f(720, 570));
                    PlayButton2.setPoint(2, sf::Vector2f(650, 605));

                }
               else
                {
                    _PlayButton.setPoint(0, sf::Vector2f(660, 540));
                    _PlayButton.setPoint(1, sf::Vector2f(720, 570));
                    _PlayButton.setPoint(2, sf::Vector2f(660, 600));
                    //----------------------------
                    PlayButton2.setPoint(0, sf::Vector2f(665, 545));
                    PlayButton2.setPoint(1, sf::Vector2f(715, 570));
                    PlayButton2.setPoint(2, sf::Vector2f(665, 595));
                }
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i P = sf::Mouse::getPosition(window);

                if (PlayButton2.getLocalBounds().contains(P.x, P.y))
                {
                    Button_pressed = true;
                    break;
                }
            
            }
        }
        r++;
        if (Button_pressed)break;

        if (r > 2000)
        {
            Majestic.setFillColor(sf::Color::White);
            //Moves.setFillColor(sf::Color::White);

            window.draw(Neon);
            Majestic.setOutlineThickness(3);
            Majestic.setOutlineColor(neonPurple);
            Moves.setOutlineThickness(3);
            Moves.setOutlineColor(neonPurple);

            /*Moves2.setOutlineThickness(3);
            Moves2.setOutlineColor(sf::Color::Black);*/
        }
        if (r >2200 )
        {
         
            window.draw(PlayButton2);
            window.draw(_PlayButton);

        }
        if (r >= 1000)
        window.draw(Majestic);
       
        if(r>=1500)
        window.draw(Moves);
        window.display();
    }
    //sf::sleep(sf::seconds(1));

}
void SelectPlayer( RenderWindow& window, Sprite SP,int &Nop, Text SelectP, Text PT, sf::Text PF,Text &PS)
{
    sf::Color neonPurple(205, 0, 205);
    sf::Color neonBlue(0, 246, 255);

    SP.setScale(0.25, 0.25);
    SP.setPosition(5, 0);

    //-------------------------
    
    //-----------------------------
    bool break_ = false;
    while (window.isOpen())
    {
       
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        
            if (evnt.type == Event::MouseMoved)
            {
                sf::Vector2i mouseP = sf::Mouse::getPosition(window);


                if ((mouseP.x >= 130 && mouseP.x < 333) && (mouseP.y >= 353 && mouseP.y < 394))
                {
                    PT.setFillColor(sf::Color::Red);
                    PT.setCharacterSize(45);
                }
                else  
                {
                    PT.setFillColor(neonBlue);
                    PT.setCharacterSize(40);
                }

                if ((mouseP.x >= 130 && mouseP.x < 333) && (mouseP.y >= 453 && mouseP.y < 494))
                {
                    PF.setFillColor(sf::Color::Red);
                    PF.setCharacterSize(45);
                }

                else
                {
                    PF.setFillColor(neonBlue);
                    PF.setCharacterSize(40);
                }
                if ((mouseP.x >= 130 && mouseP.x < 333) && (mouseP.y >= 553 && mouseP.y < 594))
                {
                    PS.setFillColor(sf::Color::Red);
                    PS.setCharacterSize(45);
                
                }
                else
                {
                    PS.setFillColor(neonBlue);
                    PS.setCharacterSize(40);
                }
              
            }
             if (evnt.type == Event::MouseButtonPressed)
            {
                sf::Vector2i mouseP = sf::Mouse::getPosition(window);

                if ((mouseP.x >= 130 && mouseP.x < 333) && (mouseP.y >= 353 && mouseP.y < 394))
                {
                    break_ = true;
                    Nop = 2; break;
                }
                if ((mouseP.x >= 130 && mouseP.x < 333) && (mouseP.y >= 453 && mouseP.y < 494))
                {
                    break_ = true;
                    Nop = 4;
                    break;
                }
                if ((mouseP.x >= 130 && mouseP.x < 333) && (mouseP.y >= 553 && mouseP.y < 594))
                {
                    break_ = true;
                    Nop = 6;
                    break;
                }
           
            }
            if(break_ == true)
                break;
        
        }

        if (break_ == true)
            break;

        window.clear();
        window.draw(SP);
        window.draw(SelectP);
        window.draw(PT);
        window.draw(PF);
        window.draw(PS);

        window.display();
    }
}

int main()
{

    sf::RenderWindow window(sf::VideoMode(1375, 696), "Ludo Game", sf::Style::Close | sf::Style::Resize);
    window.setPosition(sf::Vector2i(-10, 0));

    sf::Color neonPurple(205, 0, 205);
    sf::Font GOT;
    sf::Font Lato;
    Lato.loadFromFile("Lato.ttf");
    GOT.loadFromFile("GameOfThrones.ttf");
    sf::Color navy_blue(0, 0, 128);
    sf::Color neonBlue(0, 246, 255);

    sf::Text RisingGeek("RISING   GEEKS", GOT, 80);
    RisingGeek.setPosition(360, 190);
    RisingGeek.setFillColor(sf::Color::White);
    sf::Text Majestic("LUDO", GOT, 80);
    Majestic.setPosition(535, 250);
    Majestic.setFillColor(neonPurple);
    sf::Text Moves("LEGACY", GOT, 80);
    Moves.setPosition(500, 360);
    Moves.setFillColor(neonBlue);
    sf::Text Moves2("M   VES", GOT, 80);
    Moves2.setPosition(770, 250);
    Moves2.setFillColor(sf::Color::White);
    sf::Texture NE;
    NE.loadFromFile("NeonP1.png");
    sf::Sprite Neon(NE);
    Neon.setScale(0.35, 0.35);
    Neon.setPosition(5, 0);
    sf::Texture Dc;
    Dc.loadFromFile("UniqDixe.png");
    sf::Sprite _Dice(Dc);
   // Dice.setScale(0.55, 0.55);
    _Dice.setPosition(830, 220);
    _Dice.setScale(0.9,0.9);
    sf::Texture NS;
    NS.loadFromFile("NeonSky_.png");
    sf::Sprite NeonSky(NS);
    NeonSky.setScale(0.35, 0.35);
    NeonSky.setPosition(5, 0);
	sf::Color blur = sf::Color(255, 255, 255, 130);
    //----------------------------

    //----------------------------
    sf::ConvexShape PlayButton;
    PlayButton.setPointCount(3);
    //===============================

    PlayButton.setOutlineThickness(3);
    PlayButton.setPoint(0, sf::Vector2f(660, 540));
    PlayButton.setPoint(1, sf::Vector2f(720, 570));
    PlayButton.setPoint(2, sf::Vector2f(660, 600));
    PlayButton.setFillColor(blur);
    PlayButton.setOutlineColor(neonPurple);
    //PlayButton.setPosition(40, 80);
    //--------------------
    sf::ConvexShape PlayButton2;
    PlayButton2.setPointCount(3);
    PlayButton2.setPoint(0, sf::Vector2f(665, 545));
    PlayButton2.setPoint(1, sf::Vector2f(715, 570));
    PlayButton2.setPoint(2, sf::Vector2f(665, 595));
    PlayButton2.setOutlineThickness(7);
    PlayButton2.setOutlineColor(neonBlue);
    PlayButton2.setFillColor(blur);

    //---------------------------------
    int NOP = 0;
    sf::SoundBuffer Gl;
    sf::SoundBuffer ST;
    Gl.loadFromFile("Glitch.wav");
    ST.loadFromFile("StrangerThingsOrg.wav");
    sf::Sound Glitch(Gl);
    sf::Sound StrangerT(ST);
    sf::Text Amna_MOq("AMNA   and   MOQEET", GOT, 30);
    Amna_MOq.setPosition(500, 350);
    Amna_MOq.setFillColor(sf::Color::White);
 
  // Dice D(1150, 500);
   // board B(NOP);
    //-----------------------------------------
    sf::Text SelectP("SELECT  PLAYERS", GOT, 80);
    //SelectP.setPosition(345, 100);
    SelectP.setFillColor(neonPurple);
    SelectP.setPosition(335 , 100 );
    //-----------------------------
    sf::Text P2("2 PLAYERS", Lato, 40);
    P2.setPosition(130, 350);
    P2.setFillColor(neonBlue);
    //-----------------------------
    sf::Text P4("4 PLAYERS", Lato, 40);
    P4.setPosition(130, 450);
    P4.setFillColor(neonBlue);
    //-----------------------------
    sf::Text P6("6 PLAYERS", Lato, 40);
    P6.setPosition(130, 550);
    P6.setFillColor(neonBlue);

    //---------------------------------
    sf::Texture SP;
    SP.loadFromFile("SelectPlayer.jpg");
    sf::Sprite SPl(SP);

//-------------------------------------
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        RisingGeeks(window,RisingGeek,Glitch);
        Amna_Moqeet(window, RisingGeek, Amna_MOq,StrangerT, NeonSky); 
        MajesticMoves(window, Majestic, Moves,Neon,PlayButton,PlayButton2);
        SelectPlayer(window,SPl, NOP,SelectP, P2, P4, P6);
        Ludo L(NOP);
        L.play(window);      
        window.display();
    }
    return 0;
}
