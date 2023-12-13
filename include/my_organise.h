/*
** EPITECH PROJECT, 2023
** header
** File description:
** MY_ORGANISE_H
*/

#ifndef MY_ORGANISE_
    #define MY_ORGANISE_
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stddef.h>
    #include <limits.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <ncurses.h>
    #include "linked_list.h"
    #include "shell.h"

//my_put ...
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_putchar(char l);

//my_strcmp.c
int my_strcmp(char *s1, char *s2);

//my_getnbr.c
int my_getnbr(char const *str);

#endif /* MY_ORGANISE_ */
