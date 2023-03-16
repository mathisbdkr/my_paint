/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** struct_draw
*/

#ifndef STRUCT_DRAW_H_
    #define STRUCT_DRAW_H_

    #include "../include.h"

struct pen_t {
    sfColor color_pick;
    int gomme;
    float size_pen;
    float size_eraser;
    int cercle_pen;
    int cercle_eraser;
    int id_color;
    int back_color;
    sfColor border_color;
};

struct paint_t {
    sfRenderWindow *window;
    sfRectangleShape *back;
    sfRectangleShape *color_block;
    sfVector2u win_size;
    sfImage *image;
    sfVector2f pos;
    sfVector2f size_win;
    int display_pixel;
    sfSprite *pen;
    sfSprite *eraser;
    sfSprite *fleche;
    int tool_bare;
    int tmp;
    char *path_name;
    int back_color;
    sfSprite *jour_nuit;
    float zoom;
    sfSprite *zoom_sprite;
};

#endif /* !STRUCT_DRAW_H_ */
