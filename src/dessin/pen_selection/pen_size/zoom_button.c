/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** zoom_button
*/

#include "../../../../include/my.h"

void zoom_button(struct paint_t *paint)
{
    sfRenderWindow_drawSprite(paint->window, paint->zoom_sprite, 0);
    int x = 460;
    int y = 35;
    sfVector2f pos = paint->pos;
    if (pos.x <= x + 50 && pos.x >= x &&
    pos.y <= y + 50 && pos.y >= y &&
    sfMouse_isButtonPressed(0)) {
        paint->zoom += 0.1;
        while (sfMouse_isButtonPressed(0)) {
        }
    }
    if (pos.x <= x + 50 && pos.x >= x &&
    pos.y <= y + 50 && pos.y >= y &&
    sfMouse_isButtonPressed(1)) {
        paint->zoom -= 0.1;
        while (sfMouse_isButtonPressed(1)) {
        }
    }
}
