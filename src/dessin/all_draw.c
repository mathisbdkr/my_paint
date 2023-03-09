/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** all_draw
*/

#include "../../include/my.h"

void draw_all(struct paint_t *paint, sfEvent event, struct pen_t *pen)
{
    sfVector2f pos = paint->pos;
    sfRenderWindow_drawSprite(paint->window, paint->fleche, 0);
    int pass = 0;
    if (pos.x <= 30 && pos.x >= 0 && pos.y <= 23 && pos.y >= 0 &&
    event.type == sfEvtMouseButtonPressed && paint->tool_bare == 100) {
        paint->tool_bare = 0;
        pass = 1;
    } else if (pos.x <= 30 && pos.x >= 0 && pos.y <= 23 && pos.y >= 0 &&
    event.type == sfEvtMouseButtonPressed && paint->tool_bare == 0) {
        paint->tool_bare = 100;
        pass = 1;
    }
    while (sfMouse_isButtonPressed(0) && pass >= 1) {
    }
    paint_win(event, paint, pen);
    if (paint->tool_bare == 100) {
        color_select(paint, pen, event);
        pen_size(paint, pen, event);
    }
    sfRenderWindow_drawSprite(paint->window, paint->fleche, 0);
}
