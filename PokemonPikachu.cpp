#include "PokemonPikachu.hpp"

void PokemonPikachu::sofrerAtaque(int ataque){
    int vida;
    vida = (getVida() - ataque >= 0)?(getVida() - ataque):0;
    setVida(vida);
}