#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <Storage.hpp>
#include <Logger.hpp>
#include "hero.hpp"

namespace Game
{
    sf::RenderWindow* window;
    Hero boi;
    sf::Texture boiTex;

    void init(sf::RenderWindow* theWindow)
    {   
        window = theWindow;
        log << "window: " << window << '\n';

        boiTex.loadFromFile("assets/boi.jpg");

        boi.sprite.setTexture(boiTex);
        sf::Vector2u boiTexDim = boiTex.getSize();
        boi.sprite.setTextureRect(sf::IntRect(0, 0, boiTexDim.x, boiTexDim.y));
        boi.sprite.setColor(sf::Color(255, 255, 255, 200));    
    }   

    void update(float deltaTime)
    {
        //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
          //  window->close();
    }

    void draw()
    {
        window->draw(boi.sprite);
    }

    void deinit()
    {


    }
}