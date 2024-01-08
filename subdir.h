#ifndef SUBDIR_H
#define SUBDIR_H

#define SUBSCRIBER_FIELD_SIZE 10
#define SUBDIR_SIZE 100

struct Subscriber {
    char name[SUBSCRIBER_FIELD_SIZE];
    char second_name[SUBSCRIBER_FIELD_SIZE];
    char tel[SUBSCRIBER_FIELD_SIZE];
};

enum Subdir_command_list {
    SUBDIR_CMD_NONE,
    SUBDIR_CMD_ADD_SUB,
    SUBDIR_CMD_REMOVE_SUB,
    SUBDIR_CMD_FIND_SUB_BY_NAME,
    SUBDIR_CMD_PRINT_ALL_ENTRIES,
    SUBDIR_CMD_EXIT
};

void subdir_cmd_add_sub(unsigned int *last_empty, unsigned int *count_free, struct Subscriber *subdir_base, char *subdir_list);
void subdir_cmd_remove_sub(unsigned int *last_empty, unsigned int *count_free, struct Subscriber *subdir_base, char *subdir_list);
void subdir_cmd_find_sub_by_name(struct Subscriber *subdir_base, char *subdir_list);
void subdir_cmd_print_all_entries(struct Subscriber *subdir_base, char *subdir_list);

#endif // SUBDIR_H