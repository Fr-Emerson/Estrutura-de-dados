#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char *lista[], int tam){
    for (int i = 0; i < tam; i++)
    {
        char *menor = lista[i];
        for (int j = i; j < tam-1; i++)
        {
            if (strcmp(menor, lista[i+1]) < 0)
            {
            
                strcpy(menor,lista[i+1]);
            }
            strcpy(lista[i],menor);
            
        }
    }

}
int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    int tam = 3;
    char *lista[tam][15] = {"Biboca","Garagem","Favela"};
    sort(*lista,tam);

    return 0;
}