#include <stdio.h>
#include <stdlib.h>

typedef struct n Node;
struct n{
    int x;
    Node *next;
};

void printLinkedList(Node *);
Node* addElementInOrder(Node *, int); 

int main(void){
    Node *root = (Node*)malloc(sizeof(Node));
    root = NULL;
    root = addElementInOrder(root, 400);
    root = addElementInOrder(root, 40);
    root = addElementInOrder(root, 4);
    root = addElementInOrder(root, 450);
    root = addElementInOrder(root, 50);
    printLinkedList(root);

    return 0;
}

Node* addElementInOrder(Node *r, int x){
    //LinkedList'in boş olduğu durum
    if(r == NULL){ 
        r = (Node*)malloc(sizeof(Node));
        r -> next = NULL;
        r -> x = x;
        return r;
    }
    if(r->x > x){
        //İlk elemandan küçük olma durumu
        //Rootu değiştirmemiz lazım. Çünkü ilk elemanı değiştireceğiz.
        Node * temp = (Node*)malloc(sizeof(Node));
        temp -> x = x;
        temp -> next = r;
        return temp;
    }
    Node *iter = r;
    while(iter->next != NULL && iter -> next -> x < x){
        iter = iter -> next;
    }
    Node *temp = (Node*)malloc(sizeof(Node));
    temp -> next = iter->next;
    temp -> x = x;
    iter -> next = temp;
    return r;
}

void printLinkedList(Node *r){
    while(r !=NULL){
        printf("%d\n", r -> x);
        r = r -> next;
    }
}