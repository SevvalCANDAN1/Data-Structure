#include <stdio.h>
#include <stdlib.h>

typedef struct n Node;
struct n{
    int x;
    Node *next;
};

void addElement(Node *, int); 
void printLinkedList(Node *);

int main(){
    Node* root = (Node*)malloc(sizeof(Node));
    root -> x = 10;
    root -> next = (Node*)malloc(sizeof(Node));
    root -> next -> x = 20;
    root -> next -> next = (Node*)malloc(sizeof(Node));
    root -> next -> next -> x = 30;
    root -> next -> next -> next = NULL;
    Node *iter = root;
    addElement(iter, 40);
    printLinkedList(root);
    return 0;
}

void addElement(Node *r, int x){
    while(r -> next != NULL){
        r = r -> next;
    }
    r -> next = (Node*)malloc(sizeof(Node));
    r = r ->next;
    r -> x = x;
    r ->next = NULL;
    
}
void printLinkedList(Node *r){
    Node *iter = r;
    while(iter != NULL){
        printf("%d\n", iter -> x);
        iter = iter -> next;
    }
}