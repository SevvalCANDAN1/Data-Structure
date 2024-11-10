#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
    if(top == MAX-1){
        printf("Stack overflow\n");
    }else{
        stack[++top] = c;
    }
}
char pop(){
    if(top == -1){
        printf("UNDERFLOW\n");
        return -1;
    }else{
        return stack[top--];
    }
}
int precedence(char op){
    switch (op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix){
    char postfix[MAX];
    int j = 0;

    for(int i = 0; i<strlen(infix); i++){
        char token = infix[i];

        //Eğer karakter bir operand ise (harf ya da rakam) postfixe eklenir
        if(isalnum(token)){
            postfix[j++] = token;
        }
        //Eğer karakter '(' ise stacke push edilir
        else if(token == '('){
            push(token);
        }
        //Eğer karakter ')' ise '(' ile karşılaşana kadar stackteki her şey postfixe eklenir
        else if(token == ')'){
            while(top != -1 && stack[top] != '('){
                postfix[j++] = pop();
            }
            pop();
        }
        //Eğer karakter bir operatör
        else{
            while (top != -1 && precedence(stack[top])>=precedence(token)){
                postfix[j++] = pop();
            }
            push(token); 
        }
    }
    while(top != -1){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);

}

int main() {
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
