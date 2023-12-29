#include "FaseLevel1.hpp"
#include "Sound.hpp"

#include <iostream>

void FaseLevel1::init()
{	
	//Vila
	objs.push_back(new ObjetoDeJogo("Vila",Sprite("rsc/mapa2.txt"),0,0));
	
	tGrama = new PokemonTipoGrama(ObjetoDeJogo("tGrama",Sprite("rsc/personagem.txt"),40,160));
	objs.push_back(tGrama);
	
	lendario = new PokemonLendario(ObjetoDeJogo("tLendario",Sprite("rsc/personagem.txt"),108,18));
	objs.push_back(lendario);

	objs.push_back(pikachu);

	tapetePorta1 = new ObjetoDeJogo("Tapete1",SpriteBuffer(37,1),52,20);
	objs.push_back(tapetePorta1);

	tapetePorta2 = new ObjetoDeJogo("Tapete2",SpriteBuffer(37,1),52,340);
	objs.push_back(tapetePorta2);

	pacoteVida = new ObjetoDeJogo("Pacote Vida",Sprite("rsc/pacoteVida.txt"),94,200);
	objs.push_back(pacoteVida);

	mostraPacote = new ObjetoDeJogo("Mostra Pacote",Sprite("rsc/bolsaVida.txt"),94,200);
	objs.push_back(mostraPacote);
	mostraPacote->desativarObj();

	capaInvisivel1 = new ObjetoDeJogo("Capa invisivel 1",Sprite("rsc/capaInvisivel2.txt"),40,160);
	objs.push_back(capaInvisivel1);

	capaInvisivel2 = new ObjetoDeJogo("Capa invisivel 2",Sprite("rsc/capaInvisivel3.txt"),108,18);
	objs.push_back(capaInvisivel2);

	vida[0] = new ObjetoDeJogo("Vida 100%",Sprite("rsc/vida100.txt"),1,140);
	objs.push_back(vida[0]);
	vida[0]->desativarObj();

	vida[1] = new ObjetoDeJogo("Vida 80%",Sprite("rsc/vida80.txt"),1,140);
	objs.push_back(vida[1]);
	vida[1]->desativarObj();

	vida[2] = new ObjetoDeJogo("Vida 60%",Sprite("rsc/vida60.txt"),1,140);
	objs.push_back(vida[2]);
	vida[2]->desativarObj();

	vida[3] = new ObjetoDeJogo("Vida 40%",Sprite("rsc/vida40.txt"),1,140);
	objs.push_back(vida[3]);
	vida[3]->desativarObj();

	vida[4] = new ObjetoDeJogo("Vida 20%",Sprite("rsc/vida20.txt"),1,140);
	objs.push_back(vida[4]);
	vida[4]->desativarObj();
	
	quantPorcao = new ObjetoDeJogo("Quantidade da Porção",Sprite("rsc/1.txt"),2,274);
	objs.push_back(quantPorcao);
	quantPorcao->desativarObj();
}

unsigned FaseLevel1::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);

	Sound musica2("musica1.mp3");
	Sound batalha2("batalha.mp3");
	Sound ataqueInimigo2("ataqueInimigo.mp3");
	Sound ataquePersonagem2("ataquePersonagem.mp3");
	Sound oh1("ohh.mp3");
	musica2.playloop();

	while (true)
	{
		//lendo entrada
		getline(std::cin,ent);
		
		//processando entradas
		int posL = pikachu->getPosL(), posC = pikachu->getPosC();
		
		if (ent == "w" && pikachu->getPosL() > 14)
			pikachu->moveUp(8);
		else if (ent == "s" && pikachu->getPosL() < screen.getAltura() - 14)
			pikachu->moveDown(8);	
		else if (ent == "a" && pikachu->getPosC() > 18)
			pikachu->moveLeft(12);
		else if (ent == "d" && pikachu->getPosC() < screen.getLargura() - pikachu->getSprite()->getLargura() - 12)
			pikachu->moveRight(12);
		else if (ent == "x") {
			if (pikachu->colideCom(*tGrama)) {
				batalha2.playloop();
				ataquePersonagem2.play();
				tGrama->sofrerAtaque(pikachu->atacar());
				if (!tGrama->estaVivo()){
					tGrama->desativarObj();
					int cont;
					cont = pikachu->getQuantInimigos() + 1;
					pikachu->setQuantInimigos(cont);
					if (pikachu->getQuantInimigos() == 4){
						return LEVEL_COMPLETE;
					}
					oh1.play();
					ataqueInimigo2.stop();
					batalha2.unpause();
					musica2.unpause();
				}
			}
			else if (pikachu->colideCom(*lendario)) {
				batalha2.playloop();
				ataquePersonagem2.play();
				lendario->sofrerAtaque(pikachu->atacar());
				if (!lendario->estaVivo()){
					lendario->desativarObj();
					int cont;
					cont = pikachu->getQuantInimigos() + 1;
					pikachu->setQuantInimigos(cont);
					if (pikachu->getQuantInimigos() == 4){
						return LEVEL_COMPLETE;
					}
					oh1.play();
					ataqueInimigo2.stop();
					batalha2.unpause();
					musica2.unpause();
				}
			}
		}

		else if (ent == "r"){
			if (pikachu->colideCom(*mostraPacote)){
				int cont;
				cont = pikachu->getBolsaVida() + 1;
				pikachu->setBolsaVida(cont);
				mostraPacote->desativarObj();
				quantPorcao->ativarObj();
				pikachu->setUsouBolsa(1);
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

		else if (ent == "q")
			return Fase::END_GAME;

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

		if (pikachu->colideCom(*tGrama)) {
			ataqueInimigo2.playloop();
			pikachu->sofrerAtaque(tGrama->atacar());
			if (!pikachu->estaVivo())
				return GAME_OVER;
		}
		else if (pikachu->colideCom(*lendario)) {
			ataqueInimigo2.playloop();
			pikachu->sofrerAtaque(lendario->atacar());
			if (!pikachu->estaVivo())
				return GAME_OVER;
		}
		if (pikachu->colideCom(*pacoteVida)){
			pacoteVida->desativarObj();
			mostraPacote->ativarObj();
		}
		
		if (pikachu->colideCom(*capaInvisivel1)){
			musica2.pause();
			batalha2.playloop();
			capaInvisivel1->desativarObj();
			}
		
		if (pikachu->colideCom(*capaInvisivel2)){
			musica2.pause();
			batalha2.playloop();
			capaInvisivel2->desativarObj();
			}
			
		if (pikachu->colideCom(*tapetePorta1)) {
			quantPorcao->desativarObj();
			vida[0]->desativarObj();
			vida[1]->desativarObj();
			vida[2]->desativarObj();
			vida[3]->desativarObj();
			vida[4]->desativarObj();
			pikachu->moveTo(39,90);
			return CASA1;
		}
		if (pikachu->colideCom(*tapetePorta2)) {
			quantPorcao->desativarObj();
			vida[0]->desativarObj();
			vida[1]->desativarObj();
			vida[2]->desativarObj();
			vida[3]->desativarObj();
			vida[4]->desativarObj();
			pikachu->moveTo(46,250);
			return CASA2;
		}

		//padrão
		update();
		draw(screen);
		system("clear");
		show(screen);
	}

}
