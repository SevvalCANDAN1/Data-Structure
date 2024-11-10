#include "stack_ll.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Node* s = NULL;
    for(int i = 0; i <10; i++)
        s = push(s, i*5);
    //print(s);
    int value = pop(&s);
    for(int i = 0; i <10; i++){
        value = pop(&s);
        printf("%d\n", value);
    }
    
    value = pop(&s);
    //print(s);
    printf("%d\n", value);

    return 0;
}