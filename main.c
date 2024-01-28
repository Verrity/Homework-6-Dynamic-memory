
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "subdir.h"

#define SUBSCRIBER_FIELD_SIZE 10
#define SUBDIR_SIZE 100

#define EXITMSG(msg) do { \
        perror(msg); \
        exit(EXIT_FAILURE); } while(0)

int main(){
    // Создаём справочник
    struct Subscriber* subdir_base = calloc(SUBDIR_SIZE, sizeof(struct Subscriber));
    if (subdir_base == NULL) EXITMSG("subdir_base creation error");
    // Создаём индикаторный список для быстрого опознания пустых и не пустых записей
    unsigned int last_empty = 0;
    unsigned int count_free = SUBDIR_SIZE;
    // Помечаем все записи как пустые, unsigned char для меньшей памяти
    char* subdir_list = calloc(SUBDIR_SIZE, sizeof(unsigned char));
    if (subdir_list == NULL) EXITMSG("subdir_list creation error");

    enum Subdir_command_list cmd = SUBDIR_CMD_NONE;

    printf("--- Command menu ---\n");
    printf("Code/Command\n");
    printf(" -%d- Add subscriber\n", (unsigned int)SUBDIR_CMD_ADD_SUB);
    printf(" -%d- Remove subscriber\n", (unsigned int)SUBDIR_CMD_REMOVE_SUB);
    printf(" -%d- Find subscriber by name\n", (unsigned int)SUBDIR_CMD_FIND_SUB_BY_NAME);
    printf(" -%d- Print all entries\n", (unsigned int)SUBDIR_CMD_PRINT_ALL_ENTRIES);
    printf(" -%d- Exit\n", (unsigned int)SUBDIR_CMD_EXIT);

    unsigned int input_commad = 0;

    char work = 1;
    while (work){
        printf("\nEnter command code > ");
        scanf("%u", &input_commad);
        getchar();
        cmd = input_commad;

        switch (cmd)
        {
        case SUBDIR_CMD_ADD_SUB:
                subdir_cmd_add_sub(&last_empty, &count_free, subdir_base, subdir_list);
            break;
        case SUBDIR_CMD_REMOVE_SUB:
                subdir_cmd_remove_sub(&last_empty, &count_free, subdir_base, subdir_list);
            break;
        case SUBDIR_CMD_FIND_SUB_BY_NAME:
                subdir_cmd_find_sub_by_name(subdir_base, subdir_list);
            break;
        case SUBDIR_CMD_PRINT_ALL_ENTRIES:
                subdir_cmd_print_all_entries(subdir_base, subdir_list);
            break;
        case SUBDIR_CMD_EXIT:
            work = 0;
            break;
        default:
            printf("Error: Unknown command code\n");
            break;
        }
    }

    free(subdir_base);
    free(subdir_list);
    return 0;
}

