/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** back_color
*/

#include "../../../include/my.h"

static int color_cmp(sfColor color_one, sfColor color_two)
{
    if (color_one.r == color_two.r &&
    color_one.g == color_two.g &&
    color_one.b == color_two.b &&
    color_one.a == color_two.a) {
        return 1;
    }
    return 0;
}

static void color_change(int i, int j, struct paint_t *paint)
{
    if (color_cmp(sfImage_getPixel(paint->image, j, i), sfBlack) == 1) {
        sfImage_setPixel(paint->image, j, i, sfColor_fromRGBA(0,0,0, 10));
    }
    if (color_cmp(sfImage_getPixel(paint->image, j, i), sfWhite) == 1) {
        sfImage_setPixel(paint->image, j, i, sfBlack);
    }
    if (color_cmp(sfImage_getPixel(paint->image, j, i),
    sfColor_fromRGBA(0,0,0, 10)) == 1) {
        sfImage_setPixel(paint->image, j, i, sfWhite);
    }
}

static void color_swap(struct paint_t *paint)
{
    sfVector2u size_img = sfImage_getSize(paint->image);
    for (int i = 0; i < size_img.y; i++) {
        for (int j = 0; j < size_img.x; j++) {
            color_change(i, j, paint);
        }
    }
}

void back_color(struct paint_t *paint, struct pen_t *pen)
{
    color_swap(paint);
    if (pen->back_color == 0) {
        pen->back_color = 1;
        paint->back_color = 1;
    } else if (pen->back_color == 1) {
        pen->back_color = 0;
        paint->back_color = 0;
    }
    while (sfMouse_isButtonPressed(0)) {
    }
}
