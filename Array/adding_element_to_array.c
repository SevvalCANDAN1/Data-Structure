#include <stdio.h>

int main(void){
    int array[10] = {1,2,3,4,5,6};
    int i = 0;
    while(array[i] != 0 && i != sizeof(array)/ sizeof(array[0])){
        i++;
    }
    if (i < sizeof(array) / sizeof(array[0])) {
        int num = 23;
        array[i] = num; // Boş yere 23'ü ekle
    }
    for(int j; j<10; j++){
        printf("%d\n", array[j]);
    }
}