#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int w, jan = 0, i, j, x, y,xX,yX,xV,yV,xe,ye, roll, life = 3, contfase = 0;
char input, map[60][60],submap[60][60];
/*		
	i e j = linha e coluna
	jan = janela
	map = mapa impresso
	submap = mapa auxiliar(contera apenas as informacoes do mapa original)
*/

void monsterX(){// Monstro lvl 1(Movimento aleatório)
	roll = 1+rand()%5;// Movimento definidos entre 1 e 4
	
	if (roll == 1){
		if(map[xX-1][yX] != '*' && map[xX-1][yX] != 'D' && map[xX-1][yX] != '#' && map[xX-1][yX] != '='){
	 		if(map[xX][yX] == '&'){
	 			map[xX][yX] = '&';
			}
			else if(submap[xX][yX] == '@' ){
				map[xX][yX] = '@';
			}
			else if(submap[xX][yX] == '0' ){
				map[xX][yX] = '0';
			}
			else if(submap[xX][yX] == 'o' ){
				map[xX][yX] = 'o';
			}
			else{
				map[xX][yX] = ' ';
		}
		
			map[xX-1][yX] = 'X';
			xX = xX - 1;
		}
	}
	else if (roll == 2){
		if(map[xX][yX-1] != '*' && map[xX][yX-1] != 'D' && map[xX][yX-1] != '#' && map[xX][yX-1] != '='){
			if(map[xX][yX] == '&'){
	 			map[xX][yX] = '&';
			}
			else if(submap[xX][yX] == '@' ){
				map[xX][yX] = '@';
			}
			else if(submap[xX][yX] == '0' ){
				map[xX][yX] = '0';
			}
			else if(submap[xX][yX] == 'o' ){
				map[xX][yX] = 'o';
			}
			else{
				map[xX][yX] = ' ';
		}
			map[xX][yX-1] = 'X';
			yX = yX - 1;
		}
	}
	else if (roll == 3){
		if(map[xX+1][yX] != '*' && map[xX+1][yX] != 'D' && map[xX+1][yX] != '#' && map[xX+1][yX] != '='){
	 		if(map[xX][yX] == '&'){
	 			map[xX][yX] = '&';
			}
			else if(submap[xX][yX] == '@' ){
				map[xX][yX] = '@';
			}
			else if(submap[xX][yX] == '0' ){
				map[xX][yX] = '0';
			}
			else if(submap[xX][yX] == 'o' ){
				map[xX][yX] = 'o';
			}
			else{
				map[xX][yX] = ' ';
		}
			map[xX+1][yX] = 'X';
			xX = xX + 1;
		}
	}
	else if (roll == 4){
		
		if(map[xX][yX+1] != '*' && map[xX][yX+1] != 'D' && map[xX][yX+1] != '#' && map[xX][yX+1] != '='){
			if(map[xX][yX] == '&'){
	 			map[xX][yX] = '&';
			}
			else if(submap[xX][yX] == '@' ){
				map[xX][yX] = '@';
			}
			else if(submap[xX][yX] == '0' ){
				map[xX][yX] = '0';
			}
			else if(submap[xX][yX] == 'o' ){
				map[xX][yX] = 'o';
			}
			else{
				map[xX][yX] = ' ';
		}
			map[xX][yX+1] = 'X';
			yX = yX + 1;
		}
	}
}

void monsterV(){// MONSTRO LVL 2(Segue o Player) ==========================================================================================================================================================
	roll = 1+rand()%3;// Movimento definidos entre 1 e 2(baseado na posicao do player

//CASO O PLAYER ESTEJA A ESQUERDA DO MONSTRO	
	if(y < yV){
		if(x < xV){
			
			if(roll == 1){
				if(map[xV+1][yV] != '*' && map[xV+1][yV] != 'D' && map[xV+1][yV] != '#' && map[xV+1][yV] != '='){
	 				if(map[xV][yV] == '&'){
	 					map[xV][yV] = '&';
					}
					else if(submap[xV][yV] == '@' ){
						map[xV][yV] = '@';
					}
					else if(submap[xV][yV] == '0' ){
						map[xV][yV] = '0';
					}
					else if(submap[xV][yV] == 'o' ){
						map[xV][yV] = 'o';
					}
					else{
						map[xV][yV] = ' ';
					}
					map[xV-1][yV] = 'V';
					xV = xV - 1;
				}
			}
			
			if(roll == 2){
				if(map[xV][yV+1] != '*' && map[xV][yV+1] != 'D' && map[xV][yV+1] != '#' && map[xV][yV+1] != '='){
	 				if(map[xV][yV] == '&'){
	 					map[xV][yV] = '&';
					}
					else if(submap[xV][yV] == '@' ){
						map[xV][yV] = '@';
					}
					else if(submap[xV][yV] == '0' ){
						map[xV][yV] = '0';
					}
					else if(submap[xV][yV] == 'o' ){
						map[xV][yV] = 'o';
					}
					else{
						map[xV][yV] = ' ';
					}
					map[xV][yV-1] = 'V';
					yV = yV - 1;
				}
			}
		}
		else if(x > xV){
			if(roll == 1){
				if(map[xV-1][yV] != '*' && map[xV-1][yV] != 'D' && map[xV-1][yV] != '#' && map[xV-1][yV] != '='){
	 				if(map[xV][yV] == '&'){
	 					map[xV][yV] = '&';
					}
					else if(submap[xV][yV] == '@' ){
						map[xV][yV] = '@';
					}
					else if(submap[xV][yV] == '0' ){
						map[xV][yV] = '0';
					}
					else if(submap[xV][yV] == 'o' ){
						map[xV][yV] = 'o';
					}
					else{
						map[xV][yV] = ' ';
					}
					map[xV+1][yV] = 'V';
					xV = xV + 1;
				}
			}
			if(roll == 2){
				if(map[xV][yV+1] != '*' && map[xV][yV+1] != 'D' && map[xV][yV+1] != '#' && map[xV][yV+1] != '='){
	 				if(map[xV][yV] == '&'){
	 					map[xV][yV] = '&';
					}
					else if(submap[xV][yV] == '@' ){
						map[xV][yV] = '@';
					}
					else if(submap[xV][yV] == '0' ){
						map[xV][yV] = '0';
					}
					else if(submap[xV][yV] == 'o' ){
						map[xV][yV] = 'o';
					}
					else{
						map[xV][yV] = ' ';
					}
					map[xV][yV-1] = 'V';
					yV = yV - 1;
				}
			}
		}
		else{
			if(map[xV][yV+1] != '*' && map[xV][yV+1] != 'D' && map[xV][yV+1] != '#' && map[xV][yV+1] != '='){
	 				if(map[xV][yV] == '&'){
	 					map[xV][yV] = '&';
					}
					else if(submap[xV][yV] == '@' ){
						map[xV][yV] = '@';
					}
					else if(submap[xV][yV] == '0' ){
						map[xV][yV] = '0';
					}
					else if(submap[xV][yV] == 'o' ){
						map[xV][yV] = 'o';
					}
					else{
						map[xV][yV] = ' ';
					}
					map[xV][yV-1] = 'V';
					yV = yV - 1;
			}
		}
	}
	
//CASO O PLAYER ESTEJA A DIREITA DO MONSTRO

	else if(y > yV){
		if(x > xV){
			
			if(roll == 1){
				if(map[xV-1][yV] != '*' && map[xV-1][yV] != 'D' && map[xV-1][yV] != '#' && map[xV-1][yV] != '='){
	 				if(map[xV][yV] == '&'){
	 					map[xV][yV] = '&';
					}
					else if(submap[xV][yV] == '@' ){
						map[xV][yV] = '@';
					}
					else if(submap[xV][yV] == '0' ){
						map[xV][yV] = '0';
					}
					else if(submap[xV][yV] == 'o' ){
						map[xV][yV] = 'o';
					}
					else{
						map[xV][yV] = ' ';
					}
					map[xV+1][yV] = 'V';
					xV = xV + 1;
				}
			}
			
			if(roll == 2){
				if(map[xV][yV-1] != '*' && map[xV][yV-1] != 'D' && map[xV][yV-1] != '#' && map[xV][yV-1] != '='){
	 				if(map[xV][yV] == '&'){
	 					map[xV][yV] = '&';
					}
					else if(submap[xV][yV] == '@' ){
						map[xV][yV] = '@';
					}
					else if(submap[xV][yV] == '0' ){
						map[xV][yV] = '0';
					}
					else if(submap[xV][yV] == 'o' ){
						map[xV][yV] = 'o';
					}
					else{
						map[xV][yV] = ' ';
					}
					map[xV][yV+1] = 'V';
					yV = yV + 1;
				}
			}
		}
		else if(x < xV){
			if(roll == 1){
				if(map[xV+1][yV] != '*' && map[xV+1][yV] != 'D' && map[xV+1][yV] != '#' && map[xV+1][yV] != '='){
	 				if(map[xV][yV] == '&'){
	 					map[xV][yV] = '&';
					}
					else if(submap[xV][yV] == '@' ){
						map[xV][yV] = '@';
					}
					else if(submap[xV][yV] == '0' ){
						map[xV][yV] = '0';
					}
					else if(submap[xV][yV] == 'o' ){
						map[xV][yV] = 'o';
					}
					else{
						map[xV][yV] = ' ';
					}
					map[xV-1][yV] = 'V';
					xV = xV - 1;
				}
			}
			if(roll == 2){
				if(map[xV][yV-1] != '*' && map[xV][yV-1] != 'D' && map[xV][yV-1] != '#' && map[xV][yV-1] != '='){
	 				if(map[xV][yV] == '&'){
	 					map[xV][yV] = '&';
					}
					else if(submap[xV][yV] == '@' ){
						map[xV][yV] = '@';
					}
					else if(submap[xV][yV] == '0' ){
						map[xV][yV] = '0';
					}
					else if(submap[xV][yV] == 'o' ){
						map[xV][yV] = 'o';
					}
					else{
						map[xV][yV] = ' ';
					}
					map[xV][yV+1] = 'V';
					yV = yV + 1;
				}
			}
		}
		else{
			if(map[xV][yV+1] != '*' && map[xV][yV-1] != 'D' && map[xV][yV-1] != '#' && map[xV][yV-1] != '='){
	 				if(map[xV][yV] == '&'){
	 					map[xV][yV] = '&';
					}
					else if(submap[xV][yV] == '@' ){
						map[xV][yV] = '@';
					}
					else if(submap[xV][yV] == '0' ){
						map[xV][yV] = '0';
					}
					else if(submap[xV][yV] == 'o' ){
						map[xV][yV] = 'o';
					}
					else{
						map[xV][yV] = ' ';
					}
					map[xV][yV+1] = 'V';
					yV = yV + 1;
			}
		}
	}
//CASO O PLAYER ESTEJA DIRETAMENTE EM CIMA OU EM BAIXO DO MONSTRO
	else{
		if(x < xV){
			if(map[xV+1][yV] != '*' && map[xV+1][yV] != 'D' && map[xV+1][yV] != '#' && map[xV+1][yV] != '='){
	 			if(map[xV][yV] == '&'){
	 				map[xV][yV] = '&';
				}
				else if(submap[xV][yV] == '@' ){
					map[xV][yV] = '@';
				}
				else if(submap[xV][yV] == '0' ){
					map[xV][yV] = '0';
				}
				else if(submap[xV][yV] == 'o' ){
					map[xV][yV] = 'o';
				}
				else{
					map[xV][yV] = ' ';
				}
				map[xV-1][yV] = 'V';
				xV = xV - 1;
			}
		}
		else{
			if(map[xV-1][yV] != '*' && map[xV-1][yV] != 'D' && map[xV-1][yV] != '#' && map[xV-1][yV] != '='){
	 			if(map[xV][yV] == '&'){
	 				map[xV][yV] = '&';
				}
				else if(submap[xV][yV] == '@' ){
					map[xV][yV] = '@';
				}
				else if(submap[xV][yV] == '0' ){
					map[xV][yV] = '0';
				}
				else if(submap[xV][yV] == 'o' ){
					map[xV][yV] = 'o';
				}
				else{
					map[xV][yV] = ' ';
				}
				map[xV+1][yV] = 'V';
				xV = xV + 1;
			}
		}
	}

}

void monstere(){// Monstro lvl ??(Movimento Espelhado)
	if(input == 'w'){
		if(map[xe+1][ye] != '*' && map[xe+1][ye] != 'D' && map[xe+1][ye] != '=' && map[xe+1][ye] != '#'){			
	 		if(map[xe][ye] == '&'){
	 			map[xe][ye] = '&';
			}
			else if(submap[xe][ye] == '@' ){
				map[xe][ye] = '@';
			}
			else{
				map[xe][ye] = ' ';
			}
			
			map[xe+1][ye] = 'e';
			xe = xe + 1;
		}

	}
	else if(input == 'a'){
		if(map[xe][ye+1] != '*' && map[xe][ye+1] != 'D' && map[xe][ye+1] != '=' && map[xe][ye+1] != '#'){		
	 		if(map[xe][ye] == '&'){
	 			map[xe][ye] = '&';
			}
			else if(submap[xe][ye] == '@' ){
				map[xe][ye] = '@';
			}
			else{
				map[xe][ye] = ' ';
			}
			map[xe][ye+1] = 'e';
	 		ye = ye + 1;
		}
	}
	
	else if(input == 's'){
		if(map[xe-1][ye] != '*' && map[xe-1][ye] != 'D' && map[xe-1][ye] != '=' && map[xe-1][ye] != '#'){
	 		if(map[xe][ye] == '&'){
	 			map[xe][ye] = '&';
			}
			else if(submap[xe][ye] == '@' ){
				map[xe][ye] = '@';
			}
			else{
				map[xe][ye] = ' ';
			}
			
			map[xe-1][ye] = 'e';
			xe = xe-1;
		}
	}
	else if(input == 'd'){
		if(map[xe][ye-1] != '*' && map[xe][ye-1] != 'D' &&  map[xe][ye-1] != '=' &&  map[xe][ye-1] != '#'){
	 		if(map[xe][ye] == '&'){
	 			map[xe][ye] = '&';
			}
			else if(submap[xe][ye] == '@' ){
				map[xe][ye] = '@';
			}
			else{
				map[xe][ye] = ' ';
			}
			map[xe][ye-1] = 'e';
	 		ye = ye - 1;
		}
	}
}

void playermove(){
	//system("cls");
	if(input == 'w'){
		
		if(map[x-1][y] != '*' && map[x -1][y] != 'D'){
			
			if(submap[x][y] == '@' ){
				map[x][y] = '@';
			}
			else if(submap[x][y] == '0' ){
				map[x][y] = '0';
			}
			else if(submap[x][y] == 'o' ){
				map[x][y] = 'o';
			}
			else{
				map[x][y] = ' ';
			}
			
			map[x -1][y] = '&';
			x = x -1;
		}

	}
	else if(input == 'a'){
		
		if(map[x][y-1] != '*' && map[x][y-1] != 'D'){
			if(submap[x][y] == '@' ){
				map[x][y] = '@';
			}
			else if(submap[x][y] == '0' ){
				map[x][y] = '0';
			}
			else if(submap[x][y] == 'o' ){
				map[x][y] = 'o';
			}
			else{
				map[x][y] = ' ';
			}
			
			map[x][y-1] = '&';
	 		y = y - 1;
		}
	}
	else if(input == 's'){
		if(map[x+1][y] != '*' && map[x+1][y] != 'D'){
			if(submap[x][y] == '@' ){
				map[x][y] = '@';
			}
			else if(submap[x][y] == '0' ){
				map[x][y] = '0';
			}
			else if(submap[x][y] == 'o' ){
				map[x][y] = 'o';
			}
			else{
				map[x][y] = ' ';
			}
			map[x+1][y] = '&';
			x = x+1;
		}
	}
	else if(input == 'd'){
		if(map[x][y+1] != '*' && map[x][y+1] != 'D'){
			if(submap[x][y] == '@' ){
				map[x][y] = '@';
			}
			else if(submap[x][y] == '0' ){
				map[x][y] = '0';
			}
			else if(submap[x][y] == 'o' ){
				map[x][y] = 'o';
			}
			else{
				map[x][y] = ' ';
			}
			map[x][y+1] = '&';
	 		y = y + 1;
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
	life = 3;
	contfase = 0;
	system("cls");
	mainmenu();
}

void morreu(){
	system("cls");
    printf("                     __      ______   _____ ______   __  __  ____  _____  _____  ______ _    _ \n");
    printf("                     \\ \\    / / __ \\ / ____|  ____| |  \\/  |/ __ \\|  __ \\|  __ \\|  ____| |  | |\n");
    printf("                      \\ \\  / / |  | | |    | |__    | \\  / | |  | | |__) | |__) | |__  | |  | |\n");
    printf("                       \\ \\/ /| |  | | |    |  __|   | |\\/| | |  | |  _  /|  _  /|  __| | |  | |\n");
    printf("                        \\  / | |__| | |____| |____  | |  | | |__| | | \\ \\| | \\ \\| |____| |__| |\n");
    printf("                         \\/   \\____/ \\_____|______| |_|  |_|\\____/|_|  \\_\\_|  \\_\\______|\\____/ \n");
    printf("                                                                                                \n");
    printf("\n\n\n\t\t\t\t    -- APERTE QUALQUER BOTAO PARA TENTAR DE NOVO --");
	getch();
	
	
	if(contfase == 1){
		system("cls");
		fase1();
	}
	if(contfase == 2){
		system("cls");
		fase2();
	}
	if(contfase == 3){
		system("cls");
		fase3();	
	}
	
}
int fase3(){// FASE DE TESTES ========================================================================================================
	contfase = 3;
	x = 5;
	y = 5;
	xV = 30;
	yV = 30;
	
	for(i =0 ; i<=39; i++){
		for(j = 0; j<= 39; j++){
			map[i][j] = '*';
			submap[i][j] = '*';
		}
	}
	
	for(i =1 ; i<=38; i++){
		for(j = 1; j<= 38; j++){
			map[i][j] = ' ';
			submap[i][j] = ' ';
		}
	}
	
	
	//player e monstro
	map [x] [y] = '&';
	map [xV] [yV] = 'V';
	
	
	//==========================================================================================================
	while(life != 0){
	printf("Vida: %d\n\n", life);	
	
	//MENSAGENS DE LOGS =======================================================================================================
	if (map[x][y] == map [2][8] && map [0][17] == '='){
		printf("-- Voce pegou a chave! Corra para a porta! --");
	}


	printf("\n\n\n\n\n");
	for(i = 0; i <=39; i++){
		printf("\t\t\t\t\t  ");
		for(j = 0;j<=39; j++){
			printf("%c ", map [i] [j]);
		}
		printf("\n");
	
	}
	
	
	input = getche();
	playermove();
	monsterV();
	system("cls");
	
	
	if(map[x][y] == map[xV][yV] || submap[x][y] == '#'){
		
		life--;
		
		if(life == 0){
			gameover();
		}	
		
		else{
			morreu();
		}
	}
	
	}
}

int fase2(){
	contfase=2;
	x = 1;
	y = 12;
	xX = 15;
	yX = 13;
	xe = 1;
	ye = 17;
	
	//PAREDE======================================================================================================================================================================================================
	for(i =0 ; i<=19; i++){
		for(j = 0; j<= 19; j++){
			map[i] [j] = '*';
		}
	}
	
	for(i =1 ; i<=18; i++){
		for(j = 1; j<= 18; j++){
			map[i] [j] = ' ';
		}
	}
	
	//DETALHES DO MAPA ===================================================================================================================================================================================================
		for(j =4; j<=10; j++){
		map [5]  [j] = '*';
	}
	
		for(i = 1; i<= 4; i ++){
		map[i] [10] = '*';
	}
	
	for(i = 6; i<= 11; i ++){
		map[i] [9] = '*';
	}
	
	for(j =9; j<=18; j++){
		map [11]  [j] = '*';
	}
	
	for(i = 1; i<= 3; i ++){
		map[i] [14] = '*';
	}
	for(i = 12; i<= 13; i ++){
		map[i] [13] = '*';
	}
	
	map[18] [13] = '*';
	
	//MAP PROS ESPINHOS==========================================================================================================================================================================================
	
	for(i = 2; i<= 16; i ++){
		map[i] [1] = '#';
	}
	
	map[16] [2] = '#';
	map[17] [2] = '#';
	map[17] [3] = '#';
	map[17] [4] = '#';
	
		for(j =3; j<=6; j++){
		map [14]  [j] = '#';
	}
	
	for(j =3; j<=6; j++){
		map [6]  [j] = '#';
	}
	
	map [13]  [3] = '#';
	map [12]  [3] = '#';
	map [12]  [4] = '#';
	map [12]  [5] = '#';
	map [11]  [6] = '#';
	map [11]  [7] = '#';
	map [10]  [2] = '#';
	map [10]  [3] = '#';
	map [9]  [3] = '#';
	map [9]  [4] = '#';
	map [9]  [5] = '#';
	map [8]  [6] = '#';
	map [2]  [3] = '#';
	map [1]  [8] = '#';
	
	
	for(i = 1; i<= 3; i ++){
		map[i] [7] = '#';
		map[i] [9] = '#';
	}
	for(i = 2; i<= 4; i ++){
		map[i] [4] = '#';
	}
	
	for(i = 4; i<= 7; i ++){
		map[i] [3] = '#';
	}
	

	
	for(j =15; j<=18; j++){
		map [3]  [j] = '#';
	}
	
	//ESPINHOS COBRINDO O PORTAL 1
	map[10] [17] = '#';
	map[9] [17] = '#';
	map[9] [18] = '#';

	
	for(i = 6; i<= 11; i ++){
		map[i] [8] = '#';
	}
	map[11][5] = '#';
	map[9][6] = '#';
	map[6][7] = '#';
	
	
	//SUBMAP PRO ESPINHO===========================================================================================================================================================================================
	
	for(i = 2; i<= 16; i ++){
		submap[i] [1] = '#';
	}
	

	submap[16] [2] = '#';
	submap[17] [2] = '#';
	submap[17] [3] = '#';
	submap[17] [4] = '#';
	
		for(j =3; j<=6; j++){
		submap [14]  [j] = '#';
	}
	
	for(j =3; j<=6; j++){
		submap [6]  [j] = '#';
	}
	
	submap [13]  [3] = '#';
	submap [12]  [3] = '#';
	submap [12]  [4] = '#';
	submap [12]  [5] = '#';
	submap [11]  [6] = '#';
	submap [11]  [7] = '#';
	submap [10]  [2] = '#';
	submap [10]  [3] = '#';
	submap [9]  [3] = '#';
	submap [9]  [4] = '#';
	submap [9]  [5] = '#';
	submap [8]  [6] = '#';
	submap [2]  [3] = '#';
	submap [1]  [8] = '#';

	
	
	
	for(i = 1; i<= 3; i ++){
		submap[i] [7] = '#';
		submap[i] [9] = '#';
	}
	for(i = 2; i<= 4; i ++){
		submap[i] [4] = '#';
	}
	
	for(i = 4; i<= 7; i ++){
		submap[i] [3] = '#';
	}
	

	
	for(j =15; j<=18; j++){
		submap [3]  [j] = '#';
	}
	
	//ESPINHOS COBRINDO O PORTAL 1
	submap[10] [17] = '#';
	submap[9] [17] = '#';
	submap[9] [18] = '#';
	
	for(i = 6; i<= 11; i ++){
		submap[i] [8] = '#';
	}
	
	submap[11][5] = '#';
	submap[9][6] = '#';
	submap[6][7] = '#';
	
	
	
	//Botao
	map[17] [1] = 'o';
	submap[17] [1] = 'o';
	map [4] [14] ='o';
	submap [4] [14] ='o';
	
	//porta
	map [0] [17] = 'D';
	submap [0] [17] = 'D';
	
	//Portal 1
	map[10][18] = '0'; 
	submap[10][18] = '0';
	
	//Portal 2 
	map[12][12] = '0'; 
	submap[12][12] = '0';
		
	//chave
	map [2] [8] = '@';
	submap [2] [8] = '@';
	
	//player e monstros
	map [x] [y] = '&';
	map [xX] [yX] = 'X';
	map[xe][ye] = 'e';
	
	
	
	//=======================================================================================================================================================================================================
	while(life != 0){
	printf("Vida: %d\n\n", life);	
	
	//MENSAGENS DE LOGS =======================================================================================================
	if (map[x][y] == map [2][8] && map [0][17] == '='){
		printf("-- Voce pegou a chave! Corra para a porta! --");
	}


	printf("\n\n\n\n\n");
	for(i = 0; i <=19; i++){
		printf("\t\t\t\t\t  ");
		for(j = 0;j<=19; j++){
			printf("%c ", map [i] [j]);
		}
		printf("\n");
	
	}
	
	
	input = getche();
	playermove();
	monsterX();
	monstere();
	system("cls");
	
	
	if(input == 'i'){
		//Interacao chave
		if(map[x][y] == map [2][8]){
			map [0][17] ='=';
			submap [0][17] ='=';	
			submap [2][8] = ' ';	
			for(j= 15; j<=18; j++){
				map [3] [j] = ' ';
				submap [3] [j] = ' ';
			}
		}
		
		//Interacao portais			
		//funciona; volta
		if(map [x] [y] == map[12][12]){//Leva para a coordenada [10][10]
			map [x] [y] = '0';
			map[10] [10]  = '&';
			x = 10;
			y = 10;
		}
		//funciona; ida
		if(map [x] [y] == map[10][18]){//Leva para a coordenada[18][18]
			map[x][y] = '0';
			map[18][18] = '&';
			x = 18;		
		}
			
		//Interacao botoes
		if(map[x][y] == map [17][1]){
			
			map[12]	[11] = ' ';
			map[13]	[11] = ' ';
			map[13]	[12] = ' ';
			submap[12]	[11] = ' ';
			submap[13]	[11] = ' ';
			submap[13]	[12] = ' ';
			
			map[10] [17] = '#';
			map[9] [17] = '#';
			map[9] [18] = '#';
			submap[10] [17] = '#';
			submap[9] [17] = '#';
			submap[9] [18] = '#';
			
		}
		
		if(map[x][y] == map [4][14]){
			
			map[12]	[11] = '#';
			map[13]	[11] = '#';
			map[13]	[12] = '#';
			submap[12]	[11] = '#';
			submap[13]	[11] = '#';
			submap[13]	[12] = '#';
			
			map[10] [17] = ' ';
			map[9] [17] = ' ';
			map[9] [18] = ' ';
			submap[10] [17] = ' ';
			submap[9] [17] = ' ';
			submap[9] [18] = ' ';
			
		}
}
	
	
		if(map[x][y] == map[xX][yX] || submap[x][y] == '#'){

			life--;
		
			if(life == 0){
				gameover();
			}	
			
			else{
				morreu();
			}
		}
		if(map[x][y] == map[0][17]){
		fase3(); 
		}
	}
}

int fase1(){
	contfase = 1;
	x = 1;
	y = 1;	
	xX = 7;
	yX = 7;
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
	
	map [x][y] = '&';
	map [xX][xX] = 'X';
	
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
	map [7][2] = '*';
	map [8][1] = '@';
	map [8][2] = '*';
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
	

	//MECANICA DE VIDA==========================================================================================================
	while(life != 0){
	printf("Vida: %d\n\n", life);	
	
	//MENSAGENS DE LOGS =======================================================================================================
	if (map[x][y] == map [2][8] && map [0][17] == '='){
		printf("-- Voce pegou a chave! Corra para a porta! --");
	}


	printf("\n\n\n\n\n");
	for(i = 0; i <=9; i++){
		printf("\t\t\t\t\t\t");
		for(j = 0;j<=9; j++){
			printf("%c ", map [i] [j]);
		}
		printf("\n");
		
	}
	printf("\n\n\n\n\n");
	input = getche();
	playermove();
	monsterX();
	system("cls");

	if(input == 'i'){
		if(map[x][y] == map [8][1]){
			map [5][9] ='=';
			submap [5][9] ='=';	
			submap [8][1] = ' ';	
		}
	}
	
	if(map[x][y] == map[xX][yX]){
		life--;
		
		if(life == 0){
			gameover();
		}	
		else{
			morreu();
		}
	}
		
	if(map[x][y] == map [5][9]){
		fase2(); 
		}
	}
}

	
//FECHAMENTO DO JOGO ================================================================================================================================================================================
int saida(){
	system ("cls");
	printf("\n\n\n\n\t\t\t\t\t\t--Obrigado por jogar!!!--\n\n\n\n\n");
	exit(0);
	return 0;
}





//Tela inicial
int mainmenu(){
	w = 0;

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
        printf("\n\n\t\t\t\t\t\t\tA) JOGAR\n\n\t\t\t\t\t\t\tB) TUTORIAL\n\n\t\t\t\t\t\t\tC) TROCAR O TEMA\n\n\t\t\t\t\t\t\tD) SAIR\n");
        input = getche();
        system("cls");

        if (input == 'a' || input == 'A') {
        	system("cls");
        	fase1();
        }
		else if (input == 'b' || input == 'B') {
			w = 1;
			while (w == 1) {
	 			printf("\n\n\n\tW: O jogador movimenta uma unidade para cima.\n\tA: O jogador movimenta uma unidade para esquerda.\n\tS: O jogador movimenta uma unidade para baixo.\n\tD: O jogador movimenta uma unidade para direita.\n\tI: O jogador interage com o objeto que esta em cima.\n");
        		printf("\n\t'@' eh a chave.\n\t'D' eh a porta fechada.\n\t'=' eh a porta aberta.\n\t'O': Simbolo que representa um botao que o usuario pode interagir, o botao fica no chao\n\t e o jogador deve ficar em cima dele para poder interagir.");
       	 		printf("\n\t'#' eh um espinho que se vc tocar a fase reinicia.\n\t'>'eh um portal.\n\t'X' eh um monstro que possui um comportamento contrario ao do jogador.\n\t'V'eh um montro que te segue.\n\n");
       	 		printf("\t--Pressione qualquer tecla para voltar para o Menu--\n\n\t");
       	 		getch();
      	  		w = 0;
      	  		system("cls");
			}
		}
		else if (input == 'c' || input == 'C'){
			system("cls");
			w = 4;
			while(w == 4){
				printf("\t         APERTE [E] PARA MODO ESCURO E [C] PARA MODO CLARO\n");
				input = getch();
			
				if (input == 'e' || input == 'E'){//ESCURO
					system("color 06");
					printf("\n\n\t\t\t  --Tema definido para MODO ESCURO--\n\n");
				}
				if (input == 'c' || input == 'C'){//CLARO
					system("color 74");
					printf("\n\n\t\t\t  --Tema definido para MODO CLARO--\n\n");
				}
				
				printf("\n\t\t--Pressione qualquer tecla para voltar para o Menu--\n\n\t");
				getch();
				w = 0;
				system("cls");
			}
		}
	
		else if (input == 'd' || input == 'D') {
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

int main(int argc, char *argv[]) {
	srand(time(NULL));
	system("color 06");
	
	mainmenu();
	//gameover();
	//fase1();
	//fase2();
	//fase3();
	//morreu();
}
