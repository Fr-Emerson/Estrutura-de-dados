#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void trocar(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int* vet, int tam, int i){
    int maior =i;
    int left = 2*i+1;
    int right = 2*i+2;
    if (left < tam && !(vet[maior] < vet[left]))
    {
        maior = left;
    }
    if (right < tam && !(vet[maior] < vet[right]))
    {
        maior = right;
    }
    if (maior != i)
    {
        trocar(&vet[i],&vet[maior]);
        heapify(vet, tam, maior);
    }
        
}
void buildHeap(int* vet, int size){
        for (int i = (size-1)/2; i >=0; i--)
        {
            heapify(vet, size, i);
        }
}
void heap_sort(int* vet, int tam){
    for (int i = tam/2-1; i >0; i--)
    {
        heapify(vet, tam,i);
    }
    for ( int i = tam-1; i >= 0; i--)
    {
        trocar(&vet[0],&vet[i]);
        heapify(vet,i,0);
    }
}
void printar(int* vet, int tam){
    printf("\n");
    for (int i = 0; i < tam; i++)
    {
        printf("| %d |->",vet[i]);
    }
    printf("FIM\n");
    
}

void printar_arvore(int* vet, int tam, int index, int nivel) {
    if (index >= tam) return;

    printar_arvore(vet, tam, 2 * index + 2, nivel + 1);

    for (int i = 0; i < nivel; i++) {
        printf("   ");
    }
    printf("|%d|\n", vet[index]);

    printar_arvore(vet, tam, 2 * index + 1, nivel + 1);
}
void randomizar(int* vet, int tam){
    for (int i = 0; i < tam; i++)
    {
        vet[i] = rand()%100;
    }

}
void delete_heap(int* vet,int* tam){
    int last= vet[*tam -1];
    vet[0] = last;
    *tam = *tam -1;
    heapify(vet,*tam, 0);
}

int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    srand(time(NULL));
    int tam = 15;
    int vet[tam];
    randomizar(vet, tam);
    printf("\n\nHeap Antes:\n\n");
    printar_arvore(vet, tam,0,0);
    buildHeap(vet, tam);
    printf("\n\nHeap Depois:\n\n");
    printar_arvore(vet,tam,0,0);
    heap_sort(vet,tam);
    printar(vet,tam);
    return 0;
}