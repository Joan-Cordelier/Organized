/*
** EPITECH PROJECT, 2023
** cmopare str
** File description:
** str
*/

#include "my_organise.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != 0) {
        i++;
    }
    return (i);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strdup(char const *src)
{
    char *dest = NULL;
    char *i = NULL;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    i = my_strcpy(dest, src);
    return (i);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    char *str1 = my_strdup(s1);
    char *str2 = my_strdup(s2);

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < 97)
            str1[i] += 32;
        if (str2[i] < 97)
            str2[i] += 32;
        if (str1[i] != str2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

int my_real_strcmp(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return (str1[i] - str2[i]);
}
