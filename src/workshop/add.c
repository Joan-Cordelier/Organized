/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include "my_organise.h"

static int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    if (i % 2 != 0)
        return -1;
    return i;
}

static int get_indice(element_t *data)
{
    int i = 0;

    for (element_t *temp = data; temp != NULL; temp = temp->next)
        i++;
    return i;
}

static int check_type(char *str)
{
    if (my_strcmp("Actuator", str) != 0 &&
        my_strcmp("Device", str) != 0 &&
        my_strcmp("Processor", str) != 0 &&
        my_strcmp("Sensor", str) != 0 &&
        my_strcmp("Wire", str) != 0)
        return -1;
    return 0;
}

int disp_add(element_t *data)
{
    my_putstr(data->type);
    my_putstr(" n°");
    my_put_nbr(data->indice);
    my_putstr(" - “");
    my_putstr(data->name);
    my_putstr("” added.\n");
    return 0;
}

char *init_str(char *str)
{
    char *copy = NULL;
    int compt = 0;

    for (int i = 0; str[i] != '\0'; i++)
        compt++;
    copy = malloc(sizeof(char) * compt + 1);
    for (int i = 0; str[i] != '\0'; i++)
        copy[i] = str[i];
    copy[compt] = '\0';
    return copy;
}

int add(void *data, char **args)
{
    int add_nb = tab_len(args);
    element_t **list = (element_t **) data;
    element_t *new = NULL;

    for (int i = 0; i < add_nb; i += 2) {
        new = malloc(sizeof(element_t));
        new->indice = get_indice(*list);
        new->name = init_str(args[i + 1]);
        if (check_type(args[i]) == -1)
            return 84;
        new->type = init_str(args[i]);
        new->next = *list;
        *list = new;
        disp_add(new);
    }
    if (add_nb == -1 || add_nb == 0)
        return 84;
    return 0;
}
