#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef Button_h
#define Button_h

class Button{
public:
    sf::RectangleShape newButton(sf::RenderWindow &App, int fontSize, int xStart, int Ystart, sf::Color boxColor, std::string say);
    int newButton(sf::RenderWindow &App, int fontSize, int xStart, int Ystart, sf::Color boxColor, sf::Color fontColor, std::string say);
};

#endif /* Button_h */
