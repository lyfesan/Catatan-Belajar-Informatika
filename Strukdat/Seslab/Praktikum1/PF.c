#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef struct {
    int top; 
    char data[10];
}STACK;
STACK stack;

void initialization(){
    stack.top=-1;
}

bool isEmpty(){
    return (stack.top==-1) ? 1 : 0;
}

void Push(char c){
    stack.data[++stack.top]=c;
}

void Pop(){
    stack.top--;
}

char Top(){
    return stack.data[stack.top];
}

int cekDerajat(char c1, char c2){
    if((c1=='*' && c2=='+') || (c1=='*' && c2=='-') || (c1=='/' && c2=='+') || (c1=='/' && c2=='-')) return 1;
    else if((c1=='+' && c2=='*') || (c1=='-' && c2=='*') || (c1=='+' && c2=='/') || (c1=='-' && c2=='/')) return -1;
    return 0;
}

int main(){
    char s[10];
    //char operator;
    char postfix[10];
    int pos=0;
    initialization();
    scanf("%s", s);
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='0' && s[i]<='9'){
            postfix[pos++]=s[i];
        }
        else{
            if(isEmpty() || cekDerajat(s[i],Top())==1) Push(s[i]);
            else{
                while(!isEmpty() && cekDerajat(s[i],Top())<=0){
                postfix[pos++]=Top();
                Pop();
                }
                Push(s[i]);
            }
        }
    }
    while(!isEmpty()){
        postfix[pos++]=Top();
        Pop();
    }
    for(int i=0;i<strlen(s);i++){
        printf("%c", postfix[i]);
    }
    printf("\n");
}