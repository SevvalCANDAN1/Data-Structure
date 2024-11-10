#include <stdio.h>

void func(int x){
    printf("%d\n", x);
}
void func1(int *x){
    printf("%d\n", *x);
}

int main(){
    /*int array[5]={1,2,3,4,5};
    func(array[4]);
    func1(&array[4]);

    // Adres yazdırma 
    printf("%p %p %p\n", &array[0], &array[2], array);

    //int *ptr = array;
    //int *ptr1 = array+2;
    //printf("%p %p %p\n", &array[0], ptr, ptr1);
    //printf("%d\n", ptr1 -ptr);

    int ptr1[3] ={1,2,3};
    int ptr2[4] ={4, 4, 4, 4};
    int ptr3[5] ={10, 20, 30};
    int *ptra[3] = {ptr1, ptr2, ptr3};

    for(int i = 0; i<3; i++){
        printf("%d\n", *ptra[i]);
    }*/
    char a[50] = "asdfgh";
    printf("%.2s", a);



    return 0;
}