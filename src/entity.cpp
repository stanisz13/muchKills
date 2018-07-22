#include "entity.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

void Entity::setBox (vec2f newPos, vec2f newSize) {
    box.setPos(newPos);
    box.setSize(newSize);
}

void Entity::setPos(const vec2f& newPos) {
    pos = newPos;
    box.setPos(pos);
    sprite.setPosition(pos);
}
void Entity::setSize(const vec2f& newSize) {
    size = newSize;
    box.setSize(size);
}
void Entity::setSizeFromSprite() {
    auto bound = sprite.getGlobalBounds();
    sf::RectangleShape boxxx(vec2f(bound.width, bound.height));
    auto s = boxxx.getSize();
    vec2f newSize{s.x, s.y};
    this->setSize(newSize);
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
    this->setSizeFromSprite();

    this->move(acceleration*deltaTime);
    this->deaccelerate(deltaTime);
}
void Entity::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Entity::loadSprite(sf::Texture& newTexture, const vec2f& scale) {
    vec2u texDim = newTexture.getSize();

    this->sprite.setTexture(newTexture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, texDim.x, texDim.y));
    this->sprite.setColor(sf::Color(255, 255, 255, 255));
    this->sprite.scale(scale);

    this->setSizeFromSprite();
}
