/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "my_organise.h"

void dealloc(element_t **list)
{
    element_t *curr = *list;
    element_t *pre = curr;

    while (curr != NULL) {
        pre = curr;
        curr = curr->next;
        free(pre->name);
        free(pre->type);
        free(pre);
    }
}

int main(void)
{
    element_t *list = NULL;

    workshop_shell(&list);
    dealloc(&list);
    return 84;
}
