#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    struct Node *left, *right, *parent;
};
 
// A utility function to create a new BST Node
struct Node *newNode(int item){
    struct Node *temp =  new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->parent = NULL;
    return temp;
}
 
// A utility function to do inorder traversal of BST
void inorder(struct Node *root, int x, bool &y){
    if (root != NULL){
        if(root->left!=NULL && root->right!=NULL){
            if(root->key+root->left->key+root->right->key==x) {y=true;return;}
        }
        if(root->left!=NULL && root->left->left!=NULL){
            if(root->key+root->left->key+root->left->left->key==x){y=true;return;}
        }
        if(root->right!=NULL && root->right->right!=NULL){
            if(root->key+root->right->key+root->right->right->key==x) {y=true;return;}
        }
        /*
        if(root->parent==NULL){
            if(root->left!=NULL && root->right!=NULL){
                if(root->key+root->left->key+root->right->key==x) {y=true;return;}
            }
        }
        else{
            if(root->left!=NULL){
                if(root->key+root->left->key+root->parent->key==x){y=true;return;}
            }
            else if(root->right!=NULL){
                if(root->key+root->left->key+root->parent->key==x) {y=true;return;}
            }
            else if(root->left!=NULL && root->right!=NULL){
                if(root->key+root->left->key+root->right->key==x){y=true;return;}
            }
        }
        */
        inorder(root->left,x, y);
        inorder(root->right,x, y);
    }
}
 
/* A utility function to insert a new Node with
   given key in BST */
struct Node* insert(struct Node* node, int key){
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key){
        Node *lchild = insert(node->left, key);
        node->left  = lchild;
 
        // Set parent of root of left subtree
        lchild->parent = node;
    }
    else if (key > node->key){
        Node *rchild = insert(node->right, key);
        node->right  = rchild;
 
        // Set parent of root of right subtree
        rchild->parent = node;
    }
 
    return node;
}
 
int main(){
    struct Node *root = NULL;
    int n,x,t;
    bool y=false;
    cin>>n;
    n--;
    cin>>x;
    root = insert(root, x);
    while(n--){
        cin>>x;
        insert(root, x);
    }
    cin>>t;
    inorder(root, t, y);
    //cout<<"yayaya\n";
    if(y) cout<<t<<" Selamat! Kalian menemukan harta karunnya\n";
    else cout<<t<<" Tidak ada kombinasi yang tepat! Bikin ulang.\n";
}