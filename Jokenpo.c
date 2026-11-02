#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game (int plays) {

    int choose, aux;
    const char *moves[] = {"Rock", "Scissors", "Paper"};
    
    aux = 0;

    while (aux != plays) {

        printf("Choose one of the moves below: \n[1] Rock\t\n[2] Scissors\t\n[3] Paper\t\n>> ");
        printf("\n");
        scanf("%d", &choose);
        printf("\n");
    
        int pc_move = rand () % 3 + 1;
        printf("PC chose: %s\n", moves[pc_move - 1]);
        printf("\n");

        if (choose < 1 || choose > 3)  {
            printf("Invalid input!!\n");
        } else {
        
            if (choose == pc_move) {
        
                printf("Draw!!\n");
                printf("\n");
        
            } else if ((choose == 1 && pc_move == 2) || 
                       (choose == 2 && pc_move == 3) || 
                       (choose == 3 && pc_move == 1)) {

                printf("Player wins!!\n");
                printf("\n");
    
            } else {
        
                printf("PC wins!!\n");
                printf("\n");
            }
            aux += 1;
        }
    }
}

int main () {
    int plays;
    
    srand(time(NULL));
    
    printf("Welcome to Jokenpo game!!\t\n");

    printf("How many rounds would you like to play? \n >> ");
    scanf("%d", &plays);

    game(plays);
    
    return 0;
}
