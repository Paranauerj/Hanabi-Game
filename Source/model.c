
#include "imports.c"






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

