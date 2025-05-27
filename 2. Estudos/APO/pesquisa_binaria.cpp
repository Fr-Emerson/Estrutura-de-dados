#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    system("chcp 65001");
    system("cls");
    int topo = 100;
    int vet[topo];
    for (int i = 0; i < topo; i++)
    {
        vet[i] = i;
    }
    int random;
    srand(time(NULL));
    // random = rand() % topo + 1;
    printf("Insert -> ");
    scanf("%d",&random);
    // printf("%d",random);
    if (random < 0 || random > topo){
        printf("Valor inválido!\n");   
    }
    else{
        bool acerto = false;
        int tries = 1;
        int inicio = 0;
        int meio = 0;
        do 
        {
            meio = (inicio+topo)/2;
            if (random == vet[meio])
            {
                acerto = true;
            }
            else{
                tries++;
                if (random > vet[meio])
                {
                    inicio = meio+1;
                }
                else{
                    topo = meio;
                }   
            }
        } while (acerto != true);
        printf("Tries: %d\n",tries);
    }  
    return 0;
}