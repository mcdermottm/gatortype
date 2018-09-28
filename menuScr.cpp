//
//  menuScr.cpp
//  Gator Type
//
//  Created by Ankit  on 4/22/18.
//  Copyright © 2018 Ankit . All rights reserved.
//

#include <stdio.h>
#include "Frame.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Button.h"
#include "menuScr.h"
#include "Game.h"

menuScr::menuScr(void){
    playing = false;
}

int menuScr::Run(sf::RenderWindow &App, TextGen &T, Game &game){
    //making buttons
    Button* butt = new Button;
    sf::Color color(0, 0, 0, 155);
    sf::Color colors(0, 0, 0, 10);
    sf::RectangleShape mid;
    mid.setFillColor(color);
    mid.setSize({400.0f, 640.0f});
    mid.setPosition(440.0f, 0.0f);
    
    sf::Texture back;
    sf::Sprite image;
    
    if (!back.loadFromFile("UF.png", sf::IntRect(1550, 900, 1280, 640)))
    {
        std::cout << "Error: Could not display Gators bruh" << std::endl;
    }
    image.setTexture(back);
    
    //loading font
    sf::Font font;
    if (!font.loadFromFile("Bit.ttf"))
    {
        std::cout << "Can't find the font file" << std::endl;
    }
    
    //exit button
    sf::Texture exitButton;
    sf::Sprite exitButtonImage;
    if (!exitButton.loadFromFile("ExitButton.png"))
    {
        std::cout << "Can't find the image" << std::endl;
    }
    
    /*float exitButtonWidth = exitButtonImage.getLocalBounds().width;
     float exitButtonHeight = exitButtonImage.getLocalBounds().height;*/
    
    exitButtonImage.setTexture(exitButton);
    exitButtonImage.setPosition(385.0f, 430.0f);
    
    //"Gator" text
    sf::Text Gatortype;
    Gatortype.setFont(font);
    Gatortype.setString("Gator");
    Gatortype.setFillColor(sf::Color::Green);
    Gatortype.setCharacterSize(60);
    Gatortype.setPosition(510.0f, 15.0f);
    
    //"Type" text
    sf::Text Type;
    Type.setFont(font);
    Type.setString("Type");
    Type.setFillColor(sf::Color::Green);
    Type.setCharacterSize(60);
    Type.setPosition(537.0f, 75.0f);

    //"Play Game" text
    sf::Text startText;
    startText.setFont(font);
    startText.setString("Play Game");
    startText.setFillColor(sf::Color::Blue);
    startText.setCharacterSize(40);
    startText.setPosition(490.0f, 165.0f);
    
    //"Easy" button text
    sf::Text eas;
    eas.setFont(font);
    eas.setString("Easy");
    eas.setFillColor(sf::Color::Blue);
    eas.setCharacterSize(35);
    eas.setPosition(585.0f, 235.0f);
    
    //"Medium" button text
    sf::Text med;
    med.setFont(font);
    med.setString("Medium");
    med.setFillColor(sf::Color::Blue);
    med.setCharacterSize(35);
    med.setPosition(560.0f, 310.0f);
    
    //"Hard" button text
    sf::Text har;
    har.setFont(font);
    har.setString("Hard");
    har.setFillColor(sf::Color::Blue);
    har.setCharacterSize(35);
    har.setPosition(585.0f, 385.0f);
    
    //Matthew's name text
    sf::Text name1;
    name1.setFont(font);
    name1.setString("McDermottMeister");
    name1.setFillColor(sf::Color::Blue);
    name1.setCharacterSize(20);
    name1.setPosition(1010.0f, 430.0f);
    
    //Daniel's name text
    sf::Text name2;
    name2.setFont(font);
    name2.setString("the Xu (SHOE)");
    name2.setFillColor(sf::Color::Blue);
    name2.setCharacterSize(20);
    name2.setPosition(1010.0f, 460.0f);
    
    //Sasank's name text
    sf::Text name3;
    name3.setFont(font);
    name3.setString("Shank");
    name3.setFillColor(sf::Color::Blue);
    name3.setCharacterSize(20);
    name3.setPosition(1010.0f, 490.0f);
    
    //Cullen's name text
    sf::Text name4;
    name4.setFont(font);
    name4.setString("Quagmire");
    name4.setFillColor(sf::Color::Blue);
    name4.setCharacterSize(20);
    name4.setPosition(1010.0f, 520.0f);
    
    //Paul's name text
    sf::Text name5;
    name5.setFont(font);
    name5.setString("Paul");
    name5.setFillColor(sf::Color::Blue);
    name5.setCharacterSize(20);
    name5.setPosition(1010.0f, 550.0f);
    
    //Nolan's name text
    sf::Text name6;
    name6.setFont(font);
    name6.setString("Nolan");
    name6.setFillColor(sf::Color::Blue);
    name6.setCharacterSize(20);
    name6.setPosition(1010.0f, 580.0f);
    
    //Ankit's name text
    sf::Text name7;
    name7.setFont(font);
    name7.setString("Ankeeet");
    name7.setFillColor(sf::Color::Blue);
    name7.setCharacterSize(20);
    name7.setPosition(1010.0f, 610.0f);
    
    //Alligator sprite Right Movement
    sf::Texture alligator;
    alligator.loadFromFile("alligator.png");
    sf::IntRect rectSourceSprite(0, 164, 127, 82);
    
    //Rectangle of sprite will be incremented to the left by a certain number of pixels
    
    sf::Sprite gatorR(alligator, rectSourceSprite);
    float gatorX1 = 135.0f; //Initialize to left offset distance
    float gatorY1 = 150.0f;
    gatorR.setPosition(gatorX1, gatorY1);
    
    //Alligator sprite Up Movement
    sf::Texture alligators;
    alligators.loadFromFile("alligator.png");
    sf::IntRect sprite(0, 244, 127, 82);
    
    //Rectangle of sprite will be incremented to the left by a certain number of pixels
    
    sf::Sprite gatorU(alligators, sprite);
    float gatorX2 = 135.0f; //Initialize to left offset distance
    float gatorY2 = 640.0f;
    gatorU.setPosition(gatorX2, gatorY2);
    
    sf::RectangleShape easy = butt->newButton(App, 35, 585.0f, 235.0f, sf::Color::Red, "Easy");
    sf::RectangleShape medium = butt->newButton(App, 35, 560.0f, 310.0f, colors, "Medium");
    sf::RectangleShape hard = butt->newButton(App, 35, 585.0f, 385.0f, colors, "Hard");
    sf::RectangleShape start = butt->newButton(App, 40, 490.0f, 165.0f, colors, "Play Game");
    
    int diffSelect = 0;
    sf::Clock gatorRectClock;
    sf::Clock gatorRectumClock;
    
    sf::Music opening;
    //opening.initialize();
    //opening.openFromFile("GatorSong.ogg");
    //opening.play();
    
    //for alligator right movement on menu screen
    while (App.isOpen())
    {
        //changes gator animations based on a clock
        if(gatorRectClock.getElapsedTime().asSeconds() > 0.1f)
        {
            /*
            In the PNG image put into the texture there
            are multiple images of the alligator in different
            positions so this if statement increments through
             the images based on a timer and changes the gator
             image shown to the screen by moving what pixels are
             shown. All that is needed to be done is simply move
             the x pixels over so that the gator image is a different
              one and this shows motion. The gator image resets to the
             first image once it reaches the third image.
             */
            
            if(rectSourceSprite.left > 250)
            {
                rectSourceSprite.left = 0;
                sprite.left = 0;
            }
            else
            {
                sprite.left += 127;
                rectSourceSprite.left += 127;
            }
            gatorRectClock.restart();
        }
        
        gatorU.setTextureRect(sprite);
        gatorR.setTextureRect(rectSourceSprite);
        
        if(gatorR.getPosition().x >= App.getSize().x)
        {
            gatorR.setPosition(0, gatorY1);
        }
        else {
            gatorR.move(0.6f, 0.0f);
        }
        
        /*if(gatorU.getPosition().y >= App.getSize().y)
         {
            gatorU.setPosition(135, 640);
        }
        else {
            gatorU.move(0.0f, 0.6f);
        }
        
        if(gatorRectClock.getElapsedTime().asSeconds() > 0.2f)
         {
            if(rectSourceSprite3.left > 250)
         {
                rectSourceSprite3.left = 0;
            }
            else {
                rectSourceSprite3.left += 127;
            }
            gatorRectClock.restart();
        }
        gatorU.setTextureRect(rectSourceSprite3);
        if(gatorU.getPosition().y >= App.getSize().y)
         {
            //FIXME remove from final code, only for testing
            gatorY2 = 640;
            gatorR.setPosition(gatorX2, gatorY2);
        }
        else {
            //dist += (characters typed/total characters)*(screenwidth-left offset - right offset)
            gatorY2 += 25.6;
            gatorU.setPosition(gatorX2, gatorY2);
        }*/
        
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            switch (Event.type)
            {
                case sf::Event::Closed:
                    opening.stop();
                    return -1;
                    break;
                    
                case sf::Event::MouseMoved:
                {
                    //Gets position of mouse
                    sf::Vector2i mousePos = sf::Mouse::getPosition(App);
                    //Returns a vector with x and y values
                    sf::Vector2f mousePosit(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    //If statement that checks if mouse position is over one of the buttons then
                    //set the color of the buttons to red
                    if (exitButtonImage.getGlobalBounds().contains(mousePosit))
                    {
                        exitButtonImage.setColor(sf::Color::Red);
                    }
                    else
                    {
                        exitButtonImage.setColor(sf::Color::White);
                    }
                    if (easy.getGlobalBounds().contains(mousePosit))
                     {
                     easy.setFillColor(sf::Color::Red);
                     }
                     else
                     {
                     easy.setFillColor(colors);
                     }
                     if (medium.getGlobalBounds().contains(mousePosit))
                     {
                     medium.setFillColor(sf::Color::Red);
                     }
                     else
                     {
                     medium.setFillColor(colors);
                     }
                     if (hard.getGlobalBounds().contains(mousePosit))
                     {
                     hard.setFillColor(sf::Color::Red);
                     }
                     else
                     {
                     hard.setFillColor(colors);
                     }
                     if (start.getGlobalBounds().contains(mousePosit))
                     {
                     start.setFillColor(sf::Color::Red);
                     }
                     else
                     {
                     start.setFillColor(colors);
                     }
                    if(diffSelect == 0)
                    {
                        easy.setFillColor(sf::Color::Red);
                    }
                    else if(diffSelect == 1){
                        medium.setFillColor(sf::Color::Red);
                    }
                    else{
                        hard.setFillColor(sf::Color::Red);
                    }
                }
                    break;
                case sf::Event::MouseButtonPressed:
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(App);
                    sf::Vector2f mousePosit(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    
                    /*
                    If statement that checks if the position of the mouse
                    is over the buttons and if it is located over them
                    then activate what ever command is dictated by the text
                    on the buttons
                    */
                    
                    if (exitButtonImage.getGlobalBounds().contains(mousePosit))
                    {
                        opening.stop();
                        return -1;
                    }
                    else if(easy.getGlobalBounds().contains(mousePosit))
                    {
                        //diffSelect variable is set to 0 for easy and at the
                        //end of the loop is passed to the text generator
                        //so that it can dictate what text to output
                        diffSelect = 0;
                    }
                    else if(medium.getGlobalBounds().contains(mousePosit))
                    {
                        //1 for diffSelect corresponds to medium difficulty
                        diffSelect = 1;
                    }
                    else if(hard.getGlobalBounds().contains(mousePosit))
                    {
                        //2 for diffSelect corresponds to hard difficulty
                        diffSelect = 2;
                    }
                    else if(start.getGlobalBounds().contains(mousePosit))
                    {
                        opening.stop();
                        //The 1 that is returned moves the frame to the actual
                        //play screen
                        return 1;
                    }
                }
                    break;
                default:
                    break;
            }
        }
        
        T.setDifficulty(diffSelect);
        App.clear();
        
        //Background picture
        
        App.draw(image);
        
        //names of group members
        App.draw(name1);
        App.draw(name2);
        App.draw(name3);
        App.draw(name4);
        App.draw(name5);
        App.draw(name6);
        App.draw(name7);
        
        //Gators moving across screen
        App.draw(gatorR);
        App.draw(gatorU);
        
        /*
        Draws the translucent background to improve
        text readability
        */
        App.draw(mid);
        
        //Draws the buttons for the corresponding text
        App.draw(start);
        App.draw(easy);
        App.draw(medium);
        App.draw(hard);
        
        //draws the text on the buttons
        App.draw(startText);
        App.draw(eas);
        App.draw(med);
        App.draw(har);
        
        //Exit Button Sprite
        App.draw(exitButtonImage);
        
        //Title Font
        App.draw(Gatortype);
        App.draw(Type);
        
        App.display();
    }
    return 0;
}
