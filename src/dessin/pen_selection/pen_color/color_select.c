/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** color_select
*/

#include "../../../../include/my.h"

sfRectangleShape *create_back(struct paint_t *paint, int h, sfColor color)
{
    sfRectangleShape_setSize(paint->back,
    get_position(1920, h));
    sfRectangleShape_setFillColor(paint->back, color);
    sfRenderWindow_drawRectangleShape(paint->window, paint->back, 0);
}

static void color_rect(struct paint_t *paint, int x, int i, struct pen_t *pen)
{
    sfColor color = color_pallet(i, pen, 1);
    sfRectangleShape_setSize(paint->color_block,
    get_position(20, 20));
    sfRectangleShape_setPosition(paint->color_block, get_position(x, 30));
    sfRectangleShape_setFillColor(paint->color_block, color);
    sfRectangleShape_setOutlineThickness(paint->color_block, 1);
    if (paint->pos.x <= x + 20 && paint->pos.x >= x &&
    paint->pos.y <= 30 + 20 && paint->pos.y >= 30) {
        sfRectangleShape_setOutlineColor(paint->color_block, sfWhite);
    } else {
        sfRectangleShape_setOutlineColor(paint->color_block, sfBlack);
    }
    if (i == pen->id_color)
        sfRectangleShape_setOutlineColor(paint->color_block, sfGreen);
    sfRenderWindow_drawRectangleShape(paint->window, paint->color_block, 0);
}

static void selected_color(struct paint_t *paint, struct pen_t *pen)
{
    sfRectangleShape_setSize(paint->color_block,
    get_position(30, 30));
    sfRectangleShape_setPosition(paint->color_block, get_position(1220, 60));
    sfRectangleShape_setFillColor(paint->color_block,
    color_pallet(pen->id_color, pen, 1));
    sfRectangleShape_setOutlineThickness(paint->color_block, 1);
    sfRectangleShape_setOutlineColor(paint->color_block, sfBlack);
    sfRenderWindow_drawRectangleShape(paint->window, paint->color_block, 0);
}

static void toolbare_back(struct paint_t *paint, struct pen_t *pen)
{
    if (pen->back_color == 1) {
        create_back(paint,100, sfColor_fromRGBA(200,200,200,255));
        create_back(paint,25, sfColor_fromRGBA(150,150,150,255));
    } else {
        create_back(paint,100, sfColor_fromRGBA(37,31,75,255));
        create_back(paint,25, sfColor_fromRGBA(23,20,47,255));
    }
}

void color_select(struct paint_t *paint, struct pen_t *pen, sfEvent event)
{
    int x = 1130;
    int y = 30;
    sfVector2f pos = paint->pos;
    toolbare_back(paint, pen);
    back_change(paint, pen);
    select_type(paint, pen, event);
    pen_shape(paint, pen, event);
    for (int i = 1; i < 8; i++) {
        color_rect(paint,x, i, pen);
        if (pos.x <= x + 20 && pos.x >= x &&
        pos.y <= y + 20 && pos.y >= y &&
        sfMouse_isButtonPressed(0)) {
            pen->color_pick = color_pallet(i, pen, 0);
            pen->id_color = i;
        }
        selected_color(paint, pen);
        x += 30;
    }
    zoom_button(paint);
}
