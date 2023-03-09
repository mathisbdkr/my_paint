/*
** EPITECH PROJECT, 2023
** all_navy
** File description:
** my_strcat
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strcat(char* src, char* dest)
{
    int len = my_strlen(src);
    int i;
    char *a = malloc(sizeof(char) * 1000);
    my_strcpy(a, src);
    for (i = 0; dest[i] != '\0'; i++) {
        a[len + i] = dest[i];
    }
    a[len + i] = '\0';
    return a;
}
