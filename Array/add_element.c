#include <stdio.h>
void insert(int A[], int *N, int POS, int VAL);
void printArray(int A[], int);

int main(void) {
    int array[10] = {10, 20, 30, 40, 50, 60}; 
    int N = 6; 
    int pos, val;


    printf("Diziye eklenmek istenen pozisyonu girin (1-%d): ", N + 1);
    scanf("%d", &pos);
    printf("Diziye eklenmek istenen değeri girin: ");
    scanf("%d", &val);

   
    if (pos < 1 || pos > N + 1) {
        printf("Geçersiz pozisyon! Lütfen 1 ile %d arasında bir değer girin.\n", N + 1);
        return 1;
    }


    insert(array, &N, pos, val);

    printf("Güncellenmiş dizi: ");
    printArray(array, N);

    return 0;
}

void insert(int A[], int *N, int POS, int VAL){
    for(int i = *N; POS<=i; i--){
        A[i] = A[i-1]; 
    }
    A[POS-1] = VAL;
    *N++;
}
void printArray(int A[], int N){
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

