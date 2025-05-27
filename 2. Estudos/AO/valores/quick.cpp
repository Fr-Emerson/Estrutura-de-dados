#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct lista{
    int val;
    struct lista *prox;
    struct lista *ant;
};
typedef lista lista;
void trocar(lista *a, lista *b){
    int temp = a->val;
    a->val = b->val;
    b->val = temp;

}
void add(lista **l, int val){
    lista *novo = (lista*) calloc(1,sizeof(lista));
    novo->prox =NULL;
    novo->ant = NULL;
    novo->val = val;

    if (*l == NULL)
    {
        (*l) = novo;

    }else{
        lista *copy = (*l);
        while (copy->prox)
        {
            copy = copy->prox;
        }
        copy->prox = novo;
        copy->ant = copy; 
    }
    
}
int partition(lista **l,lista *left, lista *right, lista **nLeft, lista **nRight){
   int pivot = (left->val + right->val +((left->val + right->val)/2))/3;
   lista *bottom = left;
   while (bottom != NULL && right != NULL && bottom != right && bottom->ant != right)
   {
        // while (condition)
        // {
        //     /* code */
        // }
        
   }
    
    
    
}
void sort(int *l, int tam){
    
    

}
void print_lista(lista *l) {
    lista *cpy = l;
    printf("Lista:\n");
    while (cpy != NULL) {
        printf("|%d| <-> ", cpy->val);
        cpy = cpy->prox;
    }
    printf("NULL\n");
}

int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    int tam = 10;
    lista *l = NULL;
    srand(time(NULL));
    for (int i = 0; i < tam; i++)
    {
        add(&l,rand() % 100);
    }
    // print_lista(l);


    return 0;
}