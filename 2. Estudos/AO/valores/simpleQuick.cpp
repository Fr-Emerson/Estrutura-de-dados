    #include<stdio.h>
    #include<stdlib.h>
    #include <time.h>
    void printar(int *vet, int tam){
        printf("\n");
        for (int i = 0; i < tam; i++)
        {
            printf("|%d|->", vet[i]);
        }
        printf("FIM\n");
    }
    void randomizar(int *vet, int tam){
        srand(time(NULL));
        for (int i = 0; i < tam; i++)
        {
            vet[i] = rand() % 101;
        }
    }

    void trocar(int *vet, int i, int j){
        int aux;
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
    }
    int particionado(int *vet, int left, int right){
        int pivot = (vet[left]+vet[right]+ vet[(left+right)/2])/3;
        while (left <= right)
        {
            while (vet[left] < pivot)
                left++;
            while (vet[right] > pivot)
                right--;
            
            if (left <= right)
            {
                trocar(vet, right, left);
                left++;
                right--;
            }
            
        }
    
        return left;
    }

    void sort(int *lista, int left, int right){
        if (left < right)
        {
            int pos = particionado(lista, left, right);
            sort(lista, left, pos-1);
            sort(lista, pos, right);
        }

    }
    int main(int argc, char *const _argv[]){
        system("chcp 65001");
        system("cls");
        int tam = 17;
        int lista[tam];
        randomizar(lista,tam);
        printf("Antes do sort: \n");
        printar(lista,tam);
        printf("Depois do sort: \n");
        sort(lista,0 ,tam-1);
        printar(lista,tam);

        return 0;
    }