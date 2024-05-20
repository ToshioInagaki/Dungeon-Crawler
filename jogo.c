	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>	// Biblioteca que permite o acesso ás funções baseadas em tempo, possibilitando o uso de números randômicos
	#include <locale.h> //Biblioteca que vai permitir o suporte de caracteres da língua portuguesa


	//Variáveis globais utilizadas ao longo do código
	int w, jan = 0, i, j, x, y,xX,yX,xV,yV,xe,ye, roll, life = 3, contfase = 0, zoacaomorte;
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
				else if(submap[xX][yX] == '#' ){
					map[xX][yX] = '#';
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
				else if(submap[xX][yX] == '#' ){
					map[xX][yX] = '#';
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
				else if(submap[xX][yX] == '#' ){
					map[xX][yX] = '#';
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
				else if(submap[xX][yX] == '#' ){
					map[xX][yX] = '#';
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
		roll = 1+rand()%3;// Movimento definidos entre 1 e 2(baseado na posicao do player)
	
	//CASO O PLAYER ESTEJA A ESQUERDA DO MONSTRO	
		if(y < yV){
			//CASO ESTEJA ACIMA
			if(x < xV){
				
				if(roll == 1){
					if(map[xV-1][yV] != '*' && map[xV-1][yV] != 'D' && map[xV-1][yV] != '='){
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
						else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
						}
						else{
							map[xV][yV] = ' ';
						}
						map[xV-1][yV] = 'V';
						xV = xV - 1;
					}
					else{
						roll++;
					}
				}
				
				if(roll == 2){
					if(map[xV][yV-1] != '*' && map[xV][yV-1] != 'D' && map[xV][yV-1] != '='){
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
						else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
						}
						else{
							map[xV][yV] = ' ';
						}
						
						map[xV][yV-1] = 'V';
						yV = yV - 1;
					}
					else{
						roll--;
					}
				}
			}
			//CASO ESTEJA ABAIXO
			else if(x > xV){
				if(roll == 1){
					if(map[xV+1][yV] != '*' && map[xV+1][yV] != 'D' && map[xV+1][yV] != '='){
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
						else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
						}
						else{
							map[xV][yV] = ' ';
						}
						map[xV+1][yV] = 'V';
						xV = xV + 1;
					}
					else{
						roll++;
					}
				}
				if(roll == 2){
					if(map[xV][yV-1] != '*' && map[xV][yV-1] != 'D' && map[xV][yV-1] != '='){
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
						else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
						}
						else{
							map[xV][yV] = ' ';
						}
						map[xV][yV-1] = 'V';
						yV = yV - 1;
					}
					else{
						roll--;
					}
				}
			}
			else{
				if(map[xV][yV-1] != '*' && map[xV][yV-1] != 'D' && map[xV][yV-1] != '='){
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
						else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
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
			//CASO PLAYER ESTEJA ACIMA
			if(x < xV){
				if(roll == 1){
					if(map[xV-1][yV] != '*' && map[xV-1][yV] != 'D' && map[xV-1][yV] != '='){
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
						else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
						}
						else{
							map[xV][yV] = ' ';
						}
						map[xV-1][yV] = 'V';
						xV = xV - 1;
					}
					else{
						roll++;
					}
				}
				
				if(roll == 2){
					if(map[xV][yV+1] != '*' && map[xV][yV+1] != 'D' && map[xV][yV+1] != '='){
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
						else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
						}
						else{
							map[xV][yV] = ' ';
						}
						map[xV][yV+1] = 'V';
						yV = yV + 1;
					}
					else{
						roll--;
					}
				}
			}
			//CASO PLAYER ESTEJA ABAIXO
			else if(x > xV){
				if(roll == 1){
					if(map[xV+1][yV] != '*' && map[xV+1][yV] != 'D' && map[xV-1][yV] != '='){
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
						else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
						}
						else{
							map[xV][yV] = ' ';
						}
						map[xV+1][yV] = 'V';
						xV = xV + 1;
					}
					else{
						roll++;
					}
				}
				if(roll == 2){
					if(map[xV][yV+1] != '*' && map[xV][yV+1] != 'D' && map[xV][yV+1] != '='){
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
						else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
						}
						else{
							map[xV][yV] = ' ';
						}
						map[xV][yV+1] = 'V';
						yV = yV + 1;
					}
					else{
						roll--;
					}
				}
			}
			else{
				if(map[xV][yV+1] != '*' && map[xV][yV+1] != 'D' && map[xV][yV+1] != '='){
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
						else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
						}
						else{
							map[xV][yV] = ' ';
						}
						map[xV][yV+1] = 'V';
						yV = yV + 1;
				}
			}
		}
	//CASO O PLAYER ESTEJA DIRETAMENTE ACIMA OU ABAIXO DO MONSTRO
		else if(y == yV){
			//PLAYER ACIMA
			if(x > xV){
				if(map[xV+1][yV] != '*' && map[xV+1][yV] != 'D' && map[xV+1][yV] != '='){
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
					else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
					}
					else{
						map[xV][yV] = ' ';
					}
					map[xV+1][yV] = 'V';
					xV = xV + 1;
				}
			}
			//PLAYER ABAIXO
			else if(x < xV){
				if(map[xV-1][yV] != '*' && map[xV-1][yV] != 'D' && map[xV-1][yV] != '='){
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
					else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
					}
					else if(submap[xV][yV] == '#' ){
							map[xV][yV] = '#';
						}
					else{
						map[xV][yV] = ' ';
					}
					map[xV-1][yV] = 'V';
					xV = xV - 1;
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
				else if(submap[xe][ye] == '0' ){
					map[xe][ye] = '0';
				}
				else if(submap[xe][ye] == 'o' ){
					map[xe][ye] = 'o';
				}
				else if(submap[xe][ye] == '#' ){
					submap[xe][ye] = '#';
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
				else if(submap[xe][ye] == '0' ){
					map[xe][ye] = '0';
				}
				else if(submap[xe][ye] == 'o' ){
					map[xe][ye] = 'o';
				}
				else if(submap[xe][ye] == '#' ){
					submap[xe][ye] = '#';
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
				else if(submap[xe][ye] == '0' ){
					map[xe][ye] = '0';
				}
				else if(submap[xe][ye] == 'o' ){
					map[xe][ye] = 'o';
				}
				else if(submap[xe][ye] == '#' ){
					submap[xe][ye] = '#';
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
				else if(submap[xe][ye] == '0' ){
					map[xe][ye] = '0';
				}
				else if(submap[xe][ye] == 'o' ){
					map[xe][ye] = 'o';
				}
				else if(submap[xe][ye] == '#' ){
					submap[xe][ye] = '#';
				}
				else{
					map[xe][ye] = ' ';
				}
				map[xe][ye-1] = 'e';
		 		ye = ye - 1;
			}
		}
	}
	
	void playermove(){//MECANICA DE MOVIMENTO DO PLAYER
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
				else if(map[x][y] == '#'  ){
					map[x][y] = '#';
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
				else if(map[x][y] == '#' ){
					map[x][y] = '#';
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
				else if(map[x][y] == '#' ){
					map[x][y] = '#';
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
				else if(map[x][y] == '#' ){
					map[x][y] = '#';
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
		printf("\t\t\t\t\t                              _____              __  __   ______      ____   __      __  ______   _____  \n");
		printf("\t\t\t\t\t                             / ____|     /\\     |  \\/  | |  ____|    / __ \\  \\ \\    / / |  ____| |  __ \\ \n");
		printf("\t\t\t\t\t                            | |  __     /  \\    | \\  / | | |__      | |  | |  \\ \\  / /  | |__    | |__) |\n");
		printf("\t\t\t\t\t                            | | |_ |   / /\\ \\   | |\\/| | |  __|     | |  | |   \\ \\/ /   |  __|   |  _  / \n");
		printf("\t\t\t\t\t                            | |__| |  / ____ \\  | |  | | | |____    | |__| |    \\  /    | |____  | | \\ \\ \n");
		printf("\t\t\t\t\t                             \\_____| /_/    \\_\\ |_|  |_| |______|    \\____/      \\/     |______| |_|  \\_\\\n");
		printf("\t\t\t\t\t                                                                                                          \n");
		printf("\t\t\t\t\t                                                                                                          \n");
	  	printf(" \n\n\n\n\t\t\t\t  Parece que os monstros estão se divertindo a sua custa. Será que você é realmente tão ruim em fugir? Talvez seja hora de aceitar o seu destino...\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t           --PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU--\n");
	  	getch();
		w = 0;
		life = 3;
		contfase = 0;
		system("cls");
		mainmenu();
	}
	
	void ending(){
		system("cls");
		printf("\nApós escapar da Argo, Serruya comemora sua liberdade com bebidas e fortune dragon, pois o tigrinho não esta pagando. No entanto, à medida\nque a luz do dia comeca a raiar,  Serruya tem um momento de lucidez e se lembra que faltam poucas horas para a aula da Alessandra, sua\nprofessora mais temida. Serruya passa mal só de imaginar o olhar desapontado da professora ao descobrir sua ausência.\n");
		getch();
		//system("cls");
		printf("\nEnquanto a festança acontecia ao seu redor, Serruya percebe que, apesar de ter conseguido sobreviver, ainda existiam responsabilidades que\no aguardavam. ");
		printf("Ele respira fundo e vai para a faculdade, com ressaca e triste por ter perdido todo o seu dinheiro apostando.\n");
		getch();
		//system("cls");
		printf("\nDurante a aula da Alessandra, Serruya tentou acompanhar a explicação sobre números binários, porém, sucumbiu ao cansaço novamente...\n");
		getch();
		//system("cls");
		printf("\nO resto é historia.\n");
	    getch();
		system("cls");
		
		
		printf("\t\t\t\t\t                                                 ______ _____ __  __             ___   \n");
		printf("\t\t\t\t\t                                                |  ____|_   _|  \\/  |           |__ \\  \n");
		printf("\t\t\t\t\t                                                | |__    | | | \\  / |              ) | \n");
		printf("\t\t\t\t\t                                                |  __|   | | | |\\/| |             / /  \n");
		printf("\t\t\t\t\t                                                | |     _| |_| |  | |_   _   _   |_|   \n");
		printf("\t\t\t\t\t                                                |_|    |_____|_|  |_(_) (_) (_)  (_)   \n");
	  	printf(" \n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t          Obrigado por jogar!\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t         --PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU--\n");
	  	getch();
		w = 0;
		life = 3;
		contfase = 0;
		system("cls");
		mainmenu();
	}
	
	void morreu(){
		zoacaomorte = 1+rand() % 3;
		system("cls");
		
	    printf("\t\t\t\t\t                             __      ______   _____ ______   __  __  ____  _____  _____  ______ _    _ \n");
	    printf("\t\t\t\t\t                             \\ \\    / / __ \\ / ____|  ____| |  \\/  |/ __ \\|  __ \\|  __ \\|  ____| |  | |\n");
	    printf("\t\t\t\t\t                              \\ \\  / / |  | | |    | |__    | \\  / | |  | | |__) | |__) | |__  | |  | |\n");
	    printf("\t\t\t\t\t                               \\ \\/ /| |  | | |    |  __|   | |\\/| | |  | |  _  /|  _  /|  __| | |  | |\n");
	    printf("\t\t\t\t\t                                \\  / | |__| | |____| |____  | |  | | |__| | | \\ \\| | \\ \\| |____| |__| |\n");
	    printf("\t\t\t\t\t                                 \\/   \\____/ \\_____|______| |_|  |_|\\____/|_|  \\_\\_|  \\_\\______|\\____/ \n");
	    printf("\t\t\t\t\t                                                                                                        \n");
	    if(zoacaomorte == 1){
	    	printf(" \n\n\n\n\t\t\t\t\t\t\t\t\t\t\t            Tá bebado, Pai?\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t          -- APERTE QUALQUER BOTAO PARA TENTAR DE NOVO --\n");
	    	
		}
		
		if(zoacaomorte == 2){
			printf(" \n\n\n\n\t\t\t\t\t\t\t\t\t\t\t         Tranca o curso, irmão.\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t          -- APERTE QUALQUER BOTAO PARA TENTAR DE NOVO --\n");
	    	
		}
		
		if(zoacaomorte == 3){
			printf(" \n\n\n\n\t\t\t\t\t\t\t\t\t           Pra apostar tavas bem, agora pra sobreviver...\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t          -- APERTE QUALQUER BOTAO PARA TENTAR DE NOVO --\n");
	    	
		}
		
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
	
	
//FASE 3 ================================================================================================================================================================================
	int fase3(){
		contfase = 3;
		int keyportal = 0;
		int area = 3;
	
		//area 1
		x = 38;
		y = 1;
		xX = 32;
		yX = 9;	
		xe = 31;
		ye = 34;
		xV = 35;
		yV = 34;
		
		
		//area 2
//		x = 17;
//		y = 8;

		//area 3
/*		x = 11;
		y = 32;
		xX = 17;
		yX = 20;
		xe = 1;
		ye = 20;
		xV = 1;
		yV = 19;*/
//==================================================

		

		
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
		


		//PAREDES INTERNAS DE ESPINHO =======================================================================================================
		
		for(j =1; j<= 38 ; j++){
			map [13] [j] = '#';
			submap [13] [j] = '#';
				if(j>=15 && j<=24){
				map [13] [j] = ' ';	
				submap [13] [j] = ' '; //APENAS SE o monstro sumir na cordenada dessa linha especifica, o problema ta aq (declaração do sub)
				}
		}
		
		for(j =1; j<= 38 ; j++){
			map [26] [j] = '#';
			submap [26] [j] = '#';
				if(j>=15 && j<=24){
				map [26] [j] = ' ';
				submap [26] [j] = ' ';	//APENAS SE o monstro sumir na cordenada dessa linha especifica, o problema ta aq (declaração do sub)
			}
		}
	
		for(i = 14 ; i <= 18; i++){
			map [i] [14] = '#';
			submap [i] [14] = '#';
		
		}
		
		for(i =  14; i <= 18; i++){
			map [i] [25] = '#';
			submap [i] [25] = '#';
		
		}
		
		for(i = 1 ; i <= 5; i++){
			map [i] [14] = '#';
			submap [i] [14] = '#';
		
		}
		
		for(i = 1 ; i <= 5; i++){
			map [i] [25] = '#';
			submap [i] [25] = '#';
		
		}
	
		for(i = 27; i <= 31; i++){
			map [i] [14] = '#';
			submap [i] [14] = '#';
		
		}
		
		for(i = 27 ; i <= 31; i++){
			map [i] [25] = '#';
			submap [i] [25] = '#';
		
		}
		
		for( j = 15; j <= 24; j++){
			map [18] [j] = '#';
			submap [18] [j] = '#';
		}
		
		for( j = 15; j <= 24; j++){
			map [31] [j] = '#';
			submap [31] [j] = '#';
		}
		
		for( j = 15; j <= 24; j++){
			map [5] [j] = '#';
			submap [5] [j] = '#';
			if(j >=19 && j<=20){
			map [5] [j] = ' ';
			submap [5] [j] = ' ';  //APENAS SE o monstro sumir na cordenada dessa linha especifica, o problema ta aq (declaração do sub)
			}
		}
		
		//PORTAIS========================================================================================
		
		/*IDA ANDAR 1/2*/ map [38] [38] = '0'; submap [38][38] = '0';
		
		/*IDA ANDAR 2/3 */ map [17][13] = '0'; submap [17][13] = '0';
		
	
		
		
		//PORTA====================================================================================================
		map[0] [19] = 'D'; submap[0] [19] = 'D';
		map[0] [20] = 'D'; submap[0] [20] = 'D';
		
		//CHAVE===================================================================================================
		
		map[1] [1] = '@'; submap[1] [1] = '@';
		
		//BOTOES=================================================================================================
		
		map [27][2] = 'o'; submap [27][2] = 'o';
		map [16][37] = 'o'; submap [16][37] = 'o';
		
		//ESPINHOS===============================================================================================
		
		//AREA 1=========================================================================================================================
		map[29][28] = '#'; submap[29][28] = '#';
		map[27][30] = '#'; submap[27][30] = '#';
		map[29][32] = '#'; submap[29][32] = '#';
		map[27][34] = '#'; submap[27][34] = '#';
		map[29][36] = '#'; submap[29][36] = '#';
	
	
		for(j = 28; j <= 35;j++){
			map[30][j] = '#'; submap[30][j] = '#';
		}
		for(i = 31; i <= 38;i++){
			map[i][35] = '#'; submap[i][35] = '#';
		}
		
		for(i = 33; i <= 37; i++){
			for(j = 22; j <= 25; j++){
				map[i][j] = '#'; submap[i][j] = '#';
			}
		}
		for(i = 34; i <= 36; i++){
			for(j = 23; j <= 24; j++){
				map[i][j] = ' ';submap[i][j] = ' ';
			}
		}
		
		
		
		for(i = 33; i <= 37; i++){
			for(j = 19; j <= 20; j++){
				map[i][j] = '#'; submap[i][j] = '#';
			}
		}
				
			
		for(i = 35; i <= 36; i++){
			for(j = 4; j <= 11; j++){
				map[i][j] = '#'; submap[i][j] = '#';
			}
		}

		
		for(i = 29; i <= 34;i++){
			map[i][11] = '#'; submap[i][11] = '#';
		}
		for(j = 4; j <= 10;j++){
			map[29][j] = '#'; submap[29][j] = '#';
		}
		
		
		for(i = 33; i <= 37; i++){
			for(j = 14; j <= 17; j++){
				map[i][j] = '#'; submap[i][j] = '#';
			}
		}
		for(i = 34; i <= 36; i++){
			for(j = 15; j <= 16; j++){
				map[i][j] = ' ';submap[i][j] = ' ';
			}
		}


		for(i = 31; i <= 33; i++){
			for(j = 1; j <= 6; j++){
				map[i][j] = '#'; submap[i][j] = '#';
			}
		}
		for(j = 1; j <= 5; j++){
				map[32][j] = ' ';submap[32][j] = ' ';
		}
		
		//AREA 2=========================================================================================================================
		map[18][13] = '#'; submap[18][13] = '#';
	
		for(i = 15; i <= 18;i++){
			map[i][12] = '#'; submap[i][12] = '#';
		}
		
		for(j = 4; j <= 11; j++){
			map[15][j] = '#'; submap[15][j] = '#';
		}

		for(i = 16; i <= 20; i++){
			map[i][4] = '#'; submap[i][4] = '#';
		}
		
		map[20][4] = '#'; submap[20][4] = '#';
		
		for(i = 20; i <= 23; i++){
			map[i][3] = '#'; submap[i][3] = '#';
		}
		
		map[15][3] = '#'; submap[15][3] = '#';
		map[16][2] = '#'; submap[16][2] = '#';
		map[18][2] = '#'; submap[18][2] = '#';
		map[18][1] = '#'; submap[18][1] = '#';
		map[20][2] = '#'; submap[20][2] = '#';
		
		for(i = 19; i <= 25; i++){
			for(j = 19; j <= 20; j++){
				map[i][j] = '#'; submap[i][j] = '#';
			}
		}
		
		for(j = 17; j <= 22; j++){
			map[26][j] = '#'; submap[26][j] = '#';
		}
		
		for(j = 31; j <= 37; j++){
			map[15][j] = '#'; submap[15][j] = '#';
		}
		
		
		for(i = 15; i <= 18; i++){
			map[i][27] = '#'; submap[i][27] = '#';
		}
		
		for(j = 28; j <= 31; j++){
			map[18][j] = '#'; submap[18][j] = '#';
		}
		
		 
		map[16][31] = '#'; submap[16][31] = '#';
		map[17][31] = '#'; submap[17][31] = '#';
		
		map[16][36] = '#'; submap[16][36] = '#';
		
		for(j = 36; j <= 38; j++){
			map[17][j] = '#'; submap[17][j] = '#';
		}
		
		for(j = 6; j <= 10; j++){
			map[18][j] = '#'; submap[18][j] = '#';
		}
		
		map[23][4] = '#'; submap[23][4] = '#';
		map[22][5] = '#'; submap[22][5] = '#';
		map[22][6] = '#'; submap[22][6] = '#';
		map[24][6] = '#'; submap[24][6] = '#';
		map[23][8] = '#'; submap[23][8] = '#';
		map[25][5] = '#'; submap[25][5] = '#';
		
		map[21][9] = '#'; submap[21][9] = '#';
		map[22][11] = '#'; submap[22][11] = '#';
		map[24][11] = '#'; submap[24][11] = '#';
		map[23][14] = '#'; submap[23][14] = '#';
		map[21][15] = '#'; submap[21][15] = '#';
		map[22][17] = '#'; submap[22][17] = '#';
		map[27][18] = '#'; submap[27][18] = '#';
		map[28][19] = '#'; submap[28][19] = '#';
		map[28][20] = '#'; submap[28][20] = '#';
		map[28][22] = '#'; submap[28][22] = '#';
		map[29][23] = '#'; submap[29][23] = '#';
		map[30][20] = '#'; submap[30][20] = '#';
		map[29][17] = '#'; submap[29][17] = '#';
		map[28][15] = '#'; submap[28][15] = '#';
		
		map[19][25] = '#'; submap[19][25] = '#';
		map[20][26] = '#'; submap[20][26] = '#';
		
		for(i = 21; i <= 24; i++){
			for(j = 24; j <= 27; j++){
				map[i][j] = '#'; submap[i][j] = '#';
			}
		}
		for(i = 22; i <= 23; i++){
			for(j = 25; j <= 26; j++){
				map[i][j] = ' ';
			}
		}
		
		map[21][28] = '#'; submap[21][28] = '#';
		map[22][29] = '#'; submap[22][29] = '#';
		map[19][25] = '#'; submap[19][25] = '#'; 
		
		map[22][31] = '#'; submap[22][31] = '#';
		map[23][30] = '#'; submap[23][30] = '#';
		map[24][29] = '#'; submap[24][29] = '#';
		map[21][32] = '#'; submap[21][32] = '#';
		map[20][33] = '#'; submap[20][33] = '#';
		map[19][33] = '#'; submap[19][33] = '#';
		
		map[19][36] = '#'; submap[19][36] = '#';
		map[20][36] = '#'; submap[20][36] = '#';
		map[21][36] = '#'; submap[21][36] = '#';
		map[22][35] = '#'; submap[22][35] = '#';
		map[23][34] = '#'; submap[23][34] = '#';
		map[24][33] = '#'; submap[24][33] = '#';
		map[25][32] = '#'; submap[25][32] = '#';
		//AREA 3=========================================================================================================================
		
		for(j = 2; j<= 5; j++){
			map [5] [j] = '#'; submap [5] [j] = '#';
		}
		
		for(j = 2; j<= 5; j++){
			map [10] [j] = '#'; submap [10] [j] = '#';
		}
		
		for(j = 5; j<= 8; j++){
			map [2] [j] = '#'; submap [2] [j] = '#';
		}
		
		for(j = 25; j<= 31; j++){
			map [8] [j] = '#'; submap [8] [j] = '#';
		}
		
		for(j = 28; j<= 37; j++){
			map [2] [j] = '#'; submap [2] [j] = '#';
		}
		
		for(j = 28; j<= 37; j++){
			map [10] [j] = '#'; submap [10] [j] = '#';
		}
		
		for(j = 34; j<= 38; j++){
			map [7] [j] = '#'; submap [7] [j] = '#';
		}
		
		for(j = 31; j<= 34; j++){
			map [5] [j] = '#'; submap [5] [j] = '#';
		}
		
		for(i = 2; i <= 5; i++){
			map [i] [2] = '#'; submap [i] [2] = '#';
		}
		
		for(i = 5; i <= 10; i++){
			map [i] [5] = '#'; submap [i] [5] = '#';
		}
		
		for(i = 2; i <= 12; i++){
			map [i] [8] = '#'; submap [i] [8] = '#';
		}
		
		for(i = 2; i <= 10; i++){
			map [i] [11] = '#'; submap [i] [11] = '#';
		}
		
		for(i = 8; i <= 12; i++){
			map [i] [14] = '#'; submap [i] [14] = '#';
		}
		
		for(i = 5; i <= 13; i++){
			map [i] [18] = '#'; submap [i] [18] = '#';
		}
		
		for(i = 5; i <= 13; i++){
			map [i] [21] = '#'; submap [i] [21] = '#';
		}
		
		for(i = 8; i <= 12; i++){
			map [i] [25] = '#'; submap [i] [25] = '#';
		}
		
		for(i = 2; i <= 7; i++){
			map [i] [28] = '#'; submap [i] [28] = '#';
		}
		
		for(i = 2; i <= 4; i++){
			map [i] [37] = '#'; submap [i] [37] = '#';
		}
		
		for(i = 5; i <= 7; i++){
			map [i] [34] = '#'; submap [i] [34] = '#';
		}
		
		
		
		
		
		//player e monstro
		map[x][y] = '&';
		map[xX][yX] = 'X';
		map[xe][ye] = 'e';
		map [xV][yV] = 'V';

		
		
		//==========================================================================================================
		while(life != 0){
		printf("\n\t\t\t\t\t\t\t\t\t\t\t\t       Vida: %d\n\n", life);	
		printf("\t\t\t\t\t\t\t\t\t\t\t\t       [%d][%d]\n\n\n",x,y);
		
		//MENSAGENS DE LOGS =======================================================================================================
		if(input == 'i'){
			if (map[x][y] == map [1][1] && map [0][19] == '=' && map [0][20] == '='){
				printf("\t\t\t\t\t\t\t\t\t\t  -- Voce pegou a chave! Corra para a porta! --");
			}
			
			
			if(map [x] [y] == map[38][38] && keyportal == 0){
				printf("\t\t\t\t\t\t\t\t\t\t   -- Aperte o botao para desbloquear o portal! --");
			}
			
			if(map [x] [y] == map[17][13] && keyportal == 0){
				printf("\t\t\t\t\t\t\t\t\t\t   -- Aperte o botao para desbloquear o portal! --");
				
			}
			
			if(map [x] [y] == map[27][2] && keyportal == 1){
				printf("\t\t\t\t\t\t\t\t\t\t\t  -- Voce desbloqueou o portal! --");
				
			}
			
			if(map [x] [y] == map[16][37] && keyportal == 1){
				printf("\t\t\t\t\t\t\t\t\t\t\t  -- Voce desbloqueou o portal! --");
				
			}
		}
		
		//DESENHO DO MAPA=================================================================================================
	
		printf("\n\n\n");
		for(i = 0; i <=39; i++){
			printf("\t\t\t\t\t\t\t\t   ");
			for(j = 0;j<=39; j++){
				printf("%c ", map [i][j]);
			}
			printf("\n");
		
		}
	
	
		input = getche();
		playermove();

		monsterV();
		monsterX();
		monstere();

		system("cls");
		
		//autokill
		if(input == 'k'){
			map[x][y] = '#'; submap[x][y] = '#';
		}
		if(input == 'i'){
			//INTERACAO CHAVE
			
			if(map[x][y] == map [1][1]){
				map [0][19] ='='; submap [0][19] ='=';
				map [0][20] ='='; submap [0][20] ='=';	
				submap [1][1] = ' ';	
			}
			
			
			
			//INTERACAO PORTAIS	
				
			//IDA 1/2
			if(map [x] [y] == map[38][38] && keyportal == 1){//Leva para a coordenada [24][6]
				map[x][y] = '0';
				map[xV][yV] = ' ';
				map[xX][yX] = ' ';
				map[xe][ye] = ' ';
				map[17][8]  = '&';
				map[14][1]  = 'V';
				map[23][12] = 'X';
				map[25][37]  = 'e';
				x = 17;
				y = 8;
				xV = 14;
				yV = 1;
				xX = 23;
				yX = 12;
				xe = 25;
				ye = 37;
				keyportal = 0;
				area = 2;
			}
			
			//IDA 2/3
			if(map [x] [y] == map[17][13] && keyportal == 1){//Leva para a coordenada[11][6]
				map[x][y] = '0';
				map[xV][yV] = ' ';
				map[xX][yX] = ' ';
				map[xe][ye] = ' ';
				map[11][32]  = '&';
				map[1][19]  = 'V';
				map[1][20]  = 'e';
				map[17][20]  = 'X';
				x = 11;
				y = 32;
				xX = 17;
				yX = 20;
				xe = 1;
				ye = 20;
				xV = 1;
				yV = 19;
				keyportal = 0;
				area = 3;
			}
				
			//Interacao botoes
			if(map[x][y] == map[27][2]){ //LIBERA PORTAL 1/2
				keyportal = 1;
			}
			
			if(map[x][y] == map [16][37]){ //LIBERA PORTAL 2/3
				keyportal = 1;
				map[17] [38] = ' '; submap[17] [38] = ' ';
				map[25] [32] = ' '; submap[25] [32] = ' ';
				
			}
	}
		
		
		if(map[x][y] == map[xV][yV] || map[x][y] == map[xe][ye] || map[x][y] == map[xX][yX] || submap[x][y] == '#'){
			
			life--;
			
			if(life == 0){
				gameover();
			}	
			
			else{
				morreu();
			}
		}
		
		
		if(map[x][y] == map[0][19] || map[x][y] == map[0][20]){
			ending();
			}
		
		
		
		}
	}
	
	
	//FASE 2==================================================================================================================================================================================
	int fase2(){
		int move = 0;
		int getkey = 0;
		contfase=2;
		x = 1;
		y = 12;
		xX = 15;
		yX = 13;
		xe = 2;
		ye = 18;
		
		//PAREDE======================================================================================================================================================================================================
		for(i =0 ; i<=19; i++){
			for(j = 0; j<= 19; j++){
				map[i] [j] = '*';
			}
		}
		
		for(i =1 ; i<=18; i++){
			for(j = 1; j<= 18; j++){
				map[i] [j] = ' ';
				submap[i] [j] = ' ';
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
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t       Vida: %d\n\n", life);	
		printf("\t\t\t\t\t\t\t\t\t\t\t\t       [%d][%d]\n\n\n",x,y);	
		
		//MENSAGENS DE LOGS =======================================================================================================
		if (map[x][y] == map [2][8] && map [0][17] == '='){
			printf("\t\t\t\t\t\t\t\t\t             -- Voce pegou a chave! Corra para a porta! --");
		}
	
	
		printf("\n\n\n\n");
		for(i = 0; i <=19; i++){
			printf("\t\t\t\t\t\t\t\t\t\t        ");
			for(j = 0;j<=19; j++){
				printf("%c ", map [i] [j]);
			}
			printf("\n");
		
		}
		
	
	
		
		input = getche();
		playermove();
		monsterX();
		if (move == 1){
			monstere();
		}
		
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
				getkey = 1;
			}
			
			//Interacao portais			
			//funciona; volta
			if(map [x] [y] == map[12][12]){//Leva para a coordenada [10][10]
				map [x] [y] = '0';
				map[10] [10]  = '&';
				x = 10;
				y = 10;
				if(getkey = 1){
					move = 1;
				}
			}
			//funciona; ida
			if(map [x] [y] == map[10][18]){//Leva para a coordenada[18][18]
				map[x][y] = '0';
				map[18][18] = '&';
				x = 18;		
				move = 0;
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
		
		
			if(map[x][y] == map[xX][yX] || submap[x][y] == '#' || map[x][y] == map[xe][ye]){
	
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
				submap[i][j] = ' ';
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
		
	
	
		//==========================================================================================================
		while(life != 0){
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t       Vida: %d\n\n", life);	
		printf("\t\t\t\t\t\t\t\t\t\t\t\t       [%d][%d]\n\n\n",x,y);		
		
		//MENSAGENS DE LOGS=======================================================================================================
		if (map[x][y] == map [8][1] && map [5][9] == '='){
			printf("\t\t\t\t\t\t\t\t\t            -- Voce pegou a chave! Corra para a porta! --");
		}
	
	
		printf("\n\n\n\n");
		for(i = 0; i <=9; i++){
			printf("\t\t\t\t\t\t\t\t\t\t\t         ");
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
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t      --Obrigado por jogar!!!--\n\n\n\n\n");
		exit(0);
		return 0;
	}
	
	
	
	
	
	//Tela inicial
	int mainmenu(){
		w = 0;
		
	    do {
	    	system("cls");
	  	    printf("\t\t\t\t\t                  ______   _    _        _                _____                            _____     _____    ____  \n");
	    	printf("\t\t\t\t\t                 |  ____| | |  | |      | |     /\\       |  __ \\      /\\           /\\     |  __ \\   / ____|  / __ \\ \n");
	    	printf("\t\t\t\t\t                 | |__    | |  | |      | |    /  \\      | |  | |    /  \\         /  \\    | |__) | | |  __  | |  | |\n");
	    	printf("\t\t\t\t\t                 |  __|   | |  | |  _   | |   / /\\ \\     | |  | |   / /\\ \\       / /\\ \\   |  _  /  | | |_ | | |  | |\n");
	    	printf("\t\t\t\t\t                 | |      | |__| | | |__| |  / ____ \\    | |__| |  / ____ \\     / ____ \\  | | \\ \\  | |__| | | |__| |\n");
	    	printf("\t\t\t\t\t                 |_|       \\____/   \\____/  /_/    \\_\\   |_____/  /_/    \\_\\   /_/    \\_\\ |_|  \\_\\  \\_____|  \\____/ \n");
	    	printf("\t\t\t\t\t                                                                                                                     \n");
	    	printf("\t\t\t\t\t                                                                                                                     \n");
	        printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t    A) JOGAR\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t    B) TUTORIAL\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t    C) TROCAR O TEMA\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t    D) SAIR\n");
	        input = getche();
	        system("cls");
	
	        if (input == 'a' || input == 'A') {
	        	system("cls");
	        	fase1();
	        }
			else if (input == 'b' || input == 'B') {
				w = 1;
				while (w == 1) {
		 			printf("\n\n\n\t\t\t\t\t\t\t\t\t\tW: O jogador movimenta uma unidade para cima.\n\n\n\t\t\t\t\t\t\t\t\t\tA: O jogador movimenta uma unidade para esquerda.\\n\n\n\t\t\t\t\t\t\t\t\t\tS: O jogador movimenta uma unidade para baixo.\n\n\n\t\t\t\t\t\t\t\t\t\tD: O jogador movimenta uma unidade para direita.\n\n\n\t\t\t\t\t\t\t\t\t\tI: O jogador interage com o objeto que esta em cima.");
	        		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t@ : Chave.\n\n\n\t\t\t\t\t\t\t\t\t\tD : Porta fechada.\n\n\n\t\t\t\t\t\t\t\t\t\t= : Porta aberta.\n\n\n\t\t\t\t\t\t\t\t\t\to : Botão que o player pode interagir.\n\n\n\t\t\t\t\t\t\t\t\t\t0 : Portal.");
	       	 		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t# : Espinho que mata o player ao encostrar nele, reiniciando a fase.\n\n\n\t\t\t\t\t\t\t\t\t\tX : Monstro que se move aleatoriamente pelo mapa.\n\n\n\t\t\t\t\t\t\t\t\t\te : Monstro que possui um comportamento contrário ao do jogador.\n\n\n\t\t\t\t\t\t\t\t\t\tV : Monstro que te segue.\n\n\n\n\n");
	       	 		printf("\t\t\t\t\t\t\t\t\t\t--Pressione qualquer tecla para voltar para o Menu--\n\n\t");
	       	 		getch();
	      	  		w = 0;
	      	  		system("cls");
				}
			}
			else if (input == 'c' || input == 'C'){
				system("cls");
				w = 4;
				while(w == 4){
					printf("\n\t\t\t\t\t\t\t\t                  APERTE [E] PARA MODO ESCURO E [C] PARA MODO CLARO\n");
					input = getch();
				
					if (input == 'e' || input == 'E'){//ESCURO
						system("color 06");
						printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t          --Tema definido para MODO ESCURO--\n\n");
					}
					if (input == 'c' || input == 'C'){//CLARO
						system("color 74");
						printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t          --Tema definido para MODO CLARO--\n\n");
					}
					
					printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t         --Pressione qualquer tecla para voltar para o Menu--\n\n\t");
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
	
	void textoinicial(){
		printf("\nSerruya, um estudante universitário qualquer, estava lutando para se manter acordado durante a aula de segunda-feira de manhã. Na noite anterior, ele tinha\npassado horas e horas apostando no tigrinho, perdendo a noção do tempo enquanto a adrenalina corria solta.\n");
		getch();
		//system("cls");
		printf("\nOs olhos de Serruya piscavam lentamente enquanto ele tentava acompanhar as palavras do professor.  Mas, contra todas as probabilidades, ele sucumbe ao\ncansaço e afunda em um sono profundo.\n");
		getch();
		//system("cls");
		printf("\nQuando ele finalmente desperta, não se ve rodeado pela luz suave da manhã, mas sim pelo obscuro breu que o cerca. Confuso e atordoado,  ele percebe que está\nsozinho na sala de aula.\n");
		getch();
		//system("cls");
		printf("\nSerruya se levanta. Sua mente turva tenta entender o que havia ocorrido. Ele tenta acender as luzes, mas nada acontece. Um calafrio percorre sua espinha\nquando ele percebe que está preso na escuridão da Argo.\n");
		getch();
		//system("cls");
		printf("\nEnquanto avança pelos corredores desertos, uma sensação de terror cresce dentro de Serruya, até que ele finalmente percebe a verdade horripilante: \nOs professores não são o que parecem. Eles são monstros disfarçados, criaturas que assumiram a forma dos educadores da faculdade para atrair e capturar\nestudantes desavisados.\n");
		getch();
		//system("cls");
		printf("\nCom o coração batendo freneticamente, Serruya percebe que sua única chance de escapar é evitando as criaturas e encontrando uma saída da faculdade, antes\nque seja tarde demais...\n");
		getch();
		//system("cls");
		printf("\nVocê tem que e evitar os monstros e escapar da Argo em segurança.\n");
		getch();
	}
	int main(int argc, char *argv[]) {
		srand(time(NULL));
		
		setlocale(LC_ALL, "Portuguese");
		system("color 6");
		//system("color F4");
		
		textoinicial();
		mainmenu();
		//gameover();
		//fase1();
		//fase2();
		//fase3();
		//morreu();
		//ending();
	}
