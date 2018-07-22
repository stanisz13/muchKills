#pragma once
#include <vector.hpp>
#include <SFML/Graphics.hpp>
#include <Storage.hpp>
#include <entity.hpp>
#include <cmath>

struct BloodSplatter
{
    BloodSplatter(vec2f position, vec2f force, int dropsNum = 20);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    bool isFinished() const {return drops.size() == 0;};

    vec2f pos;

    struct BloodDrop : Entity
    {
        BloodDrop(vec2f position, vec2f direction, float sped, float lifeTime, sf::Texture& tex);
        void update(float deltaTime);
        void draw(sf::RenderWindow& window);

        bool isFinished() const {return timeLived > lifeTime;};

        vec2f dir;
        float speed;
        float lifeTime;
        float timeLived;
        float initialSpeed;
    };

    std::vector<BloodDrop> drops;
};
