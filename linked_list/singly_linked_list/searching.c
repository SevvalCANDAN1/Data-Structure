#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void appendNode(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

//Linked Listte değer arama
struct Node* search(struct Node* head, int value){
    struct Node* current = head;
    while(current != NULL){
        if(current->data == value){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main(void){
    struct Node* head = NULL;
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);

    int searchValue = 20;
    struct Node* result = search(head, searchValue);

    if(result != NULL){
        printf("Değer %d bulundu.\n", result->data); 
    }
    else{
        printf("Değer bulunamadı.\n"); 
    }

    return 0;
}