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

void Entity::update () {
    auto bound = sprite.getGlobalBounds();
    sf::RectangleShape boxxx(vec2f(bound.width, bound.height));
    boxxx.setPosition(pos);
    box.setPos(pos);
    auto s = boxxx.getSize();
    box.setSize(vec2f(s.x, s.y));

}
void Entity::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
