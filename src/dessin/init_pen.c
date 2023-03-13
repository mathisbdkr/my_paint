/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** init_pen
*/

#include "../../include/my.h"

void init_pen(struct paint_t *paint, struct pen_t *pen)
{
    pen->color_pick = sfWhite;
    pen->id_color = 1;
    pen->gomme = 0;
    pen->size_pen = 60;
    pen->size_eraser = 100;
    pen->cercle_eraser = 1;
    pen->cercle_pen = 0;
    pen->border_color = sfWhite;
}
