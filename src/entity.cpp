#include "entity.hpp"

using namespace sf;

void Entity::setBox (vec2f pos, vec2f size) {
    box.setPos(pos);
    box.setSize(size);
}

void Entity::move(const vec2f& newPos) {
    pos = pos + newPos;
    box.pos = pos;
    sprite.setPosition(pos);
}
void Entity::update () {
}
