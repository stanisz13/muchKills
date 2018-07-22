#pragma once
#include "entity.hpp"
#include <SFML/Graphics.hpp>

struct Hero : Entity
{
    float speed = 400;
    float knockbackAff = 0.7;

    bool handleMovement(const float& deltaTime);
};
