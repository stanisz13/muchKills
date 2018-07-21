#include "entity.hpp"

using namespace sf;

Entity::setPosition(const Vector2f& newPos)
{
    pos = newPos;
}

Entity::setSprite(const Sprite& newSprite)
{
    sprite = newSprite;
}

