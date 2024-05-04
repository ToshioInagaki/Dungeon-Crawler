#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
//como capturar tecla
//menu inicial
//tela de saida com agradecimento
//tela texto tutorial

char map[25][25],submap[25][25], input;
/*
i e j = linha e coluna
jan = janela
k = variavel de caso esteja segurando chave(se segura = 1 / se nao segura = 0)
map = mapa impresso
submap = mapa auxiliar(contera apenas as informacoes do mapa original)
*/
	int i, j, jan = 1, x, y, k = 0;
	x =1;
	y =1;
	
		for(i = 0; i <= 9; i++){
		for(j = 0;j<=9; j++){
			map[i][j] = '*';
		}
	}
	
	for(i = 1; i <= 8; i++){
		for(j = 1;j<=8; j++){
			map[i][j] = ' ';
		}
	}
	
	map [x] [y] = '&';
	
	for(j =1; j <=6; j ++){
		map [2] [j] = '*';
	}
	
	
	map [2][8] = '*';
	map [3][6] = '*';
	map [4][2] = '*';
	map [4][4] = '*';
	map [4][6] = '*';
	map [4][8] = '*';
	map [5][2] = '*';
	map [5][3] = '*';
	map [5][4] = '*';
	map [5][9] = 'D';
	map [6][4] = '*';
	map [6][6] = '*';
	map [7][2] = '*';
	map [7][7] = '*';
	map [8][1] = '@';
	map [8][2] = '*';
	map [8][4] = '*';
	submap [2][8] = '*';
	submap [3][6] = '*';
	submap [4][2] = '*';
	submap [4][4] = '*';
	submap [4][6] = '*';
	submap [4][8] = '*';
	submap [5][2] = '*';
	submap [5][3] = '*';
	submap [5][4] = '*';
	submap [5][9] = 'D';
	submap [6][4] = '*';
	submap [6][6] = '*';
	submap [7][2] = '*';
	submap [7][7] = '*';
	submap [8][1] = '@';
	submap [8][2] = '*';
	submap [8][4] = '*';
	
	while(jan != 0){
	
	for(i = 0; i <=9; i++){
		printf("\t\t\t\t\t\t\t\t");
		for(j = 0;j<=9; j++){
			printf("%c ", map [i] [j]);
		}
		printf("\n");
		
	}
	
	scanf(" %c", &input);
	system("cls");
	if(input == 'w'){
		
		if(map[x-1][y] != '*' && map[x -1][y] != 'D'){
			
			if(submap[x][y] == '@' ){
				map[x][y] = '@';
			}
			else{
				map[x][y] = ' ';
			}
			
			map[x -1][y] = '&';
			x = x -1;
		}

	}
	if(input == 'a'){
		
		if(map[x][y-1] != '*' && map[x][y-1] != 'D'){
			if(submap[x][y] == '@' ){
				map[x][y] = '@';
			}
			else{
				map[x][y] = ' ';
			}
			
			map[x][y-1] = '&';
	 		y = y - 1;
		}


	}
	if(input == 's'){
		if(map[x+1][y] != '*' && map[x+1][y] != 'D'){
			if(submap[x][y] == '@' ){
				map[x][y] = '@';
			}
			else{
				map[x][y] = ' ';
			}
			map[x+1][y] = '&';
			x = x+1;
		}
	}
	if(input == 'd'){
		if(map[x][y+1] != '*' && map[x][y+1] != 'D'){
			if(submap[x][y] == '@' ){
				map[x][y] = '@';
			}
			else{
				map[x][y] = ' ';
			}
			map[x][y+1] = '&';
	 		y = y + 1;
		}

	}

		if(input == 'i'){
			if(map[x][y] == map [8][1]){
				k = 1;
				map [5][9] ='=';
				submap [5][9] ='=';	
				submap [8][1] = ' ';	
			}

		}
		
	}

	

	return 0;
}
