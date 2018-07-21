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
#include <vector.hpp>

namespace Game
{
    sf::RenderWindow* window;
    Hero boi;
    sf::Texture boiTex;
    sf::Texture enemyTex;
    unsigned enemiesNumber = 1000;
    std::vector<Enemy> enemies;


    void init()
    {
        window = Storage<sf::RenderWindow*>::get("window");

        boiTex.loadFromFile("assets/boi.jpg");
        enemyTex.loadFromFile("assets/enemy.jpg");

        boi.sprite.setTexture(boiTex);
        vec2u boiTexDim = boiTex.getSize();
        boi.sprite.setTextureRect(sf::IntRect(0, 0, boiTexDim.x, boiTexDim.y));
        boi.sprite.setColor(sf::Color(255, 255, 255, 255));
        boi.sprite.scale(0.1f, 0.1f);

        vec2u windowDim = window->getSize();

        for(unsigned i = 0; i<enemiesNumber; ++i)
        {
            Enemy cur;
            cur.sprite.setTexture(enemyTex);
            vec2u enemyTexDim = enemyTex.getSize();
            cur.sprite.setTextureRect(sf::IntRect(0, 0, enemyTexDim.x, enemyTexDim.y));
            cur.sprite.setColor(sf::Color(255, 255, 255, 255));
            float inX = (float)sin(i) * 300 + windowDim.x / 2;
            float inY = (float)cos(i) * 300 + windowDim.y / 2;
            cur.pos = vec2f{inX, inY};
            cur.sprite.setPosition(cur.pos);
            cur.sprite.scale(0.08f, 0.08f);

            enemies.emplace_back(cur);
        }
    }
    void update(float deltaTime)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            window->close();

        vec2f toMove(0, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            toMove += vec2f(0, -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            toMove += vec2f(0, 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            toMove += vec2f(1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            toMove += vec2f(-1, 0);
        }

        toMove.normalize();
        toMove *= boi.speed * deltaTime;

        boi.move(toMove);

    }

    void draw()
    {
        for (unsigned i = 0; i<enemiesNumber; ++i)
        {
            window->draw(enemies[i].sprite);
        }
        //std::this_thread::sleep_for(std::chrono::seconds(10));

        window->draw(boi.sprite);
    }

    void deinit()
    {


    }
}
