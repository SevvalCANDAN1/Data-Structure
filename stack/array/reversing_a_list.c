#include <stdio.h>

int pop();
void push(int stack[],int value, int size);
void display(int [], int);
int  top = -1;
int main(){
    int val, size, i;
    printf("array boyutunu giriniz: ");
    scanf("%d", &size);
    int array[size];
    int stack[size];
    printf("array elemanlarını giriniz: ");
    for(i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    for (i = 0; i < size; i++) {
        push(stack, array[i], size);
    }
    
    // Pop each element from the stack back into the array in reverse order
    for (i = 0; i < size; i++) {
        array[i] = pop(stack);
    }
    
    printf("Reversed array: ");
    display(array, size);

}
int pop(int stack[]){
    if(stack[top] < 0){
        return -1;
    }else{
        int deleted_value = stack[top];
        top--;
        return deleted_value;
    }
}
void push(int stack[],int value, int size){
    if(top>=size){
        printf("OVERFLOw\n");
    }else{
        stack[++top] = value;
    }
}
void display(int stack[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}