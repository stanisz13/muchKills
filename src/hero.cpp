#include "hero.hpp"

bool Hero::handleMovement(const float& deltaTime) {
    vec2f direction;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        direction += vec2f{0, -1};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        direction += vec2f{0, 1};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        direction += vec2f{-1, 0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        direction += vec2f{1, 0};

    if(direction.isZero())
        return 0;

    direction.normalize();

    this->move(direction * speed * deltaTime);
    return 1;
}
