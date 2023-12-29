#include "Casa2.hpp"
#include "Sound.hpp"

void Casa2::init()
{
	objs.push_back(new ObjetoDeJogo("Casa Misteriosa",Sprite("rsc/casa3.txt"),0,0));

	objs.push_back(pikachu);

	tapetePorta = new ObjetoDeJogo("Tapete",SpriteBuffer(37,1),44,250);
	objs.push_back(tapetePorta);

	tGrama2 = new PokemonTipoGrama(ObjetoDeJogo("tGrama2",Sprite("rsc/personagem.txt"),70,200));
	objs.push_back(tGrama2);

	capaInvisivel2 = new ObjetoDeJogo("Capa Invisivel",Sprite("rsc/capaInvisivel.txt"),70,200);
	objs.push_back(capaInvisivel2);

	vida[0] = new ObjetoDeJogo("Vida 100%",Sprite("rsc/vida100.txt"),2,140);
	objs.push_back(vida[0]);
	vida[0]->desativarObj();

	vida[1] = new ObjetoDeJogo("Vida 80%",Sprite("rsc/vida80.txt"),2,140);
	objs.push_back(vida[1]);
	vida[1]->desativarObj();

	vida[2] = new ObjetoDeJogo("Vida 60%",Sprite("rsc/vida60.txt"),2,140);
	objs.push_back(vida[2]);
	vida[2]->desativarObj();

	vida[3] = new ObjetoDeJogo("Vida 40%",Sprite("rsc/vida40.txt"),2,140);
	objs.push_back(vida[3]);
	vida[3]->desativarObj();

	vida[4] = new ObjetoDeJogo("Vida 20%",Sprite("rsc/vida20.txt"),2,140);
	objs.push_back(vida[4]);
	vida[4]->desativarObj();

	quantPorcao = new ObjetoDeJogo("Quantidade da Porção",Sprite("rsc/1.txt"),3,274);
	objs.push_back(quantPorcao);
	quantPorcao->desativarObj();
}
unsigned Casa2::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	Sound musica3("musica1.mp3");
	Sound oh2("ohh.mp3");
	Sound batalha3("batalha.mp3");
	Sound ataqueInimigo3("ataqueInimigo.mp3");
	Sound ataquePersonagem3("ataquePersonagem.mp3");
	musica3.playloop();
	
	while (true)
	{
		//lendo entrada
		getline(std::cin,ent);
		
		//processando entradas
		int posL = pikachu->getPosL(), posC = pikachu->getPosC();
		
		if (ent == "w" && pikachu->getPosL() > 40)
			pikachu->moveUp(8);
		else if (ent == "s" && pikachu->getPosL() < screen.getAltura() - 22)
			pikachu->moveDown(8);	
		else if (ent == "a" && pikachu->getPosC() > 50)
			pikachu->moveLeft(12);
		else if (ent == "d" && pikachu->getPosC() < screen.getLargura() - pikachu->getSprite()->getLargura() - 74)
			pikachu->moveRight(12);
		else if (ent == "x"){
			if (pikachu->colideCom(*tGrama2)) {
				batalha3.playloop();
				ataquePersonagem3.play();
				tGrama2->sofrerAtaque(pikachu->atacar());
				if (!tGrama2->estaVivo()){
					tGrama2->desativarObj();
					int cont;
					cont = pikachu->getQuantInimigos() + 1;
					pikachu->setQuantInimigos(cont);
					if (pikachu->getQuantInimigos() == 4){
						return LEVEL_COMPLETE;
					}
					oh2.play();
					ataqueInimigo3.stop();
					batalha3.pause();
					musica3.unpause();
				}
			}
		}

		else if (ent == "u"){
			if (pikachu->getBolsaVida() != 0){
				pikachu->setUsouBolsa(1);
				pikachu->setVida(100);
				pikachu->setBolsaVida(0);
				quantPorcao->desativarObj();
				vida[1]->desativarObj();
				vida[2]->desativarObj();
				vida[3]->desativarObj();
				vida[4]->desativarObj();
				vida[0]->ativarObj();
			}
		}
		if (pikachu->getBolsaVida() != 0 && pikachu->getUsouBolsa() != 0){
			quantPorcao->ativarObj();
		}
		if (pikachu->getVida() == 100){
			vida[1]->desativarObj();
			vida[2]->desativarObj();
			vida[3]->desativarObj();
			vida[4]->desativarObj();
			vida[0]->ativarObj();
		}
		if (pikachu->getVida() < 100 && pikachu->getVida() >= 80){
			vida[0]->desativarObj();
			vida[2]->desativarObj();
			vida[3]->desativarObj();
			vida[4]->desativarObj();
			vida[1]->ativarObj();
		}
		else if (pikachu->getVida() < 80 && pikachu->getVida() >= 60){
			vida[0]->desativarObj();
			vida[1]->desativarObj();
			vida[3]->desativarObj();
			vida[4]->desativarObj();
			vida[2]->ativarObj();
		}

		else if (pikachu->getVida() < 60 && pikachu->getVida() >= 40){
			vida[0]->desativarObj();
			vida[1]->desativarObj();
			vida[2]->desativarObj();
			vida[4]->desativarObj();
			vida[3]->ativarObj();
		}

		else if (pikachu->getVida() < 40){
			vida[0]->desativarObj();
			vida[1]->desativarObj();
			vida[2]->desativarObj();
			vida[3]->desativarObj();
			vida[4]->ativarObj();
		}

		if (pikachu->colideCom(*tapetePorta)) {
			quantPorcao->desativarObj();
			vida[0]->desativarObj();
			vida[1]->desativarObj();
			vida[2]->desativarObj();
			vida[3]->desativarObj();
			vida[4]->desativarObj();
			pikachu->moveTo(54,330);
			return FASE_LEVEL1;
		}
		
		if (pikachu->colideCom(*tGrama2)) {
			ataqueInimigo3.playloop();
			pikachu->sofrerAtaque(tGrama2->atacar());
			if (!pikachu->estaVivo())
				return GAME_OVER;
		}
		if (pikachu->colideCom(*capaInvisivel2)){
			musica3.pause();
			batalha3.playloop();
			capaInvisivel2->desativarObj();
			}
		else if (ent == "q")
			return END_GAME;		
		
		//padrão
		update();
		draw(screen);
		system("clear");
		show(screen);
	}
	
	return Fase::END_GAME; // não necessário
}