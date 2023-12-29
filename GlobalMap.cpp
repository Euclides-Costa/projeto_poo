#include "GlobalMap.hpp"
#include <string>

void GlobalMap::init(){
    mapas[CASA1] = new Casa1("Casa1", Sprite("rsc/casaTia2.txt"), pikachu);
    mapas[CASA1]->init();

    mapas[CASA2] = new Casa2("Casa2", Sprite("rsc/casa3.txt"), pikachu);
    mapas[CASA2]->init();

    mapas[FASE_LEVEL1] = new FaseLevel1("Vila", Sprite("rsc/mapa2.txt"), pikachu);
    mapas[FASE_LEVEL1]->init();

    mapas[LEVEL_COMPLETE] = new FaseComplete("Vila", Sprite("rsc/mission.txt"));
    mapas[LEVEL_COMPLETE]->init();

    mapas[GAME_OVER] = new GameOver("GameOver", Sprite("rsc/gameOver.txt"));
    mapas[GAME_OVER]->init();

}

unsigned GlobalMap::run(SpriteBuffer &screen){
    unsigned map = CASA1;
    while (map != GAME_OVER){
        map = mapas[map]->run(screen);
    }
    mapas[GAME_OVER]->run(screen);
    return 1;
}