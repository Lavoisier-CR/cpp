#ifndef SHARKFISH_HPP
#define SHARKFISH_HPP

#include "Fish.hpp"

class SharkFish : public Fish {
public:
    SharkFish(const ObjetoDeJogo &obj, int life = 90, int attackPower = 100, int speed = 25) 
        : Fish(obj, life, attackPower, speed){}

    virtual ~SharkFish() {}


};

#endif // SHARKFISH_HPP
