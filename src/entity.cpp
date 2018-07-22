#include "entity.hpp"
#include <SFML/Graphics.hpp>

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
void Entity::accelerate(const vec2f& vec) {
    acceleration += vec;
}
void Entity::deaccelerate(const float& deltaTime) {
    acceleration *= pow(friction, deltaTime/deacceleration_time);
}

void Entity::update(const float& deltaTime) {
    auto bound = sprite.getGlobalBounds();
    sf::RectangleShape boxxx(vec2f(bound.width, bound.height));
    boxxx.setPosition(pos);
    box.setPos(pos);
    auto s = boxxx.getSize();
    box.setSize(vec2f(s.x, s.y));

    this->move(acceleration*deltaTime);
    this->deaccelerate(deltaTime);
}
void Entity::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
