/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** boutton_back_color
*/

#include "../../../include/my.h"

void back_change(struct paint_t *paint, struct pen_t *pen)
{
    sfVector2f pos = paint->pos;
    sfSprite_setPosition(paint->jour_nuit, get_position(540,35));
    sfRenderWindow_drawSprite(paint->window, paint->jour_nuit, 0);
    if (pos.x <= 540 + 50 && pos.x >= 540 &&
    pos.y <= 35 + 50 && pos.y >= 35 &&
    sfMouse_isButtonPressed(0)) {
        back_color(paint, pen);
    }
}
