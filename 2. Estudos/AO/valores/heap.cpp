#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    int vet[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int tam = sizeof(vet)/sizeof(vet[0]);
    printf("Tamanho do vetor: %d\n", tam);
    //printando em formato de arvore
    for (int i = 0; i < int(tam)/2; i++) {
        printf("Raiz: %d\n", vet[i]);
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        printf("Esquerda: %d\n", vet[left]);
        printf("Direita: %d\n", vet[right]);
        
        printf("\n");

    }
    

    return 0;
}