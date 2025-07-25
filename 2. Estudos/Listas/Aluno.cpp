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
    struct elem* ant = NULL;
} elemento;

typedef struct l{
    elemento* inicio = NULL;
    elemento* fim = NULL;
    int tamanho = 0;
}Lista;

aluno* cria(){
    aluno* al = (aluno*)(calloc(1,sizeof(aluno)));
    printf("Digite o nome do aluno: ");
    scanf("%29s",al->nome);
    printf("Digite a matricula do aluno: ");
    scanf("%9s",al->matricula);
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

void insert_fim(Lista* lista, aluno* aluno){
    elemento *el_novo = new elemento;
    el_novo->a = aluno;
    if (lista->tamanho == 0)
    {
        lista->inicio = el_novo;
        lista->fim = el_novo;
    }
    else{
        lista->fim->prox = el_novo;
        el_novo->ant = lista->fim;
        lista->fim = el_novo;
    } 
    lista->tamanho++;
}
void insert_inicio(Lista* lista, aluno* aluno){
    elemento *el_novo = new elemento;
    el_novo->a = aluno;
    if (lista->tamanho == 0)
    {
        lista->inicio = el_novo;
        lista->fim = el_novo;
    }
    else{
        el_novo->prox = lista->inicio;
        lista->inicio->ant = el_novo;
        lista->inicio = el_novo;
    }
    lista->tamanho++;
}
elemento* busca_ant(elemento *e){
    if (e->ant)
    {
        return e->ant;
    }
    else{
        return NULL;    
    }
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
void trocar_adj(Lista** head, elemento* e1, elemento* e2){

    if (e1->prox == e2)
    {
        e1->prox = e2->prox;
        if (e2->prox) e2->prox->ant = e1;
        else (*head)->fim = e1;

        e2->ant = e1->ant;
        if (e1->ant) e1->ant->prox = e2;
        else (*head)->inicio = e2;


        e2->prox = e1;
        e1->ant = e2;
        
    }else{
        trocar_adj(head,e2,e1);
    }
}

void trocar_n_adj(Lista** head, elemento* e1, elemento *e2){
        if (e1->ant) e1->ant->prox = e2;
        else (*head)->inicio = e2;
        if(e1->prox) e1->prox->ant = e2;
        else (*head)->fim = e2;

        if (e2->ant) e2->ant->prox = e1;
        else (*head)->inicio = e1;
        if(e2->prox) e2->prox->ant = e1;
        else (*head)->fim = e1;

        elemento* aux_prox =e1->prox;
        elemento* aux_ant =e1->ant;
        

        e1->prox = e2->prox;
        e1->ant = e2->ant;

        e2->prox = aux_prox;
        e2->ant = aux_ant;
}
void trocar(Lista** head,elemento *e1, elemento *e2){
    if (!e1 || !e2 || e1 == e2)
    {
        return;
    }
    else{
        if (e1->prox == e2 || e2->prox == e1)
        {
            trocar_adj(head, e1, e2);
        }
        else{
            trocar_n_adj(head, e1,e2);
        }
    }
}
elemento* search(Lista* head, float nota){
    if (head->inicio == NULL)
    {
        printf("Lista vazia!\n");
        return NULL;
    }
    elemento* cpy = head->inicio;
    while (cpy != NULL)
    {
        if (cpy->a->nota == nota)
        {
            return cpy;
        }
        cpy = cpy->prox;
    }
    return NULL;
}
int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    Lista *lista = new Lista; 
    if (!lista)
    {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    
    


    return 0;
}