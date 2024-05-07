#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int w, jan = 0;
int i, j, x, y,x2,y2;
char input;
/*		
	i e j = linha e coluna
	jan = janela
	map = mapa impresso
	submap = mapa auxiliar(contera apenas as informacoes do mapa original)
*/

int main(int argc, char *argv[]) {
	system("color 04");
	mainmenu();
	//gameover();
	//fase1();
	//fase2();
}


//Tela inicial
void mainmenu(){
	w=0;
	
    

    do {
    	system("cls");
  	    printf("          ______   _    _        _                _____                            _____     _____    ____  \n");
    	printf("         |  ____| | |  | |      | |     /\\       |  __ \\      /\\           /\\     |  __ \\   / ____|  / __ \\ \n");
    	printf("         | |__    | |  | |      | |    /  \\      | |  | |    /  \\         /  \\    | |__) | | |  __  | |  | |\n");
    	printf("         |  __|   | |  | |  _   | |   / /\\ \\     | |  | |   / /\\ \\       / /\\ \\   |  _  /  | | |_ | | |  | |\n");
    	printf("         | |      | |__| | | |__| |  / ____ \\    | |__| |  / ____ \\     / ____ \\  | | \\ \\  | |__| | | |__| |\n");
    	printf("         |_|       \\____/   \\____/  /_/    \\_\\   |_____/  /_/    \\_\\   /_/    \\_\\ |_|  \\_\\  \\_____|  \\____/ \n");
    	printf("                                                                                                             \n");
    	printf("                                                                                                             \n");
        printf("\n\n\t\t\t\t\t\t\tA) JOGAR\n\n\t\t\t\t\t\t\tB) TUTORIAL\n\n\t\t\t\t\t\t\tC) SAIR\n");
        input = getche();
        system("cls");

        if (input == 'a' || input == 'A') {
        	system("cls");
        	w = 2;
        	while(w == 2){
    	fase1();
	}
            
        }
		
	 else if (input == 'b' || input == 'B') {
            w = 1;
            while (w == 1) {
                printf("\n\n\n\tW: O jogador movimenta uma unidade para cima.\n\tA: O jogador movimenta uma unidade para esquerda.\n\tS: O jogador movimenta uma unidade para baixo.\n\tD: O jogador movimenta uma unidade para direita.\n\tI: O jogador interage com o objeto que esta em cima.\n");
                printf("\n\t'@' eh a chave.\n\t'D' eh a porta fechada.\n\t'=' eh a porta aberta.\n\t'O': Simbolo que representa um botao que o usuario pode interagir, o botao fica no chao\n\t e o jogador deve ficar em cima dele para poder interagir.");
                printf("\n\t'#' eh um espinho que se vc tocar a fase reinicia.\n\t'>'eh um portal.\n\t'X' eh um monstro que possui um comportamento contrario ao do jogador.\n\t'V'eh um montro que te segue.\n\n");
                printf("\tPressione qualquer tecla para voltar para o Menu\n\n\t");
                getch();
                w = 0;
                system("cls");
            }
        } else if (input == 'c' || input == 'C') {
        	system("cls");
            w = 3;
            if(w == 3){
            	saida();
			}
            
            
        } else {
        	system("cls");
            printf("Comando invalido. Digite conforme as opcoes oferecidas.\n");
            getch();
        }
    } while (w == 0);
}

void fase1(){
	char map[25][25],submap[25][25];

	jan = 1;
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
	
	printf("\n\n\n\n\n\n\n\n\n");
	for(i = 0; i <=9; i++){
		printf("\t\t\t\t\t\t");
		for(j = 0;j<=9; j++){
			printf("%c ", map [i] [j]);
		}
		printf("\n");
		
	}
	printf("\n\n\n\n\n");
	input = getche();
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

	
void fase2(){
	char map[25][25],submap[25][25];

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
		
	printf("\n\n\n\n\n\n");
	for(i = 0; i <=19; i++){
		printf("\t\t\t\t\t  ");
		for(j = 0;j<=19; j++){
			printf("%c ", map [i] [j]);
		}
		printf("\n");
		
	}
	
	input = getche();
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
		gameover();
	}

		
		
}
	
	
}

void gameover(){
	system("cls");
	printf("                      _____              __  __   ______      ____   __      __  ______   _____  \n");
	printf("                     / ____|     /\\     |  \\/  | |  ____|    / __ \\  \\ \\    / / |  ____| |  __ \\ \n");
	printf("                    | |  __     /  \\    | \\  / | | |__      | |  | |  \\ \\  / /  | |__    | |__) |\n");
	printf("                    | | |_ |   / /\\ \\   | |\\/| | |  __|     | |  | |   \\ \\/ /   |  __|   |  _  / \n");
	printf("                    | |__| |  / ____ \\  | |  | | | |____    | |__| |    \\  /    | |____  | | \\ \\ \n");
	printf("                     \\_____| /_/    \\_\\ |_|  |_| |______|    \\____/      \\/     |______| |_|  \\_\\\n");
	printf("                                                                                                  \n");
	printf("                                                                                                  \n");
  	printf(" \t\t\t\t\t\t    Ta bebado, pai?\n\n\n\t\t\t\t   --PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU--\n");
  	getch();
	w = 0;
	jan = 0;
	system("cls");
	mainmenu();
}

void saida(){
	printf("Obrigado por jogar!!!");
	return 0;
}
