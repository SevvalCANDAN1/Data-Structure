#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

int pop(Node** root){
    if(*root == NULL){
        return -1;
    }
    if((*root) -> next == NULL){
        int rvalue = (*root) -> data;
        free(*root);
        *root = NULL;
        return rvalue;

    }
    Node *iter = *root;
    while((iter) -> next -> next!= NULL){
        (iter) = (iter) -> next;
    }
    Node* temp = (iter) -> next ;
    int rvalue = (iter)-> next -> data;
    free(temp);
    (iter) -> next = NULL;
    return rvalue;
    
}

Node* push(Node* root, int a){
    if(root == NULL){
        root = (Node*)malloc(sizeof(Node));
        root -> data = a;
        root -> next = NULL;
        return root;
    }
    Node* iter = root;
    while(iter -> next != NULL){
        iter = iter -> next;
    }
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = a;
    iter -> next = temp;
    temp -> next = NULL;
    return root;
}

void print(Node* root){
    Node* iter = root;
    while(iter != NULL){
        printf("%d\n", iter -> data);
        iter = iter->next;
    }

}
