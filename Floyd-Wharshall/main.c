#include <stdio.h>
#include <stdlib.h>

#define INF 1000000007

int min(int n1, int n2){
    if (n1 < n2) return n1;
    else return n2;
}

void printa_matriz(int ** mat, int tam){
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            if (mat[i][j] >= INF-100){
                printf("∞\t");
            } else {
                printf("%d\t", mat[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int ** floydWharshall(int tam, int ** grafo){
    int n;
    int ** aux;
    n = tam;
    aux = grafo;
    for (int k = 0; k < n; k++){
        printf("iteração: %d\n", k);
        printa_matriz(aux, n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                aux[i][j] = min(aux[i][j], aux[i][k] + aux[k][j]);
            }
        }
    }
    return aux;
}

int main(int argc, char const *argv[]) {
    int ** grafo;
    int tam;
    scanf("%d", &tam);
    grafo = (int **) malloc(sizeof(int *)*tam);
    for (int i = 0; i < tam; i++){
        grafo[i] = (int *)malloc(sizeof(int)*tam);
        for (int j = 0; j < tam; j++){
            scanf("%d", &grafo[i][j]);
        }
    }
    grafo = floydWharshall(tam, grafo);
    printf("Iteração: %d\n", tam);
    printa_matriz(grafo,tam);
    return 0;
}
