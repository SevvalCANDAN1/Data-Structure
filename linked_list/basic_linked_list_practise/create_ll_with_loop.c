#include <stdio.h>
#include <stdlib.h>

typedef struct n Node;
struct n{
    int x;
    Node* next;
};

int main(void){
    Node* root = (Node*)malloc(sizeof(Node));
    root -> x = 10;
    root -> next = (Node*)malloc(sizeof(Node));
    root -> next -> x = 20;
    root -> next -> next = (Node*)malloc(sizeof(Node));
    root -> next -> next -> x = 30;
    root -> next -> next -> next = NULL;


    Node *iter;
    iter = root;
    while(iter != NULL){
        printf("%d\n", iter->x);
        iter = iter -> next;
    }

    return 0;
}