#pragma once
#include <SFML/Graphics.hpp>
#include <entity.hpp>
#include <vector.hpp>
#include <vector>

struct Enemy : Entity
{
    float othersAffection = 7.0f;
    float destAffection = 10.0f;
    float medAffection = 4.0f;
    float avgDistAffection = 10.0f;
    int randAffection = 2;


    float speed = 10;



    void moveAccordingly(const vec2f& toPos, const std::vector<Enemy*>& enemies,
    const float deltaTime);

};
