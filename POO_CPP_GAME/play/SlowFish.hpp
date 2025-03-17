#ifndef SLOWFISH_HPP
#define SLOWFISH_HPP

#include "Fish.hpp"

class SlowFish : public Fish {
public:
    SlowFish(const ObjetoDeJogo &obj, int life = 30, int attackPower = 5, int speed = 5) 
        : Fish(obj, life, attackPower, speed){}

    virtual ~SlowFish() {}


};

#endif // SLOWFISH_HPP
