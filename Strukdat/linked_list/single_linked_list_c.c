#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct TNode{
    int data;
    char nama[100];
    struct TNode *next;
} TNode;

TNode *head, *tail;

void init(){
    head=NULL;
    tail=NULL;
}

bool isEmpty(){
    if(tail==NULL) return 1;
    return 0;
}

void insertDepan(int databaru, char *namabaru){
    TNode *baru;
    baru = (TNode*) malloc(sizeof(TNode));
    baru->data = databaru;
    strcpy(baru->nama,namabaru);
    baru->next = baru;
    if(isEmpty()){
        head=baru;
        tail=baru;
        head->next=head;
        tail->next=tail;
    }
    else{
        baru->next = head;
        head=baru;
        tail->next=head;
    }
    printf("Data masuk\n");
}

void insertBelakang(int databaru, char *namabaru){
    TNode *baru;
    baru = (TNode*) malloc(sizeof(TNode));
    baru->data = databaru;
    strcpy(baru->nama,namabaru);
    baru->next=baru;
    if(isEmpty()){
        head=baru;
        tail=baru;
        head->next=head;
        tail->next=tail;
    }
    else{
        tail->next=baru;
        tail=baru;
        tail->next=head;
    }
    printf("Data masuk\n");
}

void tampil(){
    TNode *b;
    b=head;
    if(!isEmpty()){
        do{
            printf("%d %s",b->data, b->nama);
            b=b->next;
        }while(b!=tail->next);
        printf("\n");
    }
    else printf("Linked list masih kosong\n");
}

int main(){
    init();
    int c=0,x;
    char y,s[100];
    while(c!=6){
        printf("1. Insert depan\n2. Insert belakang\n3. Tampilkan data di linkedlist\n4. Keluar\n");
        printf("Masukkan pilihan : ");
		scanf("%d",&c);
        y='y';
        if(c==1){
            while(y!='n'){
                printf("Input nim : ");
                scanf("%d", &x);
				getchar();
				printf("Input nama : ");
				fgets(s,100,stdin);
                insertDepan(x,s);
                printf("Insert lagi? (y/n) : ");
                scanf("%c", &y);
            }
        }
        else if (c==2){
            while(y!='n'){
                printf("Input nim : ");
                scanf("%d", &x);
				getchar();
				printf("Input nama : ");
				fgets(s,100,stdin);
				insertBelakang(x,s);
                printf("Insert lagi? (y/n): ");\
                scanf("%c", &y);
            }
        }
        //else if(c==3) hapusDepan();
        //else if(c==4) hapusBelakang();
        else if(c==3) tampil();
        else if(c==4) break;
        else printf("Input tidak valid\n");
    }
}