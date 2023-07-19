/*Faça um programa que:
○ Peça para o usuário entrar com o nome e a posição (coordenadas X e Y) de N cidades e as
armazene em um vetor de estruturas (N é informado pelo usuário);
○ Crie uma matriz de distâncias entre cidades de tamanho N x N;
○ Calcule as distância entre cada duas cidades e armazene na matriz;
○ Exiba na tela a matriz de distâncias obtida;
○ Quando o usuário digitar o número de duas cidades o programa deverá retornar a
distância entre elas.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    char cidade[20];
    int x, y;
} loc_cidade;
double calcular_distancia(loc_cidade c1, loc_cidade c2) {
    int deltax, deltay;
    deltax = c2.x - c1.x;
    deltay = c2.y - c1.y;
    return sqrt(deltax * deltax + deltay * deltay);
}
int main()
{
    int n, i, j;
    printf("Digite o numero de cidades: ");
    scanf("%d", &n);
    loc_cidade *c = (loc_cidade *) malloc(n * sizeof(loc_cidade));
    if(c == NULL) {
        printf("Espaco insuficiente !!");
        exit(1);
    }
    printf("Entre com os dados das cidades: \n");
    for(i = 0; i < n; i++) {
        fflush(stdin);
        printf("\nDigite o nome da cidade %i: ", i);
        gets(c[i].cidade);
        printf("\nDigite a localizacao x: ");
        scanf("%d", &c[i].x);
        printf("\nDigite a localizacao y: ");
        scanf("%d", &c[i].y);
    }
    double **ppn;
    ppn = (double **) malloc(n * sizeof(double *));
    if(ppn == NULL) {
        printf("Espaco insuficiente !!");
        exit(1);
    }
    for(i = 0; i < n; i++) {
        ppn[i] = (double *) malloc(n * sizeof(double));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            ppn[i][j] = calcular_distancia(c[i], c[j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
           printf("%.2f\t", ppn[i][j]);
        }
        printf("\n");
    }
    int cidade1, cidade2;
    double distancia;
    printf("\nDigite o numero da cidade q deseja encontrar a distancia: ");
    scanf("%d", &cidade1);
    printf("\nDigite o numero da cidade q deseja encontrar a distancia: ");
    scanf("%d", &cidade2);
    distancia = calcular_distancia(c[cidade1], c[cidade2]);
    printf("\nA distancia entre eles eh %.2f", distancia);
    for(i = 0; i < n; i++){
        free(c[i]);
    }
    free(c);

    return 0;
}
