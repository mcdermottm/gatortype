//
//  menuScr.h
//  Gator Type
//
//  Created by Ankit  on 4/21/18.
//  Copyright © 2018 Ankit . All rights reserved.
//

#ifndef menuScr_h
#define menuScr_h

#include "Frame.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "textgen.h"

class menuScr : public Frame {
private:
    
    bool playing;
    
public:
    //constructor
    menuScr(void);
    //Run function that returns position in States vector
    virtual int Run(sf::RenderWindow &App, TextGen &T, Game &game);
};

#endif /* Frame_h */
