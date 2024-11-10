#ifndef stack_ll
#define stack_ll

typedef struct n Node;
struct n{
    int data;
    Node *next;
};
int pop(Node**);
Node* push(Node*, int );



#endif