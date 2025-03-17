#ifndef NORMALFISH_HPP
#define NORMALFISH_HPP

#include "Fish.hpp"

class NormalFish : public Fish {
public:
    NormalFish(const ObjetoDeJogo &obj, int life = 60, int attackPower = 20, int speed = 10) 
        : Fish(obj, life, attackPower, speed){}

    virtual ~NormalFish() {}


};

#endif // NORMALFISH_HPP
