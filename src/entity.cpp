#include "entity.hpp"

using namespace sf;

void Entity::move(const Vector2f& newPos) {
    pos = pos + newPos;
    sprite.setPosition(pos);
}
