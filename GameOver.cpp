#include "GameOver.hpp"
#include <string>
#include "Sound.hpp"
void GameOver::init()
{
	objs.push_back(new ObjetoDeJogo("GameOver",Sprite("rsc/gameOver.txt"),0,0));
}

 unsigned GameOver::run(SpriteBuffer &screen)
 {
    std::string enter;
    // getline(std::cin, enter);
    update();
    draw(screen);
    system("clear");
    show(screen);
    if (enter != "n"){
        Sound ohh("ohh.mp3");
        Sound gameOver("gameOver.mp3");
        ohh.play();
	    gameOver.playloop();

        update();
        draw(screen);
        system("clear");
        show(screen);
        getline(std::cin, enter);
    }
    

    
    // std::string enter;
    // getline(std::cin, enter);
 	return Fase::END_GAME; // não necessário
 }

