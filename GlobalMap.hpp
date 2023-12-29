#ifndef GLOBALMAP_HPP
#define GLOBALMAP_HPP

#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "PokemonPikachu.hpp"

#include "Casa1.hpp"
#include "Casa2.hpp"
#include "FaseLevel1.hpp"
#include "FaseComplete.hpp"
#include "GameOver.hpp"
#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>


class GlobalMap : public Fase
{
public:
	GlobalMap(std::string name, const Sprite &bkg, PokemonPikachu *const pikachu) : Fase(name,bkg), screen(screen), pikachu(pikachu){}
	virtual ~GlobalMap() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:
	SpriteBuffer screen;
	PokemonPikachu *pikachu;
	Fase* mapas[4];
};

#endif // GlobalMap_HPP
