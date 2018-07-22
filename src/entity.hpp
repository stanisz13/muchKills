#pragma once
#include <SFML/Graphics.hpp>
#include <vector.hpp>

using namespace sf;

struct Entity
{
    sf::Sprite sprite;
    vec2f pos;

    void move(const vec2f& newPos);
};
