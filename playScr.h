//
//  playScr.hpp
//  Gator Type
//
//  Created by Ankit  on 4/22/18.
//  Copyright © 2018 Ankit . All rights reserved.
//

#ifndef playScr_hpp
#define playScr_hpp

#include <iostream>
#include "Frame.h"
#include <SFML/Graphics.hpp>
#include "textgen.h"

class playScr : public Frame
{
private:
    float movement_step;
    float posx;
    float posy;
    sf::RectangleShape Rectangle;
public:
    playScr(void);
    virtual int Run(sf::RenderWindow &App, TextGen &T, Game &game);
};

#endif /* playScr_hpp */
