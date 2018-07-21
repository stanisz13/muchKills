#include <SFML/Graphics.hpp>

using namespace sf;

struct Entity
{   
    sf::Sprite sprite;
    sf::Vector2f pos;

    void setPosition(const Vector2f& newPos);
    void setSprite(const Sprite& newSprite);
};
