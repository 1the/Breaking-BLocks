//<--Alaa Mahmoud, Alaa Karem, Alaa Ahmed,Eman Mohammed, Yasmin Hagag-->


#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<sstream>

using namespace std;
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(510, 600), "tic game" );
      x:


    // colors balls
      sf::Texture blue;
    blue.loadFromFile("data/block01.png");
    //red
    sf::Texture red;
    red.loadFromFile("data/block02.png");
    //cyan
    sf::Texture cyan;
    cyan.loadFromFile("data/block03.png");
    //green
    sf::Texture green;
    green.loadFromFile("data/block04.png");
    //grey
    sf::Texture grey;
    grey.loadFromFile("data/block05.png");

    // blocks
    sf::RectangleShape b1;
    b1.setSize(sf::Vector2f(120,40));
    b1.setPosition(0,0);
    b1.setTexture(&blue);

    sf::RectangleShape b2;
    b2.setSize(sf::Vector2f(120,40));
    b2.setPosition(130,0);
    b2.setTexture(&grey);

    sf::RectangleShape b3;
    b3.setSize(sf::Vector2f(120,40));
    b3.setPosition(260,0);
    b3.setTexture(&green);

    sf::RectangleShape b4;
    b4.setSize(sf::Vector2f(120,40));
    b4.setPosition(390,0);
    b4.setTexture(&red);

    sf::RectangleShape b5;
    b5.setSize(sf::Vector2f(120,40));
    b5.setPosition(0,50);
    b5.setTexture(&cyan);

    sf::RectangleShape b9;
    b9.setSize(sf::Vector2f(120,40));
    b9.setPosition(0,100);
    b9.setTexture(&red);

    sf::RectangleShape b13;
    b13.setSize(sf::Vector2f(120,40));
    b13.setPosition(0,150);
    b13.setTexture(&grey);

    sf::RectangleShape b6;
    b6.setSize(sf::Vector2f(120,40));
    b6.setPosition(130,50);
    b6.setTexture(&blue);

    sf::RectangleShape b7;
    b7.setSize(sf::Vector2f(120,40));
    b7.setPosition(260,50);
    b7.setTexture(&green);

    sf::RectangleShape b8;
    b8.setSize(sf::Vector2f(120,40));
    b8.setPosition(390,50);
    b8.setTexture(&cyan);

    sf::RectangleShape b10;
    b10.setSize(sf::Vector2f(120,40));
    b10.setPosition(130,100);
    b10.setTexture(&red);

    sf::RectangleShape b11;
    b11.setSize(sf::Vector2f(120,40));
    b11.setPosition(260,100);
    b11.setTexture(&grey);

    sf::RectangleShape b16;
    b16.setSize(sf::Vector2f(120,40));
    b16.setPosition(0,200);
    b16.setTexture(&red);

    sf::RectangleShape b14;
    b14.setSize(sf::Vector2f(120,40));
    b14.setPosition(130,150);
    b14.setTexture(&green);

   sf::RectangleShape b12;
    b12.setSize(sf::Vector2f(120,40));
    b12.setPosition(390,100);
    b12.setTexture(&blue);

    sf::RectangleShape b15;
    b15.setSize(sf::Vector2f(120,40));
    b15.setPosition(390,150);
    b15.setTexture(&cyan);

    sf::RectangleShape b17;
    b17.setSize(sf::Vector2f(120,40));
    b17.setPosition(390,200);
    b17.setTexture(&green);



     sf::Texture paddle;
     paddle.loadFromFile("data/paddle.png");
     sf::RectangleShape player(sf::Vector2f(100, 10));
   player.setOrigin(player.getSize()/2.f );
   player.setTexture(&paddle);
   player.setPosition(window.getSize().x / 2+100, window.getSize().y -20);

   // screen
    sf::Text scoreOnScreen;
  scoreOnScreen.setPosition(window.getSize().x / 2.f - 120, 3.f);
  scoreOnScreen.setCharacterSize(30);
  scoreOnScreen.setFillColor(sf::Color::White);

  sf::RectangleShape loosing(sf::Vector2f(510, 600));
  loosing.setOrigin(loosing.getSize() / 2.f);

  sf::Texture game;
  game.loadFromFile("data/game.png");
  loosing.setTexture(&game);
  loosing.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

 sf::RectangleShape loosin(sf::Vector2f(510, 600));
  loosin.setOrigin(loosin.getSize() / 2.f);
  sf::Texture gam;
  gam.loadFromFile("data/gam.png");
  loosin.setTexture(&gam);
  loosin.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

   //ball
   sf::CircleShape ball(10);
   ball.setFillColor(sf::Color(222,103,48));
   ball.setPosition(250,300);


   // baddlee
    bool paddleRight = false;
    bool paddleLeft = false;

    float xSteps = 0.3;
    float ySteps = 0.3;
    float ballRadius = 10;
    ball.setOrigin(20,20);

  int cnt=0;
  long double deltatime = 0;
  bool lose=false;
  sf::Event event;

while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();

        }
        if(lose==false){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                paddleRight = true;
            }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                paddleLeft = true;
            }

         if (paddleRight)
            {
                player.move(2,0);
                paddleRight = false;
            }
              if (paddleLeft)
            {
                player.move(-2,0);
                paddleLeft = false;
            }


// coliision

if(ball.getGlobalBounds().intersects(b1.getGlobalBounds())==true)
        {
            b1.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b2.getGlobalBounds())==true)
        {
            b2.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b3.getGlobalBounds())==true)
        {
            b3.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b4.getGlobalBounds())==true)
        {
            b4.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b5.getGlobalBounds())==true)
        {
            b5.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b6.getGlobalBounds())==true)
        {
            b6.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b7.getGlobalBounds())==true)
        {
            b7.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b8.getGlobalBounds())==true)
        {
            b8.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b9.getGlobalBounds())==true)
        {
            b9.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b10.getGlobalBounds())==true)
        {
            b10.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b11.getGlobalBounds())==true)
        {
            b11.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b12.getGlobalBounds())==true)
        {
            b12.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b13.getGlobalBounds())==true)
        {
            b13.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b14.getGlobalBounds())==true)
        {
            b14.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b15.getGlobalBounds())==true)
        {
            b15.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b16.getGlobalBounds())==true)
        {
            b16.setSize(sf::Vector2f(0,0));
            cnt++;
        }
        if(ball.getGlobalBounds().intersects(b17.getGlobalBounds())==true)
        {
            b17.setSize(sf::Vector2f(0,0));
            cnt++;
        }

        if(cnt==17)
        {
     window.clear(sf::Color::Black);
      window.draw(loosin);
      window.display();
      sf::sleep(sf::milliseconds(1000));
      goto x;



        }



        // ball moving
         if (ball.getPosition().x > 510 - ballRadius)
            {
                xSteps = -xSteps;
            }
            if (ball.getPosition().y > 600 - ballRadius)
            {
                lose=true;
                 ySteps = -ySteps;
            }
            if(ball.getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                lose=false;
            }

            if (ball.getPosition().x< ballRadius)
            {
                xSteps = -xSteps;
            }
            if (ball.getPosition().y< ballRadius)
            {
                ySteps = -ySteps;
            }







            // draw
if(cnt!=17){
    if(lose==false){
    window.clear();
    ball.move(xSteps,ySteps);
window.draw(player);
    window.draw(ball);
    window.draw(b1);
            window.draw(b2);
            window.draw(b3);
            window.draw(b4);
            window.draw(b5);
            window.draw(b6);
            window.draw(b7);
            window.draw(b8);
            window.draw(b9);
            window.draw(b10);
            window.draw(b11);
            window.draw(b12);
            window.draw(b13);
            window.draw(b14);
            window.draw(b15);
            window.draw(b16);
            window.draw(b17);
    window.display();
    }
            else{
      window.clear(sf::Color::White);
      window.draw(loosing);
      window.draw(scoreOnScreen);
      window.display();
      sf::sleep(sf::milliseconds(1000));
      goto x;

            }}}
    }

    return 0;
}
