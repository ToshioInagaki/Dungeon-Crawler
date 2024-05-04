#include <stdio.h>
#include <stdlib.h>

int main() {
    char resp;
    int w = 0;

    do {
        printf("Bem vindo ao FUJA DA ARGO\na)Jogar\nb)Tutorial\nc)Sair\n");
        scanf(" %c", &resp);
        system("cls");

        if (resp == 'a' || resp == 'A') {
            printf("Ce vai jogar fi do Bill\n");
        } else if (resp == 'b' || resp == 'B') {
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
            printf("Ce vai sair fi do Bill\n");
            return 0;
        } else {
            printf("Nada a ver irmao\n");
        }
    } while (resp != 'c' && resp != 'C');

    return 0;
}

