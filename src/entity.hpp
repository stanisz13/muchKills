#pragma once
#include <SFML/Graphics.hpp>
#include <vector.hpp>
#include <bounding_box.hpp>

using namespace sf;

struct Entity
{
    sf::Sprite sprite;
    vec2f pos{0, 0};
    vec2f size{0, 0};
    bounding_box box;

    vec2f acceleration{0, 0};
    float friction = 0.1f;
    float deacceleration_time = 0.3f;

    Entity(){}

    void setBox(vec2f newPos, vec2f newSize);

    void setPos(const vec2f& newPos);
    void setSize(const vec2f& newSize);
    void setSizeFromSprite();

    void move(const vec2f& deltaPos);

    void accelerate(const vec2f& vec);
    void deaccelerate(const float& deltaTime);

    void update(const float& deltaTime);
    void draw(sf::RenderWindow& window);

    void loadSprite(sf::Texture& newTexture, const vec2f& scale);
    void loadSprite(sf::Texture& newTexture) { loadSprite(newTexture, vec2f{1.f, 1.f}); };
};
