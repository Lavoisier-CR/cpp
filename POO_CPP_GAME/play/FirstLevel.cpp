#include "FirstLevel.hpp"

#include "../src/ASCII_Engine/input/Keyboard.hpp"

#include <iostream>
#include <string>
#include <list>



void FirstLevel::init(){

	//Objetos de jogo
	fisherman = new FisherMan(ObjetoDeJogo("FisherMan", SpriteAnimado("rsc/fisherman.anm",2, COR::VERMELHA),10,10));
	objs.push_back(fisherman);
	
	box = new Box(ObjetoDeJogo("Box", SpriteAnimado("rsc/box.anm",2, COR::AMARELA),38,45));
	objs.push_back(box);

	fish1 = new SlowFish(ObjetoDeJogo("SlowFish", Sprite("rsc/fish1.img", COR::ROSA),28,44));
	objs.push_back(fish1);

	fish2 = new NormalFish(ObjetoDeJogo("NormalFish", Sprite("rsc/fish2.img", COR::MARROM),18,42));
	objs.push_back(fish2);

	arrow = new Arrow(ObjetoDeJogo("Arrow", Sprite("rsc/arrow.img", COR::AZUL),49,102));
	objs.push_back(arrow);
													 //std::string(20,'#')
	objs.push_back(new ObjetoDeJogo("Life", TextSprite("####################", COR::BRANCA),3,5));
	SpriteBase *tmp = const_cast<SpriteBase*> (objs.back()->getSprite());
	life = dynamic_cast<TextSprite*> (tmp);
	
	//screen
	objs.push_back(new ObjetoDeJogo("Bk1",Sprite("rsc/screenScoreBoard.img", COR::MAGENTA),0,0));
	colisoes.push_back(objs.back());
	
	objs.push_back(new ObjetoDeJogo("Bk2",Sprite("rsc/screenSrfcSea.img", COR::CIANO),10,0));
	colisoes.push_back(objs.back());

	objs.push_back(new ObjetoDeJogo("Bk3",Sprite("rsc/screenDpSea.img",COR::CIANO),39,0));
	colisoes.push_back(objs.back());

}

unsigned FirstLevel::run(SpriteBuffer &screen) {
	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	while (true){

		//lendo entrada
		getline(std::cin,ent);
		
		//processando entradas
		int posL = fisherman->getPosL(), posC = fisherman->getPosC();
		
		if (ent == "w" && fisherman->getPosL() > 10)
			fisherman->moveUp(3);
		else if (ent == "s" && fisherman->getPosL() < screen.getAltura() - 15)
			fisherman->moveDown(3);
		else if (ent == "a" && fisherman->getPosC() > 12)
			fisherman->moveLeft(3);
		else if (ent == "d" && fisherman->getPosC() < screen.getLargura() - fisherman->getSprite()->getLargura() - 13)
			fisherman->moveRight(3);
		else if (ent == "x") {
            if (fisherman->colideCom(*fish1)) {
                fish1->getHurt(fisherman->attackPower());
                if (!fish1->isAlive())
                    fish1->desativarObj();
            }
		}
		else if (ent == "q")
			return Fase::END_GAME;	

		if (colideComBloco()) 
			fisherman->moveTo(posL,posC);
		
		
		//processando eventos
		if (fisherman->colideCom(*fish1)) {
			fisherman->getHurt(fish1->attackPower());
					
			if (!fisherman->isAlive()){
				return Fase::GAME_OVER;
				life->setText(std::string(fisherman->getLife()/5,'#'));
			}
		}
		
		if (fisherman->colideCom(*box)){
			box->isOpened();
			fisherman-->refillArrows();
		}
		
		
		//padrão
		update();
		draw(screen);
		system("clear");
		show(screen);
	}
	
	return Fase::END_GAME; 
}

bool FaseLevel1::colideComBloco() const
{
	for (auto it = colisoes.begin() ; it != colisoes.end() ; ++it)
		if (fisherman->colideCom(**it)) {
			return true;
		}
	
	if (fisherman->colideCom(*) && !box->isOppened()) return true;
	
	return false;
}