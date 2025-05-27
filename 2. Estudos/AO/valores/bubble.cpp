#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void randomizar(int *vet, int tam){
    srand(time(NULL));
    for (int i = 0; i < tam; i++)
    {
        vet[i] = rand() % 100;
    }
}
void ordernar(int *vet, int tam, int *trocas)
{
    int aux;
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam - (i + 1); j++){
            if (vet[j + 1] < vet[j]){
                aux = vet[j + 1];
                vet[j + 1] = vet[j];
                vet[j] = aux;
                *trocas += 1;
            }
            if (trocas == 0)
            {
                return;
            }
        }
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
int main(int argc, char *const _argv[])
{
    system("chcp 65001");
    system("cls");
    int trocas = 0;
    int tam;
    printf("Digite um valor: \n");
    scanf("%d", &tam);
    int vet[tam];
    randomizar(vet,tam);
    printf("ANTES DA TROCA\n");
    printar(vet,tam);
    ordernar(vet, tam, &trocas);
    printf("\nDEPOIS DA TROCA\n");
    printar(vet,tam);
    printf("Trocas: %d", trocas);
    return 0;
}