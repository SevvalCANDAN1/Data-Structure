#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int data;
    Node* next;
};

Node* add(Node* , int, int);

int main(void){
    Node* root = (Node*)malloc(sizeof(Node));
    root -> data = 45;
    root -> next = NULL;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = 78;
    temp -> next = NULL;
    root -> next = temp;
    root = add(root, 78, 89);
    Node* iter = root;
    while(iter != NULL){
        printf("%d\n", iter -> data);
        iter = iter -> next;
    }

}

Node* add(Node* r, int x, int y){
    Node* iter = r;
    while(iter -> next != NULL){
        if(iter -> next -> data == x){
            Node* temp = (Node*)malloc(sizeof(Node));
            temp -> data = y;
            temp -> next = iter -> next;
            iter -> next = temp;
            return r;
        }
        iter = iter -> next;
    }
    printf("Eleman bulunamadı\n");
}
