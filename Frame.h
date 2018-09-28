#include <SFML/Graphics.hpp>
#include "textgen.h"
#include "Game.h"

#ifndef Frame_h
#define Frame_h

class Frame {
public:
    virtual int Run(sf::RenderWindow &App, TextGen &T, Game &game) = 0;
};

#endif /* Frame_h */

