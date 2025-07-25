#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
    int num;
    struct Node *left;
    struct Node *right;
}No;
No* create(){
    No* node = new No;
    node->num = rand()% 100;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(No* node, No *novo){
    if (node == NULL || novo == NULL)
    {
        printf("Erro");
        return;
    }
    if (node->num == novo->num)
    {
        printf("Esse número já existe !\n");
        return;
    }
    if (node->num < novo->num)
    {
        if (node->right == NULL)
        {
            node->right = novo;
            return;
        }
        insert(node->right, novo);
        
    }else{
        if (node->left == NULL)
        {
            node->left = novo;
            return;
        }
        insert(node->left, novo);
        
    }
}
No* max(No* node){
    if (node == NULL) return NULL;
    if (node->right == NULL) return node;
    else return max(node->right);
}

No* min(No* node){
    if (node == NULL) return NULL;
    if (node->left == NULL) return node;
    else return min(node->left);    
}

void imprimir(No* node, int tab, char* dir) {
    if (node == NULL) {
        return;
    }
    imprimir(node->right, tab + 1, "→");
    for (int i = 0; i < tab; i++) {
        printf("\t");
    }
    printf("%s|%d|\n", dir, node->num);
    imprimir(node->left, tab + 1, "←");
}

No* buscar(No* node, int num){
    if (node == NULL)
    {
        return NULL;
    }
    else{
        if (num > node->num)
        {
            if (node->right == NULL)
            {
                return NULL;
            }
            else{
                return buscar(node->right, num);
            }
            
        }else{
            if(num < node->num){
                if (node->left == NULL)
                {
                    return NULL;
                }
                return buscar(node->left, num);
                
            }
            else{
                return node;
            }
        }   
    }
}
No* buscar_pai(No* node, No* filho){
    if (node == NULL)
    {
        printf("Sem pai");
        return NULL;
    }   
    if (node->left == filho || node->right == filho)
    {
        return node;
    }
    No* lftsrch = buscar_pai(node->left,filho);

    if (lftsrch != NULL )
    {
        return lftsrch;
    }
    return buscar_pai(node->right, filho);

}
int contar(No* node){
    if (node == NULL)
    {
        return 0;
    }
    else{
        return 1 + contar(node->left) + contar(node->right);
    }
    
}
int menu(){
    printf("1 - adicionar um elemento;\n");
    printf("2 - imprimir arvore\n");
    printf("3 - Buscar;\n");
    printf("4 - max e min\n");
    printf("5 - deletar;\n");
    printf("0 - sair;\n");
    int esc;
    printf(">>> ");
    scanf("%d",&esc);
    return esc;
}
int main(int argc, char *const _argv[]){

    system("chcp 65001");
    system("cls");
    srand(time(NULL));
    No* node = new No;
    int esc =0;
    do
    {   
        esc = menu();
        switch (esc)
        {
        case 1:
            insert(node,create());
            break;
        case 2:
            imprimir(node,0," ");
            break;
        case 3:
        break;
        case 0:
        printf("Saindo...\n");
        break;
        default:
            printf("Erro\n");
            break;
        }
    } while (esc !=0);
    
    
    return 0;
}