#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Enemy.hpp"

void natarcie(sf::RenderWindow window);

int hp = 1;
bool isPressed = false;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Maklerny",sf::Style::Fullscreen);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("statek.png");
    sf::Sprite player;
    player.setTexture(playerTexture);
    player.setPosition(200,100);
    player.setOrigin(14,20);
    sf::Font czcionka;
    czcionka.loadFromFile("czcionka.ttf");

    sf::Sprite enemy;
    sf::Texture enemyTexture;
    enemyTexture.loadFromFile("przeciwnik.png");
    enemy.setTexture(enemyTexture);
    enemy.setPosition(1800,1200);
    enemy.rotate(-50);

    sf::Text textKeys;
    textKeys.setFont(czcionka);
    textKeys.setString("Use W-S-A-D to move, and ESCAPE to exit");
    textKeys.setCharacterSize(44);
    textKeys.setColor(sf::Color::Red);
    textKeys.setStyle(sf::Text::Bold);
    textKeys.setPosition(525,75);

    sf::Text textWelcome;
    textWelcome.setFont(czcionka);
    textWelcome.setString("Welcome in Super Mega Statek Kosmiczny");
    textWelcome.setCharacterSize(44);
    textWelcome.setColor(sf::Color::Red);
    textWelcome.setStyle(sf::Text::Bold);
    textWelcome.setPosition(530,0);

    sf::Text textReady;
    textReady.setFont(czcionka);
    textReady.setString("When ready, press Enter");
    textReady.setCharacterSize(44);
    textReady.setColor(sf::Color::Red);
    textReady.setStyle(sf::Text::Bold);
    textReady.setPosition(710,150);
    while(window.isOpen())
    {
        sf::Event zdarzenie;

            while(window.pollEvent(zdarzenie))
            {
                if(zdarzenie.type == sf::Event::Closed)
                {
                    window.close();
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    window.close();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                {
                    isPressed = true;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    player.move(2.5,-2.5);
                    player.setRotation(45);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    player.move(2.5,2.5);
                    player.setRotation(-45);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    player.move(-2.5,2.5);
                    player.setRotation(45);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    player.move(-2.5,-2.5);
                    player.setRotation(-45);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    player.move(0,-10);
                    player.setRotation(0);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    player.move(0,10);
                    player.setRotation(180);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    player.move(-10,0);
                    player.setRotation(-90);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    player.move(10,0);
                    player.setRotation(90);
                }
            }
            window.clear(sf::Color::Green);
            window.draw(player);
            if(isPressed)
            {
                window.draw(enemy);
            }
            else{window.draw(textReady);window.draw(textWelcome);window.draw(textKeys);}

        window.display();
    }


    return 0;
}
