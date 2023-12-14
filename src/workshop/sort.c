/*
** EPITECH PROJECT, 2023
** sort
** File description:
** sort
*/

#include "my_organise.h"

void reverse(element_t **list)
{
    element_t *previous = NULL;
    element_t *current = *list;
    element_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *list = previous;
}

void sort_by_name(element_t *list)
{
    char *temp_name = NULL;
    char *temp_type = NULL;
    int temp_indice = 0;

    for (element_t *temp = list->next; temp != NULL; temp = temp->next) {
        if (my_real_strcmp(list->name, temp->name) >= 0) {
            temp_name = my_strdup(list->name);
            temp_type = my_strdup(list->type);
            temp_indice = list->indice;
            list->name = temp->name;
            list->type = temp->type;
            list->indice = temp->indice;
            temp->name = temp_name;
            temp->type = temp_type;
            temp->indice = temp_indice;
        }
    }
}

void sort_by_type(element_t *list)
{
    char *temp_name = NULL;
    char *temp_type = NULL;
    int temp_indice = 0;

    for (element_t *temp = list->next; temp != NULL; temp = temp->next) {
        if (my_real_strcmp(list->type, temp->type) >= 0) {
            temp_name = my_strdup(list->name);
            temp_type = my_strdup(list->type);
            temp_indice = list->indice;
            list->name = temp->name;
            list->type = temp->type;
            list->indice = temp->indice;
            temp->name = temp_name;
            temp->type = temp_type;
            temp->indice = temp_indice;
        }
    }
}

void sort_by_id(element_t *list)
{
    char *temp_name = NULL;
    char *temp_type = NULL;
    int temp_indice = 0;

    for (element_t *temp = list->next; temp != NULL; temp = temp->next) {
        if (list->indice >= temp->indice) {
            temp_name = my_strdup(list->name);
            temp_type = my_strdup(list->type);
            temp_indice = list->indice;
            list->name = temp->name;
            list->type = temp->type;
            list->indice = temp->indice;
            temp->name = temp_name;
            temp->type = temp_type;
            temp->indice = temp_indice;
        }
    }
}

static char **init_options(int ac, char **av)
{
    char **option = malloc(sizeof(char *) * ac);

    for (int i = 0; i < ac; i++) {
        option[i] = malloc(sizeof(char) * my_strlen(av[i]));
        option[i] = av[i];
    }
    return option;
}

static int sort_to_do_2(char **option, int nb_sort, int len)
{
    if (len - nb_sort - 2 >= 0 &&
    my_real_strcmp(option[len - nb_sort - 1], "-r") == 0 &&
    my_real_strcmp(option[len - nb_sort - 2], "ID") == 0)
        return 6;
    if (len - nb_sort - 1 >= 0 &&
    my_real_strcmp(option[len - nb_sort - 1], "ID") == 0)
        return 5;
    return 0;
}

static int sort_to_do(char **option, int nb_sort, int len)
{
    if (len - nb_sort - 2 >= 0 &&
    my_real_strcmp(option[len - nb_sort - 1], "-r") == 0 &&
    my_real_strcmp(option[len - nb_sort - 2], "NAME") == 0)
        return 2;
    if (len - nb_sort - 1 >= 0 &&
    my_real_strcmp(option[len - nb_sort - 1], "NAME") == 0)
        return 1;
    if (len - nb_sort - 2 >= 0 &&
    my_real_strcmp(option[len - nb_sort - 1], "-r") == 0 &&
    my_real_strcmp(option[len - nb_sort - 2], "TYPE") == 0)
        return 4;
    if (len - nb_sort - 1 >= 0 &&
    my_real_strcmp(option[len - nb_sort - 1], "TYPE") == 0)
        return 3;
    return sort_to_do_2(option, nb_sort, len);
}

static void make_sort(element_t **list, int sort)
{
    if (sort == 1 || sort == 2) {
        for (element_t *curr = *list; curr != NULL; curr = curr->next)
            sort_by_name(curr);
        if (sort == 2)
            reverse(list);
    }
    if (sort == 3 || sort == 4) {
        for (element_t *curr = *list; curr != NULL; curr = curr->next)
            sort_by_type(curr);
        if (sort == 4)
            reverse(list);
    }
    if (sort == 5 || sort == 6) {
        for (element_t *curr = *list; curr != NULL; curr = curr->next)
            sort_by_id(curr);
        if (sort == 6)
            reverse(list);
    }
}

int sort(void *data, char **args)
{
    int arg_r = tab_len(args);
    char **option = init_options(arg_r, args);
    int sort = 0;
    int nb_sotr = 0;
    element_t **list = (element_t **) data;

    if (arg_r < 1)
        return 84;
    for (int i = 0; i < arg_r; i++) {
        sort = sort_to_do(option, nb_sotr, arg_r);
        if (sort != 0)
            make_sort(list, sort);
        if (sort == 2 || sort == 4 || sort == 6)
            i++;
        nb_sotr++;
    }
    return 0;
}
