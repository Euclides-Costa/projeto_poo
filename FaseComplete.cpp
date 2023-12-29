#include "FaseComplete.hpp"
#include <string>
#include "Sound.hpp"
void FaseComplete::init()
{
	objs.push_back(new ObjetoDeJogo("FaseComplete",Sprite("rsc/mission.txt"),0,0));
}

 unsigned FaseComplete::run(SpriteBuffer &screen)
 {
    std::string enter;
    // getline(std::cin, enter);
    update();
    draw(screen);
    system("clear");
    show(screen);
    if (enter != "n"){
        Sound final("final.mp3");
        final.playloop();

        update();
        draw(screen);
        system("clear");
        show(screen);
        getline(std::cin, enter);
    }
 	return Fase::END_GAME; // não necessário
 }

