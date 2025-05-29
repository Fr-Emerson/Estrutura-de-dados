#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct{
    char nome[30];
    char matricula[10];
    float nota = 0;
}aluno;

typedef struct elem{
    aluno *a = NULL;
    struct elem* prox = NULL;
    // struct elem* ant = NULL;
} elemento;

typedef struct l{
    elemento* inicio = NULL;
    elemento* fim = NULL;
    int tamanho = 0;
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

void insert(Lista* lista, aluno* aluno){
    elemento *el_novo = new elemento;
    el_novo->a = aluno;
    if (lista->tamanho == 0)
    {
        lista->inicio = el_novo;
        lista->fim = el_novo;
    }
    else{
        lista->fim->prox = el_novo;
        lista->fim = el_novo;
    } 
    lista->tamanho++;
}
void insert_inicio(Lista* lista, aluno* aluno){
    elemento *el_novo = new elemento;
    el_novo->a = aluno;
    if (lista->tamanho = 0)
    {
        lista->inicio = el_novo;
        lista->fim = el_novo;
    }
    else{
        el_novo->prox = lista->inicio;
        lista->inicio = el_novo;
    }
    lista->tamanho++;
}
elemento* busca_ant(Lista *lista, elemento *e){
    if ((lista->tamanho==0) || (e = lista->inicio))
    {
        return NULL;
    }
    elemento* aux = lista->inicio;
    while (aux != NULL)
    {
        if (aux->prox == e)return aux;
        aux = aux->prox;
    }

    return NULL;
}
void imprimir(Lista* l){
    elemento* aux = l->inicio;
    while (aux != NULL)
    {
        printf("| %s |->",aux->a->nome);
        aux = aux->prox;
    }
    printf("NULL\n");
    
}
int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    Lista *lista = (Lista*)(calloc(1,sizeof(Lista)));
    // if (!lista)
    // {
    //     printf("Erro ao alocar memória!\n");
    //     exit(1);
    // }
    insert(lista, cria());
    imprimir(lista);

    return 0;
}