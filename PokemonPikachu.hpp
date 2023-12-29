#ifndef POKEMONPIKACHU_HPP
#define POKEMONPIKACHU_HPP
#include "Pokemon.hpp"

class PokemonPikachu : public Pokemon{

    public:

        PokemonPikachu(const ObjetoDeJogo &obj, int vida=100, string nome="", int velAtaque=3) : Pokemon(obj, vida, nome), velAtaque(velAtaque), contAtaque(velAtaque), quantInimigos(0), bolsaVida(0), usouBolsa(0){}
        virtual ~PokemonPikachu(){}

        virtual void sofrerAtaque(int ataque);
        virtual int atacar() {return 17;};
        void setQuantInimigos(int quantInimigos) {this->quantInimigos = quantInimigos;}
        void setBolsaVida(int bolsaVida) {this->bolsaVida = bolsaVida;}
        void setUsouBolsa(int usouBolsa) {this->usouBolsa = usouBolsa;}
        int getQuantInimigos() const {return quantInimigos;}
        int getBolsaVida() const {return bolsaVida;}
        int getUsouBolsa() const {return usouBolsa;}

    private:
        int velAtaque, contAtaque;
        int quantInimigos;
        int bolsaVida;
        int usouBolsa;

};


#endif