#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.hpp"
#include "Game.hpp"
#include "Logger.hpp"

int main()
{
    srand(time(NULL));

    sf::View camera;
    vec2i cameraDims(1600, 900);
    camera.reset(sf::FloatRect(-cameraDims.x/2, -cameraDims.y/2, cameraDims.x, cameraDims.y));

    sf::RenderWindow window(sf::VideoMode(1500, 900), "SFML works!");
    window.setView(camera);
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

    Game::deinit();

    return 0;
}
