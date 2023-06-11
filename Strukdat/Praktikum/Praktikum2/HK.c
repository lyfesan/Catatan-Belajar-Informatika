#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int cnt=0;

typedef struct bstnode_t{
    int key;
    struct bstnode_t *left,*right;
} BSTNode;

typedef struct bst_t{
    BSTNode *_root;
    unsigned int _size;
} BST;

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

BSTNode* __createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __createNode(value);
    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

void bst_insert(BST *bst, int value) {
    bst->_root = __bst__insert(bst->_root, value);
    bst->_size++;
}

void __preorder(BSTNode *root) {
    if (root) {
        if(root->key%2){cnt++;printf("%d ", root->key);}
        __preorder(root->left);
        __preorder(root->right);
    }
}

void bst_preorder(BST *bst){
    __preorder(bst->_root);
}

int main(){
    BST set;
    bst_init(&set);
    int q,n;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        bst_insert(&set,n);
    }
    bst_preorder(&set);
    printf("%d\n",cnt+3+5+9);
}