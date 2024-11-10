#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node* next;
};

Node* add(Node*, int);

int main(void){
    Node* root = (Node*)malloc(sizeof(Node));
    root -> data = 100;
    root -> next = NULL;
    root = add(root, 40);
    Node* iter = root;
    while(iter != NULL){
        printf("%d\n", iter -> data);
        iter = iter -> next;
    }
    return 0;
}

Node* add(Node* r, int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = x;
    temp -> next = r;
    return temp;
}
