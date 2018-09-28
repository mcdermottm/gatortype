//
//  finishScr.cpp
//  Gator Type
//
//  Created by Ankit  on 4/22/18.
//  Copyright © 2018 Ankit . All rights reserved.
//

#include "Frame.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <stdio.h>
#include "finishScr.h"
#include "textgen.h"
#include "Game.h"

finishScr::finishScr(void)
{
    playing = false;
}

int finishScr::Run(sf::RenderWindow &App, TextGen &T, Game &game)
{
    sf::Color color(0, 0, 0, 155);
    sf::Color colors(0, 0, 0, 10);
    sf::Event Event;
    
    sf::Texture back;
    sf::Sprite image;
    
    //Imports textures for background
    if (!back.loadFromFile("UFspace.jpg", sf::IntRect(320, 220, 1280, 640)))
    {
        std::cout << "Error: Could not display Gators bruh" << std::endl;
    }
    image.setTexture(back);
    
    sf::Font font;
    if (!font.loadFromFile("Bit.ttf"))
    {
        std::cout << "Can't find the font file" << std::endl;
    }
    
    sf::RectangleShape behind;
    behind.setSize({600.0f, 460.0f});
    behind.setFillColor(color);
    behind.setPosition(340.0f, 90.0f);
    
    Button* butt = new Button;
    
    sf::Text PlayA;
    PlayA.setFont(font);
    PlayA.setString("Play Again");
    PlayA.setFillColor(sf::Color::Green);
    PlayA.setCharacterSize(40);
    PlayA.setPosition(480.0f, 370.0f);
    sf::RectangleShape playB = butt->newButton(App, 40, 480.0f, 370.0f, colors, "Play Again");
    
    sf::Text Main;
    Main.setFont(font);
    Main.setString("Main Menu");
    Main.setFillColor(sf::Color::Green);
    Main.setCharacterSize(40);
    Main.setPosition(493.0f, 460.0f);
    sf::RectangleShape mainB = butt->newButton(App, 40, 493.0f, 460.0f, colors, "Main Menu");
    
    std::string wpm = "Your WPM was: " + game.getWPM().getString();
    sf::Text WPM;
    WPM.setFont(font);
    WPM.setString(wpm);
    WPM.setFillColor(sf::Color::Blue);
    WPM.setCharacterSize(30);
    WPM.setPosition(430.0f, 225.0f);
    
    std::string acc = "Your Accuracy was: " + game.getAccuracy().getString() + "%";
    sf::Text Acc;
    Acc.setFont(font);
    Acc.setString(acc);
    Acc.setFillColor(sf::Color::Blue);
    Acc.setCharacterSize(30);
    Acc.setPosition(360.0f, 275.0f);
    
    sf::Text Congrats;
    Congrats.setFont(font);
    Congrats.setString("Congratulations!");
    Congrats.setFillColor(sf::Color::Cyan);
    Congrats.setCharacterSize(45);
    Congrats.setPosition(362.0f, 115.0f);
    
    sf::Text Bad;
    Bad.setFont(font);
    Bad.setString("\"Type better dummy!!\"");
    Bad.setFillColor(sf::Color::Red);
    Bad.setCharacterSize(35);
    Bad.setPosition(347.0f, 575.0f);
    
    sf::Text Good;
    Good.setFont(font);
    Good.setString("\"I'm so proud of you!\"");
    Good.setFillColor(sf::Color::Red);
    Good.setCharacterSize(35);
    Good.setPosition(342.0f, 575.0f);
    
    //Fuchs texture and movement
    sf::Texture fuchsTexture;
    fuchsTexture.loadFromFile("DaddyFuchs.png");
    sf::IntRect fuchsSourceSprite(0, 0, 207, 198);
    sf::Sprite fuchs(fuchsTexture, fuchsSourceSprite);
    sf::Sprite fuchs2(fuchsTexture, fuchsSourceSprite);
    sf::Clock fuchsClock;
    fuchs.setScale(1.5, 1.5);
    fuchs2.setScale(1.5, 1.5);
    fuchs.setPosition(10, 160);
    fuchs2.setPosition(950, 160);
    
    //Dennis texture and movement
    sf::Texture dennisTexture;
    dennisTexture.loadFromFile("dennisdad.png");
    sf::IntRect dennisSourceSprite(0, 0, 137, 196);
    sf::Sprite dennis(dennisTexture, dennisSourceSprite);
    sf::Sprite dennis2(dennisTexture, dennisSourceSprite);
    sf::Clock dennisClock;
    dennis.setScale(2, 2);
    dennis2.setScale(2, 2);
    dennis.setPosition(35, 130);
    dennis2.setPosition(980, 130);
    
    //Gator Clock
    sf::Clock gatorRectClock;

    //Alligator sprite Right Movement
    sf::Texture alligatorR;
    alligatorR.loadFromFile("alligator.png");
    sf::IntRect rectSourceSprite(0, 164, 127, 82);
    sf::Sprite gatorR(alligatorR, rectSourceSprite);
    float gatorX = 135.0f; //Initialize to left offset distance
    float gatorY = 10.0f;
    gatorR.setPosition(gatorX, gatorY);
    
    //Alligator sprite Left Movement
    sf::Texture alligatorL;
    alligatorL.loadFromFile("alligator.png");
    sf::IntRect rectSourceSprite2(0, 82, 127, 82);
    sf::Sprite gatorL(alligatorL, rectSourceSprite2);

    //Alligator sprite Up Movement
    sf::Texture alligatorU;
    alligatorU.loadFromFile("alligator.png");
    sf::IntRect rectSourceSprite3(0, 246, 127, 82);
    sf::Sprite gatorU(alligatorU, rectSourceSprite3);
    
    //Alligator sprite Down Movement
    sf::Texture alligatorD;
    alligatorD.loadFromFile("alligator.png");
    sf::IntRect rectSourceSprite4(0, 0, 127, 82);
    sf::Sprite gatorD(alligatorD, rectSourceSprite4);
    
    //Audio
    sf::Music ending;
    //opening.initialize();
    //ending.openFromFile(resourcePath() + "Fire.ogg");
    //ending.play();
    
    while (App.isOpen())
    {
        if(dennisClock.getElapsedTime().asSeconds() > 0.4f)
        {
            if(dennisSourceSprite.left > 136)
            {
                dennisSourceSprite.left = 0;
            }
            else{
                dennisSourceSprite.left += 137;
            }
            dennis.setTextureRect(dennisSourceSprite);
            dennis2.setTextureRect(dennisSourceSprite);
            dennisClock.restart();
        }
        
        if(fuchsClock.getElapsedTime().asSeconds() > 0.4f)
        {
            if(fuchsSourceSprite.left > 206)
            {
                fuchsSourceSprite.left = 0;
            }
            else{
                fuchsSourceSprite.left += 209;
            }
            fuchs.setTextureRect(fuchsSourceSprite);
            fuchs2.setTextureRect(fuchsSourceSprite);
            fuchsClock.restart();
        }
        if(gatorRectClock.getElapsedTime().asSeconds() > 0.2f)
        {
            if(rectSourceSprite.left > 250)
            {
                rectSourceSprite.left = 0;
            }
            else {
                rectSourceSprite.left += 127;
            }
            gatorRectClock.restart();
        }
        gatorR.setTextureRect(rectSourceSprite);
        //Verifying events
        while (App.pollEvent(Event))
        {
            // Window closed
            switch (Event.type)
            {
                case sf::Event::Closed:
                    return -1;
                    break;
                case (sf::Event::MouseMoved):
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(App);
                    sf::Vector2f mousePosit(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (playB.getGlobalBounds().contains(mousePosit))
                    {
                        playB.setFillColor(sf::Color::Red);
                    }
                    else
                    {
                        playB.setFillColor(colors);
                    }
                    if (mainB.getGlobalBounds().contains(mousePosit))
                    {
                        mainB.setFillColor(sf::Color::Red);
                    }
                    else
                    {
                        mainB.setFillColor(colors);
                    }
                    break;
                }
                case (sf::Event::MouseButtonPressed):
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(App);
                    sf::Vector2f mousePosit(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (playB.getGlobalBounds().contains(mousePosit))
                    {
                        game.delKeystrokes();
                        game.delVec();
                        return 1;
                    }
                    else if(mainB.getGlobalBounds().contains(mousePosit))
                    {
                        game.delKeystrokes();
                        game.delVec();
                        return 0;
                    }
                }
                    break;
                case sf::Event::TextEntered:
                    gatorR.setTextureRect(rectSourceSprite);
                    
                    if(gatorR.getPosition().x >= App.getSize().x)
                    {
                        //FIXME remove from final code, only for testing
                        gatorX = 0;
                        gatorR.setPosition(gatorX, gatorY);
                    }
                    else {
                        gatorX += 25.6;
                        gatorR.setPosition(gatorX, gatorY);
                    }
                default:
                    break;
            }
            //Attempted to make the gator move in up, down, right, and left directions based on a separate png file, however,
            //we were not able to do this
            //Key pressed
            /*if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                    case sf::Keyboard::Up:
                        if(true){
                            if(rectSourceSprite3.left > 250)
             {
                                rectSourceSprite3.left = 0;
                            }
                            else
             {
                                rectSourceSprite3.left += 127;
                            }
                            
                            gatorU.setTextureRect(rectSourceSprite3);
                            
                            if(gatorU.getPosition().y >= App.getSize().y)
             {
                                //FIXME remove from final code, only for testing
                                gatorY = 135;
                                gatorU.setPosition(gatorX, gatorY);
                            }
                            else
             {
                                //dist += (characters typed/total characters)*(screenwidth-left offset - right offset)
                                gatorY += 25.6;
                                gatorU.setPosition(gatorX, gatorY);
                            }
                        }
                        break;
                    case sf::Keyboard::Down:
                        if(true){
                            if(rectSourceSprite4.left > 250)
             {
                                rectSourceSprite4.left = 0;
                            }
                            else
             {
                                rectSourceSprite4.left += 127;
                            }
                            
                            gatorD.setTextureRect(rectSourceSprite4);
                            
                            if(gatorD.getPosition().y <= App.getSize().x)
             {
                                //FIXME remove from final code, only for testing
                                gatorY = 135;
                                gatorD.setPosition(gatorX, gatorY);
                            }
                            else
             {
                                //dist += (characters typed/total characters)*(screenwidth-left offset - right offset)
                                gatorY -= 25.6;
                                gatorD.setPosition(gatorX, gatorY);
                            }
                        }
                        break;
                    case sf::Keyboard::Left:
                        if(true){
                            if(rectSourceSprite2.left > 250)
             {
                                rectSourceSprite2.left = 0;
                            }
                            else
             {
                                rectSourceSprite2.left += 127;
                            }
                            
                            gatorL.setTextureRect(rectSourceSprite2);
                            
                            if(gatorL.getPosition().x <= App.getSize().x)
             {
                                //FIXME remove from final code, only for testing
                                gatorX = 135;
                                gatorL.setPosition(gatorX, gatorY);
                            }
                            else
             {
                                //dist += (characters typed/total characters)*(screenwidth-left offset - right offset)
                                gatorX -= 25.6;
                                gatorL.setPosition(gatorX, gatorY);
                            }
                        }
                        break;
                    case sf::Keyboard::Right:
                        if(true){
                            if(rectSourceSprite.left > 250)
             {
                                rectSourceSprite.left = 0;
                             }
                            else {
                                rectSourceSprite.left += 127;
                             }
                            
                            gatorR.setTextureRect(rectSourceSprite);
                            
                            if(gatorR.getPosition().x >= App.getSize().x)
             {
                                //FIXME remove from final code, only for testing
                                gatorX = 135;
                                gatorR.setPosition(gatorX, gatorY);
                            }
                            else
             {
                                //dist += (characters typed/total characters)*(screenwidth-left offset - right offset)
                                gatorX += 25.6;
                                gatorR.setPosition(gatorX, gatorY);
                            }
                        }
                    default:
                        break;
                }
            }*/
        }
        App.clear();
        App.draw(image);
        App.draw(behind);
        App.draw(playB);
        App.draw(PlayA);
        App.draw(mainB);
        App.draw(Main);
        App.draw(Congrats);
        //If accuracy is greater than 97 display Daddy Fuchs
        if(game.accuracyNum() >= 97)
        {
            App.draw(fuchs);
            App.draw(fuchs2);
            App.draw(Good);
        }
        //If accuracy is less than 80 than display dennis dad
        else if(game.accuracyNum() < 80)
        {
            App.draw(dennis);
            App.draw(dennis2);
            App.draw(Bad);
        }
        App.draw(WPM);
        App.draw(Acc);
        App.draw(gatorR);
        App.display();
    }
        //Clearing screen
        //Drawing
    /*if(sf::Keyboard::Up)
     {
        App.draw(gatorU);
    }
    if(sf::Keyboard::Left)
     {
        App.draw(gatorL);
    }
    else if(sf::Keyboard::Right)
     {
        App.draw(gatorR);
    }
    else if(sf::Keyboard::Down)
     {
        App.draw(gatorD);
    }*/
    return 2;
}
