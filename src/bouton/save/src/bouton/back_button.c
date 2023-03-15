/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** back_button
*/

#include "../../include/my.h"

void back_button(struct save_t *save)
{
    sfRenderWindow_drawSprite(save->window, save->retoure, 0);
    sfVector2f pos = save->pos;
    int x = 5;
    int y = 5;
    if (sfMouse_isButtonPressed(0) && pos.x <= x + 30 && pos.x >= x &&
    pos.y <= y + 30 && pos.y >= y) {
        save->dir_patch = my_strcat(save->dir_patch, "../");
        while (sfMouse_isButtonPressed(0)) {
        }
    }
}
