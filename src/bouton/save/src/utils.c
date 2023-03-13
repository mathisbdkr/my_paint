/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** utils
*/

#include "../include/my.h"

static int close_win(struct save_t *save, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        sfRenderWindow_close(save->window);
    }
}

static void mouse(struct save_t *save, sfEvent event)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(save->window);
    save->pos = sfRenderWindow_mapPixelToCoords(save->window,pos_mouse, NULL);
}

void utils_file_manager(struct save_t *save, sfEvent event)
{
    mouse(save, event);
    close_win(save, event);
}
