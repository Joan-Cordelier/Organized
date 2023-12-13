/*
** EPITECH PROJECT, 2023
** sort
** File description:
** sort
*/

#include "my_organise.h"

static int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return i;
}

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
        if (my_real_strcmp(list->name, temp->name) > 0) {
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

static int choose_function(int ac, char **av)
{
    if (ac == 0)
        return 84;
    if (av[ac][0] == 'N') {
        if(ac >= 1 && my_strcmp(av[1], "-r") == 0)
            return 2;
        return 1;
    }
    if (av[ac][0] == 'T') {
        if(ac >= 1 && my_strcmp(av[1], "-r") == 0)
            return 2;
        return 3;
    }
    if (av[ac][0] == 'I') {
        if(ac >= 1 && my_strcmp(av[1], "-r") == 0)
            return 2;
        return 5;
    }
    return 0;
}

int sort(void *data, char **args)
{
    int arg_r = tab_len(args);
    int nb_function = choose_function(arg_r, args);
    element_t **list = (element_t **) data;
    element_t *curr = *list;

    while (curr != NULL) {
        sort_by_name(curr);
        curr = curr->next;
    }
    if (nb_function == 2)
        reverse(list);
    return 0;
}
