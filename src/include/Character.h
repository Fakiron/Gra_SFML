#include <SFML/Graphics.hpp>

#ifndef CHARACTER_H
#define CHARACTER_H


class Character
{
    public:
        Character(string texturePath);
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif // CHARACTER_H
