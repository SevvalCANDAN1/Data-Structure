#include <stdio.h>

#define N 15
#define K 3

int stack[N];
const int b[K] = {0, N/3, 2*N/3};
const int e[K] = {(N/3)-1, (2*N/3)-1, N-1};

int top[K] = {-1, (N/3)-1, (2*N/3)-1};

//STACKLERE ELEMAN EKLEME
void push(int stackNum, int val){
    if(top[stackNum]<= e[stackNum]){
        stack[++top[stackNum]] = val;
    }else
        printf("OVERFLOW\n");
}
//STACKLERDEN ELEMAN SİLME
int pop(int stackNum){
    if(top[stackNum]>= b[stackNum]){
        return stack[top[stackNum]--];
    }else{
        printf("EMPTY\n");
        return -1;
    }
}
void display(int stackNum){
    for(int i = top[stackNum]; i>= b[stackNum]; i--){
        printf("%d\n", stack[i]);
    }
}

int main(){

    push(0, 4444);
    push(0, 444);
    push(0, 44);
    push(0, 4);

    push(1, 1);
    push(1, 2);
    push(1, 3);


    push(2, 85);
    push(2, 75);
    push(2, 65);
    push(2, 55);
    push(2, 5);

    display(0);
    printf("******\n");
    display(1);
    printf("******\n");
    display(2);
    printf("******\n");
    int value = pop(0);
    value = pop(0);
    value = pop(0);
    value = pop(0);
    //value = pop(0);
    printf("0 -> %d\n", value);
    printf("******\n");

    value = pop(1);
    printf("1 -> %d\n", value);
    printf("******\n");

    value = pop(2);
    printf("2 -> %d\n", value);
    printf("******\n");


    display(0);
    printf("******\n");
    display(1);
    printf("******\n");
    display(2);
    printf("******\n");





    return 0;
}