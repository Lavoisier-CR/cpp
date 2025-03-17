#ifndef BOX_HPP
#define BOX_HPP

#include "../src/ASCII_Engine/ObjetoDeJogo.hpp"

class Box : public ObjetoDeJogo {
    public:
        Box(const ObjetoDeJogo &obj) : ObjetoDeJogo(obj), oppened(false){}
        virtual ~Box(){}

        void BoxOpened() { if (!oppened) {ObjetoDeJogo::update();this->oppened = true;}}
        bool isOppened() const {return this->oppened;}

        virtual void update() {/*caixa fechada*/}
    
    private:
        bool oppened;

};

#endif // BOX_HPP