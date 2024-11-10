#include <stdio.h>
#include <stdlib.h>

typedef struct n Node;
struct n{
    int x;
    Node* next;
};

void printLinkedList(Node *);

int main(void){
    Node* root = (Node*)malloc(sizeof(Node));
    root -> x = 10;
    root -> next = (Node*)malloc(sizeof(Node));
    root -> next -> x = 20;
    root -> next -> next = (Node*)malloc(sizeof(Node));
    root -> next -> next -> x = 30;
    root -> next -> next -> next = NULL;
    printLinkedList(root);

    return 0;

}
void printLinkedList(Node *r){
    Node *iter = r;
    while(iter != NULL){
        printf("%d\n", iter -> x);
        iter = iter -> next;
    }
}
