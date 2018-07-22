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
#include <sound.hpp>


namespace Game
{
    sf::RenderWindow* window;
    Hero boi;
    sf::Texture boiTex;
    sf::Texture enemyTex;
    unsigned enemiesNumber = 15;
    float bloodForce = 10.0f;
    std::vector<Enemy*> enemies;


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

        boi.loadSprite(boiTex, {0.1f, 0.1f});

        vec2u windowDim = window->getSize();
        mid.x = windowDim.x/2;
        mid.y = windowDim.y/2;
        say("mid: ", mid, "\n");

        for(unsigned i = 0; i<enemiesNumber; ++i)
        {
            Enemy &cur = *new Enemy;

            cur.loadSprite(enemyTex, {0.08f, 0.08f});

            const float rozmach = 500.0;
            float inX = (float)sin(i) * rozmach;
            float inY = (float)cos(i) * rozmach;
            cur.setPos({inX, inY});

            enemies.emplace_back(&cur);
        }

        SoundManager::initSoundFiles();
    }
    void update(float deltaTime)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            window->close();

        boi.handleMovement(deltaTime);

        for (auto&& e : enemies)
        {
            e->update(deltaTime);
        }
        boi.update(deltaTime);



        for (int i = enemies.size() - 1; i>= 0; --i)
        {
            Enemy* e = enemies[i];
            if (collides(enemies[i]->box, boi.box))
            {
                boi.accelerate(vec2f(boi.pos - enemies[i]->pos).normalize() * boi.knockbackAff);
                bloodSplats.emplace_back(enemies[i]->mid(), vec2f(boi.mid() - enemies[i]->mid()).normalize() * -bloodForce*0.4, vec2f(0, 500), 50);
                enemies.erase(enemies.begin() + i);
                SoundManager::play("hit");
                delete e;
            }
        }

        enemiesNumber = enemies.size();


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
            e->moveAccordingly(boi.pos, enemies, deltaTime);
        }
    }

    void draw()
    {
        boi.draw(*window);
        for(Enemy* e : enemies)
            e->draw(*window);
        for(auto& bloodSplat : bloodSplats)
            bloodSplat.draw(*window);
    }

    void deinit()
    {
        for (unsigned i = 0; i<enemies.size(); ++i)
            delete enemies[i];
    }
}
