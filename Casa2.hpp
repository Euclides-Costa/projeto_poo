#ifndef CASA2_HPP
#define CASA2_HPP

#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "PokemonPikachu.hpp"
#include "PokemonTipoGrama.hpp"

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>


class Casa2 : public Fase
{
public:
	Casa2(std::string name, const Sprite &bkg, PokemonPikachu *const pikachu) : Fase(name,bkg), pikachu(pikachu) {}
	virtual ~Casa2() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
    
private:
	PokemonPikachu *pikachu;
	PokemonTipoGrama *tGrama2;
	ObjetoDeJogo *capaInvisivel2;
	ObjetoDeJogo *tapetePorta;
	ObjetoDeJogo *quantPorcao;
	ObjetoDeJogo *vida[5];

};

#endif // Casa2_HPP
