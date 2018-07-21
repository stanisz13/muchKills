#pragma once
#include <SFML/Graphics.hpp>

namespace Game
{
    void init(sf::RenderWindow* theWindow);
    void update(float deltaTime);
    void draw();
    void deinit();
}