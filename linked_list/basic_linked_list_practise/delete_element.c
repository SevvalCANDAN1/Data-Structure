#include <stdio.h>
#include <stdlib.h>

typedef struct n Node;
struct n{
    int x;
    Node *next;
};

Node* deleteElement(Node*, int);
Node* addElement(Node *, int); 
void printLinkedList(Node *);

int main(){
    Node *r = NULL;
    r = addElement(r, 5);
    r = addElement(r, 85);
    r = addElement(r, 185);
    r = addElement(r, 47);
    r = addElement(r, 123);
    r = addElement(r, 9);
    printLinkedList(r);
    r = deleteElement(r, 5);
    printf("*******\n");
    printLinkedList(r);

}

Node* deleteElement(Node *r, int x){
    if(r->x == x ){
        Node* temp = r;
        r = r->next;
        free(temp);
        return r;
    }

    Node* iter = r;
    Node* temp;
    while(iter -> next != NULL){
        if(iter->next -> x == x){
            temp = iter -> next->next;
            free(iter-> next);
            iter -> next = temp;
            return r;
        }
        iter = iter -> next;
    }
    printf("Silinecek karakter bulunamadı.\n");
    return r;
}

Node* addElement(Node *r, int x){
    if(r == NULL){
        r = (Node*)malloc(sizeof(Node));
        r -> next = NULL;
        r -> x = x;
        return r;
    }
    Node* iter = r;
    while(iter->next != NULL){
        iter = iter -> next;
    }
    Node* temp  = (Node*)malloc(sizeof(Node));
    iter -> next = temp;
    temp -> x = x;
    temp ->next = NULL;
    return r;
}

void printLinkedList(Node *r){
    while(r != NULL){
        printf("%d\n", r->x);
        r = r -> next;
    }
}



