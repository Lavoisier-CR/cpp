#ifndef FIRSTLEVEL_HPP
#define FIRSTLEVEL_HPP

#include "../src/ASCII_Engine/Fase.hpp"
#include "../src/ASCII_Engine/Core/SpriteBase.hpp"
#include "../src/ASCII_Engine/input/Keyboard.hpp"

#include <string>
#include <list>

#include "FisherMan.hpp"
#include "Box.hpp"
#include "Arrow.hpp"

#include "Fish.hpp"
#include "SlowFish.hpp"
#include "NormalFish.h"

class FirstLevel : public Fase {
    public:
        FirstLevel(std::string name, const SpriteBuffer &bkg) : Fase(name, bkg) {}
        FirstLevel(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
        FirstLevel(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
        virtual ~FirstLevel() {}
        
        virtual void init();
        virtual unsigned run(SpriteBuffer &screen);

        bool colideComBloco() const;
        
    private:	
        ObjetoDeJogo *fisherman;
        ObjetoDeJogo *box;
        ObjetoDeJogo *arrow;
        ObjetoDeJogo *fish1;
        ObjetoDeJogo *fish2;
        

        TextSprite *life;

        std::list<ObjetoDeJogo*> colisoes;
        
        enum {RIDING, PRACING, END};
};

#endif // FIRSTLEVEL_HPP