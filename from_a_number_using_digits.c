#include <stdio.h>

int main(void){
    int n;
    printf("Enter the number of digits: ");
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i<n; i++){
        printf("Enter the digit at position %d :", i+1);
        scanf("%d", &array[i]);
    }
    int bas = 1;
    for(int i = 0; i<n; i++){
        bas*=10;
    }
    int num=0;
    for(int j = 1, k=0; j < bas && k<n; j*=10, k++){
        num += array[k]*j;
    }
    printf("The number is : %d\n", num);
}