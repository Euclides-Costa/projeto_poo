#ifndef POKEMONLEBDARIO_HPP
#define POKEMONLENDARIO_HPP
#include "Pokemon.hpp"

class PokemonLendario : public Pokemon{

    public:

        PokemonLendario(const ObjetoDeJogo &obj, int vida=60, string nome="", int velAtaque=1) : Pokemon(obj, vida, nome), velAtaque(velAtaque), contAtaque(velAtaque){}
        virtual ~PokemonLendario(){}

        virtual void sofrerAtaque(int ataque);
        virtual int atacar();

    private:
        int velAtaque, contAtaque;

};


#endif