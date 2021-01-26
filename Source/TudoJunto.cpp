#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <locale.h>
#include <conio.h>
#include "lab.h"



// Gera as cartas do baralho em ordem sequencial
void geraBaralho(int matriz[25][3]){
	int i, cont, cor;
	
	cont = 1;
	cor = 1;
	
	for(i = 0; i < 25; i++){
		if(cont <= 5){
			matriz[i][0] = cont;
			matriz[i][1] = cor;
		}
		else{
			cor = cor + 1;
			cont = 1;
			
			matriz[i][1] = cor;
			matriz[i][0] = cont;
		}
		
		
		if(matriz[i][0] == 1){
			matriz[i][2] = 3;
		}
		else{
			if(matriz[i][0] == 5){
				matriz[i][2] = 1;
			}
			else{
				matriz[i][2] = 2;
			}
		}
		
		cont++;
	}
	    
}



// Gera dicas da máquina (nao tá 100% ainda)
void geraDicasMaquina(int matriz[10][3]){
	int i;
	for(i = 0; i < 5; i++){
		matriz[i][0] = i;
		matriz[i][1] = 0;
		matriz[i][2] = 0;
	}
	for(i = 5; i < 10; i++){
		matriz[i][0] = i - 4;
		matriz[i][1] = 1;
		matriz[i][2] = 0;
	}
}


	
// Cria a matriz com as cartas que os jogadores desceram na mesa
void criaMesa(int matriz[25][3]){
	int i, cont, cor;
	
	cont = 1;
	cor = 1;
	
	for(i = 0; i < 25; i++){
		if(cont <= 5){
			matriz[i][0] = cont;
			matriz[i][1] = cor;
		}
		else{
			cor = cor + 1;
			cont = 1;
			
			matriz[i][1] = cor;
			matriz[i][0] = cont;
		}
		
		// FUUUUUUUUUUUU
		matriz[i][2] = 0;
		// matriz[i][2] = 1;
		
		cont++;
	}
}



void criaDescarte(int matriz[25][3]){
	int i, cont, cor;
	
	cont = 1;
	cor = 1;
	
	for(i = 0; i < 25; i++){
		if(cont <= 5){
			matriz[i][0] = cont;
			matriz[i][1] = cor;
		}
		else{
			cor = cor + 1;
			cont = 1;
			
			matriz[i][1] = cor;
			matriz[i][0] = cont;
		}
		
		matriz[i][2] = 0;
		
		cont++;
	}
	
}



		
	

void insertDicas(int dicasMaquina[10][3], int valor, int posicao){
	int i;
	if(posicao == 0){
		for(i = 0; i < 5; i++){
			if(dicasMaquina[i][posicao] == valor){
				dicasMaquina[i][2] += 1;
			}
		}
	}
	if(posicao == 1){
		for(i = 5; i < 10; i++){
			if(dicasMaquina[i][posicao] == valor){
				dicasMaquina[i][2] += 1;
			}
		}
	}
	
}


// Define a cor das letras e do fundo do CMD. Também define o idioma padrão: Portugues
void presets(){
	setlocale(LC_ALL, "Portuguese");
	system("COLOR 07");
}


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

// Embaralha um vetor, precisa dos parametros (*vetor, tamanho dele)
void shuffle(int *array, size_t n){
	if (n > 1){
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

// Faz a jogada de descarte de cartas
int descartaCarta(int matriz1[5][2], int carta, int matriz2[5][2], int dicas, int matriz3[25][3]){
	int res, i;
	
	res = dicas + 1;
	
	for(i = 0; i < 25; i++){
		if(matriz3[i][0] == matriz1[carta - 1][0] && matriz3[i][1] == matriz1[carta - 1][1]){
			matriz3[i][0] = matriz1[carta - 1][0];
			matriz3[i][1] = matriz1[carta - 1][1];
			matriz3[i][2] += 1;
			i = 25;
		}
	}
	
	matriz1[carta - 1][0] = 0;
	matriz1[carta - 1][1] = 0;
	matriz2[carta - 1][0] = 0;
	matriz2[carta - 1][1] = 0;
	
	
	
	return res;
}


// Verifica se o jogador pode ou não descartar a carta (bool é um tipo de variável que indica se é true ou false
bool podeDescartar(int matriz[5][2], int carta){
	bool res;
	
	res = true;
	
	if(matriz[carta - 1][0] == 0){
		res = false;
	}
	else{
		res = true;
	}
	
	return res;
	
}

int cartasDisp(int matriz[25][3]){
	int disp = 50, i;
	
	for(i = 0; i < 25; i++){
		if(matriz[i][0] == 1){
			disp = disp - 3 + matriz[i][2];
		}
		if(matriz[i][0] == 5){
			disp = disp - 1 + matriz[i][2];
		}
		if(matriz[i][0] == 2 || matriz[i][0] == 3 || matriz[i][0] == 4){
			disp = disp - 2 + matriz[i][2];
		}
		
	}
	
	if(disp > 40){
		//disp = 40;
	}
	
	return disp;
}



bool podeJogar(int matriz1[5][2]){
	bool res;
	int i, disponiveis = 0;
	
	for(i = 0; i < 5; i++){
		if(matriz1[i][0] > 0){
			disponiveis += 1;
		}
	}
	
	if(disponiveis > 0){
		res = true;
	}
	else{
		res = false;
	}
	
	return res;
	
}



// Verifica se pode descer uma carta na mesa.
int podeDescer(int matriz1[5][2], int matriz2[25][3], int matriz3[25][3], int carta, int vidas, int matriz4[5][2]){
	int i, posicao, lives;
	
	lives = vidas;
	
	bool possui;
	
	possui = true;
	
	for(i = 0; i < 25; i++){
		if(matriz3[i][0] == matriz1[carta - 1][0] && matriz3[i][1] == matriz1[carta - 1][1] && matriz3[i][2] == 0){
			possui = false;
			posicao = i;
		}
	}
	
	if(possui){
		// Perde vida
		lives -= 1;
	}
	else{
		if((matriz1[carta - 1][0] == matriz3[posicao - 1][0] + 1  && matriz3[posicao][2] == 0 && matriz3[posicao - 1][2] != 0) || matriz1[carta - 1][0] == 1){
			
		}
		else{
			lives -= 1;
		}
	}
	
	return lives;
	
}


int desceCarta(int matriz1[5][2], int matriz2[25][3], int matriz3[25][3], int carta, int vidas, int matriz4[5][2]){
	int i, posicao, lives;
	
	lives = vidas;
	
	bool possui;
	
	possui = true;
	
	for(i = 0; i < 25; i++){
		if(matriz3[i][0] == matriz1[carta - 1][0] && matriz3[i][1] == matriz1[carta - 1][1] && matriz3[i][2] == 0){
			possui = false;
			posicao = i;
		}
	}
	
	for(i = 0; i < 25; i++){
		if(matriz2[i][0] == matriz1[carta - 1][0] && matriz2[i][1] == matriz1[carta - 1][1]){
			// matriz2[i][2] -= 1;
		}
	}
	
	if(possui){
		// Perde vida
		lives -= 1;
	}
	else{
		if((matriz1[carta - 1][0] == matriz3[posicao - 1][0] + 1 && matriz3[posicao][2] == 0 && matriz3[posicao - 1][2] != 0) || matriz1[carta - 1][0] == 1){
			matriz1[carta - 1][0] = 0;
			matriz1[carta - 1][1] = 0;
			matriz4[carta - 1][0] = 0;
			matriz4[carta - 1][1] = 0;
			// printf("\nPosicao: %d\n",posicao);
			matriz3[posicao][2] = 1;
		}
		else{
			lives -= 1;
		}
	}
	
	return lives;
	
}


// Verifica se o jogador pode ou não comprar uma carta
bool podeComprar(int matriz1[5][2], int matriz2[25][3]){
	int i, aComprar = 0, disponiveis = 0;
	bool res;
	
	res = true;
	
	for(i = 0; i < 5; i++){
		if(matriz1[i][0] == 0){
			aComprar++;
		}
	}
	
	for(i = 0; i < 25; i++){
		if(matriz2[i][2] > 0){
			disponiveis++;
		}
	}
	
	if(aComprar > 0 && disponiveis > 0){
		res = true;
	}
	else{
		res = false;
	}
	
	return res;
	
}


// O jogador compra uma carta
void compraCarta(int matriz1[5][2], int matriz2[25][3], int matriz3[5][2]){
	int i, cont = 0, posicao = -1;
	int arr[25];
	bool repeat = true;
	
	for(i = 0; i < 5; i++){
		if(matriz1[i][0] == 0){
			posicao = i;
		}
	}
	
	for(i = 0; i < 25; i++){
		arr[i] = i;
	}
	
	shuffle(arr, 25);
		
	while(repeat){
		if(posicao != -1){
			if(matriz2[arr[cont]][2] > 0){
				// printf("%d: %d %d", arr[cont], matriz2[arr[cont]][0], matriz2[arr[cont]][1]);
				matriz1[posicao][0] = matriz2[arr[cont]][0];
				matriz1[posicao][1] = matriz2[arr[cont]][1];
				
				matriz3[posicao][0] = -1;
				matriz3[posicao][1] = -1;
				
				matriz2[arr[cont]][2] -= 1;
				repeat = false;
			}
			cont++;
		}
		else{
			repeat = false;
		}
	}
}



// Pega as 5 cartas que o jogador precisa no baralho e atribui à sua mão.
void pegaCartas(int matriz1[5][2], int matriz2[25][3], int matriz3[5][2]){
	int i, j;
	int arr[25];
	for(i = 0; i < 25; i++){
		arr[i] = i;
	}
	
	shuffle(arr, 25);
	
	for(i = 0; i < 5; i++){
		if(matriz2[arr[i]][2] > 0){
			matriz1[i][0] = matriz2[arr[i]][0]; // Numero
			matriz1[i][1] = matriz2[arr[i]][1]; // Cor
			matriz2[arr[i]][2] -= 1;			// Qtde
		}
		else{
			if(arr[i] + 6 <= 24){
				matriz1[i][0] = matriz2[arr[i] + 6][2]; // Numero
				matriz1[i][1] = matriz2[arr[i] + 6][1]; // Cor
				matriz2[arr[i] + 6][2] -= 1;			// Qtde
			}
			else{
				matriz1[i][0] = matriz2[24 - arr[i]][2]; // Numero
				matriz1[i][1] = matriz2[24 - arr[i]][1]; // Cor
				matriz2[24 - arr[i]][2] -= 1;			// Qtde
			}
		}
	}
	
	for(i = 0; i < 5; i++){
		for(j = 0; j < 3; j++){
			matriz3[i][j] = -1;
		}
	}

}



// Dá uma dica
int darDica(int matriz1[5][2], int matriz2[5][2], int numero, int tipoDica, int dica){
	int disponiveis, i;
	
	disponiveis = numero;
	
	if(tipoDica == 0){
		for(i = 0; i < 5; i++){
			if(matriz1[i][0] == dica){
				matriz2[i][0] = matriz1[i][0];
			}
		}
	}
	else{
		for(i = 0; i < 5; i++){
			if(matriz1[i][1] == dica){
				matriz2[i][1] = matriz1[i][1];
			}
		}
	}
	
	disponiveis -= 1;
	
	return disponiveis;
}



// Verifica se pode ou nao dar uma dica
bool podeDica(int matriz1[5][2], int matriz2[5][2], int numero, int tipoDica, int dica){
	int i, cont = 0;
	bool res;
	
	res = true;
		
	if(tipoDica != 0 && tipoDica != 1){
		res = false;
	}
	
	if(dica > 5 || dica < 1){
		res = false;
	}
	
	for(i = 0; i < 5; i++){
		if(matriz1[5][2] != 0){
			cont++;
		}
	}
	
	if(cont == 0){
		res = false;
	}
	
	if(numero <= 0){
		res = false;
	}
	
	return res;
}


bool temCarta(int matriz1[25][3], int tipo, int numero){
	bool res;
	int i, quant = 0;
	
	
	for(i = 0; i < 25; i++){
		if(matriz1[i][tipo] == numero && matriz1[i][2] > 0){
			quant++;
		}
	}
	
	if(quant > 0){
		res = true;
	}
	else{
		res = false;
	}
	
	return res;
	
}



bool jogadorTemIA(int jogador[5][2], int revelado[5][2], int tipo, int numero){
	bool res;
	int i, quant = 0;
	
	
	for(i = 0; i < 5; i++){
		if(jogador[i][tipo] == numero && revelado[i][tipo] == -1){
			quant++;
		}
	}
	
	if(quant > 0){
		res = true;
	}
	else{
		res = false;
	}
	
	return res;
	
}



char *resultado(int matriz1[25][3]){
	int i;
	int cores[5] = {0, 0, 0, 0, 0};
	int cont = 0, cor = 0;
	char hanabis[80] = "", res[140];
	
	for(i = 0; i < 25; i++){
		if(cont == 5){
			cont = 0;
			cor += 1;
		}
		
		if(matriz1[i][2] > 0){
			cores[cor] += 1;
		}

		cont++;
		
	}
	
	cont = 0;
	strcat(hanabis, " | ");
	
	for(i = 0; i < 5; i++){
		if(cores[i] >= 5){
			strcat(hanabis, corChar(i+1));
			strcat(hanabis, " | ");
			cont++;
		}
	}
	
	if(cont == 0){
		strcpy(hanabis, " Nenhuma");
	}
	
	strcpy(res, "Você completou as fileiras: ");
	strcpy(res, hanabis);
	
	return res;
}


bool fimDeJogo(int matriz1[5][2], int matriz2[5][2], int matriz3[25][3], int matriz4[25][3], int vidas){
	bool res;
	int i, mesa = 0, baralho = 0, disponiveis1 = 0, disponiveis2 = 0;
	
	res = false;
	
	for(i = 0; i < 25; i++){
		if(matriz4[i][2] == 1){
			mesa += 1;
		}
		if(matriz3[i][2] > 0){
			baralho += 1;
		}
	}
	
	for(i = 0; i < 5; i++){
		if(matriz1[i][0] > 0){
			disponiveis1 += 1;
		}
		if(matriz2[i][0] > 0){
			disponiveis2 += 1;
		}
	}
	
	if(mesa == 25){
		res = true;
		printf("\n\nParabéns, você concluiu o jogo!\n\n");
		printf("Resultados:\n%s\n\n", resultado(matriz4));
		system("pause");
	}
	else{
		if(disponiveis1 == 0 && disponiveis2 == 0 && baralho == 0){
			res = true;
			printf("\n\nAcabaram-se as cartas. Fim de jogo!\n\n");
			printf("Resultados:\n%s\n\n", resultado(matriz4));
			system("pause");
		}
		else{
			if(vidas <= 0){
				res = true;
				printf("\n\nAcabaram-se as vidas. Fim de jogo!\n\n");
				printf("Resultados:\n%s\n\n", resultado(matriz4));
				system("pause");
			}
			else{
				if(!podeJogar(matriz1)){
					res = true;
					printf("\n\nAcabaram-se suas jogadas. Fim de jogo!\n\n");
					printf("Resultados:\n%s\n\n", resultado(matriz4));
					system("pause");
				}
				else{
					res = false;
				}
			}
		}
	}

	// fimDeGame:
	
	return res;
}


bool loadGame (int baralho[25][3], int mesa[25][3], int jogador1[5][2], int jogador2[5][2], int revelado1[5][2], int revelado2[5][2], int *vidas, int *dicas, char nome[16], int descarte[25][3]){

	
	FILE *arq, *arq2, *arq3, *arq4, *arq5, *arq6, *arq7, *arq8;	
	int i, check, aux1, aux2;
	bool retorno;
	retorno = false;
	
	char caminho[120], caminhoMatriz1[140], caminhoMatriz2[140], caminhoMatriz3[140], caminhoMatriz4[140], caminhoMatriz5[140], caminhoMatriz6[140], caminhoMatriz7[140], caminhoMatriz8[140];
	
	// Pega o caminho da pasta
	strcpy(caminho, "saves/");
	strcat(caminho, nome);
	
	// Verifica se existe pasta
	check = mkdir(caminho);

	if (!check){
		retorno = false;
	}
    else{
    	
		retorno = true;
	    // Adiciona "/" ao caminho
		strcat(caminho, "/");
		
		// Pega o caminho da matriz1.db, matriz2.db, etc...
		strcpy(caminhoMatriz1, caminho);
		strcat(caminhoMatriz1, "baralho.db");
		
		strcpy(caminhoMatriz2, caminho);
		strcat(caminhoMatriz2, "mesa.db");
		
		strcpy(caminhoMatriz3, caminho);
		strcat(caminhoMatriz3, "jogador1.db");
		
		strcpy(caminhoMatriz4, caminho);
		strcat(caminhoMatriz4, "jogador2.db");
		
		strcpy(caminhoMatriz5, caminho);
		strcat(caminhoMatriz5, "revelado1.db");
		
		strcpy(caminhoMatriz6, caminho);
		strcat(caminhoMatriz6, "revelado2.db");
		
		strcpy(caminhoMatriz7, caminho);
		strcat(caminhoMatriz7, "info.db");
		
		strcpy(caminhoMatriz8, caminho);
		strcat(caminhoMatriz8, "descarte.db");
		
		arq = fopen(caminhoMatriz1, "r");
		arq2 = fopen(caminhoMatriz2, "r");
		arq3 = fopen(caminhoMatriz3, "r");
		arq4 = fopen(caminhoMatriz4, "r");
		arq5 = fopen(caminhoMatriz5, "r");
		arq6 = fopen(caminhoMatriz6, "r");
		arq7 = fopen(caminhoMatriz7, "r");
		arq8 = fopen(caminhoMatriz8, "r");
		
	
		for(i = 0; i < 25; i++){
			fscanf(arq, "%d %d %d\n", &baralho[i][0], &baralho[i][1], &baralho[i][2]);
		}
		for(i = 0; i < 25; i++){
			fscanf(arq2, "%d %d %d\n", &mesa[i][0], &mesa[i][1], &mesa[i][2]);
		}
		for(i = 0; i < 25; i++){
			fscanf(arq8, "%d %d %d\n", &descarte[i][0], &descarte[i][1], &descarte[i][2]);
		}
	
		for(i = 0; i < 5; i++){
			fscanf(arq3, "%d %d %d\n", &jogador1[i][0], &jogador1[i][1], &jogador1[i][2]);
		}
		for(i = 0; i < 5; i++){
			fscanf(arq4, "%d %d %d\n", &jogador2[i][0], &jogador2[i][1], &jogador2[i][2]);
		}
		
		for(i = 0; i < 5; i++){
			fscanf(arq5, "%d %d %d\n", &revelado1[i][0], &revelado1[i][1], &revelado1[i][2]);
		}
		for(i = 0; i < 5; i++){
			fscanf(arq6, "%d %d %d\n", &revelado2[i][0], &revelado2[i][1], &revelado2[i][2]);
		}
		
		fscanf(arq7, "%d %d\n", &aux1, &aux2);
		
		(*vidas) = aux1;
		(*dicas) = aux2;

		
		// Fecha o arquivo da matriz 1
		fclose(arq);
		fclose(arq2);
		fclose(arq3);
		fclose(arq4);
		fclose(arq5);
		fclose(arq6);	
		fclose(arq7);
		fclose(arq8);
		}
		
		
	return retorno;
	
}

void saveGame(int baralho[25][3], int mesa[25][3], int jogador1[5][2], int jogador2[5][2], int revelado1[5][2], int revelado2[5][2], int *vidas, int *dicas, char nome[16], int descarte[25][3]){

	
	FILE *arq, *arq2, *arq3, *arq4, *arq5, *arq6, *arq7, *arq8;	
	int i, check;
	char caminho[120], caminhoMatriz1[140], caminhoMatriz2[140], caminhoMatriz3[140], caminhoMatriz4[140], caminhoMatriz5[140], caminhoMatriz6[140], caminhoMatriz7[140], caminhoMatriz8[140];
	
	bool retorno;
	
	// Pega o caminho da pasta
	strcpy(caminho, "saves/");
	strcat(caminho, nome);
	
	// Verifica se existe pasta
	check = mkdir(caminho);
	
	// Condicional para testes!
	/*if (!check){
		printf("Directory created\n"); 
	}
    else{ 
        printf("Unable to create directory\n"); 
        exit(1); 
    }*/
    
    // Adiciona "/" ao caminho
	strcat(caminho, "/");
	
	// Pega o caminho da matriz1.db, matriz2.db, etc...
	strcpy(caminhoMatriz1, caminho);
	strcat(caminhoMatriz1, "baralho.db");
	
	strcpy(caminhoMatriz2, caminho);
	strcat(caminhoMatriz2, "mesa.db");
	
	strcpy(caminhoMatriz3, caminho);
	strcat(caminhoMatriz3, "jogador1.db");
	
	strcpy(caminhoMatriz4, caminho);
	strcat(caminhoMatriz4, "jogador2.db");
	
	strcpy(caminhoMatriz5, caminho);
	strcat(caminhoMatriz5, "revelado1.db");
	
	strcpy(caminhoMatriz6, caminho);
	strcat(caminhoMatriz6, "revelado2.db");
	
	strcpy(caminhoMatriz7, caminho);
	strcat(caminhoMatriz7, "info.db");
	
	strcpy(caminhoMatriz8, caminho);
	strcat(caminhoMatriz8, "descarte.db");
	
	arq = fopen(caminhoMatriz1, "w");
	arq2 = fopen(caminhoMatriz2, "w");
	arq3 = fopen(caminhoMatriz3, "w");
	arq4 = fopen(caminhoMatriz4, "w");
	arq5 = fopen(caminhoMatriz5, "w");
	arq6 = fopen(caminhoMatriz6, "w");
	arq7 = fopen(caminhoMatriz7, "w");
	arq8 = fopen(caminhoMatriz8, "w");
	
	for(i = 0; i < 25; i++){
		fprintf(arq, "%d %d %d\n", baralho[i][0], baralho[i][1], baralho[i][2]);
	}
	for(i = 0; i < 25; i++){
		fprintf(arq2, "%d %d %d\n", mesa[i][0], mesa[i][1], mesa[i][2]);
	}
	for(i = 0; i < 25; i++){
		fprintf(arq8, "%d %d %d\n", descarte[i][0], descarte[i][1], descarte[i][2]);
	}

	for(i = 0; i < 5; i++){
		fprintf(arq3, "%d %d %d\n", jogador1[i][0], jogador1[i][1], jogador1[i][2]);
	}
	for(i = 0; i < 5; i++){
		fprintf(arq4, "%d %d %d\n", jogador2[i][0], jogador2[i][1], jogador2[i][2]);
	}
	
	for(i = 0; i < 5; i++){
		fprintf(arq5, "%d %d %d\n", revelado1[i][0], revelado1[i][1], revelado1[i][2]);
	}
	for(i = 0; i < 5; i++){
		fprintf(arq6, "%d %d %d\n", revelado2[i][0], revelado2[i][1], revelado2[i][2]);
	}
	
	fprintf(arq7, "%d %d\n", (*vidas), (*dicas));


		
	// Fecha o arquivo da matriz 1
	fclose(arq);
	fclose(arq2);
	fclose(arq3);
	fclose(arq4);
	fclose(arq5);
	fclose(arq6);	
	fclose(arq7);
	fclose(arq8);
}


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

