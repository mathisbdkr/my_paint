/*
** EPITECH PROJECT, 2022
** my
** File description:
** empoty
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
