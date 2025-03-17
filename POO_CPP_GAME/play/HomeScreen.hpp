#ifndef HOMESCREEN_HPP
#define HOMESCREEN_HPP

#include "../src/ASCII_Engine/Fase.hpp"

class HomeScreen : public Fase {
public:
    HomeScreen(std::string name, const SpriteBuffer &bkg) : Fase(name, bkg) {}
	virtual ~HomeScreen() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
private:	
    ObjetoDeJogo *ocean;
    ObjetoDeJogo *fish;
    
};

#endif // HOMESCREEN_HPP