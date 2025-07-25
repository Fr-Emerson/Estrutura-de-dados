#include<stdio.h>
#include<stdlib.h>
void trocar(int *vet, int d, int o){
    int aux = vet[d];
    vet[d] = vet[o];
    vet[o] =aux;
}
void shell_sort(int *vet, int tam) {
    int gap = tam / 2;

    while (gap > 0) {
        for (int i = gap; i < tam; i++) {
            int key = vet[i];
            int j = i;

            while (j >= gap && vet[j - gap] > key) {
                vet[j] = vet[j - gap];
                j -= gap;
            }
            vet[j] = key;
        }
        gap /= 2;
    }
}


void printar(int* vet, int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("|%d|->",vet[i]);
    }
    printf("FIM\n");
}
int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    int vet[] = {5,4,3,2,1};
    int tam = 5;
    printar(vet,tam);
    printf("Depois\n");
    shell_sort(vet,tam);
    printar(vet,tam);


    return 0;
}