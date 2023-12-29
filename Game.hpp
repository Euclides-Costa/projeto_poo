#ifndef GAME_HPP
#define GAME_HPP
#include "Casa1.hpp"
#include "GlobalMap.hpp"
#include "Casa2.hpp"
#include "FaseLevel1.hpp"
#include "GameOver.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "Sound.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(400,122);
		PokemonPikachu *pikachu = new PokemonPikachu(ObjetoDeJogo("Pikachu", Sprite("rsc/personagem.txt"),39,90));
		GlobalMap teste ("Teste", Sprite("rsc/casaTia2.txt"), pikachu);
		
		teste.init();
		teste.run(buffer);
		
		std::cout << "Saindo..." << std::endl;
	}

};

#endif // GAME_HPP
