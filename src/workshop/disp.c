/*
** EPITECH PROJECT, 2023
** disp
** File description:
** disp
*/

#include "my_organise.h"

static int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return i;
}

int disp(void *data, char **args)
{
    element_t **list = (element_t **) data;

    if (tab_len(args) != 0)
        return 84;
    for (element_t *temp = *list; temp != NULL; temp = temp->next) {
        my_putstr(temp->type);
        my_putstr(" n° ");
        my_put_nbr(temp->indice);
        my_putstr(" - “");
        my_putstr(temp->name);
        my_putstr("” added.\n");
    }
    return 0;
}
