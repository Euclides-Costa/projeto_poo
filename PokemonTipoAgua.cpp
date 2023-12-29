#include "PokemonTipoAgua.hpp"



void PokemonTipoAgua::sofrerAtaque(int ataque) {
    int vida;
    vida = (getVida() - ataque >= 0)?(getVida()- ataque):0;
    setVida(vida);
    if (vida == 0){
        this->desativarObj();
    }
}

int PokemonTipoAgua::atacar(){ 
    if (--contAtaque == 0) {
        contAtaque = velAtaque;
        return 10;
    }
    return 0;
}