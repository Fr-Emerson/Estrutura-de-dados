#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    system("chcp 65001");
    system("cls");
    int tam = 127;
    int vet[tam];
    int qtd = 5000;
    srand(time(NULL));
    int tries =0;
    int esc;
    int media=0;
    for (int j = 0; j < qtd; j++)
    {
        for (int i = 0; i < tam; i++)
    {
        vet[i] = rand() % tam + 1;
        // printf("|%d|\n",vet[i]);
    }
    // printf("Digite um valor(0-15): ");
    // scanf("%d",&esc);
    esc = rand()%tam+1;
    for (int i = 0; i < tam; i++)
    {
        tries++;
        if (esc == vet[i])
        {
            break;
        }else{
            if (i == tam - 1 )
            {
                // printf("Não encontrado\n");
            }
        }
    }
    // printf("Tentativas: %d\n",tries);
    media += tries;
    tries = 0;
    }
    media = media/qtd;
    printf("Média: %d",media);
    



    return 0;
}