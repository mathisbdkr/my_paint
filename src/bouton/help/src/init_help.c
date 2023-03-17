/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** init_struct
*/

#include "../include/my.h"

void init_help(struct help_t *help)
{
    sfVideoMode mode = { 1366, 716 , 32 };
    help->window = sfRenderWindow_create(mode, "my paint",
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(help->window, 30);
    sfRenderWindow_requestFocus(help->window);
    help->img_display = 0;
    help_one(help);
    help_two(help);
    help_three(help);
    help_four(help);
}
