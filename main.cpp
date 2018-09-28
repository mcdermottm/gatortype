#include <SFML/Graphics.hpp>
#include "Frame.h"
#include "menuScr.h"
#include "playScr.h"
#include "finishScr.h"
#include <iostream>
#include "textgen.h"

int main(int argc, char** argv)
{
    //Applications variables
    std::vector<Frame*> States;
    
    //Text Generator
    TextGen* tGen = new TextGen();
    Game * game = new Game();
    
    //Window creation
    sf::RenderWindow Typer(sf::VideoMode(1280, 640, 32), "Gator Type");
    
    //Typer.setMouseCursorVisible(false);

    //Screens preparations
    menuScr main;
    States.push_back(&main);
    playScr play;
    States.push_back(&play);
    finishScr finish;
    States.push_back(&finish);
    
    int state = 0;
    while (state >= 0)
    {
        state = States[state]->Run(Typer, *tGen, *game);
    }
    
    /*
     Main method works by creating a menu scren class,
     a play screen class, and an end screen class.
     Each screen is a branch of the frame abstract class.
     Each screen is pushed onto a vector of frame objects and each one
     contains a Run function that takes in a Render Window, a text Generator,
     and a Game object, which posseses accuracy and words per minute
     calculation abilities. The text generator and game object
     are all passed around so that the difficulty levels for the text
     generator and the words per min result and accuracy rate can be
     gotten in each screen with the getDifficulty, getAccuracy,
     and getWPM count functions. Each Run function returns 0
     if the user is trying to get to the menu screen because in the States
     vector the 0th index is the menu screen. A 1 is returned to get to
     the play screen becayse the 1st index in the States vector is a play
     screen. A 2 is returned from the run function to get to the end
     screen and this is triggered when the final word is typed from the
     text generator. In order to stay on a screen the Run functions
     continually return the same value of the screen they are on.
     For instance, if the program was on the play scren the play
     screen run method would continually return 1 so that the
     play scren window would stay being displayed. 
     */
    return EXIT_SUCCESS;
}

