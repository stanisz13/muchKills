#include "entity.hpp"

using namespace sf;

void Entity::setBox (vec2f newPos, vec2f newSize) {
    box.setPos(newPos);
    box.setSize(newSize);
}

void Entity::setPos(const vec2f& newPos) {
    pos = newPos;
    box.pos = pos;
    sprite.setPosition(pos);
}
void Entity::move(const vec2f& deltaPos) {
    this->setPos(pos + deltaPos);
}

void Entity::update () {
}
void Entity::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
