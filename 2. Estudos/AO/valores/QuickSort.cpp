#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void trocar(int *l, int x, int y){
    int aux = l[x];
    l[x] =l[y];
    l[y] = aux;

}
void randomizar(int *l, int tam){
    srand(time(NULL));
    for (int i = 0; i < tam; i++)
    {
        l[i] = rand() % 101;
    }
}
void printar(int *l, int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("|%d|->",l[i]);
    }
    printf("FIM\n");
}
int partition(int *l, int left, int right){
    int pivot = (l[left] + l[right] + l[(left+right)/2])/3;
    while (left <= right)
    {
        while (l[left] <= pivot)
            left++;
        while (l[right] > pivot)
            right--;
        if (left <= right)
        {
            trocar(l, left, right);
            left++;
            right--;
        }       
        
    }
    return left;
    
}
void sort(int *l, int left, int right){
    if (left < right)
    {
        int pos = partition(l, left, right);
        partition(l, left, pos-1);
        partition(l, pos, right);
    }
}

int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    int tam = 5;
    int lista[tam];
    randomizar(lista,tam);
    printf("Antes do sort: \n");
    printar(lista,tam);
    printf("Depois do sort: \n");
    sort(lista,0 ,tam-1);
    printar(lista,tam);

    return 0;
}