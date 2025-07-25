#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
struct avl
{
    int val;
    struct avl *left;
    struct avl *right;
    int fb;
};
typedef struct avl avl;
int fb(avl *node);
avl *create()
{
    avl *novo = (avl *)calloc(1, sizeof(avl));
    // printf("Digite um valor: ");
    // scanf("%d",&novo->val);
    novo->val = rand() % 100;
    return novo;
}
void insert(avl **root, avl *novo_no)
{
    if (*root == NULL)
    {
        *root = novo_no;
        return;
    }
    else
    {
        if (novo_no->val > (*root)->val)
        {
            if ((*root)->right == NULL)
            {
                (*root)->right = novo_no;
                return;
            }
            insert(&(*root)->right, novo_no);
        }
        else
        {
            if ((*root)->left == NULL)
            {
                (*root)->left = novo_no;
                return;
            }
            insert(&(*root)->left, novo_no);
        }
    }
}
int altura(avl *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + fmax(altura(node->left), altura(node->right));
    }
}
int fb(avl *node)
{
    if (node == NULL)
        return 0;
    else
        return altura(node->left) - altura(node->right);
}
void imprimir(avl *node, int tab = 0)
{
    if (node == NULL)
        return;
    
    imprimir(node->right, tab + 1);
    for (int i = 0; i < tab; i++)
    {
        printf("\t");
    }
    printf("|%d|\n", node->val);
    
    imprimir(node->left, tab + 1);
}
int main(int argc, char *const _argv[])
{
    system("chcp 65001");
    system("cls");
    srand(time(NULL));
    avl *root = NULL;
    for (int i = 0; i < 10; i++)
    {

        insert(&root, create());
    }

    imprimir(root, 0);

    return 0;
}