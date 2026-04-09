#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    
    printf("Enter encoded message: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        //converting to uppercase if needed
        char ch = toupper(str[i]);

        //shifting backwards by (i+1)
        ch = ch - (i + 1);

        //printing the character
        printf("%c", ch);
    }

    printf("\n");

    return 0;
}
