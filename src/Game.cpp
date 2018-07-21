#include <cmath>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Storage.hpp"
#include "Logger.hpp"
#include "hero.hpp"

Logger& operator<<(Logger&, const sf::Vector2f v)
{
    say<<v.x<<' '<<v.y;
    return say;
}



namespace Game
{
    sf::RenderWindow* window;
    Hero boi;
    sf::Texture boiTex;

    void init()
    {
        window = Storage<sf::RenderWindow*>::get("window");

        boiTex.loadFromFile("assets/boi.jpg");

        boi.sprite.setTexture(boiTex);
        sf::Vector2u boiTexDim = boiTex.getSize();
        boi.sprite.setTextureRect(sf::IntRect(0, 0, boiTexDim.x, boiTexDim.y));
        boi.sprite.setColor(sf::Color(255, 255, 255, 200));
    }
    void update(float deltaTime)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            window->close();

        sf::Vector2f toMove(0, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            toMove += sf::Vector2f(0, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            toMove += sf::Vector2f(0, 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            toMove += sf::Vector2f(1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            toMove += sf::Vector2f(-1, 0);
        }

        float len = sqrt(toMove.x * toMove.x + toMove.y * toMove.y);

        if (len != 0)
            toMove /= len;

        toMove *= boi.speed * deltaTime;

        boi.move(toMove);

    }

    void draw()
    {
        window->draw(boi.sprite);
    }

    void deinit()
    {


    }
}
