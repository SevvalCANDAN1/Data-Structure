#include <stdio.h>
#include <stdlib.h>
#include "practise.h"

stack* define(){
    stack *s = (stack*)malloc(sizeof(stack));
    s -> dizi = NULL;
    s -> boyut = 2;
    s -> tepe = 0;
    return s;
}
void print(stack *s){
    int i = 0;
    for(i; i< s -> tepe; i++){
        printf("%d\n", s -> dizi[i]);
    }
}
int pop(stack *s){
    if(s->tepe <=0 && s -> dizi == NULL){
        return -1;
    }
    if(s ->tepe <= s -> boyut/4){
        int *dizi2 = (int*)malloc(sizeof(int)* s ->boyut/2);
        for(int i = 0; i< s -> tepe; i++){
            dizi2[i] = s ->dizi[i];
        }
        free(s ->dizi);
        s ->dizi = dizi2;
        s ->boyut /=2;
    }
    s -> tepe--;
    return s ->dizi[s ->tepe];
}
void push(int a, stack *s){
    if(s ->dizi == NULL){
        s ->dizi = (int*)malloc(sizeof(int)*s ->boyut);
    }
    if(s ->tepe>= s ->boyut-1){
        int *dizi2 = (int*)malloc(sizeof(int)*s ->boyut*2);
        for(int i = 0; i<s ->boyut; i++){
            dizi2[i] = s ->dizi[i];
        }
        free(s ->dizi);
        s ->dizi = dizi2;
        s ->boyut *=2;
        
    }


    s ->dizi[s ->tepe++] = a;
}
