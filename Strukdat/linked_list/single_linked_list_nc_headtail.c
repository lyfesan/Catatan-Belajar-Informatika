#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct TNode{
    int data;
	char nama[100];
    struct TNode *next;
}TNode; 

TNode *head,*tail;

void init(){
    head=NULL;
    tail=NULL;
}

bool isEmpty(){
    if(tail==NULL) return 1;
    return 0;
}

void insertDepan(int databaru, char s[]){
    TNode *baru;
    baru = (TNode*) malloc(sizeof(TNode));
    baru->data = databaru;
    //baru->s = sbaru;
	strcpy(baru->nama,s);
    baru->next = NULL;
    if(isEmpty()==1){
        head=tail=baru;
        tail->next=NULL;
	}
    else {
	    baru->next = head;
	    head = baru;
    }
    printf("Data masuk\n");
}

void insertBelakang(int databaru, char s[]){
	TNode *baru,*bantu;
	baru = (TNode*) malloc(sizeof(TNode));;
	baru->data = databaru;
	strcpy(baru->nama,s);
    //baru->s = sbaru;
	baru->next = NULL;
	if(isEmpty()==1){
	    head=baru;
	    tail=baru;
	    tail->next = NULL;
	}
	else {
		tail->next = baru;
		tail=baru;
	} 
	printf("Data masuk\n");
}

void tampil(){
	TNode *bantu;
	bantu = head;
	if(isEmpty()==0){
		while(bantu!=NULL){
			printf("%d %s\n",bantu->data, bantu->nama);
			bantu=bantu->next;
		}
		printf("\n");
	} else printf("Masih kosong\n");
}

void hapusDepan(){
	TNode *hapus;
	int d;
	char s[100];
	if (isEmpty()==0){
		if(head!=tail){
			hapus = head;
			d = hapus->data;
			strcpy(s,hapus->nama);
			head = head->next;
			free(hapus);
		} else {
			d = tail->data;
			strcpy(s,tail->nama);
		  	head=tail=NULL;
		}
		printf("%d %s terhapus\n",d,s);
	} else printf("Masih kosong\n");
}

void hapusBelakang(){
	TNode *bantu,*hapus;
	int d;
	char s[100];
	if (isEmpty()==0){
		bantu = head;
		if(head!=tail){
			while(bantu->next!=tail){
				bantu = bantu->next;
			}
			hapus = tail;
			tail=bantu;
			d = hapus->data;
			strcpy(s,hapus->nama);
			free(hapus);
			tail->next = NULL;
		}else {
			d = tail->data;
			strcpy(s,tail->nama);
			head=tail=NULL;
		}
		printf("%d %s terhapus\n",d,s);
	} else printf("Masih kosong\n");
}

int main(){
    init();
    int c=0,x;
    char y,s[100];
    while(c!=6){
        printf("1. Insert depan\n2. Insert belakang\n3. Hapus depan\n4. Hapus belakang\n5. Tampilkan data di linkedlist\n6. Keluar\n");
        printf("Masukkan pilihan : ");
		scanf("%d",&c);
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
        else if(c==3) hapusDepan();
        else if(c==4) hapusBelakang();
        else if(c==5) tampil();
        else if(c==6) break;
        else printf("Input tidak valid\n");
    }
}