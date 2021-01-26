#include "imports.c"

#define PLAYER1HX 10 //posicao em largura das cartas
#define PLAYER1HY 2  //posicao em altura das cartas
#define PLAYER2HX 10
#define PLAYER2HY 21
#define HUDX 89
#define HUDY 13
#define TABLEX 10
#define TABLEY 11
#define DROPX 75
#define DROPY 2
#define BUYCARDX 89
#define BUYCARDY 21
#define PLAYX 120
#define PLAYY 2

#define CARDW 9
#define CARDH 6
#define HUDW 10
#define HUDH 3
#define TABLEW 9
#define TABLEH 7
#define BUYCARDW 9
#define BUYCARDH 6
#define PLAYW 6
#define PLAYH 33

#define GAP 3

// Limpa os elementos da tela
void limpaTela(){
	system("cls");
}


void regras(){
	
	printf("				REGRAS pt. 1\n\n");
	printf("É absolutamente proibido (embora para uma primeira vez a jogar seja fundamental\n");
	printf("quebrar algumas dessas regras para aprender melhor o jogo) que os jogadores falem ou\n");
	printf("comuniquem de qualquer outra forma (reações faciais, olhares, etc.) para além da altura\n");
	printf("em que dão as pistas uns aos outros e respeitando as regras das mesmas.\n\n\n");
	printf("Na sua vez de jogar um jogador deve fazer uma e só uma das seguintes ações: 1. Dar uma pista 2. Descartar uma carta 3. Jogar uma carta\n\n");
	printf("1. Dar uma pista:\n\n");
	printf("Só poderá usar esta ação se existirem fichas de pista disponíveis, ou seja com o desenho do papiro voltado para cima.\n");
	printf("Primeiro vira-se uma ficha de pista não usada ficando a face escura para cima, e de seguida escolhe-se um qualquer jogador\n"); 
	printf("para dar a pista. As únicas pistas que se podem dar são relativas ou à cor ou ao número das cartas desse jogador.\n"); 
	printf("As pistas permitidas são indicar a posição de:\n");
	printf("1- todas as cartas de uma cor;\n");
	printf("2- todas as cartas de um numero.\n");
	printf("Nunca se pode indicar simultaneamente a cor e o número de qualquer carta.\n\n");
	printf("2. Descartar uma carta:\n");
	printf("Esta ação adiciona-se uma pista às existentes virando uma das que foram usadas (com a face escura para cima).\n");
	printf("Esta ação não pode ser usada caso estejam disponíveis todas as pistas.\n");
	printf("O jogador anuncia que vai DESCARTAR uma carta e escolhe uma das suas cartas (sem nunca olhar para a frente das cartas da sua mão)\n");
	printf("E coloca-a no monte de cartas descartadas.\n");
	printf("As cartas do monte de descarte podem ser consultadas em qualquer altura por qualquer jogador.\n\n");
	printf("3. Jogar (para a mesa) uma carta:\n");
	printf("É ao jogar cartas para a mesa que se constrói o fogo-de-artifício.\n"); 
	printf("O jogador anuncia que vai JOGAR uma carta e escolhe a carta para jogar na mesa.\n");
	printf("Ocorre uma das duas situações seguintes:\n");
	system("PAUSE");
	limpaTela();
	printf("				REGRAS pt. 2\n\n");
	printf("- A carta PODE ser jogada corretamente na mesa, iniciando um fogo-de-artifício ou\n");
	printf("continuando um já existente.\n");
	printf("Ou seja, a carta inicia uma cor (é uma carta 1) ou é sequencial em relação à sua cor\n");
	printf("(por exemplo é um 3 verde e na mesa já existe um 2 verde).\n");
	printf("Caso a carta jogada seja um 5, completando uma cor, ganha-se uma pista. Se as 8 pistas\n");
	printf("já estiverem disponíveis esta benesse perde-se\n");
	printf("- A carta pode NÃO PODE ser jogada corretamente na mesa. Ou seja, não é sequencial no monte da sua cor.\n");
	printf("Por exemplo jogar um 1 verde, e na mesa já existir um 1 no monte das cartas verdes,\n");
	printf(" ou jogar um 4 azul e no monte azul não estar um 3 azul. Neste caso os\n");
	printf("deuses ficam furiosos e enviam um raio vindo do céu, resultando na perda de uma vida.\n");
	printf("Volta-se uma ficha de vida ao contrário exibindo agora um raio.\n");
	printf("As vidas não são recuperáveis.\n\n");
	printf("Depois de jogar o jogador completa a sua mão para 5 (ou 4) cartas retirando uma nova\n");
	printf("carta do monte de compra (se houver cartas disponíveis no baralho de compra),\n");
	printf("mas sem olhar para a frente da carta!\n\n");
	printf("FIM DO JOGO:\n\n");
	printf("O jogo termina se:\n\n\n");
	printf("- todos os montes de cor forem terminados. O espetáculo terminou e a pontuação é de 25 pontos.\n\n");
	printf("- a última carta do baralho de compra for removida, nesse caso todos os jogadores jogam uma última vez.\n"); 
	printf("A pontuação final corresponde ao total de cartas que conseguiram jogar na mesa.\n");
	printf(" - a terceira ficha de vida for virada. O jogo termina e a pontuação é de 0 pontos.\n");
	printf("Os deuses demonstram a sua ira na forma de uma tempestade que põe fim ao fogo-de-artifício.\n");
	
}



// Muda a cor do texto (descontinuada)
void mudaCor(char *cor){
	char str[30];
	strcpy(str, "COLOR 0");
	strcat(str, cor);
	system(str);
}

char *corChar(int cor){
	char res[20];
	
	switch(cor){
		case 0:
			strcpy(res, "-");
			break;
			
		case 1:
			strcpy(res, "Amarelo");
			break;
		
		case 2:
			strcpy(res, "Azul");
			break;
			
		case 3:
			strcpy(res, "Branco");
			break;
			
		case 4:
			strcpy(res, "Vermelho");
			break;
			
		case 5:
			strcpy(res, "Verde");
			break;
			
		default:
			strcpy(res, "XXXXXXXX");
			break;
	}
	
	return res;
	
}

// Função de debug (para testes). Apresenta o baralho sem formatação
void printBaralho(int matriz[25][3]){
	int i, j;
	
	for(i = 0; i < 25; i++){
		printf("Linha %d:	", i);
		for(j = 0; j < 3; j++){
			printf("  %d  ", matriz[i][j]);
		}
		
		printf("\n\n");
	}
}



// Função de debug (para testes). Apresenta as cartas que desceram na mesa
void printMesa(int matriz[25][3]){
	int i, j;
	
	for(i = 0; i < 25; i++){
		printf("Linha %d:	", i);
		for(j = 0; j < 3; j++){
			printf("  %d  ", matriz[i][j]);
		}
		
		printf("\n\n");
	}
}

void printCartasDescarte(int matriz[25][3]){
	int i;
	
	for(i = 0; i < 25; i++){
		printf("%d %s %d", matriz[i][0], corChar(matriz[i][1]), matriz[i][2]);
		printf("\n");
	}
	
}




// *Precisa ser alterada. Parte gráfica da mão do jogador adversario
void showMaoOposta(int matriz[5][2]){
	int i, j, cont = 0;
	
	gotoxy(33,1);
	printf("MÃO  DO BOT");
	
	for(i = 0; i < 5; i++){ 
		//printf("Carta %d:  %d %s\n", i + 1, matriz[i][0], corChar(matriz[i][1]));
		//showRectAt(PLAYER1HX+i*(CARDW+GAP),PLAYER1HY, CARDW, CARDH);
		showRectAt(PLAYER1HX+i*(CARDW+GAP), PLAYER1HY, CARDW, CARDH);
		
		gotoxy(11 + cont, 4);
		printf("%s", corChar(matriz[i][1]));
		gotoxy(14 + cont, 6);
		printf("%d", matriz[i][0]);
		
		cont += 12;
	
	}
	
	
}



void showDeck(int numero){
	
	showRectAt(BUYCARDX, BUYCARDY, BUYCARDW, BUYCARDH);
	
	gotoxy(BUYCARDX+3,BUYCARDY+1);
	printf("DECK");
	gotoxy(BUYCARDX+4,BUYCARDY+3);
	printf("%d", numero);
	
	gotoxy(1,33);
}



void showDescarte(int matriz[25][3]){
	int i, j, cont = 1, aux = 12, contador = 0;
	gotoxy(DROPX, DROPY);
	printf("DESCARTE\n");
	
	for(i=1; i<=5; i++){
		gotoxy(DROPX+9+contador, DROPY+1);
		printf("%d", i);
		contador = contador + 6;
	}
	
	contador=0;
	
	for(i=1; i<=5; i++){
		gotoxy(DROPX, DROPY+1+i);
		switch (i){
			case 1:
				setForeColor(14);
				break;
			case 2:
				setForeColor(9);
				break;
			case 3:
				setForeColor(15);
				break;
			case 4:
				setForeColor(12);
				break;
			case 5:
				setForeColor(10);
				break;
			
		}
		printf("%s", corChar(i));
		resetColor();
	}
	
	for(i = 0; i<5; i++){
		gotoxy(DROPX+9+contador, DROPY+2);
		printf("%d	",matriz[i][2]);
		contador = contador+6;
	}
	
	contador=0;
	
	for(i = 5; i<10; i++){
		gotoxy(DROPX+9+contador, DROPY+3);
		printf("%d	",matriz[i][2]);
		contador = contador+6;
	}
	
	contador=0;
	
	for(i = 10; i<15; i++){
		gotoxy(DROPX+9+contador, DROPY+4);
		printf("%d	",matriz[i][2]);
		contador = contador+6;
	}
	
	contador=0;
	
	for(i = 15; i<20; i++){
		gotoxy(DROPX+9+contador, DROPY+5);
		printf("%d	",matriz[i][2]);
		contador = contador+6;
	}
	
	contador=0;
	
	for(i = 20; i<25; i++){
		gotoxy(DROPX+9+contador, DROPY+6);
		printf("%d	",matriz[i][2]);
		contador = contador+6;
	}
	
	contador=0;
	
	gotoxy(1, 45);
}
// *Precisa ser alterada. Parte gráfica da mesa (cartas que os jogadores desceram na mesa)
void showMesa(int matriz[25][3]){
	int i, j, cont = 1, aux = 12;
	gotoxy(37,10);
	printf("MESA\n");
	
	gotoxy(11,12);
	setForeColor(14);
	printf("Amarelo");
	resetColor();
	
	gotoxy(24,12);
	setForeColor(9);
	printf("Azul");
	resetColor();
	
	gotoxy(36,12);
//	setForeColor(9);
	printf("Branco");
	//resetColor();
	
	gotoxy(47,12);
	setForeColor(12);
	printf("Vermelho");
	resetColor();
	
	gotoxy(61,12);
	setForeColor(10);
	printf("Verde");
	resetColor();
	
	gotoxy(14,13);
	printf("");
	for(i = 0; i < 25; i = i + 5){
		if(matriz[i][2] > 0)
		printf("%d", matriz[i][0]);
		
		gotoxy(14 + aux, 13);
		aux += 12;
		//printf("		");
	}
	
	aux = 12;
	
	gotoxy(14,14);
 	//printf("  ");
 	
	for(i = 1; i < 25; i = i + 5){
		if(matriz[i][2] > 0)
		printf("%d", matriz[i][0]);
		
		gotoxy(14 + aux, 14);
		aux += 12;
		//printf("		");
	}
	
	aux = 12;
	gotoxy(14,15);
	//printf("  ");
	
	for(i = 2; i < 25; i = i + 5){
		if(matriz[i][2] > 0)
		printf("%d", matriz[i][0]);
		
		gotoxy(14 + aux, 15);
		aux += 12;
		 //printf("		");
	}
	
	aux = 12;
	gotoxy(14,16);
//	printf("  ");
	
	for(i = 3; i < 25; i = i + 5){
		if(matriz[i][2] > 0)
		printf("%d", matriz[i][0]);
		
		gotoxy(14 + aux, 16);
		aux += 12;
		//printf("		");
	}
	
	aux = 12;
	gotoxy(14,17);
	//printf("  ");
	
	for(i = 4; i < 25; i = i + 5){
		if(matriz[i][2] > 0)
		printf("%d", matriz[i][0]);
		gotoxy(14 + aux, 17);
		aux += 12;
	    //printf("		");
	}
		
	printf("\n");
	for(i = 0; i < 5; i++){
		showRectAt(TABLEX+i*(TABLEW+GAP), TABLEY, TABLEW, TABLEH);
	}
	
	gotoxy(12,20);
	
	
	
}



// *Precisa ser alterada. Parte gráfica das vidas e dicas
void showInfo(int vidas, int dicas){
	//printf("\n	Vidas: %d				Dicas: %d\n\n", vidas, dicas);
	gotoxy(HUDX+1,HUDY+1);
	printf("Vidas: %d", vidas);
	
	gotoxy(HUDX+1,HUDY+2);
	printf("Dicas: %d",dicas);
	
	showRectAt(HUDX, HUDY, HUDW, HUDH);
	printf("\n");
	gotoxy(3,31);
}


void showPlay(char *vez, char *jogada){
	
	showRectAt(PLAYX, PLAYY, PLAYH, PLAYW);
	
	gotoxy(PLAYX+1, PLAYY+1);
	printf("%s", vez);
	gotoxy(PLAYX+1,PLAYY+2);
	printf("%s", jogada);

}



// Função de debug (para testes). Apresenta as cartas da mao do jogador
void printMao(int matriz[5][2]){
	int i, j;
	
	for(i = 0; i < 5; i++){
		printf("Linha %d:	", i);
		for(j = 0; j < 2; j++){
			printf("  %d  ", matriz[i][j]);
		}
		printf("\n\n");
	}
}



// Função de debug (para testes). Apresenta as cartas que o jogador já conhece de sua mao
void printRevelados(int matriz[5][2]){
	int i, j;
	
	for(i = 0; i < 5; i++){
		printf("Linha %d:	", i);
		for(j = 0; j < 2; j++){
			printf("  %d  ", matriz[i][j]);
		}
		printf("\n\n");
	}
}



// *Precisa ser alterada. Parte gráfica das cartas reveladas
void showRevelado(int matriz[5][2], char *nome){
	int i, j, cont = 0;
	char aux;
	gotoxy(34,20);
	printf("MÃO DE %s", strupr(nome));
	
	for(i = 0; i < 5; i++){ 
	 
		//printf("Carta %d:  %d %s\n", i + 1, matriz[i][0], corChar(matriz[i][1]));
		//showRectAt(PLAYER1HX+i*(CARDW+GAP),PLAYER1HY, CARDW, CARDH);
		
		if(matriz[i][0] == -1){
			aux = 'X';
		}
		else{
			if(matriz[i][0] == 0){
				aux = '-';
			}
			else{
				aux = matriz[i][0] + '0';
			}
			
		}
		
		gotoxy(11 + cont, 23);
		printf("%s", corChar(matriz[i][1]));
		gotoxy(14 + cont, 25);
		printf("%c", aux);
		
				cont += 12;
				
		showRectAt(PLAYER2HX+i*(CARDW+GAP), PLAYER2HY, CARDW, CARDH);
		
		//printf("Carta %d:  %c %s\n", i + 1, aux, corChar(matriz[i][1]));
	}
}


int menu1(){
	bool repete;
	int res;
	
	repete = true;
	
	
	while(repete){
		
		limpaTela();
		
		printf("\nBem-vindo(a) ao menu de HANABI, escolha uma ação:\n1- Novo jogo\n2- Carregar jogo\n3- Regras\n4- Sair\n");
		
		scanf("%d", &res);
		
		if(res > 0 && res < 5){
			repete = false;
		}
		else{
			printf("\nDigite uma opção válida!\n");
		}
		
	}
	
	return res;
	
}


int menuJogada(){
	bool repete;
	int res;
	
	repete = true;
	
	
	while(repete){
		
		printf("\t Escolha a sua jogada:\n\t 1- Dar dica\n\t 2- Descartar carta\n\t 3- Descer carta na mesa\n\t 4- Salvar o jogo\n\t 5- Sair do jogo\n\t ");
		
		scanf("%d", &res);
		
		if(res < 1 || res > 5){
			printf("\n\t Jogada inválida!\n\n");
			repete = true;
		}
		
		else{
			repete = false;
		}
		
	}
	
	return res;
	
}


char *menuLoad(){
	char retorno[50];
	bool loop;
	int cont = 0;
	loop = true;
	
	while(loop){
		printf("Escreva o nome do jogo salvo (digite 'sair' para voltar ao menu inicial): ");
		
		fflush(stdin);
		gets(retorno);
		
		
		if(strlen(retorno) != 0){
			loop = false;
		}
		
		cont++;
		
	}

	return retorno;
}


char *readName(){
	char retorno[16];
	bool loop;
	int cont = 0;
	loop = true;
	
	while(loop){
		if(cont > 0){
			printf("Por favor, insira um nome não nulo com até 16 caracteres: ");
			fflush(stdin);
			gets(retorno);
		}
		else{
			printf("Olá, bem-vindo(a) ao jogo Hanabi!\nInsira seu nome: ");
			fflush(stdin);
			gets(retorno);
		}
		if(strlen(retorno) > 0 && strlen(retorno) <= 16){
			loop = false;
		}
		else{
			printf("\nNome inválido!\n");
		}
		cont++;
	}
	
	return retorno;
	
}
