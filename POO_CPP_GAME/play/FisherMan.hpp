#ifndef FISHERMAN_HPP
#define FISHERMAN_HPP

#include "../src/ASCII_Engine/ObjetoDeJogo.hpp"
#include <iostream>


class FisherMan : public ObjetoDeJogo {

    public:
        FisherMan(const ObjetoDeJogo &obj, int life = 100, int arrows = 5 , int score = 0 ) : ObjetoDeJogo(obj), life(life), arrows(arrows), score(score) {}
        virtual ~FisherMan() {}

        bool isAlive() const {return life > 0;}
        int getLife() const {return life;}
        int getScore() const {return score;}
        int fishing() const {return 30;}

        void getHurt(int attack) {life = (life - attack >= 0)?(life - attack):0;}
        
        /*void decreaseOxygen() {
            if (pos_y > 10) { // Se estiver abaixo da superfície
                life -= (pos_y / 10) + 1;// Quanto mais profundo, mais rápido perde oxigênio
                if(life < 0) life = 0;
            }
        }
        
        void refillOxygen() {
            if (pos_y == 10) { // Se estiver na superfície
                life = 100;
            }
        }
       */ 
        void shootArrow() {
            if (arrows > 0) {
                arrows--;
            } else {
                std::cout << "Sem flechas! Procure uma caixa de reposição!\n";
            }
        }
        
        void refillArrows() {
            arrows = std::min(arrows+5,50);
        }     

        

    private:
        int life;
        int arrows;
        int score;
};

#endif // FISHERMAN_HPP
