#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int data;
    Node* next;
};

Node* add_element(Node*, int);

int main(void){
    Node* root = (Node*)malloc(sizeof(Node));
    root -> data = 45;
    root -> next = NULL;
    root = add_element(root, 87);
    root = add_element(root, 123);
    root = add_element(root, 250);
    root = add_element(root, 300);
    Node* iter = root;
    while(iter != NULL){
        printf("%d\n", iter -> data);
        iter = iter -> next;
    }
    return 0;

}

Node* add_element(Node* r, int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    Node* iter = r;
    temp -> data = x;
    while(iter-> next != NULL){
        iter = iter -> next;
    }
    iter -> next = temp;
    temp -> next = NULL;
    return r;
}