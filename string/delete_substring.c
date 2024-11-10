#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* delete(char* text, int position, int length){
    int text_length = strlen(text);
    int new_length = text_length - length;
    char* new_string = (char*)malloc(new_length + 1);
    int i = 0, j = 0;

    while(text[i] != '\0'){
        if(i == position){
            i += length;
        }
        if(i<text_length){
            new_string[j] = text[i];
            j++;
            i++;
        }
    }
    new_string[j] = '\0';
    return new_string;
}

int main() {
    char text[] = "ABCDXXXABCD";
    int position = 4; // Silme işleminin başlayacağı pozisyon (0 tabanlı, yani 4. pozisyon 'X')
    int length = 3;   // Silinecek karakter sayısı ('XXX' silinecek)

    // Substring silme işlemini gerçekleştir
    char* result = delete(text, position, length);

    // Sonucu yazdır
    printf("Sonuç: %s\n", result);

    // Dinamik olarak ayrılan belleği serbest bırak
    free(result);

    return 0;
}