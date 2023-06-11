#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool y=false;

struct node {
    int key;
    struct node *left, *right, *parents;
};
  
// Function to create a new BST node
struct node* newNode(int item, struct node* par)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->parents = par;
    return temp;
}
  
// Function to insert a new node with
// given key in BST
struct node* insert(struct node* node, int key, struct node* par)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key, par);
  
    // Otherwise, recur down the tree
    if (key < node->key) {
        node->left = insert(node->left, key, node);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key, node);
    }
  
    // Return the node pointer
    return node;
}
  
// Function to do inorder traversal of BST
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main(){
    struct node* root = NULL;
    int n,x,t;
    scanf("%d", &n);
    scanf("%d", &t);
    t--;
    scanf("%d", &x);
    root = insert(root, x, NULL);
    while(t--){
        scanf("%d", &x);
        insert(root, x, NULL);
    }
    inorder(root);
}