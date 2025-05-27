#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void randomizar(int *vet, int tam){
    for (int i = 0; i < tam; i++)
    {
        vet[i] = rand() % 100;
    }
}
void merge(int *l,int left, int middle, int right){
    int leftLen = middle - left +1;
    int rightLen = right - middle;
    
    int rightArray[rightLen];
    int leftArray[leftLen];

    int i, j , k;
    for (int i = 0; i < leftLen; i++)
    {
        leftArray[i] = l[left+i];
    }
    for (int i = 0; i < rightLen; i++)
    {
        rightArray[i] = l[middle + i + 1];
    }
    for ( i = 0, j = 0, k = left ; k <=right; k++)
    {
        if ((i < leftLen) && (j>=rightLen || leftArray[i] <= rightArray[j]))  
        {
            l[k] = leftArray[i];
            i++;
        }else{
            l[k] = rightArray[j];
            j++;
        }
        
    }
    
}
void merge_recursion(int *lista, int left, int right){
    if (left < right)
    {
        int middle = left + (right - left)/2;
        merge_recursion(lista, left, middle);
        merge_recursion(lista, middle+1, right);
        
        merge(lista, left, middle, right);
    }
    
}
void sort(int *lista, int tam){
    merge_recursion(lista, 0, tam -1);
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
    srand(time(NULL));
    int tam = 10;
    int vet[tam];
    randomizar(vet,tam);
    printf("Antes da troca: \n");
    printar(vet,tam);
    sort(vet,tam);
    printf("Depois da troca: \n");
    printar(vet,tam);
    

    return 0;
}