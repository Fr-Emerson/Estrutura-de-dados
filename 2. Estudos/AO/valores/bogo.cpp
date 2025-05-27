#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
void gerar(int *vet, int tam){
    srand(time(NULL));
    for (int i = 0; i < tam; i++)
    {
        int posR = rand() % tam;
        trocar(vet, i, posR);
    }
}
bool isSorted(int* vet, int tam){
    for (int i = 0; i < tam-1; i++)
    {
        if (vet[i+1] < vet[i])
        {
            return false;
        }
    }
    return true;
}
void sort(int* vet,int tam, long long int *tries){
    while (!isSorted(vet,tam))
    {
        gerar(vet, tam);
        (*tries)++;
    }
    
}
void printar(int *vet, int tam){

    for (int i = 0; i < tam; i++)
    {
        printf("|%d|->", vet[i]);
    }
    printf("FIM\n");
}
int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    long long int tries =0;
    int tam = 5;
    int lista[tam];
    randomizar(lista,tam);
    printf("Antes do sort: \n");
    printar(lista,tam);
    printf("Depois do sort: \n");
    sort(lista,tam, &tries);
    printar(lista,tam);
    printf("Tentativas: %lld",tries);

    return 0;
}