#include "imports.c"

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
