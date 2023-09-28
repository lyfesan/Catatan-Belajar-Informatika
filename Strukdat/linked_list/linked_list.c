#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Mahasiswa{
    int nim;    
    char nama[100];
    struct Mahasiswa *next;
} Mahasiswa;

void init(Mahasiswa **p){
    *p=NULL;
}

Mahasiswa *alokasi(/*int num, char name[]*/){
        Mahasiswa *P;
        P = (Mahasiswa*) malloc(sizeof(Mahasiswa));
        if(P!=NULL){
            P->next=NULL;
            //P->nim=num;
            //strcpy(P->nama,name);
        }
        return (P);
}

void Add(Mahasiswa **p){
    *p=alokasi();
    scanf("%d %s",&(*p)->nim, (*p)->nama);
    printf("%d %s\n",(*p)->nim, (*p)->nama);
}

Mahasiswa *adding(Mahasiswa *p,int nim, char nama[]){
    p=alokasi(/*int nim, char name[]*/);
    printf("Ini ada di fungsi add %d %s\n", (p)->nim);
    return p;
}
/*
void print_list(Mahasiswa **p){
    Mahasiswa *current = &p;
    while(current!=NULL){
        printf("%d %s\n", current->nim, current->nama);
        current=current->next;
    }
}
*/

int main(){
    Mahasiswa *head;
    //Mahasiswa *first = &head;
    int x,n;
    //char s[50];
    init(&head);
    scanf("%d", &n);
    while(n--){
        //scanf("%d %s",&x,s);
        Add(&head);
    }
    
    Mahasiswa *now = head;
    while(now!=NULL){
        printf("%d %s\n", now->nim, now->nama);
        now = now->next;
    }
    //print_list(&head);

    printf("\n");
}