/*
 * main.cpp
 *
 *  Created on: Mar 27, 2018
 *      Author: Matthew
 */

#include "window.h"
#include "accuracy.h"
#include "player.h"
#include "textgen.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200,200), "Hello World");
    sf::CircleShape shape(100.f);
    shape.setPointCount(128);
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

