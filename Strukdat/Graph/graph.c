#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tipeS{
    struct tipeS *Left;
    int info;
    struct tipeS *Right;
} tipeS;

typedef struct tipeS simpul;

simpul *P, *FIRST, *LAST, *PVertex, *PEdge, *Q, *R, *S;
simpul *PointS[5];

int main(){
    int x;
    printf("Masukkan jumlah node : ");
    scanf("%d", &x);
    int A[x+5][x+5];
    memset(A,0,sizeof(A));
    char NmS[x];
    for(int i=0;i<x;i++){
        NmS[i]='A'+i;
    }
    int I,J;

    printf("Representasi graph dengan adjacency matrix %dx%d\n", x,x);
    for(I=0;I<x;I++){
        for(J=0;J<x;J++){
            if(I==J) continue;
            printf("Nilai %c -> %c : ",I+65,J+65);
            scanf("%d", &A[I][J]);
        }
    }
    
    //Simpul Vertex pertama
    I=0;J=0;
    P = (simpul*) malloc(sizeof(simpul));
    P->info = NmS[0];
    FIRST = P;
    LAST = P;
    P->Left = NULL;
    P->Right = NULL;
    PointS[0] = P;
    printf("%c", P->info);
    printf(" alamat %d ", PointS[0]);

    //Simpul Vertex yang berikutnya
    for(I=1;I<x;I++){
        P = (simpul*) malloc(sizeof(simpul));
        P->info = NmS[I];
        LAST->Left =  P;
        LAST = LAST->Left;
        P->Left = NULL;
        P->Right = NULL;
        PointS[I] = P;
        printf("\n%c ", P->info);
        printf("alamat %d ", PointS[I]);
    }
    printf("\n");

    //Simpul Edge untuk semua Vertex
    Q = FIRST;
    for(I=0; I<x; I++){
        R=Q;
        printf("Vertex %c ....", Q->info);
        for(J=0; J<x;J++){
            if(A[I][J]!=0){
                P = (simpul*) malloc(sizeof(simpul));
                P->info = A[I][J];
                P->Right = P;
                P->Left = PointS[J];
                printf(" berhubungan dengan %c: ", P->Left->info);
                printf("bobot %d;", P->info);
                P->Right = NULL;
                R = P; 
            }
        }
        printf("\n");
        Q = Q->Left;
    }
}