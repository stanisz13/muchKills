#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.hpp"
#include <Game.hpp>
#include "Logger.hpp"

int main()
{
    Storage<int>::add("trojka", 3);
    std::cout << Storage<int>::get("trojka") << '\n';

    say << "Starting program...\n";
    say("you can also use it like ", "this", 123, "\n");
    std::vector<int> v = {1, 2, 3, 4};
    std::pair<int, float> p = {12, 2.5};
    say << "vec: " << v << ' ' << "pair: " << p << "\n";

    sf::RenderWindow window(sf::VideoMode(1900, 900), "SFML works!");
    Storage<sf::RenderWindow*>::add("window", &window);

    Game::init(&window);

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
