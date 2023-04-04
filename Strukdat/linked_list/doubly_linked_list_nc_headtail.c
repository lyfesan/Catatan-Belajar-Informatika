#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct TNode{
    int data;
    struct TNode *prev,*next;
} TNode;

TNode *head,*tail;

void init(){
    head = NULL;
    tail = NULL;
}

bool isEmpty(){
    if(tail==NULL) return true;
    return false;
}

void insertDepan(int databaru){
    TNode *baru,*bantu;
    baru = (TNode*) malloc(sizeof(TNode));
    bantu = (TNode*) malloc(sizeof(TNode));
    baru->data = databaru;
    baru->next = NULL;
    baru->prev = NULL;
    if(isEmpty()){
        bantu->data=1;
        bantu->next = NULL;
        bantu->prev = NULL;
        head = bantu;
        tail = baru;
        head->next = tail;
        head->prev = NULL;
        tail->prev = head;
        tail->next = NULL;
    }
    else{
        bantu->data=++head->data;
        bantu->next = head;
        bantu->prev = NULL;
        head->prev = bantu;
        head = bantu;
        head->next->data = databaru;
        head->prev=NULL;
    }
    printf("Data masuk\n");
}

void insertBelakang(int databaru){
    TNode *baru,*bantu;
	baru = (TNode*)malloc(sizeof(TNode));
    bantu = (TNode*)malloc(sizeof(TNode));
	baru->data = databaru;
	baru->next = NULL;
	baru->prev = NULL;
	if(isEmpty()){
        bantu->data=1;
        bantu->next = NULL;
        bantu->prev = NULL;
        head = bantu;
        tail = baru;
        head->next = tail;
        head->prev = NULL;
        tail->prev = head;
        tail->next = NULL;
	}
	else {
        head->data++;
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        tail->next = NULL;
	}
	printf("Data masuk\n");
}

void tampil(){
    TNode *bantu;
	bantu = head;
	if(!isEmpty()){
		while(bantu!=NULL){
            printf("%d ", bantu->data);
			bantu=bantu->next;
		}
		printf("\n");
	} else printf("Masih kosong\n");
}

void tampilBelakang(){
    TNode *bantu;
    bantu = tail;
    if(!isEmpty()){
        while(bantu!=NULL){
            printf("%d ", bantu->data);
            bantu = bantu->prev;
        }
        printf("\n");
    }
    else printf("Masih kosong\n");
}

void hapusDepan(){
	TNode *hapus;
	int d;
	if (!isEmpty()){
        if(head->next->next != NULL){
            d = head->next->data;
            head->next->data=head->data--;
            hapus = head;
            head = head->next;
            head->prev = NULL;
            free(hapus);
        } else {
            d = head->next->data;
            head = NULL;
            tail = NULL;
        }
        printf("%d terhapus\n",d);
	} 
    else printf("Masih kosong\n");
}

void hapusBelakang(){
	TNode *hapus;
	int d;
	if (!isEmpty()){
        if(head->next->next != NULL){
            hapus = tail;
            d = tail->data;
            tail = tail->prev;
            tail->next = NULL;
            free(hapus);
        } else {
            d = head->next->data;
            head = NULL;
            tail = NULL;
        }
        printf("%d terhapus\n",d);
	} 
    else printf("Masih kosong\n");
}

void clear(){
    TNode *bantu,*hapus;
	bantu = head;
	while(bantu!=NULL){
		hapus = bantu;
		bantu = bantu->next;
		free(hapus);
	}
	head = NULL;
	tail = NULL;	
}

void jumlahData(){
    if(!isEmpty()) printf("%d\n", head->data);
    else printf("Masih kosong\n");
}

int main(){
    init();
    int c=0,x;
    char y;
    while(c!=8){
        y="";
        printf("1. Insert depan\n2. Insert belakang\n3. Hapus depan\n4. Hapus belakang\n5. Tampilkan data\n6. Tampilkan data dari belakang\n7. Jumlah data\n8. Keluar\n");
        printf("Masukkan pilihan : ");
		scanf("%d",&c);
        if(c==1){
            while(y!='n'){
                printf("Input data : ");
                scanf("%d", &x);
                getchar();
                insertDepan(x);
                printf("Insert lagi? (y/n) : ");
                scanf("%c", &y);
            }
        }
        else if (c==2){
            while(y!='n'){
                printf("Input data : ");
                scanf("%d", &x);
                getchar();
				insertBelakang(x);
                printf("Insert lagi? (y/n): ");\
                scanf("%c", &y);
            }
        }
        else if(c==3) hapusDepan();
        else if(c==4) hapusBelakang();
        else if(c==5) tampil();
        else if(c==6) tampilBelakang();
        else if(c==7) jumlahData();
        else if(c==8) break;
        else printf("Input tidak valid\n");
    }
}