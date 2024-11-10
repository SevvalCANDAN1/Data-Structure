#include "practise.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    stack *s1 = define();
    stack *s2 = define();
    for(int i = 0; i<10; i++){
        push(i*10, s1);
    }
    print(s1);
    for(int i = 0; i<10; i++){
        push(pop(s1),s2);
    }
    print(s2);
    

}