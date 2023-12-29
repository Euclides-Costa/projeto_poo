#ifndef POKEMONTIPOGRAMA_HPP
#define POKEMONTIPOGRAMA_HPP
#include "Pokemon.hpp"

class PokemonTipoGrama : public Pokemon{

    public:

        PokemonTipoGrama(const ObjetoDeJogo &obj, int vida=50, string nome="", int velAtaque=2) : Pokemon(obj, vida, nome), velAtaque(velAtaque), contAtaque(velAtaque){}
        virtual ~PokemonTipoGrama(){}

        virtual void sofrerAtaque(int ataque);
        virtual int atacar();

    private:
        int velAtaque, contAtaque;

};


#endif