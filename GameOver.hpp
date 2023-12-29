#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>

class GameOver : public Fase
{
public:
	GameOver(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	virtual ~GameOver() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

};

#endif // GameOver_HPP
