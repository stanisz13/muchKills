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

    vec2f acceleration;
    float friction = 0.1f;
    float deacceleration_time = 0.3f;

    Entity(){}

    void setBox(vec2f newPos, vec2f newSize);

    void setPos(const vec2f& newPos);
    void move(const vec2f& deltaPos);
    void accelerate(const vec2f& vec);
    void deaccelerate(const float& deltaTime);

    void update(const float& deltaTime);
    void draw(sf::RenderWindow& window);
};
