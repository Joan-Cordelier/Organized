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

int sort(void *data, char **args)
{
    int arg_r = tab_len(args) - 1;
    element_t **list = (element_t **) data;

    if (args[arg_r][0] == '-' && args[arg_r][1] == 'r')
        reverse(list);
    return 0;
}
