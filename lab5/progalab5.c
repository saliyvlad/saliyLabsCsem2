#include <stdio.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_RECORDS 100

typedef struct {
    char name[MAX_NAME];
    int price;
    int code;
} Toy;


void create_file(const char *filename, int n) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Ошибка открытия файла для записи.\n");
        return;
    }

    Toy toy;
    for (int i = 0; i < n; i++) {
        printf("Введите данные для игрушки %d:\n", i + 1);
        printf("Название: ");
        scanf("%s", toy.name);
        printf("Стоимость: ");
        scanf("%d", &toy.price);
        printf("Код товара: ");
        scanf("%d", &toy.code);

        fwrite(&toy, sizeof(Toy), 1, file);
    }

    fclose(file);
    printf("Файл успешно создан и заполнен.\n");
}


void search_in_file(const char *filename, int field) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка открытия файла для чтения.\n");
        return;
    }

    Toy toy;
    int found = 0;
    char search_name[MAX_NAME];
    int search_price;
    int search_code;

    switch (field) {
        case 1:
            printf("Введите название игрушки для поиска: ");
            scanf("%s", search_name);
            break;
        case 2:
            printf("Введите стоимость игрушки для поиска: ");
            scanf("%d", &search_price);
            break;
        case 3:
            printf("Введите код товара для поиска: ");
            scanf("%d", &search_code);
            break;
        default:
            printf("Неверный выбор поля.\n");
            fclose(file);
            return;
    }

    while (fread(&toy, sizeof(Toy), 1, file) == 1) {
        if ((field == 1 && strcmp(toy.name, search_name) == 0) ||
            (field == 2 && toy.price == search_price) ||
            (field == 3 && toy.code == search_code)) {
            printf("Найдена игрушка: Название: %s, Стоимость: %d, Код товара: %d\n", toy.name, toy.price, toy.code);
            found = 1;
        }
    }

    if (!found) {
        printf("Игрушка с указанными данными не найдена.\n");
    }

    fclose(file);
}

int main() {
    const char *filename = "ToysPrice.dat";
    int n, choice;

    printf("Введите количество записей: ");
    scanf("%d", &n);

    create_file(filename, n);

    printf("Выберите поле для поиска:\n");
    printf("1. Название\n");
    printf("2. Стоимость\n");
    printf("3. Код товара\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    search_in_file(filename, choice);

    return 0;
}
