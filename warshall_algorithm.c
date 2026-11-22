
#include <stdio.h>

void criarGrafo(int vertices, int grafo[vertices][vertices]) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            grafo[i][j] = 0;
        }
    }
}

void warshall(int vertices, int grafo[vertices][vertices]) {

    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {

                grafo[i][j] = grafo[i][j] || (grafo[i][k] && grafo[k][j]);
            }
        }

        printf("\nMatriz apos k = %d:\n", k);

        for (int l = 0; l < vertices; l++) {
            for (int m = 0; m < vertices; m++) {
                printf("%4d", grafo[l][m]);
            }
            printf("\n");
        }
    }
}

int main() {

    int vertices = 4;
    int grafo[vertices][vertices];

    criarGrafo(vertices, grafo);

    grafo[0][1] = 1;
    grafo[1][2] = 1;
    grafo[2][3] = 1;

    printf("Matriz inicial:\n");

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%4d", grafo[i][j]);
        }
        printf("\n");
    }

    warshall(vertices, grafo);

    return 0;
}
