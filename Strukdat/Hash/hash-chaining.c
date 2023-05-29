#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define size 13

typedef struct Hash{
    int data;
    bool state;
    struct Hash *next, *prev;
} Hash;

Hash *htable[size];

//Alokasi node baru
Hash *allocation(int val){
    Hash *P = (Hash*) malloc(sizeof(Hash));
    P->next=NULL;
    P->prev=NULL;
    P->state=true;
    P->data=val;
    return (P);
}

//Inisialisasi hash table
void init(){
    for(int i=0;i<size;i++){
        htable[i] = allocation(i);
    }
}

//Insert data baru
void insert(int value){ 
    int key = value % size;  
    if(htable[key]->next==NULL){
        Hash *P = allocation(value);
        P->prev = htable[key];
        P->next = NULL;
        htable[key]->next = P;
    }
    else{
        Hash *P = htable[key]->next;
        Hash *Pre;
        while(P!=NULL){
            if(P->data == value && P->state){
                printf("Data sudah ada!\n");
                return;
            }
            Pre=P;
            P=P->next;
        }
        Hash *tmp = allocation(value);
        P = tmp;
        Pre->next = P;
        P->prev = Pre;
    }
    printf("Data berhasil dimasukkan\n");
}

//Fungsi mencari node yang bernilai value, return node
Hash *find(int val){
    int key = val % size;
    Hash *tmp = htable[key]->next;
    while(tmp!=NULL){
        if(tmp->data == val){
            if(tmp->state) return tmp;
            return NULL;
        }
        tmp = tmp->next;   
    }
    return NULL;
}

void search(int val){
    Hash *P = find(val);
    if(P==NULL) printf("Data tidak ditemukan!\n");
    else printf("Data ditemukan!\n");
}

//Fungsi delete value
void del(int value){
    bool y=0;
    int key = value % size;
    Hash *P = find(value);
    if(P==NULL) printf("Data tidak ditemukan!\n");
    else{
        P->state = 0;
        printf("Data berhasil dihapus\n");
    }
}

//Print semua
void print(){
    Hash *P;
    for(int i=0;i<size;i++){
        printf("hash[%d] : ", i);
        P = htable[i]->next;
        while(P!=NULL){
            if(P->state) printf("%d ",P->data);
            P = P->next;
        }
        printf("\n");        
    }
}

int main(){
    init();
    int x;
    while(1){
        printf("Hash:\n");
        printf("1. Insert\n2. Delete\n3. Print all value\n4. Search\n5. Exit\nChoice : ");
        scanf("%d", &x);
        if(x==5) return 0;
        else if(x==1){
            scanf("%d", &x);
            insert(x);
        }
        else if(x==2){
            scanf("%d", &x);
            del(x);
            printf("Hash table after the deletion\n");
            print();
            printf("\n");
        }
        else if(x==3){
            printf("Hash table :\n");
            print();
            printf("\n");
        }
        else if(x==4){
            scanf("%d", &x);
            search(x);
        }
        else printf("Invalid number!\n");
    }

}