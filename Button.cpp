#include <SFML/Graphics.hpp>
#include "Button.h"

sf::RectangleShape Button::newButton(sf::RenderWindow &App, int fontSize, int xStart, int Ystart, sf::Color boxColor, std::string say){
    //Takes in the size and font of a text object and creates a rectangle around it
    //that is offset in every direction
    //Loads the font to get the specific size of it
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("Bit.ttf")){
        std::cout << "Can't find the font file" << std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setString(say);
    text.setPosition(xStart, Ystart);
    
    sf::RectangleShape Butt(sf::Vector2f(text.getGlobalBounds().width + 40.0f, text.getGlobalBounds().height + 20.0f));
    //offset values
    Butt.setPosition(text.getGlobalBounds().left - 20.0f, text.getGlobalBounds().top - 10.0f);
    Butt.setFillColor(boxColor);

    return Butt;
}

int Button::newButton(sf::RenderWindow &App, int fontSize, int xStart, int Ystart, sf::Color boxColor, sf::Color  fontColor, std::string say){
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("Bit.ttf")){
        std::cout << "Can't find the font file" << std::endl;
    }
    text.setFont(font);
    text.setFillColor(fontColor);
    text.setCharacterSize(fontSize);
    text.setString(say);
    text.setPosition(xStart, Ystart);
    
    sf::RectangleShape Butt(sf::Vector2f(text.getGlobalBounds().width + 60.0f, text.getGlobalBounds().height + 40.0f));
    Butt.setPosition(text.getGlobalBounds().left - 30.0f, text.getGlobalBounds().top - 20.0f);
    Butt.setFillColor(boxColor);
    
    //creates event
    sf::Event Event;
    switch (Event.type)
    {
        case sf::Event::MouseMoved:
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(App);
            sf::Vector2f mousePosit(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            
            //changes color of "Exit" button if mouse hovers over
            if (Butt.getGlobalBounds().contains(mousePosit)){
             Butt.setFillColor(sf::Color::Red);
             }
             else{
             Butt.setFillColor(boxColor);
             }
        }
            break;
            
        case sf::Event::MouseButtonPressed:
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(App);
            sf::Vector2f mousePosit(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            
            //selects button of choice if mouse is on button when clicked
            if(Butt.getGlobalBounds().contains(mousePosit)){
                if(text.getString() == "Play Game"){
                    return 1;
                }
                else if(text.getString() == "Easy"){
                    
                }
                else if(text.getString() == "Medium"){
                    
                }
                else if(text.getString() == "Hard"){
                    
                }
                else{
                    return 0;
                }
            }
            break;
        }
            
        default:
            return 0;
            break;
    }
    App.draw(Butt);
    App.draw(text);
    return 0;
}

