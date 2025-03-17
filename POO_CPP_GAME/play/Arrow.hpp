#ifndef ARROW_HPP
#define ARROW_HPP

#include "Mobile.hpp"

class Arrow : public Mobile {
public:
    Arrow(const ObjetoDeJogo &obj, const Way followWay, const int speedObj = 2) : Mobile{obj, followWay, speedObj} {}
    ~Arrow() {}

    bool getActive() const { return activeMobile; }
    void setActive(const bool active) { activeMobile = active; }

    void update() override {
        ObjetoDeJogo::update();
        if(getWay() == RightWay) {
            this->moveRight(getSpeed());
        } else {
            this->moveLeft(getSpeed());
        }

        if(getActive()) {
            setSpeed(getSpeed() + 6);
            if(getSpeed() >= 16) { setActive(false); }
        } else {
            setSpeed(getSpeed() - 4);
            if(getSpeed() <= 2) { setActive(true); }
        }
    }

private:
    bool activeMobile{true};
    int speedObj{2};
};

#endif