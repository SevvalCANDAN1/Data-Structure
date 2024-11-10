#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* insert(char* text, int position, char* string){
    char* new_string = (char*)malloc(strlen(text) + strlen(string) + 1);
    int i = 0, j = 0;
    while(text[i] != '\0' && i < position){
        new_string[i] = text[i];
        i++;
    }
    while(string[j] != '\0'){
        new_string[i] = string[j];
        j++;
        i++;
    }

    while (text[position] != '\0') {
        new_string[i] = text[position];
        i++;
        position++;
    }
    new_string[i] = '\0';
    return new_string;
}

int main(){
    char text[] = "Hello World!";
    char string[] = "Beautiful ";
    int position = 6; // Eklemek istediğimiz pozisyon

    // Fonksiyonu çağır
    char* result = insert(text, position, string);

    // Sonucu yazdır
    printf("Sonuç: %s\n", result);

    // Belleği serbest bırak
    free(result);

    return 0;
}