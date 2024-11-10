#include <stdio.h>

#define N 10

int top = -1;
int stack[N];

void push(int value){
    if(top < N-1){
        stack[++top] = value;
    }
    else
        printf("OVERFLOW\n");
}

int pop(){
    if(top >= 0){
        int deleted_value = stack[top];
        stack[--top];
        return deleted_value;
    }
    else{
        printf("OVERFLOW\n");
        return -1;
    }
}

void display(){
    int iter = top;
    while(iter >= 0){
        printf("%d\n", stack[iter--]);
    }
}

int peek(){
    if(top == -1){
        printf("EMPTY\n");
        return -1;
    }
    else
        return stack[top];
}

int main(){
    push(10);
    push(17);
    push(15);
    push(20);
    push(10);


    int value = pop();
    printf("%d\n", value);
    int peek_num = peek();
    printf("%d\n", peek_num);
    printf("****\n");
    display();
    return 0;

}