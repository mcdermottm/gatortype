//
//  Game.cpp
//  GataType
//
//  Created by Daniel Xu on 4/22/18.
//  Copyright © 2018 Daniel Xu. All rights reserved.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Game.h"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

Game::Game(){
    font.loadFromFile(resourcePath() + "Courier.dfont");
}

void Game::setSentence(std::string x){
    std::string temp = x;
    
    for (int i = 0; i < temp.size(); ++i) {
        inputSentence.push_back(temp[i]);
    }
}

void Game::setTextVector(){
    for (int i = 0; i < inputSentence.size(); ++i) {
        sf::Text tempText(inputSentence[i], font, 35);
        tempText.setFillColor(sf::Color::Black);
        //tempText.setOutlineColor(sf::Color::Black);
        //tempText.setStyle(sf::Text::Underlined);
        tempText.setPosition(20 * (i % 60) + 20, 40 * (int)(float)(i / 60) + 400);
        sentence.push_back(tempText);
    }
}

void Game::printInputSentence(){
    for (int i = 0; i < inputSentence.size(); ++i) {
        std::cout << inputSentence[i];
    }
    std::cout << std::endl;
}

void Game::correct(){
    sentence[current].setFillColor(sf::Color::Green);
    current++;
}

void Game::wrong() {
    sentence[current].setFillColor(sf::Color::Red);
}

sf::Text Game::getElement(int x){
    return sentence.at(x);
}

std::string Game::getElementS(int x){
    return sentence.at(x).getString();
}

int Game::getCurrent() {
    return current;
}

bool Game::isEmpty() {
    return sentence.empty();
}

void Game::newKeystroke() {
    keystrokes++;
    return;
}

/*sf::Text Game::getAccuracy() {
    if(keystrokes != 0) {
        accuracy.setString("Accuracy is " + std::to_string((int)(std::trunc(((float)(current)/keystrokes) * 100))) + "%");
    }
    else {
        accuracy.setString("Accuracy is 0%");
    }
    
    accuracy.setFont(font);
    accuracy.setCharacterSize(35);
    accuracy.setFillColor(sf::Color::White);
    accuracy.setPosition(150, 550);
    return accuracy;
}*/

sf::Text Game::getAccuracy()
{
    if(keystrokes != 0)
    {
        accuracy.setString(std::to_string((int)(std::trunc(((float)(current)/keystrokes) * 100))));
    }
    else {
        accuracy.setString("0");
    }
    
    accuracy.setFont(font);
    accuracy.setCharacterSize(30);
    accuracy.setFillColor(sf::Color::Black);
    accuracy.setPosition(150, 550);
    return accuracy;
}

int Game::accuracyNum()
{
    return (int)(std::trunc(((float)(current)/keystrokes) * 100));
}

/*bool Game::charMatch()
 {
    
}*/

void Game::calcWPM(sf::Time time)
{
    float elapsedTime = time.asSeconds();
    
    if(keystrokes != 0)
    {
        WPM.setString(std::to_string((int)(std::trunc((current * 12) / elapsedTime))));
    }
    else
    {
        WPM.setString("0");
    }
}

sf::Text Game::getWPM()
{
    WPM.setFont(font);
    WPM.setCharacterSize(35);
    WPM.setFillColor(sf::Color::White);
    WPM.setPosition(700, 550);
    return WPM;
}

float Game::getSize()
{
    return sentence.size(); 
}

/*
 Because one game object is being used in the whole program
 the private vector containing the char array given by the
 text generator and the sf::Text array it creates must be emptied
 so that any new call to the function doesn't just append to the
 already existing char vector and sf::Text vector and instead can
 display a completely new line
 */
void Game::delVec(){
    current = 0;
    sentence.clear();
    inputSentence.clear();
}

void Game::delKeystrokes(){
    keystrokes = 0;
}
