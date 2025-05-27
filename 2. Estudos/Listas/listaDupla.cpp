#include <stdio.h>
#include <stdlib.h>
#include<time.h>
struct lista
{
    int val;
    int pos;
    struct lista *prox;
    struct lista *ant;
};

typedef struct lista lista;
struct cel
{
    int tamanho;
    lista *inicio;
};
typedef struct cel cel;
lista *add()
{
    lista *novo = (lista *)(calloc(1, sizeof(lista)));
    printf("Digite um valor: ");
    scanf("%d", &(novo->val));
    return novo;
}
void insert(cel *head, lista *novo_no)
{
    if (head->inicio == NULL)
    {
        head->inicio = novo_no;
        novo_no->pos = 0;
    }
    else
    {
        lista *cpy = head->inicio;
        while (cpy->prox != NULL)
        {
            cpy = cpy->prox;
        }
        cpy->prox = novo_no;
        novo_no->ant = cpy;
        novo_no->pos = cpy->pos + 1;
    }
    head->tamanho++;
}
lista *search_alt(lista *head, int val)
{
    if (head->val == val) return head;
    if (head == NULL) return NULL;
    return search_alt(head, val);
}

lista *search(cel *head, int pos)
{
    if (pos < 0)
    {
        printf("Inválido!\n");
        return NULL;
    }
    lista *cpy = head->inicio;
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
void printar_st(cel *head)
{
    lista *cpy = head->inicio;
    while (cpy != NULL)
    {
        printf("| %d° = %d |->", cpy->pos + 1, cpy->val);
        cpy = cpy->prox;
    }
    printf("NULL\n");
}

int deletar(cel *head, lista *delet)
{
    if (delet == NULL)
    {
        return -1;
    }
    int val = delet->val;

    if (delet->prox == NULL)
    {
        if (delet->ant == NULL)
        {
            head->inicio = NULL;
        }
        else
        {
            delet->ant->prox = NULL;
        }
    }
    else
    {
        if (delet->ant == NULL)
        {
            delet->prox->ant = NULL;
            head->inicio = delet->prox;
        }
        else
        {
            delet->ant->prox = delet->prox;
            delet->ant = delet->ant;
        }
    }
    free(delet);
    head->tamanho--;
    return val;
}

void liberar_lista(lista *l)
{
    lista *temp;
    while (l != NULL)
    {
        temp = l;
        l = l->prox;
        free(temp);
    }
}

void liberar_cel(cel *head)
{
    liberar_lista(head->inicio);
    head->inicio = NULL;
    head->tamanho = 0;
}

void atualizar_posicoes(cel *head)
{
    lista *cpy = head->inicio;
    int i = 0;
    while (cpy != NULL)
    {
        cpy->pos = i++;
        cpy = cpy->prox;
    }
}

void trocar_adj(cel** head, lista* origem, lista* destino) {
    if (origem->prox == destino) {

        origem->prox = destino->prox; // igualando os próximos de origem para destino

        if (destino->prox) destino->prox->ant = origem; // caso destino não seja o ultimo, o anterior do prox recebe a origem

        destino->ant = origem->ant; // igualando os anteriores de destino para origem
        if (origem->ant) origem->ant->prox = destino; 
        else (*head)->inicio = destino;
        
        destino->prox = origem;
        origem->ant = destino;
    } else {
        trocar_adj(head, destino, origem); 
    }
}
void trocar_nao_adj(cel** head, lista* a, lista* b) {

    if (a->ant) a->ant->prox = b;
    else (*head)->inicio = b;

    if (a->prox) a->prox->ant = b;

    if (b->ant) b->ant->prox = a;
    else (*head)->inicio = a;

    if (b->prox) b->prox->ant = a;
    
   lista *temp_ant = a->ant;
   lista *temp_pos = a->prox;

   a->ant = b->ant;
   a->prox = b->prox;

   b->ant = temp_ant;
   b->prox = temp_pos;
}

void trocar(cel** head, lista* origem, lista* destino) {
    if (!origem || !destino || origem == destino) return;

    if (origem->prox == destino || destino->prox == origem) {
        trocar_adj(head, origem, destino);
    } else {
        trocar_nao_adj(head, origem, destino);
    }
}
void max_min(cel* head, int *max, int *min){
    if (head->inicio == NULL)
    {
        return;
    }
    lista* cpy = head->inicio;
    *max = cpy->val;
    *min = cpy->val;
    while (cpy->prox != NULL)
    {
        if (cpy->prox->val > *max)
        {
            *max = cpy->prox->val;
        }
        if (cpy->prox->val < *min)
        {
            *min = cpy->prox->val;
        }
        cpy = cpy->prox;
    }
}
lista* ultimo(cel* head){
    lista* cpy = head->inicio;
    if (cpy == NULL)
    {
        return NULL;
    }
    while (cpy->prox != NULL)
    {
        cpy = cpy->prox;
    }
    return cpy;
}
lista* middle(lista* left, lista* right){
    lista* slow = left;
    lista* fast = left;
    while (fast != right && right->prox != right)
    {
        slow = slow->prox;
        if (fast->prox)
        {
            fast = fast->prox->prox;
        }
        else{
            break;
        } 
    }
    return slow;
}
int menu()
{
    printf("\n+---------- MENU ----------+\n");
    printf("1 - Adicionar;\n");
    printf("2 - Buscar;\n");
    printf("3 - Printar;\n");
    printf("4 - Deletar;\n");
    printf("5 - Resetar;\n");
    printf("6 - Trocar;\n");
    printf("7 - Ordenar;\n");
    printf("8 - Max e Min;\n");
    printf("0 - sair;\n");
    int esc;
    printf("ESCOLHA >> ");
    scanf("%d", &esc);
    return esc;

}

int main(int argc, char *const _argv[])
{
    srand(time(NULL));
    system("chcp 65001");
    system("cls");
    int esc = 0;
    cel *head = (cel *)(calloc(1, sizeof(cel)));
    do
    {
        system("pause");
        system("cls");
        esc = menu();
        switch (esc)
        {
        case 1:
            insert(head, add());
            printf("Adicionado com sucesso!\n");
            break;
        case 2:
        {
            printf("Digite a posição: ");
            int pos;
            scanf("%d", &pos);
            lista *valor = search(head,pos);
            (valor == NULL ? printf("Não encontrado\n") : printf("Valor encontrado: %d\n", valor->val));
            break;
        }
        case 3:
            printf("Tamanho da lista: %d\n", head->tamanho);
            printar_st(head);
            break;
        case 4:
        {
            printf("Digite a posição: ");
            int pos;
            scanf("%d", &pos);
            int val = deletar(head, search(head,pos));
            (val == -1 ? printf("Não encontrado\n") : printf("Valor deletado: %d\n", val));
            atualizar_posicoes(head);
            break;
        }
        case 5:

            liberar_cel(head);
            printf("Célula resetada com sucesso !\n");
            break;
        case 6:
            int a, b;
            printf("Digite os valores para trocar(ex: a b): ");
            scanf("%d %d",&a,&b);
            trocar(&head, search_alt(head->inicio, a), search_alt(head->inicio, b));
            printf("Valores trocados com sucesso!\n");
            atualizar_posicoes(head);
            break;
        case 7:{
            int tam;
            printf("Digite a quantidade de valores: ");
            scanf("%d",&tam);
            if (tam < 0)
            {
                /* code */
            }
            
            break;
            }
        case 8:{
            int max= 0, min= 0;
            max_min(head,&max,&min);
            (max == min ? printf("Os valores são iguais!\n"):printf("Maior: %d\nMenor: %d\n",max,min));
            break;
        }
        case 0:
            printf("Adeus...\n");
            break;
        default:
            printf("Erro\n");
            break;
        }
    } while (esc != 0);
    system("pause");
    system("cls");
    liberar_cel(head);
    free(head);

    return 0;
}