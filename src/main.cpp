#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Enemy.hpp"

void natarcie(sf::RenderWindow okienko);

int zycie = 1;
bool wcisnieto = false;

int main()
{
    sf::RenderWindow okienko(sf::VideoMode(1920,1080), "Maklerny",sf::Style::Fullscreen);

    sf::Texture tekstura;
    tekstura.loadFromFile("statek.png");
    sf::Sprite sprajt;
    sprajt.setTexture(tekstura);
    sprajt.setPosition(200,100);
    sprajt.setOrigin(14,20);
    sf::Font czcionka;
    czcionka.loadFromFile("czcionka.ttf");

    sf::Sprite przeciwnik;
    sf::Texture tekstura_przeciwnika;
    tekstura_przeciwnika.loadFromFile("przeciwnik.png");
    przeciwnik.setTexture(tekstura_przeciwnika);
    przeciwnik.setPosition(1800,1200);
    przeciwnik.rotate(-50);

    sf::Text tekst3;
    tekst3.setFont(czcionka);
    tekst3.setString("Use W-S-A-D to move, and ESCAPE to exit");
    tekst3.setCharacterSize(44);
    tekst3.setColor(sf::Color::Red);
    tekst3.setStyle(sf::Text::Bold);
    tekst3.setPosition(525,75);

    sf::Text tekst2;
    tekst2.setFont(czcionka);
    tekst2.setString("Welcome in Super Mega Statek Kosmiczny");
    tekst2.setCharacterSize(44);
    tekst2.setColor(sf::Color::Red);
    tekst2.setStyle(sf::Text::Bold);
    tekst2.setPosition(530,0);

    sf::Text tekst;
    tekst.setFont(czcionka);
    tekst.setString("When ready, press Enter");
    tekst.setCharacterSize(44);
    tekst.setColor(sf::Color::Red);
    tekst.setStyle(sf::Text::Bold);
    tekst.setPosition(710,150);
    while(okienko.isOpen())
    {
        sf::Event zdarzenie;

            while(okienko.pollEvent(zdarzenie))
            {
                if(zdarzenie.type == sf::Event::Closed)
                {
                    okienko.close();
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    okienko.close();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                {
                    wcisnieto = true;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    sprajt.move(2.5,-2.5);
                    sprajt.setRotation(45);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    sprajt.move(2.5,2.5);
                    sprajt.setRotation(-45);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    sprajt.move(-2.5,2.5);
                    sprajt.setRotation(45);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    sprajt.move(-2.5,-2.5);
                    sprajt.setRotation(-45);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    sprajt.move(0,-10);
                    sprajt.setRotation(0);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    sprajt.move(0,10);
                    sprajt.setRotation(180);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    sprajt.move(-10,0);
                    sprajt.setRotation(-90);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    sprajt.move(10,0);
                    sprajt.setRotation(90);
                }
            }
            okienko.clear(sf::Color::Green);
            okienko.draw(sprajt);
            if(wcisnieto)
            {
                okienko.draw(przeciwnik);
            }
            else{okienko.draw(tekst);okienko.draw(tekst2);okienko.draw(tekst3);}

        okienko.display();
    }


    return 0;
}
