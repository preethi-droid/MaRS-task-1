#include <stdio.h>
#include <string.h>

//structure are used to store morse and the corresponding letter
struct Morse {
    char code[10];
    char letter;
};

//morse and letters
struct Morse morseTable[] = {
    {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},
    {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'},
    {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'},
    {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'},
    {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
    {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'},
    {"-.--", 'Y'}, {"--..", 'Z'}
};

//function to convert morse to letter
char getLetter(char *code) {
    int size = sizeof(morseTable) / sizeof(morseTable[0]);

    for (int i = 0; i < size; i++) {
        if (strcmp(code, morseTable[i].code) == 0) {
            return morseTable[i].letter;
        }
    }
    return '?'; // if not found
}

int main() {
    char input[200];
    char *word, *letter;

    printf("Enter Morse Code:\n");
    fgets(input, sizeof(input), stdin);

    //split words (3 spaces)
    word = strtok(input, "   ");

    while (word != NULL) {
        //split letters (1 space)
        letter = strtok(word, " ");

        while (letter != NULL) {
            printf("%c", getLetter(letter));
            letter = strtok(NULL, " ");
        }

        printf(" "); //space between words
        word = strtok(NULL, "   ");
    }

    return 0;
}
