#ifndef POKEMON_HPP
#define POKEMON_HPP
#include <iostream>
#include <string>
#include "ASCII_Engine/ObjetoDeJogo.hpp"
using namespace std;

class Pokemon : public ObjetoDeJogo

{
    public:
        Pokemon(const ObjetoDeJogo &obj, int vida=100, string nome="") : ObjetoDeJogo(obj), vida(vida), nome(nome){}
        virtual ~Pokemon(){}

        virtual void sofrerAtaque(int ataque) =0; //{ vida = (vida - ataque >= 0)?(vida - ataque):0; }
        virtual int atacar() =0; 
        void setNome(string nome) {this->nome = nome;}
        void setVida(int vida) {this->vida = vida;}
        
        string getNome() const {return nome;} 
        bool estaVivo() const {return vida != 0;} 
        int getVida() const {return vida;}

    private:
        int vida;
        string nome;
};


#endif

