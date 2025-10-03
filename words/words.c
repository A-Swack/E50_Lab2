#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void process_file(FILE *fp) {
    int c;
    int in_word = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            putchar(c);
            in_word = 1;
        } else {
            if (in_word) {
                putchar('\n');   // end of word
                in_word = 0;
            }
        }
    }
    // if file ended while still in a word
    if (in_word) {
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // No arguments ->  process stdin
        process_file(stdin);
    } else {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-") == 0) {
                process_file(stdin);
            } else {
                FILE *fp = fopen(argv[i], "r");
                if (!fp) {
                    fprintf(stderr, "%s: cannot open %s\n", argv[0], argv[i]);
                    return `1;  // error
                }
                process_file(fp);
                fclose(fp);
            }
        }
    }
    return 0;
}

