#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Node{
    int val;
    int fb = 0;
    struct Node* left = NULL;
    struct Node* right = NULL;
};
typedef struct Node Node;
Node* buscar_pai(Node* root, Node* filho){
    if (root == NULL)
    {
        return NULL; // sem pai kkkkk
    }
    if (root->left == filho || root->right == filho)
    {
        return root;
    }
    Node* lftsrch = buscar_pai(root->left, filho);
    if (lftsrch != NULL)
    {
        return lftsrch;
    }
    return buscar_pai(root->right, filho);
}
Node* create(){
    Node* no = new Node;
    no->val = rand()%100;
    no->left = NULL;
    no->fb = 0;
    no->right = NULL;
    return no;
}
void insert(Node *root, Node* novo){
    if (root == NULL)
    {
        root = novo;
    }else{

    }
}

int main(int argc, char *const _argv[]){
    system("chcp 65001");
    system("cls");
    srand(time(NULL));


    return 0;
}