#include <stdio.h>
#include <stdlib.h>

typedef struct n Node;

struct n{
    int data;
    Node* next;
};

Node* push(Node*, int);
Node* pop(Node*);
void display(Node*);
int peek(Node*);

int main(){
    Node* top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = push(top, 50);
    top = push(top, 60);
    top = push(top, 70);
    top = push(top, 80);
    top = push(top, 190);
    display(top);
    printf("********\n");
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);

    display(top);
    printf("********\n");
    printf("%d\n", peek(top));


    

    return 0;


}
Node* push(Node* root, int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = data;
    if(root == NULL){
        temp -> next = NULL;
        return temp;
    }else{
        temp -> next = root;
        return temp;
    }
}
Node* pop(Node* root){
    if(root == NULL){
        return root;
    }
    else{
        Node* ptr = root -> next;
        free(root);
        return ptr;
    }
}
void display(Node* root){
    Node* iter = root;
    while(iter != NULL){
        printf("%d\n", iter -> data);
        iter = iter -> next;
    }
}
int peek(Node* root){
    if(root == NULL)
        return -1;
    return root -> data;
}


