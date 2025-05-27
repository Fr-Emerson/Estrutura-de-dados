#include<stdio.h>
#include<stdlib.h>
struct lista
{
    int val;
    int pos;
    struct lista *prox;
};
typedef struct lista lista;
struct cel{
    int tamanho;
    lista *inicio;
};
typedef struct cel cel;
void insert(cel** head, lista* no){
    if ((*head)->inicio == NULL)
    {
        (*head)->inicio = no;
        no->pos = 0;
        no->prox = NULL;
    }
    else{
        lista* cpy = (*head)->inicio;
        while (cpy->prox != NULL)
        {
            cpy = cpy->prox;
        }
        cpy->prox = no;
        no->prox = NULL;
        no->pos = cpy->pos + 1;
    }
    (*head)->tamanho++;
    
    
}
lista* novo_no(){
    lista* novo = (lista*)(calloc(1,sizeof(lista)));
    printf("Digite um valor: ");
    scanf("%d",&(novo->val));
    novo->prox = NULL;
    return novo;
}
void printar_st(cel *head){
    lista* cpy = head->inicio;
    while (cpy != NULL)
    {
        printf("|%d°: |%d|->",cpy->pos+1,cpy->val);
        cpy = cpy->prox;
    }
    printf("NULL\n");
}
lista* search_no(lista* no, int val){
    if (no == NULL) return NULL;
    if (no->val == val) return no;
    return search_no(no->prox, val);
}
void liberar_lista(lista* head) {
    lista* temp;
    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);
    }
}
void liberar_cel(cel* head){
    liberar_lista(head->inicio);
    free(head);
}
void reset(cel* head){
    liberar_lista(head->inicio);
    head->inicio = NULL;
    head->tamanho = 0;

}
bool deletar(cel* head, lista* delet, int *val_deletado){
    if (delet == NULL)
    {
        return false;
    }
    else{
        lista* atual = head->inicio;
        lista* ant = NULL;
        while (atual != NULL)
        {
            if (atual == delet)
            {
                if (ant == NULL)
                {
                    head->inicio = atual->prox;
                }
                else{
                    ant->prox = atual->prox;
                }
                *val_deletado = atual->val;
                free(atual);
                head->tamanho--;
                lista* atualiza = head->inicio;
                int pos = 0;
                while (atualiza != NULL) {
                    atualiza->pos = pos++;
                    atualiza = atualiza->prox;
                }
                return true;
            }
            ant = atual;
            atual = atual->prox;
        } 
    }
    return false;
    
}
void trocar(cel *head, lista* origem, lista* destino){
    lista* antOrigem = head->inicio;
    lista* antDestino = head->inicio;

    while (antDestino != NULL && antDestino->prox != destino) antDestino = antDestino->prox;
    while (antOrigem != NULL && antOrigem->prox != origem) antOrigem = antOrigem->prox;
    if (antOrigem == NULL || antDestino == NULL)
    {
        printf("Impossivel trocar!");
    }
    else{
        antOrigem->prox = destino;
        origem->prox = destino->prox;
        antDestino->prox = antOrigem->prox;
        destino->prox = antDestino;
        printf("Trocados com sucesso!\n");
    }
    
}
int menu(){
    printf("\n+---------- MENU ----------+\n");
    printf("1 - Adicionar;\n");
    printf("2 - Buscar;\n");
    printf("3 - printar;\n");
    printf("4 - deletar;\n");
    printf("5 - resetar;\n");
    printf("0 - sair;\n");
    int esc;
    printf("ESCOLHA >> ");
    scanf("%d",&esc);
    return esc;
}
int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    cel *cabeca = (cel*)(calloc(1,sizeof(cel)));
    if (cabeca == NULL) {
        printf("Erro de alocação.\n");
        exit(1);
    }
    int val;
    int esc = -1;
    do
    {
        system("pause");
        system("cls");
        esc = menu();
        switch (esc)
        {
        case 1:
            insert(&cabeca,novo_no());
            printf("Adicionado com sucesso!\n");
            break;
        case 2:{
            printf("Digite o valor a ser buscado: ");
            scanf("%d",&val);
            lista* busca = search_no(cabeca->inicio,val);
            if (busca == NULL)
            {
                printf("Valor não encontrado\n");
            }
            else{
                printf("Posição de %d: %d°\n",busca->val,busca->pos+1);
            }
            break;
        }
        case 3:
            printar_st(cabeca);
            break;
        case 4:{
            printf("Digite o valor a ser buscado: ");
            scanf("%d",&val);
            int val_delet;
            if (deletar(cabeca, search_no(cabeca->inicio, val), &val_delet))
            {
                printf("valor deletado: %d\n",val_delet);
            }
            else{
                printf("Não encontrado!\n");
            }

            break;
        }
        case 5:
            reset(cabeca);
            printf("Resetado com sucesso!\n");
            break;
        case 6: {
            int origem, destino;
            printf("Digite os valores a serem trocado(ex: a b)\n>>");
            scanf("%d %d",&origem,&destino);
            trocar(cabeca, search_no(cabeca->inicio, origem), search_no(cabeca->inicio, destino));
            break;
        }
        case 0:
            printf("Adeus...\n");
            break;
        default:
            printf("ERRO\n");
            break;
        }
    } while (esc != 0);
    system("pause");
    system("cls");
    liberar_cel(cabeca);

    return 0;
}