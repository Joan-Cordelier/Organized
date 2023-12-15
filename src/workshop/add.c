/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include "my_organise.h"

static int check_type(char **str, int ac)
{
    for (int i = 0; i < ac; i += 2) {
        if ((my_strcmp("Actuator", str[i]) != 0 &&
            my_strcmp("Device", str[i]) != 0 &&
            my_strcmp("Processor", str[i]) != 0 &&
            my_strcmp("Sensor", str[i]) != 0 &&
            my_strcmp("Wire", str[i]) != 0) ||
            str[i] == NULL)
            return -1;
    }
    return 0;
}

int disp_add(element_t *data)
{
    my_putstr(data->type);
    my_putstr(" n°");
    my_put_nbr(data->indice);
    my_putstr(" - \"");
    my_putstr(data->name);
    my_putstr("\" added.\n");
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
    static int id = 0;
    element_t **list = (element_t **) data;
    element_t *new = NULL;

    if (add_nb == -1 || add_nb == 0 || add_nb % 2 != 0 ||
    check_type(args, add_nb) == -1)
        return 84;
    for (int i = 0; i < add_nb; i += 2) {
        new = malloc(sizeof(element_t));
        new->indice = id;
        new->name = init_str(args[i + 1]);
        new->type = init_str(args[i]);
        new->next = *list;
        *list = new;
        disp_add(new);
        id++;
    }
    return 0;
}
