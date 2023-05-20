#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef unsigned long long ull;
 
int cnt=0;
bool y=0;

typedef struct bstnode_t{
    ull key;
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

BSTNode* __bst__insert(BSTNode *root, ull value) {
    if (root == NULL) 
        return __createNode(value);
    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

void bst_insert(BST *bst, ull value) {
    bst->_root = __bst__insert(bst->_root, value);
    bst->_size++;
}

void __bst__inorder_search(BSTNode *root, ull s) {
    if (root) {
        __bst__inorder_search(root->left,s);
        cnt++;
        //printf("%d ", root->key);
        __bst__inorder_search(root->right,s);
        if(root->key==s) 
        {
            y=1;
            return;
        }
    }
}

void bst_inorder_search(BST *bst,ull s) {
    __bst__inorder_search(bst->_root,s);
}

int main(){
    BST set;
    bst_init(&set);
    //printf("%d", set->_size);
    int q,t;
    ull x;
    scanf("%d", &q);
    while(q--){
        cnt=0;
        y=0;
        scanf("%d %llu",&t,&x);
        if(t==1) bst_insert(&set,x);
        if(t==2){ 
            bst_inorder_search(&set,x);
            if(y) printf("%d\n", cnt);
            else printf("Data tidak ada\n");
        }
    }
}
