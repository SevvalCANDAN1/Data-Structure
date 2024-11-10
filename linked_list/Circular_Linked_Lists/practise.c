#include <stdio.h>
#include <stdlib.h>

typedef struct n Node;
struct n{
    int x;
    Node *next;
};

void printCircularLinkedList(Node *);
void addElements(Node *, int);
Node* addElementsInOrder(Node*, int);
Node* deleteElementInCircularLL(Node*, int); 

int main(void){
    Node *root = (Node*)malloc(sizeof(Node));
    root = NULL;
    root = addElementsInOrder(root, 400);
    root = addElementsInOrder(root, 40);
    root = addElementsInOrder(root, 4);
    root = addElementsInOrder(root, 450);
    root = addElementsInOrder(root, 50);
    printCircularLinkedList(root);
    printf("******\n");
    root = deleteElementInCircularLL(root, 451);
    printCircularLinkedList(root);


    return 0;
}

void printCircularLinkedList(Node *r){
    Node* iter = r;
    printf("%d\n", iter->x);
    iter = iter -> next;
    while(iter != r){
        printf("%d\n", iter->x);
        iter = iter -> next;
    }
}

void addElements(Node *r, int x){
    Node *iter = r;
    while(iter -> next != r){
        iter = iter -> next;
    }
    iter -> next = (Node*)malloc(sizeof(Node));
    iter -> next -> x = x;
    iter -> next -> next = r;
}

Node* addElementsInOrder(Node *r, int x){
    if(r == NULL){ //Boşsa
        r = (Node*)malloc(sizeof(Node));
        r -> next = r;
        r -> x = x;
        return r;
    }
    if(r->x > x){
        Node *temp = (Node*)malloc(sizeof(Node));
        temp -> x = x;
        temp -> next = r;
        Node *iter = r;
        while(iter-> next != r){
            iter = iter -> next;
        }
        iter -> next = temp;
        return temp;
    }
    Node *iter = r;
    while(iter -> next != r && iter -> next -> x < x){
        iter = iter -> next;
    }
    Node *temp = (Node*)malloc(sizeof(Node));
    temp -> x = x;
    temp ->  next = iter -> next;
    iter -> next = temp;
    return r;
}

Node* deleteElementInCircularLL(Node *r, int x){
    Node *temp ;//= (Node*)malloc(sizeof(Node));
    Node *iter = r;
    if(r->x == x){
        while(iter -> next != r){
            iter = iter -> next;
        }
        iter -> next = r -> next;
        free(r);
        r = iter -> next;
        return r;
    }
    while(iter->next != r){
        if(iter -> next -> x == x){
            temp = iter -> next;
            iter -> next = iter -> next -> next;
            temp = NULL;
            free(temp);
            return r;
        }
        iter = iter-> next;
    }
    printf("Silinmek istenen eleman listede yok\n");
    return r;
}