/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** square_cercle
*/

#include "../../../include/my.h"

int check_pixel(float y,float x, float size, struct paint_t *paint)
{
    sfVector2u size_img = sfImage_getSize(paint->image);
    if (y - size <= 0 || y + size >= size_img.y)
        return 0;
    if (x - size <= 0 || x + size >= size_img.x)
        return 0;
    return 1;
}

void pixel(struct paint_t *paint, struct pen_t *pen, float size)
{
    sfVector2f pos = paint->pos;
    int x = pos.x;
    int y = pos.y;
    size /= 2;
    y -= size;
    while (y < pos.y + size) {
        for (x = pos.x - size; x < pos.x + size &&
        check_pixel(pos.y, pos.x, size, paint); x++) {
            sfImage_setPixel(paint->image, x, y, pen->color_pick);
        }
        y++;
    }
}

void square_cercle(struct paint_t *paint, struct pen_t *pen, float size)
{
    sfVector2f pos = paint->pos;
    int cercle = pen->cercle_pen;
    if (pen->gomme == 1) {
        cercle = pen->cercle_eraser;
    }
    if (cercle == 1)
        draw_circle(paint, pen, size);
    else
        pixel(paint, pen, size);
}
