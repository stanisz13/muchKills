#include <cmath>
#include <enemy.hpp>
#include <vector>
#include <thread>
#include <chrono>
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
    sf::Texture enemyTex;
    unsigned enemiesNumber = 10;
    std::vector<Enemy> enemies;


    void init()
    {
        window = Storage<sf::RenderWindow*>::get("window");

        boiTex.loadFromFile("assets/boi.jpg");
        enemyTex.loadFromFile("assets/enemy.jpg");

        boi.sprite.setTexture(boiTex);
        sf::Vector2u boiTexDim = boiTex.getSize();
        boi.sprite.setTextureRect(sf::IntRect(0, 0, boiTexDim.x, boiTexDim.y));
        boi.sprite.setColor(sf::Color(255, 255, 255, 255));
        boi.sprite.scale(0.1f, 0.1f);

        sf::Vector2u windowDim = window->getSize();

        for(unsigned i = 0; i<enemiesNumber; ++i)
        {
            Enemy cur;
            cur.sprite.setTexture(enemyTex);
            sf::Vector2u enemyTexDim = enemyTex.getSize();
            cur.sprite.setTextureRect(sf::IntRect(0, 0, enemyTexDim.x, enemyTexDim.y));
            cur.sprite.setColor(sf::Color(255, 255, 255, 255));
            cur.pos = {windowDim.x / 2 + sin(i) * 300, windowDim.y / 2 + cos(i) * 300};
            cur.sprite.setPosition(cur.pos);
            cur.sprite.scale(0.3f, 0.3f);// = 0.3;

            enemies.emplace_back(cur);
        }
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
        for (unsigned i = 0; i<enemiesNumber; ++i)
        {
            say<<enemies[i].pos<<"\n";
            window->draw(enemies[i].sprite);
        }
        //std::this_thread::sleep_for(std::chrono::seconds(10));

        window->draw(boi.sprite);
    }

    void deinit()
    {


    }
}
