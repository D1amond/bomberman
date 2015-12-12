#include <iostream>
#include <SFML/Graphics.hpp>
#include "kangaru.h"

using namespace kgr;

int main(int argc, char **argv) {
	Container container;
    sf::RenderWindow window(sf::VideoMode(200, 200), "Bomberman");
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
