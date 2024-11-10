#include <stdio.h>
#include <string.h>

int find_pattern(char* text, char* pattern){
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);

    int max = text_length - pattern_length +1;
    for(int i = 0; i<max; i++){
        int j = 0;

        while(j < pattern_length && text[i+j] == pattern[j]){
            j++;
        }
        if(j == pattern_length){
            return i+1;
        }
    }
    return 0;
}

int main(){
    char text[] = "Welcome to the world of programming";
    char pattern[] = "opp";
    
    // Deseni bulma
    int position = find_pattern(text, pattern);
    
    if (position != 0) {
        printf("Desen %d. pozisyonda bulundu.\n", position);
    } else {
        printf("Desen bulunamadı.\n");
    }
    
    return 0;
}
