#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[2], "r");
    if (!file) {
        printf("Error opening file: %s\n", argv[2]);
        return 1;
    }
    int character_count = 0;
    int word_count = 0;
    char word[100];
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (strcmp(argv[1], "-c") == 0) {
            character_count++;
        } else if (strcmp(argv[1], "-w") == 0) {
            if (ch == ' ' || ch == '\n' || ch == '\t') {
                word_count++;
            }
        }
    }
    if (strcmp(argv[1], "-c") == 0) {
        printf("×Ö·ûÊý£º%d\n", character_count);
    } else if (strcmp(argv[1], "-w") == 0) {
        printf("µ¥´ÊÊý£º%d\n", word_count);
    }
    fclose(file);
    return 0;
}
