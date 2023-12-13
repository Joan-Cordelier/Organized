/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** écrit un int entré en paramètre
*/

#include "my_organise.h"

int my_recursive(int nb, int *len)
{
    char reste;

    if (nb == 0)
        return *len;
    reste = nb % 10;
    nb = nb - reste;
    my_recursive(nb / 10, len);
    my_putchar(reste + 48);
    *len += 1;
    return *len;
}

int my_put_nbr(int nb)
{
    int len = 0;

    if (nb == -2147483648) {
        len += my_putchar('-');
        len += my_putchar('2');
        nb = nb + 2000000000;
        nb = -nb;
    }
    if (nb < 0) {
        len += my_putchar('-');
        nb = - nb;
    }
    if (nb == 0)
        len += my_putchar('0');
    return (my_recursive(nb, &len));
}
