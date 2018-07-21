#include "entity.hpp"

using namespace sf;

void Entity::move(const vec2f& newPos) {
    pos = pos + newPos;
    sprite.setPosition(pos);
}
