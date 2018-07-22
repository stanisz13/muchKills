#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.hpp"
#include "Game.hpp"
#include "Logger.hpp"

int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1500, 900), "SFML works!");
    Storage<sf::RenderWindow*>::add("window", &window);

    Game::init();

    sf::Clock cock;

    while (window.isOpen())
    {
        float dt = cock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Game::update(dt);

        window.clear();
        Game::draw();
        window.display();
    }

    return 0;
}
