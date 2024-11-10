#ifndef practise_h
#define practise_h

struct s{
    int boyut;
    int tepe;
    int *dizi;
};
typedef struct s stack ;

int pop(stack *x);
void push(int a, stack *x);
void print(stack *s);
stack * define();


#endif