#include "imports.c"

#include "model.c"
#include "visual.c"
#include "controller.c"


int main(){
	
	// Variáveis necessárias para o funcionamento principal do programa.
	
	presets();
	int baralho[25][3];
	int mesa[25][3], descarte[25][3];
	int jogador1[5][2], jogador2[5][2];
	int revelado1[5][2], revelado2[5][2];
	int i, j, a, b, test = 1, auxMove = 0;
	int vidas, dicas;
	char nome[16], loadName[50];
	int jogada, cor, numero, dika, numeroDika, corDika, cartaDescarte, cartaDescer;
	int dicasMaquina[10][3];
	int maior[2], menor[2];
	bool repete, repete2;
	int opcaoInicio, primJogador, nj = 0;
	
	maior[0] = -99999;
	menor[0] =  99999;
	
	vidas = 3;
	dicas = 8;
	
	// Necessário para gerar uma variável aleatória diferente com o rand()
	srand(time(0));
	
	repete2 = true;
	
	while (repete2){
	
	opcaoInicio = menu1();
	
	system("pause");
	
	switch(opcaoInicio){
		
	case 2:
	case 1:
	// Gera o baralho, cria a mesa, geraDicasMaquina(nao ta pronta ainda)
	
	limpaTela();
	
	geraDicasMaquina(dicasMaquina);
	maior[0] = -99999;
	menor[0] =  99999;
		
	if(opcaoInicio == 1){
		// Começa novo jogo
		
		strcpy(nome, readName());
		
		system("pause");
		vidas = 3;
		dicas = 8;
		geraBaralho(baralho);
		criaMesa(mesa);
		criaDescarte(descarte);
		pegaCartas(jogador1, baralho, revelado1);
		pegaCartas(jogador2, baralho, revelado2);
	}
	else{
		if(opcaoInicio == 2){
			// Carrega jogo
			bool loopLoad;
			int contaLoad = 0;
			loopLoad = true;
			
			while(loopLoad){
				limpaTela();
				
				strcpy(loadName, menuLoad());
				strcpy(nome, loadName);
				
				if(!loadGame(baralho, mesa, jogador1, jogador2, revelado1, revelado2, &vidas, &dicas, nome, descarte)){
					printf("\nNão foi possível carregar o jogo!\n\n");
				}
				else{
					if(strcmp(nome, "sair") == 0){
						goto fimDoLoop;
					}
					else{
						printf("\nCarregando...\n\n");
						loopLoad = false;
					}
				}
				
				contaLoad++;
				system("pause");
				
			}
			
		}
	}
	
	
	nj = 0;
	
	// Primeiro jogador
	primJogador = rand()%2;
	
	// while(true){
	while(fimDeJogo(jogador1, jogador2, baralho, mesa, vidas) == false){
		auxMove = 0;
		limpaTela();
		
		if(primJogador == 0 && nj == 0){
			goto jogadaLabel;
		}
		if(primJogador == 1 && nj == 0){
			goto jogadaMaquinaLabel;
		}

		maior[0] = -99999;
		menor[0] =  99999;
	
		jogadaLabel:
		if(!podeJogar(jogador1)){
			goto jogadaMaquinaLabel;
		}
		
		
		limpaTela();
		geraDicasMaquina(dicasMaquina);
		showMaoOposta(jogador2);
		showMesa(mesa);
		showRevelado(revelado1, nome);
		showInfo(vidas, dicas);
		showPlay("Sua vez de jogar.", "Escolha com sabedoria ^^");
		showDescarte(descarte);
		showDeck(cartasDisp(baralho));
		
		jogada = menuJogada();

		// Se for para dar dica!
		if(jogada == 1){
			printf("\n\t Tipo de dica:\n\t 1- Número\n\t 2- Cor :\t ");
			scanf("%d", &dika);
			if(dika - 1 > 1 || dika - 1 < 0){
				printf("\n\t Dica inválida!\n\n");
				goto jogadaLabel;
			}
			else{
				if(dika - 1 == 0){
					printf("\n\t Selecione:\n\t 1- Nº 1\n\t 2- Nº 2\n\t 3- Nº 3\n\t 4- Nº 4\n\t 5- Nº 5 :\t ");
					scanf("%d", &numeroDika);
					if(numeroDika > 5 || numeroDika < 1){
						printf("\n\t Número de carta inválido!\n\n");
						goto jogadaLabel;
					}
					else{
						if(podeDica(jogador2, revelado2, dicas, 0, numeroDika)){
							dicas = darDica(jogador2, revelado2, dicas, 0, numeroDika);
						}
						else{
							printf("\t Nao é possível fornecer dicas!\n\n");
							goto jogadaLabel;
						}
					}
				}
				else{
					printf("\n\t Selecione:\n\t 1- Amarelas\n\t 2- Azúis\n\t 3- Brancas\n\t 4- Vermelhas\n\t 5- Verdes :\t ");
					scanf("%d", &corDika);
					if(corDika > 5 || corDika < 1){
						printf("\n\t Cor de carta inválido!\n\n");
						goto jogadaLabel;
					}
					else{
						//printf("%d",podeDica(jogador2, revelado2, dicas, 1, corDika));
						
						if(podeDica(jogador2, revelado2, dicas, 1, corDika)){
							dicas = darDica(jogador2, revelado2, dicas, 1, corDika);
						}
						else{
							printf("\t Nao é possível fornecer dicas!\n\n");
							goto jogadaLabel;
						}
					}
				}
			}
		}
		
		// Se for para descartar carta
		if(jogada == 2){
			printf("\n\t Insira o número da sua carta para descarte: ");
			scanf("%d", &cartaDescarte);
			if(cartaDescarte < 1 || cartaDescarte > 5){
				printf("\n\t Carta inválida!\n\n");
				goto jogadaLabel;
			}
			else{
				if(podeDescartar(jogador1, cartaDescarte)){
					dicas = descartaCarta(jogador1, cartaDescarte, revelado1, dicas, descarte);
					if(podeComprar(jogador1, baralho)){
						compraCarta(jogador1, baralho, revelado1);
					}
				}
				else{
					printf("\n\t Não é possível descartar esta carta!\n\n");
					goto jogadaLabel;
				}
			}
		}
		
		// Se for para descer carta
		if(jogada == 3){
			printf("\t Insira o número da sua carta para descer na mesa: ");
			scanf("%d", &cartaDescer);
			if(cartaDescer < 1 || cartaDescer > 5){
				printf("\n\t Carta inválida!\n\n");
				goto jogadaLabel;
			}
			else{
				if(podeDescartar(jogador1, cartaDescer)){
					vidas = desceCarta(jogador1, baralho, mesa, cartaDescer, vidas, revelado1);
					descartaCarta(jogador1, cartaDescer, revelado1, dicas, descarte);
					if(podeComprar(jogador1, baralho)){
						compraCarta(jogador1, baralho, revelado1);
					}
				}
				else{
					printf("\n\t Carta inválida!\n\n");
					goto jogadaLabel;
				}
			}
		}
		
		// Se for para salvar o jogo
		if(jogada == 4){
			saveGame(baralho, mesa, jogador1, jogador2, revelado1, revelado2, &vidas, &dicas, nome, descarte);
			limpaTela();
			printf("Jogo salvo!\n");
			system("PAUSE");
		}
		
		// Se for para sair do jogo
		if(jogada == 5){
			goto fimDoLoop;
		}
			
		
		
		if(fimDeJogo(jogador1, jogador2, baralho, mesa, vidas)){
			goto fimDoLoop;
		}
		
		jogadaMaquinaLabel:
			
		if(!podeJogar(jogador2)){
			goto nextMove;
		}

		limpaTela();
		showMaoOposta(jogador2);
		showMesa(mesa);
		showRevelado(revelado1, nome);
		showInfo(vidas, dicas);
		showDescarte(descarte);
		showDeck(cartasDisp(baralho));
		
		
		// Jogada da máquina - Deixa comigo essa parte, tá uma confusão muito grande kkk
		for(a = 0; a < 5; a++){
			// Se a carta existir no baralho
			if(revelado2[a][0] != -1 && revelado2[a][1] != -1 && revelado2[a][0] != 0 && revelado2[a][1] != 0){
				// Se puder descer a carta na mesa
				test = podeDescer(jogador2, baralho, mesa, a+1, test, revelado2);
				if(test == 1){
					// Desce a carta na mesa
					desceCarta(jogador2, baralho, mesa, a+1, vidas, revelado2);
					descartaCarta(jogador2, a+1, revelado2, dicas, descarte);
					if(podeComprar(jogador2, baralho)){
						compraCarta(jogador2, baralho, revelado2);
					}
					showPlay("Vez do BOT jogar.", "BOT desceu uma carta.");
					goto nextMove;
				}
				else{
					test = 1;
					for(i = 0; i < 25; i++){
						// Se a carta já existir na mesa, descarta ela
						if(mesa[i][2] > 0 && mesa[i][0] == revelado2[a][0] && mesa[i][1] == revelado2[a][1]){
							dicas = descartaCarta(jogador2, a+1, revelado2, dicas, descarte);
							if(podeComprar(jogador2, baralho)){
								compraCarta(jogador2, baralho, revelado2);
							}
							showPlay("Vez do BOT jogar.", "O BOT descartou uma carta.");
							auxMove = 1;
							goto nextMove;
						}
					}
				}
			}
			// Nao conhece a carta
			else{
				// Verifica se existe algum 1 em sua mão
				if(revelado2[a][0] == 1){
					// Verifica se nao existe nenhum 1 na mesa
					if(!temCarta(mesa, 0, 1)){
						desceCarta(jogador2, baralho, mesa, a+1, vidas, revelado2);
						descartaCarta(jogador2, a+1, revelado2, dicas, descarte);
						if(podeComprar(jogador2, baralho)){
							compraCarta(jogador2, baralho, revelado2);
						}
						showPlay("Vez do BOT jogar.", "BOT desceu uma carta.");
						goto nextMove;
					}
				}
				if(revelado2[a][0] != 0 || revelado2[a][1] != 0){
					// Lê os dados e passa para a matriz de análise de dicas
					if(dicas >= 0){
						if(revelado1[a][0] == -1){
							insertDicas(dicasMaquina, jogador1[a][0], 0);
						}
						if(revelado1[a][1] == -1){
							insertDicas(dicasMaquina, jogador1[a][1], 1);							
						}
						
					}
				}
				
			}
		}

			if(dicas > 1){
				for(i = 0; i < 10; i++){
					if(dicasMaquina[i][2] > maior[0]){
						maior[0] = dicasMaquina[i][2];
						maior[1] = i;
					}
				}
				
				if(jogadorTemIA(jogador1, revelado1, 0, 1)){
					if(podeDica(jogador1, revelado1, dicas, 0, 1)){
						dicas = darDica(jogador1, revelado1, dicas, 0, 1);
						showPlay("Vez do BOT jogar", "O BOT deu uma dica.");
					}
				}
				else{
					if(podeDica(jogador1, revelado1, dicas, dicasMaquina[maior[1]][1], dicasMaquina[maior[1]][0])){
						dicas = darDica(jogador1, revelado1, dicas, dicasMaquina[maior[1]][1], dicasMaquina[maior[1]][0]);
						showPlay("Vez do BOT jogar", "O BOT deu uma dica.");
					}
				}
				
				
				goto nextMove;
				
			}
			else{
				for(i = 0; i < 5; i++){
					if(podeDescartar(jogador2, i)){
						// printf("\n\n%d\n\n", dicas);
						dicas = descartaCarta(jogador2, i, revelado2, dicas, descarte);
						if(podeComprar(jogador2, baralho)){
							compraCarta(jogador2, baralho, revelado2);
						}
						showPlay("Vez do BOT jogar", "O BOT descartou uma carta");
						
						goto nextMove;
					}
				}
				
			}
		
		nextMove:
		nj++;
		
		gotoxy(20,30);
		system("pause");

		// FIM DO LOOP ABAIXO!
	}
	fimDoLoop:
	
	break;
		
	case 3:
		limpaTela();
		regras();
		printf("\n\n");
		system("pause");
		limpaTela();
		break;
		
	case 4:
		repete2 = false;
		exit(-1);
		break;
	} // Fim do switch
	} 

	
	system("PAUSE");	
	return 0;
}

