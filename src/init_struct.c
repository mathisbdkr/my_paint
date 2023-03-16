/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** init_struct
*/

#include "../include/my.h"

void position_boutton(struct button_s *boutton)
{
    boutton->rect = sfRectangleShape_create();
    boutton->def_button = malloc(sizeof(int *) * 4);
    int x = 30;
    for (int i = 0; i < 4; i++) {
        boutton->def_button[i] = malloc(sizeof(int) * 6);
        boutton->def_button[i][0] = x;
        boutton->def_button[i][1] = 3;
        boutton->def_button[i][2] = 20;
        boutton->def_button[i][3] = 40;
        boutton->def_button[i][4] = 1;
        boutton->def_button[i][5] = 0;
        x += 45;
    }
}

static void init_paint(struct paint_t *paint)
{
    paint->win_size = sfRenderWindow_getSize(paint->window);
    paint->back = sfRectangleShape_create();
    paint->color_block = sfRectangleShape_create();
    paint->image = sfImage_createFromColor(1367, 718,sfWhite);
    paint->tool_bare = 100;
    paint->tmp = 0;
    set_pen(paint);
    set_eraser(paint);
    set_fleche(paint);
    paint->path_name = NULL;
    paint->back_color = 1;
    jour_nuit(paint);
    zoom_sprite(paint);
    paint->zoom = 1;
}

void init_struct(struct paint_t *paint, struct button_s *boutton)
{
    sfVideoMode mode = { 1366, 716 , 32 };
    paint->window = sfRenderWindow_create(mode, "my paint",
    sfResize | sfClose, NULL);
    init_paint(paint);
    position_boutton(boutton);
    boutton->window = paint->window;
}
