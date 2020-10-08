#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

typedef struct{
	int x;
	int y;
}estado;


//Variaveis para o tamanho da matriz
long int x, y;

//Topo da Pilha
long int topo;


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
	if(cima.y == y-1){
		return cima;
	}
	if(cima.x-1 >= 0){
		cima.x--;
	}
	return cima;
}
estado moverDireita(estado direita){
	if(direita.y+1 < y){
		direita.y++;
	}
	return direita;
}
estado moverEsquerda(estado esquerda){
	if(esquerda.x == x-1){
		return esquerda;
	}
	if(esquerda.y-1 > 0){
		esquerda.y--;
	}
	return esquerda;
}
estado moverBaixo(estado baixo){
	if(baixo.x+1 < x){
		baixo.x++;
	}
	return baixo;
}

bool visitado(estado inicial){
	if(!pilhavazia()){
		estado aux = top();
		if(inicial.x == aux.x && inicial.y == aux.y){
			return true;
		}
	}
	return false;
}

bool buscarSaida(estado inicial, estado saida, char maze[][y]){
	if(maze[inicial.x][inicial.y] == '#' || visitado(inicial)){
		return false;
	}
	if(inicial.x == saida.x && inicial.y == saida.y){
		push(inicial);
		printf("\nAchei a saida!!!\n");
		return true;
	}
	push(inicial);	
	
	if(buscarSaida(moverBaixo(inicial), saida, maze) || buscarSaida(moverDireita(inicial), saida, maze) || buscarSaida(moverEsquerda(inicial), saida, maze) || buscarSaida(moverCima(inicial), saida, maze)){
		
	}else{
		pop();
		return false;
	}
}

int main(){
	estado final, inicial;
	
	printf("Digite o tamanho do labirinto: \n>> ");
	
	setbuf(stdin, NULL);	
	
	scanf("%d %d", &x, &y);
	
	setbuf(stdin, NULL);
	
	char maze[x][y];

	//Já tentei com gets() e não funcionou
	printf("Desenhe o labirinto: ");
	scanf("%s", &maze);
	setbuf(stdin, NULL);
	
	inicial.x = 0;
	inicial.y = 1;
	final.x = x-1;
	final.y = y-2;
	printf("\n");
	for(int i = 0; i<x; i++){
		for(int j = 0; j<y; j++){
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
	
	criapilha();
	buscarSaida(inicial, final, maze);

	//Mostra o caminho na tela.
	int i = 0;
	printf("Caminho");
	while(!pilhavazia()){
		estado f = pilha[i];
		printf("\n(%d, %d)", f.x, f.y);
		pop();
		i++;
	}
	
	
	return 0;
}
