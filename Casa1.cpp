#include "Casa1.hpp"
#include "Sound.hpp"
void Casa1::init()
{
	objs.push_back(new ObjetoDeJogo("Casa da Tia",Sprite("rsc/casaTia2.txt"),0,0));

	objs.push_back(pikachu);

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

	
	tGrama = new PokemonTipoGrama(ObjetoDeJogo("tGrama",Sprite("rsc/personagem.txt"),90,309));
	objs.push_back(tGrama);

	tapetePorta = new ObjetoDeJogo("Tapete",SpriteBuffer(35,1),37,75);
	objs.push_back(tapetePorta);

	capaInvisivel = new ObjetoDeJogo("Capa Invisivel",Sprite("rsc/capaInvisivel.txt"),90,309);
	objs.push_back(capaInvisivel);

	quantPorcao = new ObjetoDeJogo("Quantidade da Porção",Sprite("rsc/1.txt"),2,274);
	objs.push_back(quantPorcao);
	quantPorcao->desativarObj();
	

}
unsigned Casa1::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	Sound musica1("musica1.mp3");
	Sound oh("ohh.mp3");
	Sound batalha("batalha.mp3");
	Sound ataqueInimigo("ataqueInimigo.mp3");
	Sound ataquePersonagem("ataquePersonagem.mp3");
	musica1.playloop();

	while (true)
	{
		//lendo entrada
		getline(std::cin,ent);
		
		//processando entradas
		int posL = pikachu->getPosL(), posC = pikachu->getPosC();

		if (ent == "w" && pikachu->getPosL() > 38)
			pikachu->moveUp(8);
		else if (ent == "s" && pikachu->getPosL() < screen.getAltura() - 20)
			pikachu->moveDown(8);	
		else if (ent == "a" && pikachu->getPosC() > 74)
			pikachu->moveLeft(12);
		else if (ent == "d" && pikachu->getPosC() < screen.getLargura() - pikachu->getSprite()->getLargura() - 85)
			pikachu->moveRight(12);
		else if (ent == "x") {
			if (pikachu->colideCom(*tGrama)) {
				// musica1.pause();
				batalha.playloop();
				ataquePersonagem.play();
				tGrama->sofrerAtaque(pikachu->atacar());
				if (!tGrama->estaVivo()){
					tGrama->desativarObj();
					int cont;
					cont = pikachu->getQuantInimigos() + 1;
					pikachu->setQuantInimigos(cont);
					if (pikachu->getQuantInimigos() == 4){
						return LEVEL_COMPLETE;
					}
					oh.play();
					ataqueInimigo.stop();
					batalha.pause();
					musica1.unpause();

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

		if (pikachu->colideCom(*tGrama)) {
			ataqueInimigo.playloop();
			pikachu->sofrerAtaque(tGrama->atacar());
			if (!pikachu->estaVivo()){
				return GAME_OVER;
			}	
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

		if (pikachu->colideCom(*capaInvisivel)){
			musica1.pause();
			batalha.playloop();
			capaInvisivel->desativarObj();
			}

		if (pikachu->colideCom(*tapetePorta)) {
			quantPorcao->desativarObj();
			vida[0]->desativarObj();
			vida[1]->desativarObj();
			vida[2]->desativarObj();
			vida[3]->desativarObj();
			vida[4]->desativarObj();
			
			pikachu->moveTo(54,20);
			return FASE_LEVEL1;
		}
		// }
		else if (ent == "q")
			return Fase::END_GAME;

		//padrão
		update();
		draw(screen);
		system("clear");
		show(screen);
	}
	
	return Fase::END_GAME; // não necessário
}