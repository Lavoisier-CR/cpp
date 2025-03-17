#ifndef FISH_HPP
#define FISH_HPP

#include "../src/ASCII_Engine/ObjetoDeJogo.hpp"
#include <algorithm>

class Fish : public ObjetoDeJogo {
public:
    Fish(const ObjetoDeJogo &obj, int life, int attackPower, int speed) 
        : ObjetoDeJogo(obj), life(life), attackPower(attackPower), speed(speed) {}

    virtual ~Fish() {}

    bool isAlive() const { return life > 0; }
    
    void getHurt(int damage) {
        life = std::max(0, life - damage);
    }

    int getLife() const { return life; }
    int getAttackPower() const { return attackPower; }
    int getSpeed() const { return speed; }

protected:
    int life;
    int attackPower;
    int speed;
};

#endif // FISH_HPP
