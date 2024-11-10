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
    Node *root = (Node*)malloc(sizeof(Node));
    root -> next = NULL;
    root -> x = 500;
    int i = 0;
    for(i; i<5; i++){
        addElement(root, i*10);
    } 
    //printLinkedList(root);
    Node *iter = root;
    for(i = 0; i<3; i++){
        iter = iter -> next;
    }
    Node *temp = (Node*)malloc(sizeof(Node));
    temp -> next = iter->next;
    iter->next = temp;
    temp -> x = 8;
    printLinkedList(root);
    
    return 0;
    
}

void addElement(Node *r, int x){
    while(r -> next != NULL){
        r = r -> next;
    }
    r -> next = (Node*)malloc(sizeof(Node));
    r = r -> next;
    r -> next = NULL;
    r -> x = x;
} 
void printLinkedList(Node *r){
    while(r != NULL){
        printf("%d\n", r -> x);
        r = r -> next;
    }
}
