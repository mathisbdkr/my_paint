/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** fe
*/
#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int nbr = nb;
    if (nbr > 9) {
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    } else if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * -1;
        my_put_nbr(nbr);
    } else {
        my_putchar(nbr + '0');
    }
}
