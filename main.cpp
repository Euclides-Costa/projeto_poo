
#include <iostream>
#include <string>
#include "Game.hpp"
int main(){
	Game::run();

	return 0;
}
// #include "ASCII_Engine/Sprite.hpp"
// #include "ASCII_Engine/SpriteBuffer.hpp"
// #include "ASCII_Engine/SpriteAnimado.hpp"
// #include "ASCII_Engine/ObjetoDeJogo.hpp"


// int main(){

// 	system("clear");
// 	SpriteBuffer screen (400,122);

// 	ObjetoDeJogo bg("Fase1", Sprite("rsc/mostra2.txt"), 0,0);
// 	ObjetoDeJogo hero("Pessonagem", Sprite("rsc/personagem.txt"), 40,80);

// 	std::string str;

// 	while(true){

// 		getline(std::cin,str);

// 		bg.update();
// 		hero.update();

// 		// mover
// 		if (str =="w")
// 			hero.moveUp(3);
// 		else if (str == "s")
// 			hero.moveDown(3);
// 		else if (str == "a")
// 			hero.moveLeft(3);
// 		else if (str == "d")
// 			hero.moveRight(3);
		
// 		screen.clear();
// 		bg.draw(screen,bg.getPosL(), bg.getPosC());
// 		hero.draw(screen,hero.getPosL(), hero.getPosC());

// 		system("clear");
// 		std::cout << screen << std::endl;

// 	}

// 	return 0;
// }











// int main()
// {
// 	system("clear");
	
// 	SpriteBuffer screen(400, 122);

// 	Sprite bg("rsc/mostra2.txt");
// 	Sprite hero("rsc/personagem.txt");
	
// 	std::string str;
	
// 	while(true) {
// 		getline(std::cin,str);
		
// 		bg.update();
// 		hero.update();
		
// 		bg.draw(screen,0,0);
// 		hero.draw(screen,42,80);
		
// 		system("clear");
		
// 		std::cout << screen << std::endl;
// 	}
	
// 	return 0;
// }
