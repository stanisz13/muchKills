#pragma once
#include <SFML/Graphics.hpp>
#include <entity.hpp>
#include <vector.hpp>
#include <vector>

struct Enemy : Entity
{
    const float othersAffection = 7.0f;
    const float destAffection = 10.0f;
    const float medAffection = 4.0f;
    const float avgDistAffection = 10.0f;
    const int randAffection = 2;

    float speed = 10;

    void moveAccordingly(const vec2f& toPos, const std::vector<Enemy>& enemies,
    const float deltaTime);
};
