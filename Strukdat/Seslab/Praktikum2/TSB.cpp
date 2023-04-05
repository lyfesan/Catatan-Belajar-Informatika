#include<bits/stdc++.h>
using namespace std;

typedef struct bstnode_t{
    string key;
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

BSTNode* __createNode(string value) {
    BSTNode *newNode = new(BSTNode);
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

BSTNode* __bst__insert(BSTNode *root, string value) {
    if (root == NULL) 
        return __createNode(value);
    if (root->key<value)
        root->left = __bst__insert(root->left, value);
    else if (root->key>value)
        root->right = __bst__insert(root->right, value);
    return root;
}

void bst_insert(BST *bst, string value) {
    bst->_root = __bst__insert(bst->_root, value);
    bst->_size++;
}

BSTNode* __bst_search_anak(BSTNode *root, string value) {
    while (root != NULL) {
        if (root->key<value)
            root = root->left;
        else if (root->key>value)
            root = root->right;
        else
            return root;
    }
    return root;
}

void bst_find_anak(BST *bst, string value) {
    BSTNode *temp = __bst_search_anak(bst->_root, value);
    if (temp->left==NULL && temp->right==NULL) cout<<"Aku Sedih!! Tidak Memiliki Anak:)";
    else {
        if(temp->left!=NULL){
            cout<<temp->left->key<<" ";
        }
        else cout<<"- ";
        if(temp->right!=NULL){
            cout<<temp->right->key;
        }
        else cout<<"-";
    }
}

void bst_find_ibu(BST *bst, string value){
    BSTNode *root = bst->_root;
    while(root!=NULL){
        if(root->left!=NULL){
            if(root->left->key==value){
                cout<<root->key;
                break;
            }
        }
        if(root->right!=NULL){
            if(root->right->key==value){
                cout<<root->key;
                break;
            }
        }
        if(root->key<value) root=root->left;
        else if(root->key>value) root=root->right;
    }
}

int main(){
    BST fam;
    bst_init(&fam);
    int n,q;
    string s,o,akar;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s;
        if(i==0) akar=s;
        bst_insert(&fam,s);
    }
    while(q--){
        cin>>o>>s;
        if(o=="Ibu"){
            if(s==akar) cout<<"Aku Adalah Pemimpin Keluarga Ini! HAHAHA";
            else bst_find_ibu(&fam,s);
        }
        else if(o=="Anak"){
            bst_find_anak(&fam,s);
        }
        cout<<"\n";
    }
}