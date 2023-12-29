#ifndef POKEMONTIPOAGUA_HPP
#define POKEMONTIPOAGUA_HPP
#include "Pokemon.hpp"

class PokemonTipoAgua : public Pokemon{

    public:

        PokemonTipoAgua(const ObjetoDeJogo &obj, int vida=50, string nome="", int velAtaque=1) : Pokemon(obj, vida, nome), velAtaque(velAtaque), contAtaque(velAtaque){}
        virtual ~PokemonTipoAgua(){}

        virtual void sofrerAtaque(int ataque);
        virtual int atacar();

    private:
        int velAtaque, contAtaque;

};

#endif