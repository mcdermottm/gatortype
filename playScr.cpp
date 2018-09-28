//
//  playScr.cpp
//  Gator Type
//
//  Created by Ankit  on 4/22/18.
//  Copyright © 2018 Ankit . All rights reserved.
//

#include "ResourcePath.hpp"
#include "playScr.h"
#include <iostream>
#include "Frame.h"
#include <SFML/Graphics.hpp>
#include "textgen.h"
#include "Game.h"
#include <sstream>

playScr::playScr(void){};

int playScr::Run(sf::RenderWindow &App, TextGen &T, Game &game){
    // Boolean for underlined text
    bool currentIsWrong = false;
    
    sf::RectangleShape typeArea;
    typeArea.setSize({1280.0f, 256.0f});
    typeArea.setPosition(0.0f, 384.0f);
    sf::Color color2(200, 200, 200);
    typeArea.setFillColor(color2);
    
    sf::RectangleShape followLine;
    followLine.setSize({850.0f, 5.0f});
    followLine.setPosition(140.0f, 288.0f);
    followLine.setFillColor(sf::Color::Yellow);
    
    //Dirt texture
    sf::Texture dirt;
    if (!dirt.loadFromFile("dirt2.png", sf::IntRect(0, 0, 1280, 125))){
        std::cout << "Can't find the image" << std::endl;
    }
    sf::Sprite dirtBack;
    dirtBack.setTexture(dirt);
    dirtBack.setPosition(0.0f, 259.0f);
    
    //Sky texture
    sf::Texture sky;
    if (!sky.loadFromFile("sky2.jpg", sf::IntRect(0, 900, 1280, 259))){
        std::cout << "Can't find the image" << std::endl;
    }
    sf::Sprite skyBack;
    skyBack.setTexture(sky);
    skyBack.setPosition(0.0f, 0.0f);
    
    //Tower sprite
    sf::Texture tower;
    if (!tower.loadFromFile("tower.png")){
        std::cout << "Can't find the image" << std::endl;
    }
    sf::Sprite century;
    century.setTexture(tower);
    century.setPosition(1020.0f, 110.0f);
    
    //Potato sprite
    sf::Texture potato;
    if (!potato.loadFromFile("potatoman.png")){
        std::cout << "Can't find the image" << std::endl;
    }
    sf::Sprite potatoMan;
    potatoMan.setTexture(potato);
    potatoMan.setPosition(20.0f, 120.0f);
    
    //Alligator sprite
    sf::Texture alligator;
    alligator.loadFromFile("alligator.png");
    sf::IntRect rectSourceSprite(0, 164, 127, 82);
    sf::Sprite gator(alligator, rectSourceSprite);
    float gatorX = 135; //Initialize to left offset distance
    float gatorY = 245;
    gator.setPosition(gatorX, gatorY);
    
    //Cloud texture
    sf::Texture cloudTexture;
    cloudTexture.loadFromFile("cloud2.png");
    sf::IntRect cloudSourceSprite(0, 0, 541, 150);
    sf::Sprite cloud(cloudTexture, cloudSourceSprite);
    //cloud.setPosition(300, 20);
    sf::Clock cloudClock;
    
    //Grass texture
    sf::Texture grass;
    if (!grass.loadFromFile("grassy2.png"))
    {
        std::cout << "Can't find the image" << std::endl;
    }
    sf::Sprite grasses;
    grasses.setTexture(grass);
    
    //Text from text generator
    sf::Text sentence;
    sf::Font funt;
    funt.loadFromFile(resourcePath() + "Courier.dfont");
    sentence.setFont(funt);
    sentence.setFillColor(sf::Color::Black);
    if(T.getDifficulty() == 0)
    {
        sentence.setString(T.trimSentence(T.generateSentence(), 175));
    }
    else if(T.getDifficulty() == 1)
    {
        sentence.setString(T.trimSentence(T.generateSentence(), 210));
    }
    else if(T.getDifficulty() == 2)
    {
        sentence.setString(T.trimSentence(T.generateSentence(), 245));
    }
    
    sf::Clock gatorRectClock;

    game.setSentence(sentence.getString());
   // game.printInputSentence();
    game.setTextVector();
    //std::string sent = (std::string) game.getElement(game.getCurrent()).getString();
    //sstd::cout << sent << std::endl;
    
    sf::Clock wpmClock;
    bool isFirstTime = true;
    
    sf::Text accuracy;
    accuracy.setString("Accuracy is N/A");
    accuracy.setFont(funt);
    accuracy.setFillColor(sf::Color::Black);
    accuracy.setCharacterSize(35);
    accuracy.setPosition(100.0f, 590.0f);
    
    sf::Text wpm;
    wpm.setString("WPM is N/A");
    wpm.setFont(funt);
    wpm.setFillColor(sf::Color::Black);
    wpm.setCharacterSize(35);
    wpm.setPosition(500.0f, 590.0f);
    
    //Escape text
    sf::Text esc;
    esc.setFont(funt);
    esc.setString("Press Esc to leave");
    esc.setFillColor(sf::Color::Black);
    esc.setCharacterSize(20);
    esc.setPosition(1050.0f, 600.0f);

    sf::Music music;
    music.openFromFile(resourcePath() + "oof.ogg");
    
    while (App.isOpen())
    {
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
        gator.setTextureRect(rectSourceSprite);
        
        if(cloudClock.getElapsedTime().asSeconds() > 0.8f)
        {
            if(cloudSourceSprite.left > 540)
            {
                cloudSourceSprite.left = 0;
            }
            else{
                cloudSourceSprite.left += 541;
            }
            cloud.setTextureRect(cloudSourceSprite);
            cloudClock.restart();
        }
        
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            if(Event.key.code == sf::Keyboard::Escape)
            {
                game.delKeystrokes();
                game.delVec();
                return 0;
            }
            switch (Event.type)
            {
                case sf::Event::Closed:
                    return -1;
                    break;
                case sf::Event::TextEntered:
                {
                    //accuracy updates on screen every time a key press is entered
                    accuracy.setString("Accuracy is " + game.getAccuracy().getString() + "%");
                    
                    if(isFirstTime == true)
                    {
                        /*
                         firsTime bool was created so that whenever the first character
                        is typed then the wpm timer starts so that it does not run while
                         nothing is being typed
                         */
                        isFirstTime = false;
                        wpmClock.restart();
                    }
                    if(game.getCurrent() == game.getSize() - 1)
                    {
                        /*
                         Game object is deleted so that it can be regenerated
                         whenever it is called. Without this when we would shift
                         frames text would simply append and the string to be typed
                         would be a longer version of what was displayed before.
                         */
                        
                        /*for(int i = game.getSize(); i > 0; i--)
                        {
                            std::cout << ((std::string) game.getElement(game.getCurrent()).getString()).at(0);
                        }
                        //sf::Time totalTime = wpmClock.getElapsedTime();
                        //std::cout << "Sup" << std::endl;*/
                        return 2;
                    }
                    //accuracy is current/keystrokes so need to increment keystrokes
                    game.newKeystroke();
                    //if the keystroke was right
                    /*std::string sent = game.getElementS(game.getCurrent());
                    std::stringstream ss(sent);
                    int x;
                    ss >> x;
                    std::cout << x << std::endl;
                     */
                    if(Event.text.unicode == (int) ((std::string) game.getElement(game.getCurrent()).getString()).at(0))
                    {
                        std::cout << game.getElementS(game.getCurrent());
                        game.correct();
                        currentIsWrong = false;
                        wpm.setString("WPM is " + game.getWPM().getString());
                        game.calcWPM(wpmClock.getElapsedTime());
                        
                        gator.setTextureRect(rectSourceSprite);
                        
                        if(gator.getPosition().x >= App.getSize().x - 415.0f)
                        {
                            //FIXME remove from final code, only for testing
                            gatorX = 135;
                            gator.setPosition(gatorX, gatorY);
                        }
                        else {
                            gatorX = (game.getCurrent()/game.getSize())*723.0f + 135;
                            //gatorX += 25.6;
                            gator.setPosition(gatorX, gatorY);
                        }
                    }
                    //if the keystroke was wrong
                    else
                    {
                        currentIsWrong = true; 
                        game.wrong();
                        music.play();
                    }
                    break;
            }
                default:
                    break;
            }
        }
        
        App.clear();
        App.draw(typeArea);
        /*for (float i = 0.0f; i < game.getSize(); ++i)
         {
            App.draw(game.getElement(i));
        }*/
        for (int i = 0; i < game.getSize(); ++i)
        {
            if(i == game.getCurrent())
            {
                sf::Text tempText(game.getElement(i).getString(), funt, 35);
                tempText.setStyle(sf::Text::Underlined);
                
                if(currentIsWrong)
                {
                    tempText.setFillColor(sf::Color::Red);
                }
                else
                {
                    tempText.setFillColor(sf::Color::Black);
                    
                }
                tempText.setPosition(20 * (i % 60) + 20, 40 * (int)(float)(i / 60) + 400);
                App.draw(tempText);
        
            }
            else
            {
                App.draw(game.getElement(i));
            }
            
        }
        
        //Displays accuracy and wpm
        App.draw(accuracy);
        App.draw(wpm);
        App.draw(esc);
        
        //App.draw(sentence);
        
        //Draws nature textures
        App.draw(dirtBack);
        App.draw(skyBack);
        App.draw(cloud);
        /*
         For loop creates multiple cloud images and draws them in
         different x positions relative to each other
         */
        
        float cloudLeft = 0.0f;
        for(int i = 0; i < 3; i++)
        {
            cloud.setPosition(cloudLeft, 20.0f);
            App.draw(cloud);
            cloudLeft += 600.0f;
        }
        
        //Draws landmarks
        App.draw(century);
        App.draw(potatoMan);
        
        App.draw(followLine);
        App.draw(gator);
        
        //Grass is drawn over landmarks in order to give a more outdoor vibe
        float grassLeft = 0.0f;
        for(int i = 0; i < 3; i++)
        {
            grasses.setPosition(grassLeft, 300.0f);
            App.draw(grasses);
            grassLeft += 700.0f;
        }
        
        App.display();
    }
    return 1;
}
 
