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
void sort(int *l, int tam){
    for (int i = 1; i < tam; i++)
    {
        int key = l[i];
        int j = i-1;
        while (j >= 0 && l[j] > key)
        {
            l[j +1] = l[j];
            j--;
        }
        l[j+1] = key;
    }
}
void printar(int *vet, int tam){
    printf("\n");
    for (int i = 0; i < tam; i++)
    {
        printf("|%d|->", vet[i]);
    }
    printf("FIM\n");
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