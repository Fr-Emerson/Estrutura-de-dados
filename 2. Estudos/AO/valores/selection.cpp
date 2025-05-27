#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void randomizar(int *vet, int tam){
    srand(time(NULL));
    for (int i = 0; i < tam; i++)
    {
        vet[i] = rand() % 100;
    }
}

void trocar(int *vet, int i, int j){
    int aux;
    aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

void printar(int *vet, int tam){
    printf("\n");
    for (int i = 0; i < tam; i++)
    {
        printf("|%d|->", vet[i]);
    }
    printf("FIM\n");
}
void sort(int *lista, int tam){
    for (int i = 0; i < tam-1; i++)
    {
        int menor = i;
        for (int j = i; j < tam; j++)
        {
            if (lista[j] <   lista[menor])
            {   
                menor = j;
            }
        }
        trocar(lista, i , menor);
    }
}
int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    int tam = 10;
    int lista[tam];
    randomizar(lista,tam);
    printf("Antes do sort: \n");
    printar(lista,tam);
    printf("Depois do sort: \n");
    sort(lista, tam);
    printar(lista,tam);

    return 0;
}