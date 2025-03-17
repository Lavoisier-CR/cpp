#ifndef GAME_HPP
#define GAME_HPP

#include "HomeScreen.hpp"
#include "FirstLevel.hpp"
//#include "FinalLevel.hpp"

#include "../src/ASCII_Engine/Sprite.hpp"
#include "../src/ASCII_Engine/SpriteAnimado.hpp"
#include "../src/ASCII_Engine/Cores.hpp"


class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(150,57);
	
		HomeScreen start("HomeScreen",SpriteAnimado("rsc/ocean.anm",3));
		FirstLevel FirstLevel("FirstLevel",Sprite("rsc/fisherman.img"));
				
		start.init();
		start.run(buffer);
		
		buffer.clear();
		FirstLevel.init();
		int ret1 = FirstLevel.run(buffer);
		if ( ret1 != Fase::GAME_OVER && ret1 != Fase::END_GAME){
		
			buffer.clear();
			//FinalLevel.init();
			//FinalLevel.run(buffer);
		}
		else
			std::cout << "GAME OVER" << std::endl;
		
		std::cout << "So Long..." << std::endl;
	}

};

#endif // GAME_HPP
