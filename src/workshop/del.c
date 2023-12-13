/*
** EPITECH PROJECT, 2023
** del
** File description:
** del
*/

#include "my_organise.h"

static int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return i;
}

int disp_rm(element_t *data)
{
    my_putstr(data->type);
    my_putstr(" n°");
    my_put_nbr(data->indice);
    my_putstr(" - “");
    my_putstr(data->name);
    my_putstr("” deleted.\n");
    return 0;
}

void del_element(element_t **list, int indice)
{
    element_t *to_rm = NULL;

    for (element_t *tmp = *list; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->next->indice == indice) {
            to_rm = tmp->next;
            disp_rm(to_rm);
            free(to_rm->name);
            free(to_rm->type);
            free(to_rm);
            tmp->next = tmp->next->next;
            return;
        }
    }
}

int del(void *data, char **args)
{
    int rm_nb = tab_len(args);
    element_t **list = (element_t **) data;
    element_t *to_rm = NULL;

    if (*list == NULL)
        return 84;
    for (int i = 0; i < rm_nb; i ++) {
        if ((*list)->indice == my_getnbr(args[i])) {
            to_rm = *list;
            disp_rm(to_rm);
            free(to_rm->name);
            free(to_rm->type);
            free(to_rm);
            *list = (*list)->next;
        } else
            del_element(list, my_getnbr(args[i]));
    }
    return 0;
}
