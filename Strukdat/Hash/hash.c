#include<stdio.h>
#include<string.h>

#define size 13

int arr[size];

void init(){
    memset(arr,-1,sizeof(arr));
}

void insert(int value){ 
    int key = value % size;  
    if(arr[key] == -1){   
        arr[key] = value;
        printf("%d masuk pada arr[%d]\n", value,key);
    }
    else{   
        printf("Terjadi Collision : arr[%d] element %d sudah ada \n",key,arr[key]);
        printf("Insert di batalkan %d\n",value);
    }
}

void del(int value){
    int key = value % size;
    if(arr[key] == value){
        arr[key] = -1;
        printf("%d is successfully deleted\n", value);
    }
    else printf("%d not present in the hash table\n",value);
}

void search(int value){
    int key = value % size;
    if(arr[key] == value) printf("Search Found\n");
    else printf("Search Not Found\n");
}

void print(){
    for(int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
}

int main()
{
    int x;
    init();
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
        else return 1;
    }
}