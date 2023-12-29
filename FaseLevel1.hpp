#ifndef FASELEVEL1_HPP
#define FASELEVEL1_HPP

#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Sound.hpp"

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>

#include "PokemonTipoGrama.hpp"
#include "PokemonTipoAgua.hpp"
#include "PokemonLendario.hpp"
#include "PokemonPikachu.hpp"


class FaseLevel1 : public Fase
{
public:
	FaseLevel1(std::string name, const Sprite &bkg, PokemonPikachu *const pikachu) : Fase(name,bkg), pikachu(pikachu){}
	virtual ~FaseLevel1() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

	
	
private:
	PokemonTipoGrama *tGrama;
	PokemonLendario *lendario;
	PokemonPikachu *pikachu;
	ObjetoDeJogo *tapetePorta1;
	ObjetoDeJogo *tapetePorta2;
	ObjetoDeJogo *capaInvisivel1;
	ObjetoDeJogo *capaInvisivel2;
	ObjetoDeJogo *pacoteVida;
	ObjetoDeJogo *mostraPacote;
	ObjetoDeJogo *quantPorcao;
	ObjetoDeJogo *vida[5];
};

#endif // FASELEVEL1_HPP
