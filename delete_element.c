#include <stdio.h>

int main(void){
    int array[60] = {10, 20, 30, 40};
    int i = 0;
    while(array[i] != 0){
        i++;
    }
    array[i-1] = 0;
    for(i = 0; i<60; i++){
        printf("%d ", array[i]);
    }
}