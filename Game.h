//
//  Game.hpp
//  GataType
//
//  Created by Daniel Xu on 4/22/18.
//  Copyright © 2018 Daniel Xu. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>

class Game{
private:
    std::vector<char> inputSentence;
    std::vector<sf::Text> sentence;
    sf::Font font;
    sf::Text accuracy;
    int current = 0;
    int keystrokes = 0;
    sf::Text WPM; 
public:
    Game();
    std::string getElementS(int x);
    void setSentence(std::string x);
    void setTextVector();
    void printInputSentence();
    void correct();
    void wrong();
    sf::Text getElement(int x);
    bool charMatch();
    float getSize();
    int getCurrent();
    bool isEmpty();
    void newKeystroke();
    sf::Text getAccuracy();
    void calcWPM(sf::Time time);
    sf::Text getWPM();
    sf::Text getsAccuracy();
    void delVec();
    int accuracyNum();
    void delKeystrokes();
};

#endif /* Game_hpp */
