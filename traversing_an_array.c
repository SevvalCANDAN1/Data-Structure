#include <stdio.h>

int main(void){
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int array[n];
    int *ptr = array;
    printf("Enter the elements: ");
    for(i = 0; i<n; i++){
        scanf("%d", &array[i]);
    }
    int small = array[0];
    for(i=1; i<n; i++){
        if(small>array[i]){
            small = array[i];
            ptr = &array[i];
        }
    }
    printf("The smallest element is: %d\n", small);
    printf("The position of the smallest element in the array is : %d", (ptr-array));

}