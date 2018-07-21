#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.hpp"
#include "hero.hpp"
#include "Logger.hpp"

int main()
{
    Storage<int>::add("trojka", 3);
    std::cout << Storage<int>::get("trojka") << '\n';

    log << "Starting program...\n";
    log("you can also use it like ", "this", 123, "\n");
    std::vector<int> v = {1, 2, 3, 4};
    std::pair<int, float> p = {12, 2.5};
    log << "vec: " << v << ' ' << "pair: " << p << "\n";

    sf::RenderWindow window(sf::VideoMode(1900, 900), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Hero boi;

    sf::Texture boiTex;
    boiTex.loadFromFile("assets/boi.jpg");
    
    boi.sprite.setTexture(boiTex);
    sf::Vector2u boiTexDim = boiTex.getSize();
    boi.sprite.setTextureRect(sf::IntRect(0, 0, boiTexDim.x, boiTexDim.y));
    boi.sprite.setColor(sf::Color(255, 255, 255, 200));    
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(boi.sprite);
        window.display();
    }

    return 0;
}
