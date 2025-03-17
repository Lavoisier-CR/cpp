#include "HomeScreen.hpp"

#include "../src/ASCII_Engine/input/Keyboard.hpp"
#include "../src/ASCII_Engine/Cores.hpp"

void HomeScreen::init(){
    objs.push_back(new ObjetoDeJogo("ocean", Sprite("../rsc/ocean.anm", COR::CIANO), 1,1));
}