/*
** EPITECH PROJECT, 2023
** header
** File description:
** struct.h
*/

#ifndef STRUCT_ORGANISE_
    # define STRUCT_ORGANISE_

typedef struct element {
    char *type;
    char *name;
    int indice;
    struct element *next;
    struct element *previous;
}element_t;
#endif /* STRUCT_ORGANISE_ */
