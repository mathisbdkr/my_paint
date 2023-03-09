/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** cercle_shape
*/

#include "../../../include/my.h"

void draw_circle_pixel(struct paint_t *paint, sfColor color, int x, float y)
{
    if (!check_pixel(paint->pos.y, paint->pos.x, y, paint))
        return;
    sfImage_setPixel(paint->image, paint->pos.x + x, paint->pos.y - y, color);
    sfImage_setPixel(paint->image, paint->pos.x + y, paint->pos.y - x, color);
    sfImage_setPixel(paint->image, paint->pos.x - x, paint->pos.y - y, color);
    sfImage_setPixel(paint->image, paint->pos.x - y, paint->pos.y - x, color);
    sfImage_setPixel(paint->image, paint->pos.x + y, paint->pos.y + x, color);
    sfImage_setPixel(paint->image, paint->pos.x - y, paint->pos.y + x, color);
    sfImage_setPixel(paint->image, paint->pos.x - x, paint->pos.y + y, color);
    sfImage_setPixel(paint->image, paint->pos.x + x, paint->pos.y + y, color);
}

static void call_circle_pixel(struct paint_t *paint, sfColor color, float rad)
{
    int x = 0;
    float y = rad;
    float d = 3 - 2 * rad;
    while (x <= y) {
        draw_circle_pixel(paint, color, x, y);
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void draw_circle(struct paint_t *paint, struct pen_t *pen, int radius)
{
    int x = 0;
    if (radius == -1)
        return;
    radius /= 1.5;
    if (radius == 0)
        radius = 1;
    int y = radius;
    int d = 3 - 2 * radius;
    sfColor color = pen->color_pick;
    pixel(paint, pen, radius + (radius / 2.6));
    float rad = radius;
    while (rad > 0) {
        call_circle_pixel(paint, color, rad);
        rad -= 0.01;
    }
}
