#include <stdio.h>
#include <stdlib.h>

typedef struct n Node;
struct n{
    int data;
    Node* next;
};



int main(void){
    Node *root = (Node*)malloc(sizeof(Node)); //Başlangıç nodenu oluşturduk.
    root -> data = 10;
    root -> next = (Node*)malloc(sizeof(Node));
    root -> next -> data = 20;
    root -> next -> next = (Node*)malloc(sizeof(Node));
    root -> next -> next -> data = 30;
    Node* iter;
    iter = root; //Iteri başlangıca eşitledik.
    printf("%d\n", iter -> data);
    iter = iter->next;
    printf("%d\n", iter -> data);

    return 0;

}