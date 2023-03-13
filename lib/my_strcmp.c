/*
** EPITECH PROJECT, 2023
** all_navy
** File description:
** my_strcmp
*/

#include "../include/my.h"

int my_strcmp(const char* s1, const char* s2)
{
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    return s1[i] - s2[i];
}
