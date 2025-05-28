#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <имя_файла>\n", argv[0]);
        return 1;
    }
    FILE *file;
    file  = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 2;
    }
    char longest_line[MAX_LINE_LENGTH] = "";
    char current_line[MAX_LINE_LENGTH];
    size_t max_length = 0;
    while (fgets(current_line, MAX_LINE_LENGTH, file) != NULL) {
        size_t current_length = strlen(current_line);
        if (current_length > max_length) {
            max_length = current_length;
            strncpy(longest_line, current_line, MAX_LINE_LENGTH);
        }
    }
    if (ferror(file)) {
        perror("Ошибка чтения файла");
        fclose(file);
        return 0;
    }
    fclose(file);

    if (max_length == 0) {
        printf("Файл пуст или содержит только пустые строки.\n");
        return 0;
    }
    printf("Самая длинная строка (%zu символов):\nОригинал: %s\nОбратный порядок: ", max_length, longest_line);

    for (int i = strlen(longest_line) - 1; i >= 0; i--) {
        putchar(longest_line[i]);
    }
    printf("\n");

    return 0;
}
