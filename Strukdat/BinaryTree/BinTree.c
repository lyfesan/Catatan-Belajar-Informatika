#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
}Tree;

bool isEmpty(Tree*root){
    if(root==NULL) return 1;
    return 0;
}

void insert(Tree **root, int newdata){
    if((*root) == NULL){
        Tree *baru = (Tree*) malloc(sizeof(Tree));
        baru->data = newdata;
        baru->left = NULL;
        baru->right =  NULL;
        (*root) = baru;
        (*root)->left = NULL;
        (*root)->right = NULL;
        printf("Data masuk\n");
    }
    else if(newdata < (*root)->data) insert(&(*root)->left,newdata);
	else if(newdata > (*root)->data) insert(&(*root)->right,newdata);
	else if(newdata == (*root)->data) printf("Data sudah ada!\n");
}

void preOrder(Tree *root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Tree *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void postOrder(Tree *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

Tree *search(Tree *root, int dat){
    if(root==NULL) return NULL;
    else if(dat < root->data) return search(root->left, dat);
    else if(dat > root->data) return search(root->right, dat);
    else return root;
}

void cari(Tree *root, int dat){
    Tree *ketemu = search(root,dat);
    if(ketemu==NULL) printf("Data tidak ditemukan\n");
    else printf("Data ketemu!\n");
}

int countNode(Tree *root)
{
	 if (root == NULL) return 0;
	 return countNode(root->left) + countNode(root->right) + 1;
}

int height(Tree *root)
{
	 if (root == NULL) return -1;
	 int u = height(root->left), v = height(root->right);
	 if (u > v) return u+1;
	 else return v+1;
}   

Tree *findMin(Tree *root)
{
	if(root == NULL) return NULL;
	else{
		if(root->left == NULL) return root;
		else return findMin(root->left);
    }
}

void cariMin(Tree *root){
    Tree *mins = findMin(root);
    if(mins == NULL) printf("Tree kosong!\n");
    else printf("%d\n", mins->data);
}

Tree *findMax(Tree *root)
{
	if(root == NULL) return NULL;
	else{
		if(root->right == NULL) return root;
		else return findMax(root->right);
    }
}

void cariMaks(Tree *root){
    Tree *maks = findMax(root);
    if(maks == NULL) printf("Tree kosong!\n");
    else printf("%d\n", maks->data);
}

void leaf(Tree *root){
    if(root == NULL) printf("Tree kosong!\n");
    if(root->left!=NULL) leaf(root->left);
	if(root->right!=NULL) leaf(root->right);
    if(root->right == NULL && root->left == NULL) printf("%d ",root->data);
}

int main(){
    Tree *pohon = NULL;
    int c,x;
    while(1){
        printf("Program Tree...\n");
        printf("1. Insert data\n2. Traverse Tree Preorder\n3. Traverse Tree Inorder\n4. Traverse Tree Postorder\n5. Cari data\n6. Hitung jumlah node\n7. Tinggi Tree\n8. Cari Node Min\n9. Cari Node Max\n10. Print Semua Leaf\n11. Exit\n");
        printf("Masukkan Pilihan : ");
        scanf("%d", &c);
        switch(c){
            case 1:
                printf("Masukkan data : ");
                scanf("%d", &x);
                insert(&pohon, x);
                break;
            case 2:
                preOrder(pohon);
                printf("\n");
                break;
            case 3:
                inOrder(pohon);
                printf("\n");
                break;
            case 4:
                postOrder(pohon);
                printf("\n");
                break;
            case 5:
                printf("Masukkan data yang ingin dicari : ");
                scanf("%d", &x);
                cari(pohon, x);
                break;
            case 6:
                printf("Jumlah Node : %d\n", countNode(pohon));
                break;
            case 7:
                printf("Tinggi Tree : %d\n", height(pohon));
                break;
            case 8:
                cariMin(pohon);
                break;
            case 9:
                cariMaks(pohon);
                break;
            case 10:
                leaf(pohon);
                printf("\n");
                break;
            case 11:
                return 0;
                break;
        }
    }
}