#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.hpp"
#include "hero.hpp"

int main()
{
    Storage<int>::add("trojka", 3);
    std::cout << Storage<int>::get("trojka") << '\n';

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
