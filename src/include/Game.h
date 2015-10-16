#include <SFML/Graphics.hpp>

#include "Character.h"

#ifndef GAME_H
#define GAME_H


class Game
{
    public:
        Game();

        void start();

        Character player;
        Character enemy;
    private:
        void loop();

        sf::RenderWindow window;
        sf::Event event;
        sf::Font font;
};

#endif // GAME_H
