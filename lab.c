#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

typedef struct{
	int x;
	int y;
}estado;


//Variaveis para o tamanho da matriz
int x, y;
int topo;

//Pilha
estado pilha[10*20];

void criapilha(){
	topo = (-1);
}

void push(estado elemento){
    if (topo > x*y-1){
    	printf("Overflow");
    	return;
	}
    pilha[++topo] = elemento;
}
estado pop(){
    if(topo != -1){
        return pilha[topo--];
	}
	return pilha[0];
}

estado top(){
	return pilha[topo-1];
}

bool pilhavazia(){
	if(topo == -1){
		return true;
	}
    return false;
}

//Movimentação
estado moverCima(estado cima){
	if(cima.x-1 >= 0){
		cima.x--;
		return cima;
	}
	return cima;
}
estado moverDireita(estado direita){
	if(direita.y+1 < y){
		direita.y++;
		return direita;
	}
	return direita;
}
estado moverEsquerda(estado esquerda){
	if(esquerda.y-1 >= 1){
		esquerda.y--;
		return esquerda;
	}
	return esquerda;
}
estado moverBaixo(estado baixo){
	if(baixo.x+1 < x){
		baixo.x++;
		return baixo;
	}
	return baixo;
}

bool visitado(estado inicial){
	estado aux = top();
	if(inicial.x == aux.x && inicial.y == aux.y){
		if(pilhavazia()){
			return false;
		}
		return true;
	}

	return false;
}

void buscarSaida(estado inicial, estado saida, char maze[][saida.y+2]){
	if(maze[inicial.x][inicial.y] == '#' || visitado(inicial)){
		printf("\nParede\n");
		return;
	}
	if(inicial.x == saida.x && inicial.y == saida.y){
		printf("\nAchei a saida!!!");
		system("pause");
		return;
	}
	push(inicial);	
	
	printf("\n(%d, %d)", inicial.x, inicial.y);
	buscarSaida(moverBaixo(inicial), saida, maze);

	printf("\n(%d, %d)", inicial.x, inicial.y);
	buscarSaida(moverDireita(inicial), saida, maze);

	printf("\n(%d, %d)", inicial.x, inicial.y);	
	buscarSaida(moverEsquerda(inicial), saida, maze);
	
	printf("\n(%d, %d)", inicial.x, inicial.y);
	buscarSaida(moverCima(inicial), saida, maze);
}

int main(){
	estado final, inicial;
	
	printf("Digite o tamanho do labirinto: \n>> ");
	
	setbuf(stdin, NULL);	
	
	scanf("%d %d", &x, &y);
	
	setbuf(stdin, NULL);
	
	char maze[x][y];
	
	printf("Desenhe o labirinto: ");
	gets(maze);
	setbuf(stdin, NULL);
	
	inicial.x = 0;
	inicial.y = 1;
	final.x = x-1;
	final.y = y-2;
	
	for(int i = 0; i<x; i++){
		for(int j = 0; j<y; j++){
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
	criapilha();
	buscarSaida(inicial, final, maze);
	
	return 0;
}
