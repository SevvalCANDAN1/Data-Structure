#include <stdio.h>
#include <stdlib.h>

// Node tanımlıyoruz.

struct Node {
    int data; //Veri
    struct Node* next; //Sonraki node'un pointerı
};

// Yeni bir node oluşturmak için fonksiyon
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
};

//Linked List düğüm ekleyen fonksiyon (Listenin sonuna ekler)
void appendNode(struct Node** head, int data){
    struct Node* newNode = createNode(data); //Yeni düğüm oluşturur
    if(*head == NULL){
        *head = newNode; //Liste boşsa yeni düğümü ilk düğüm olarak ata
        return;
    }
    struct Node* temp = *head;
    while(temp ->next != NULL){ //Listenin sonuna kadar git
        temp = temp -> next;
    }
    temp -> next = newNode; //Son düğümün nextini yeni düğüme bağla
}

//Linked Listi ekrana bastırma
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Bellekte yer açılan düğümleri temizleyen fonksiyon
void freeList(struct Node* head){
    struct Node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void){
    struct Node* head = NULL;
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);

    // Listeyi ekrana yazdır
    printf("Linked List: ");
    printList(head);

    // Bellek temizleme
    freeList(head);

    return 0;
}
