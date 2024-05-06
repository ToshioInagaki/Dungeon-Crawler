#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int w;
int main(int argc, char *argv[]) {
	mainmenu();
}


//Tela inicial
int mainmenu(){
	char resp;
	w=0;
    

    do {
    	system("cls");
     printf("  ______   _    _        _                _____                            _____     _____    ____  \n");
    printf(" |  ____| | |  | |      | |     /\\       |  __ \\      /\\           /\\     |  __ \\   / ____|  / __ \\ \n");
    printf(" | |__    | |  | |      | |    /  \\      | |  | |    /  \\         /  \\    | |__) | | |  __  | |  | |\n");
    printf(" |  __|   | |  | |  _   | |   / /\\ \\     | |  | |   / /\\ \\       / /\\ \\   |  _  /  | | |_ | | |  | |\n");
    printf(" | |      | |__| | | |__| |  / ____ \\    | |__| |  / ____ \\     / ____ \\  | | \\ \\  | |__| | | |__| |\n");
    printf(" |_|       \\____/   \\____/  /_/    \\_\\   |_____/  /_/    \\_\\   /_/    \\_\\ |_|  \\_\\  \\_____|  \\____/ \n");
    printf("                                                                                                     \n");
    printf("                                                                                                     \n");
        printf("\nA) Jogar\nB) Tutorial\nC) Sair\n");
        scanf(" %c", &resp);
        system("cls");

        if (resp == 'a' || resp == 'A') {
        	system("cls");
        	w = 2;
        	while(w == 2){
    	fase1();
	}
            
        }
		
	 else if (resp == 'b' || resp == 'B') {
            w = 1;
            while (w == 1) {
                printf("W: O jogador movimenta uma unidade para cima.\nA: O jogador movimenta uma unidade para esquerda.\nS: O jogador movimenta uma unidade para baixo.\nD: O jogador movimenta uma unidade para direita.\nI: O jogador interage com o objeto que esta em cima.\n");
                printf("\n'@' eh a chave.\n'D' eh a porta fechada.\n'=' eh a porta aberta.\n'O': Simbolo que representa um botao que o usuario pode interagir, o botao fica no chao\n e o jogador deve ficar em cima dele para poder interagir.");
                printf("\n'#' eh um espinho que se vc tocar a fase reinicia.\n'>'eh um portal.\n'X' eh um monstro que se move aleatoriamente.\n'V'eh um montro que te segue.\n\n");
                printf("Pressione qualquer tecla para voltar para o Menu\n");
                getch();
                w = 0;
                system("cls");
            }
        } else if (resp == 'c' || resp == 'C') {
        	system("cls");
            printf("Ce vai sair fi do Bill\n");
            break;
        } else {
        	system("cls");
            printf("Nada a ver irmao\n");
            getch();
        }
    } while (resp != 'c' && resp != 'C');{
		return 0;
	}
}
int fase1(){
	char map[25][25],submap[25][25], input;
/*
i e j = linha e coluna
jan = janela
k = variavel de caso esteja segurando chave(se segura = 1 / se nao segura = 0)
map = mapa impresso
submap = mapa auxiliar(contera apenas as informacoes do mapa original)
*/
	int i, j,jan = 1, x, y, k = 0;
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
		
		if(map[x] [y] == map [5] [10]){
			fase2();
		
	}
}
}

	
	int fase2(){
	char map[25][25],submap[25][25], input;
	/*
	i e j = linha e coluna
	jan = janela
	k = variavel de caso esteja segurando chave(se segura = 1 / se nao segura = 0)
	map = mapa impresso
	submap = mapa auxiliar(contera apenas as informacoes do mapa original)
	*/
	int i, j, jan = 1, x, y,x2,y2, k = 0;
	x=5;
	y=5;
	x2=15;
	y2=15;
	
		for(i = 0; i <= 19; i++){
		for(j = 0;j<=19; j++){
			map[i][j] = '*';
		}
	}
	
	for(i = 1; i <= 18; i++){
		for(j = 1;j<=18; j++){
			map[i][j] = ' ';
		}
	}
	
	map [x] [y] = '&';
	map [x2] [y2] = 'X';
	

	
	
	
	
	while(jan != 0){
	
	for(i = 0; i <=19; i++){
		printf("\t\t\t\t\t\t\t\t");
		for(j = 0;j<=19; j++){
			printf("%c ", map [i] [j]);
		}
		printf("\n");
		
	}
	
	scanf(" %c", &input);
	system("cls");
	if(input == 'w'){
		
		if(map[x-1][y] != '*' && map[x -1][y] != 'D'){
			
			
			map[x][y] = ' ';
			map[x -1][y] = '&';
			x = x -1;
			
			if(map[x2 +1][y2] != '*'){
				if(map[x2][y2] == '&'){
					map[x2 +1][y2] = 'X';
			x2 = x2 +1;
	 				
				 }
			 else{
			map[x2][y2]= ' ';
			map[x2 +1][y2] = 'X';
			x2 = x2 +1;
	 		
	 	}
			
			
		
			}
		}

	}
	if(input == 'a'){
		
		if(map[x][y-1] != '*' && map[x][y-1] != 'D'){
			
		
			map[x][y] = ' ';
			map[x][y-1] = '&';
	 		y = y - 1;
	 		
	 		if(map[x2][y2+1] != '*'){
	 			if(map[x2][y2] == '&'){
	 				map[x2][y2+1] = 'X';
	 				y2 = y2 + 1;
	 				
				 }
			 else{
			 	map[x2][y2] = ' ';
	 		map[x2][y2+1] = 'X';
	 		y2 = y2 + 1;
	 		
	 	}
			 
	 	
	 	 }
		}


	}
	if(input == 's'){
		if(map[x+1][y] != '*' && map[x+1][y] != 'D'){
		
			map[x][y] = ' ';
			map[x+1][y] = '&';
			x = x+1;
			
			if(map[x2 -1][y2] != '*'){
				if(map[x2][y2] == '&'){
					map[x2 -1][y2] = 'X';
					x2 = x2 -1;
	 				
				 }
			 else{
			 	map[x2][y2] = ' ';
			map[x2 -1][y2] = 'X';
			x2 = x2 -1;
	 		
	 	}
			
		
		}
		}
	}
	if(input == 'd'){
		if(map[x][y+1] != '*' && map[x][y+1] != 'D'){
		
			map[x][y] = ' ';
			map[x][y+1] = '&';
	 		y = y + 1;
	 		
	 		if(map[x2][y2-1] != '*'){
	 			if(map[x2][y2] == '&'){
	 				map[x2][y2-1] = 'X';
	 				y2 = y2 - 1;
				 }
			 else{
	 		map[x2][y2] = ' ';
	 		map[x2][y2-1] = 'X';
	 		y2 = y2 - 1;
	 	}
	 	}
		}

	}

	if(map[x] [y] == map[x2] [y2]){
		system("cls");
		printf("   _____              __  __   ______      ____   __      __  ______   _____  \n");
		printf("  / ____|     /\\     |  \\/  | |  ____|    / __ \\  \\ \\    / / |  ____| |  __ \\ \n");
		printf(" | |  __     /  \\    | \\  / | | |__      | |  | |  \\ \\  / /  | |__    | |__) |\n");
		printf(" | | |_ |   / /\\ \\   | |\\/| | |  __|     | |  | |   \\ \\/ /   |  __|   |  _  / \n");
		printf(" | |__| |  / ____ \\  | |  | | | |____    | |__| |    \\  /    | |____  | | \\ \\ \n");
		printf("  \\_____| /_/    \\_\\ |_|  |_| |______|    \\____/      \\/     |______| |_|  \\_\\\n");
		printf("                                                                               \n");
		printf("                                                                               \n");
  	 	printf("     Tomou na Jabiraca, Filho da XANAINA.\n\n--PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU--");
  	 	getch();
		system("cls");
		mainmenu();
	}

		
		
}
	
	
}
