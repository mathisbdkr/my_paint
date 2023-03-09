/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** select_type
*/

#include "../../../include/my.h"

static void box(struct paint_t *paint, int y, int select, sfEvent event)
{
    int x = 1090 - 7;
    sfRectangleShape *box = sfRectangleShape_create();
    sfRectangleShape_setSize(box,get_position(30, 30));
    sfRectangleShape_setPosition(box, get_position(x, y));
    sfRectangleShape_setFillColor(box, sfColor_fromRGBA(0,0,0,0));
    sfRectangleShape_setOutlineThickness(box, 2);
    sfRectangleShape_setOutlineColor(box, sfBlack);
    if (select == 1)
        sfRectangleShape_setOutlineColor(box, sfGreen);
    sfRenderWindow_drawRectangleShape(paint->window, box, 0);
}

void select_gomme(struct paint_t *paint, struct pen_t *pen, sfEvent event)
{
    sfVector2f pos = paint->pos;
    int x = 1090 - 7;
    int y = 70 - (50 / 8);
    sfSprite_setPosition(paint->eraser,get_position(x, y));
    sfSprite_setScale(paint->eraser, get_position(0.06, 0.06));
    sfRenderWindow_drawSprite(paint->window, paint->eraser, 0);
    sfSprite_setScale(paint->eraser, get_position(0.1, 0.1));
    if (pos.x <= x + 33 && pos.x >= x &&
    pos.y <= y + 33 && pos.y >= y &&
    event.type == sfEvtMouseButtonPressed) {
        pen->color_pick = color_pallet(0, pen, 0);
    }
    if (pen->gomme == 1)
        box(paint, y, 1, event);
    else
        box(paint, y, 0, event);
}

void select_pen(struct paint_t *paint, struct pen_t *pen, sfEvent event)
{
    sfVector2f pos = paint->pos;
    int x = 1090 - 8;
    int y = 35 - (50 / 9);
    sfSprite_setPosition(paint->pen,get_position(x, y));
    sfSprite_setScale(paint->pen, get_position(0.07, 0.07));
    sfRenderWindow_drawSprite(paint->window, paint->pen, 0);
    sfSprite_setScale(paint->pen, get_position(0.1, 0.1));
    if (pos.x <= x + 30 && pos.x >= x &&
    pos.y <= y + 30 && pos.y >= y &&
    event.type == sfEvtMouseButtonPressed) {
        pen->color_pick = color_pallet(pen->id_color, pen, 1);
        pen->gomme = 0;
    }
    if (pen->gomme == 0)
        box(paint, y, 1, event);
    else
        box(paint, y, 0, event);
}

void select_type(struct paint_t *paint, struct pen_t *pen, sfEvent event)
{
    select_gomme(paint, pen, event);
    select_pen(paint, pen, event);
}
