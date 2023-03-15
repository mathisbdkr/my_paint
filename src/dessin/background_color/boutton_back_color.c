/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** boutton_back_color
*/

#include "../../../include/my.h"

void back_change(struct paint_t *paint, struct pen_t *pen)
{
    sfRenderWindow_drawSprite(paint->window, paint->jour_nuit, 0);
    if (paint->pos.x <= 540 + 50 && paint->pos.x >= 540 &&
    paint->pos.y <= 35 + 50 && paint->pos.y >= 35 &&
    sfMouse_isButtonPressed(0)) {
        back_color(paint, pen);
        while (sfMouse_isButtonPressed(0)) {
        }
    }
}
