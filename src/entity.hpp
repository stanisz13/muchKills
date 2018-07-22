#pragma once
#include <SFML/Graphics.hpp>
#include <vector.hpp>
#include <bounding_box.hpp>

using namespace sf;

struct Entity
{
    sf::Sprite sprite;
    vec2f pos;
    bounding_box box;

    Entity(){}
    void move(const vec2f& newPos);
    void update();
};
