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

    void setBox(vec2f pos, vec2f size);

    void setPos(const vec2f& newPos);
    void move(const vec2f& deltaPos);

    void update();
    void draw(sf::RenderWindow& window);
};
