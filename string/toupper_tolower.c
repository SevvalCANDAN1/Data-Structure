#include <stdio.h>

char *toupperr(char *A){
    char *ptr = A;
    while(*ptr != '\0'){
        if(*ptr >= 'a'&& *ptr <= 'z'){
            *ptr -= 'a' -'A'; 
        }
        *ptr++;
    }
    return A;
}

char *tolowerr(char *A){
    char *ptr = A;
    while(*ptr != '\0'){
        if(*ptr<= 'Z' && *ptr >= 'A'){
            *ptr += 'a' -'A';
        }
        ptr++;
    }
    return A;
}
int main(){
    char a[50] = "asAERFFHBNJdsAFadas";
    printf("%s\n", toupperr(a));
    printf("%s\n", tolowerr(a));

}