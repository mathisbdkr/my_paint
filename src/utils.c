/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** utils
*/

#include "../include/my.h"

int close_win(struct paint_t *paint, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        sfRenderWindow_close(paint->window);
    }
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(paint->window);
    }
}
