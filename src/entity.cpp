#include "entity.hpp"

using namespace sf;

void Entity::setPosition(const Vector2f& newPos)
{
    pos = newPos;
}

void Entitu::move(const Vector2f& newPos) {
    pos = pos + newPos;
}

void Entity::setSprite(const Sprite& newSprite)
{
    sprite = newSprite;
}
