#include <stdio.h>
#include <stdlib.h>

typedef struct n Node;
struct n{
    Node* previous;
    int x;
    Node* next;
};

Node* addElement(Node*, int);
Node* deleteElement(Node*, int);
Node* addElementInOrder(Node*, int);
void printLinkedList(Node*);

int main(void){
    Node *root = NULL;
    root = addElement(root, 40);
    root = addElementInOrder(root, 45);
    root = addElementInOrder(root, 123);
    root = addElementInOrder(root, 47);
    root = addElementInOrder(root, 53);
    printLinkedList(root);
    printf("********\n");
    root = deleteElement(root, 53);
    printLinkedList(root);
    return 0;
}
Node* addElementInOrder(Node* r, int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    if(r->x > x){
        r->previous = temp; 
        temp -> next = r;
        temp -> previous = NULL;
        temp -> x = x;
        return temp;
    }
    Node* iter = r;
    while(iter -> next != NULL && iter -> next -> x <= x){
        iter = iter -> next;  
    }
    if(iter->next != NULL)
        iter -> next -> previous = temp;
    temp -> next = iter-> next;
    temp -> previous = iter;
    iter -> next = temp;
    temp -> x = x; 
    return r;
}

Node* deleteElement(Node* r, int x){
    if(r->x == x){
        Node* temp = r ;
        r = r -> next;
        r -> previous = NULL;
        free(temp);
        return r;
    }
    Node* iter = r;
    while(iter->next != NULL){
        if(iter->next->x == x){
            Node* temp = iter->next;
            iter->next = iter->next->next;
            if(iter->next != NULL){
                iter->next->previous = iter;
            }
            free(temp);
            return r;
        }
        iter = iter -> next; 
    }
    printf("Silinecek eleman bulunamdı.\n");
    return r;
    
}

Node* addElement(Node* r, int x){
    if(r == NULL){
        r = (Node*)malloc(sizeof(Node));
        r -> previous = NULL;
        r -> x = x;
        r -> next = NULL;
        return r;
    }
    else{
        Node* iter = r;
        while(iter -> next != NULL){
            iter = iter ->next;
        }
        Node* temp = (Node*)malloc(sizeof(Node));
        iter->next = temp;
        temp -> previous = iter;
        temp -> x = x;
        temp -> next = NULL;
        return r;
    }
}

void printLinkedList(Node *r){
    while(r != NULL){
        printf("%d\n", r->x);
        r = r->next;
    }
}

