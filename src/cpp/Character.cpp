#include "Character.h"

Character::Character(string texturePath)
{
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
}
