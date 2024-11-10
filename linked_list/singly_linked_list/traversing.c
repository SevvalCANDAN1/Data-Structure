#include <stdio.h>
#include <stdlib.h>

//Bir node yapısını tanımlıyoruz
struct Node {
    int data;
    struct Node* next;
};

//Yeni bir node eklemek için bir fonksiyon tanımlama (Başa node ekleme)
struct Node* addNode(struct Node* head, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

//Linked Listte Dolaşma 
void traverseList(struct Node* head){
    struct Node* ptr = head; //ptr değişkenini ilk node ayarlıyoruz

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    
}

//Düğüm sayısını bulma
int countNodes(struct Node* head){
    int count = 0;
    struct Node* ptr = head;

    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}

int main(){
    struct Node* head = NULL;

    head = addNode(head, 10);   
    head = addNode(head, 20);   
    head = addNode(head, 30);

    printf("Linked List: ");
    traverseList(head);
    int nodeCount = countNodes(head);
    printf("Node Count: %d\n", nodeCount);

    return 0;
}