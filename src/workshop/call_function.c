/*
** EPITECH PROJECT, 2023
** call
** File description:
** functions
*/

#include "my_organise.h"

void call_name_sort(element_t **list, element_t *curr, int nb_function)
{
    switch (nb_function) {
    case 1:
        while (curr != NULL) {
            sort_by_name(curr);
            curr = curr->next;
        }
        break;
    case 2:
        while (curr != NULL) {
            sort_by_name(curr);
            curr = curr->next;
        }
        reverse(list);
        break;
    default:
        break;
    }
}
