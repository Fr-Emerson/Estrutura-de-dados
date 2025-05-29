#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct{
    char nome[30];
    char matricula[10];
    float nota;
}aluno;

typedef struct elem{
    aluno a;
    struct elem* prox;
    struct elem* ant;
} elemento;

typedef struct l{
    elemento* inicio;
    elemento* fim;
    int tamanho;
}Lista;

aluno* cria(){
    aluno* al = (aluno*)(calloc(1,sizeof(aluno)));
    printf("Digite o nome do aluno: ");
    scanf("%s",al->nome);
    printf("Digite a matricula do aluno: ");
    scanf("%s",al->matricula);
    printf("Digite a nota do aluno: ");
    scanf("%f",&al->nota);
    if (al->nota < 0 || al->nota > 10)
    {
        printf("Nota inválida!\n");
        return NULL;
    }
    printf("Aluno criado com sucesso!\n");
    return al; 
}

void insert(Lista* head, aluno* novo_no){

}

int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    Lista *lista = (Lista*)(calloc(1,sizeof(Lista)));
    if (!lista)
    {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    


    return 0;
}