#ifndef MOBILE_HPP
#define MOBILE_HPP

#include "../src/ASCII_Engine/ObjetoDeJogo.hpp"
#include <string>

enum Way { LeftWay, RightWay };

class Mobile : public ObjetoDeJogo {
public:
    Mobile (const ObjetoDeJogo &obj, const Way followWay, const int speedObj = 2) : ObjetoDeJogo{obj}, mobileWay{followWay}, mobileSpeed{speedObj} {}
    virtual ~Mobile() {}

    Way getWay() const { return mobileWay; }

    int getSpeed() const { return mobileSpeed; }
    void setSpeed(const int speed) { mobileSpeed = speed; }

    virtual void update() {
        ObjetoDeJogo::update();
        if(getWay() == LeftWay) {
            this->moveLeft(getSpeed());
        } else {
            this->moveRight(getSpeed());
        }
    }

private:
    int mobileSpeed;
    Way mobileWay;
};

#endif  // MOBILE_HPP