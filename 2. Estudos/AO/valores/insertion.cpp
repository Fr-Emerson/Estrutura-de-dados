#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

struct Lista
{
    int valor;
    int pos;
    struct Lista *prox;
    struct Lista *ant;
    
};
void add(Lista **l, int val){
    Lista *novo = (Lista*) calloc(1,sizeof(Lista));
    novo->ant = NULL;
    novo->pos = 0;
    novo->prox = NULL;
    novo->valor = val;
    if (*l == NULL )
    {
        (*l) = novo;
    }
    else{
        Lista *cpy = (*l);
        while (cpy->prox)
        {
            cpy = cpy->prox;
        }
        novo->pos = cpy->pos +1;
        cpy->prox = novo;
        novo->ant = cpy;
    }
}

void trocar(int *val, int *prox){
    int aux;
    aux = *val;
    *(val) = *(prox);
    *prox = aux;
}
Lista *busca(Lista *l, int pos){
    Lista *cpy = l;
    while (cpy != NULL)
    {
        if (cpy->pos == pos)
        {
            return cpy;
        }   
        cpy = cpy->prox;
    }
    return NULL;
}
void print_lista(Lista *l) {
    Lista *cpy = l;
    printf("Lista:\n");
    while (cpy != NULL) {
        printf("|%d| <-> ", cpy->valor);
        cpy = cpy->prox;
    }
    printf("NULL\n");
}
void sort(Lista **l){
    if (*l == NULL || (*l)->prox == NULL)
    {
        return;
    }
    Lista *atual = (*l)->prox;
    while (atual != NULL)
    {
        int val_atual = atual->valor;
        Lista *ant = atual->ant;
        while (ant != NULL && ant->valor > val_atual)
        {
            ant->prox->valor = ant->valor;
            ant = ant->ant;
        }
        if (ant== NULL)
        {
            (*l)->valor = val_atual;
        }else{
            ant->prox->valor = val_atual;
        }
        atual = atual->prox;
    }

}
int main(int argc, char *const _argv[]){
    srand(time(NULL));
    system("chcp 65001");
    system("cls");
    int tam = 10;
    int random;
    Lista *l = NULL;
    for (int i = 0; i < tam; i++)
    {
        random = rand()%100;
        add(&l, random);
    }

    printf("Antes da troca: \n");
    print_lista(l);
    sort(&l);
    printf("Depois da troca: \n");
    print_lista(l);
    

    return 0;
}