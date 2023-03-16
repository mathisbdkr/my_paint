/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** pen_shape
*/

#include "../../../../include/my.h"

static void box(struct paint_t *paint, int y, int select)
{
    int x = 1030;
    for (int i = 0; i < 2; i++) {
        sfRectangleShape *box = sfRectangleShape_create();
        sfRectangleShape_setSize(box,get_position(30, 30));
        sfRectangleShape_setPosition(box, get_position(x, y));
        sfRectangleShape_setFillColor(box, sfColor_fromRGBA(0,0,0,0));
        sfRectangleShape_setOutlineThickness(box, 2);
        sfRectangleShape_setOutlineColor(box, sfBlack);
        if (select == 0)
            sfRectangleShape_setOutlineColor(box, sfGreen);
        sfRenderWindow_drawRectangleShape(paint->window, box, 0);
        y += 35;
        if (select == 0)
            select = 1;
        else
            select = 0;
    }
}

int square_pen(struct paint_t *paint, int y, sfEvent event, struct pen_t *pen)
{
    int x = 1035;
    int select = 1;
    sfVector2f pos = paint->pos;
    sfRectangleShape *box = sfRectangleShape_create();
    sfRectangleShape_setSize(box,get_position(20, 20));
    sfRectangleShape_setPosition(box, get_position(x, y));
    sfRectangleShape_setFillColor(box, pen->color_pick);
    sfRectangleShape_setOutlineThickness(box, 2);
    sfRectangleShape_setOutlineColor(box, sfBlack);
    sfRenderWindow_drawRectangleShape(paint->window, box, 0);
    if (pos.x <= x + 30 && pos.x >= x &&
    pos.y <= y + 30 && pos.y >= y &&
    event.type == sfEvtMouseButtonPressed) {
        select = 0;
    }
    if (select == 0 && pen->gomme == 0)
        pen->cercle_pen = 0;
    if (select == 0 && pen->gomme == 1)
        pen->cercle_eraser = 0;
}

int cercle_pen(struct paint_t *paint, int y, sfEvent event, struct pen_t *pen)
{
    int x = 1035;
    int select = 1;
    sfVector2f pos = paint->pos;
    sfCircleShape *box = sfCircleShape_create();
    sfCircleShape_setRadius(box, 10);
    sfCircleShape_setPosition(box, get_position(x, y));
    sfCircleShape_setFillColor(box, pen->color_pick);
    sfCircleShape_setOutlineThickness(box, 2);
    sfCircleShape_setOutlineColor(box, sfBlack);
    sfRenderWindow_drawCircleShape(paint->window, box, 0);
    if (pos.x <= x + 30 && pos.x >= x &&
    pos.y <= y + 30 && pos.y >= y &&
    event.type == sfEvtMouseButtonPressed) {
        select = 0;
    }
    if (select == 0 && pen->gomme == 0)
        pen->cercle_pen = 1;
    if (select == 0 && pen->gomme == 1)
        pen->cercle_eraser = 1;
}

void pen_shape(struct paint_t *paint, struct pen_t *pen, sfEvent event)
{
    int y = 30;
    square_pen(paint, 35, event, pen);
    cercle_pen(paint, 70, event, pen);
    if (pen->gomme == 0)
        box(paint, y, pen->cercle_pen);
    if (pen->gomme == 1)
        box(paint, y, pen->cercle_eraser);
}
