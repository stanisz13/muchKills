#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

struct Entity
{
    sf::Sprite sprite;
    sf::Vector2f pos;
    float speed = 400;

    void move(const Vector2f& newPos);
};
