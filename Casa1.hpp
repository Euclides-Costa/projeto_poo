#ifndef CASA1_HPP
#define CASA1_HPP

#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "PokemonPikachu.hpp"
#include "PokemonTipoGrama.hpp"

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>


class Casa1 : public Fase
{
public:
	Casa1(std::string name, const Sprite &bkg, PokemonPikachu *const pikachu) : Fase(name,bkg), pikachu(pikachu) {}
	virtual ~Casa1() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
private:
	PokemonPikachu *pikachu;
	ObjetoDeJogo *tapetePorta;
	ObjetoDeJogo *capaInvisivel;
	PokemonTipoGrama *tGrama;
	ObjetoDeJogo *quantPorcao;
	ObjetoDeJogo *vida[5];							

};

#endif // Casa1_HPP
