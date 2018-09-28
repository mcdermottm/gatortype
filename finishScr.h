//
//  finishScr.hpp
//  Gator Type
//
//  Created by Ankit  on 4/22/18.
//  Copyright © 2018 Ankit . All rights reserved.
//

#ifndef finishScr_hpp
#define finishScr_hpp

#include "Frame.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <stdio.h>

class finishScr : public Frame
{
private:
    
    bool playing;
    
public:
    //Basic Constructor
    finishScr(void);
    //Run Method that returns place in States vector
    virtual int Run(sf::RenderWindow &App, TextGen &T, Game &game);
};

#endif /* finishScr_hpp */
