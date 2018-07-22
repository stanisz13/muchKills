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
#include "BloodSplatter.hpp"



namespace Game
{
    sf::RenderWindow* window;
    Hero boi;
    sf::Texture boiTex;
    sf::Texture enemyTex;
    unsigned enemiesNumber = 15;
    std::vector<Enemy> enemies;


    std::vector<BloodSplatter> bloodSplats;

    vec2f mid;

    void init()
    {
        window = Storage<sf::RenderWindow*>::get("window");

        Storage<sf::Texture>::add("blood0", {}).loadFromFile("assets/blood0.png");
        Storage<sf::Texture>::add("blood1", {}).loadFromFile("assets/blood1.png");
        Storage<sf::Texture>::add("blood2", {}).loadFromFile("assets/blood2.png");
        Storage<sf::Texture>::add("blood3", {}).loadFromFile("assets/blood3.png");
        Storage<sf::Texture>::add("blood4", {}).loadFromFile("assets/blood4.png");

        boiTex.loadFromFile("assets/boi.jpg");
        enemyTex.loadFromFile("assets/enemy.jpg");

        boi.sprite.setTexture(boiTex);
        vec2u boiTexDim = boiTex.getSize();
        boi.sprite.setTextureRect(sf::IntRect(0, 0, boiTexDim.x, boiTexDim.y));
        boi.sprite.setColor(sf::Color(255, 255, 255, 255));
        boi.sprite.scale(0.1f, 0.1f);

        vec2u windowDim = window->getSize();
        mid.x = windowDim.x/2;
        mid.y = windowDim.y/2;
        say("mid: ", mid, "\n");

        for(unsigned i = 0; i<enemiesNumber; ++i)
        {
            Enemy cur;
            cur.sprite.setTexture(enemyTex);
            vec2u enemyTexDim = enemyTex.getSize();
            cur.sprite.setTextureRect(sf::IntRect(0, 0, enemyTexDim.x, enemyTexDim.y));
            cur.sprite.setColor(sf::Color(255, 255, 255, 255));
            const float rozmach = 500.0;
            float inX = (float)sin(i) * rozmach;
            float inY = (float)cos(i) * rozmach;
            cur.pos = vec2f{inX, inY};
            cur.sprite.setPosition(cur.pos);
            cur.sprite.scale(0.08f, 0.08f);

            enemies.emplace_back(cur);
        }

        boi.setBox(boi.pos, boi.sprite.getTexture()->getSize());


        for (auto&&e : enemies)
        {
            e.setBox(e.pos, e.sprite.getTexture()->getSize());
        }
    }
    void update(float deltaTime)
    {
        if(bloodSplats.size() < 1)
            bloodSplats.emplace_back(vec2f(0, 0), vec2f(20, 0));

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

        for (auto&& e : enemies)
        {
            e.update();
        }
        boi.update();




        std::vector<unsigned> toDel;
        unsigned a = 0;
        for (auto&& e : enemies)
        {
            if (collides(boi.box, e.box))
            {
                bloodSplats.emplace_back(e.pos, vec2f(boi.pos - e.pos));
                toDel.emplace_back(a);
            }

            a++;
        }

        /*
        for (int i = toDel.size() - 1; i>= 0; --i)
        {
            enemies.erase(enemies.begin() + toDel[i]);
        }*/





        std::vector<int> toDelete;
        for(auto& bloodSplat : bloodSplats)
        {
            bloodSplat.update(deltaTime);

            if(bloodSplat.isFinished())
                toDelete.emplace_back(&bloodSplat-&bloodSplats.front());
        }

        for(int i = toDelete.size()-1; i >= 0; i--)
            bloodSplats.erase(bloodSplats.begin() + toDelete[i]);
        for (auto&& e : enemies)
        {
            e.moveAccordingly(boi.pos, enemies, deltaTime);
        }
    }

    void draw()
    {
        for (unsigned i = 0; i<enemiesNumber; ++i)
        {
            window->draw(enemies[i].sprite);

            auto bound = enemies[i].sprite.getGlobalBounds();
            sf::RectangleShape box(vec2f(bound.width, bound.height));
            box.setPosition(enemies[i].pos);
            box.setFillColor(sf::Color(255, 0, 0, 250));
            window->draw(box);
        }
        //std::this_thread::sleep_for(std::chrono::seconds(10));

        window->draw(boi.sprite);

        for (unsigned i = 0; i<enemiesNumber; ++i)
        {
            sf::RectangleShape boxSprite;
            boxSprite.setFillColor(sf::Color::Green);
            
            boxSprite.setPosition(enemies[i].pos);
            say<<enemies[i].pos<<"\n";
            sf::Vector2u dim = enemies[i].box.size;
            const sf::Vector2f toPassLul(dim.x, dim.y);
            boxSprite.setSize(toPassLul);

            window->draw(boxSprite);
        }


        for(auto& bloodSplat : bloodSplats)
            bloodSplat.draw(*window);
    }

    void deinit()
    {


    }
}
