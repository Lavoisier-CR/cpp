#ifndef FASTFISH_HPP
#define FASTFISH_HPP

#include "Fish.hpp"

class FastFish : public Fish {
public:
    FastFish(const ObjetoDeJogo &obj, int life = 60, int attackPower = 35, int speed = 15) 
        : Fish(obj, life, attackPower, speed){}

    virtual ~FastFish() {}


};

#endif // FASTFISH_HPP
