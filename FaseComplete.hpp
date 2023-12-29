#ifndef FASECOMPLETE_HPP
#define FASECOMPLETE_HPP

#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>


class FaseComplete : public Fase
{
public:
	FaseComplete(std::string name, const Sprite &bkg) : Fase(name,bkg){}
	virtual ~FaseComplete() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);					

};

#endif // Casa1_HPP
