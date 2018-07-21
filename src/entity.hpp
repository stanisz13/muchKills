#include <SFML/Graphics.hpp>

using namespace sf;

struct Entity
{
    sf::Sprite sprite;
    sf::Vector2f pos;

    void move(const Vector2f& newPos);
};
