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
    sfVector2f pos = save->pos;
    sfVector2u size_win = sfRenderWindow_getSize(save->window);
    if (pos.x <= size_win.x && pos.x >= 0 &&
    pos.y <= size_win.y && pos.y >= 0) {
    } else if (sfMouse_isButtonPressed(0)) {
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
