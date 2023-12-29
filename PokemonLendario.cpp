#include "PokemonLendario.hpp"



void PokemonLendario::sofrerAtaque(int ataque) {
    int vida;
    vida = (getVida() - ataque >= 0)?(getVida()- ataque):0;
    setVida(vida);
    if (vida == 0){
        this->desativarObj();
    }
}

int PokemonLendario::atacar(){ 
    if (--contAtaque == 0) {
        contAtaque = velAtaque;
        return 18;
    }
    return 0;
}