#include "entity.hpp"

using namespace sf;

void Entity::setPosition(const Vector2f& newPos)
{
    pos = newPos;
}

void Entity::setSprite(const Sprite& newSprite)
{
    sprite = newSprite;
}

