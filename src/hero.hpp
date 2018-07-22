#pragma once
#include "entity.hpp"
#include <SFML/Graphics.hpp>

struct Hero : Entity
{
    float speed = 400;

    bool handleMovement(const float& deltaTime);
};
