/*
** EPITECH PROJECT, 2023
** test
** File description:
** print_pixel
*/

#include "../../../include/my.h"

static void display_draw(struct paint_t *paint)
{
    sfTexture *text_bord = sfTexture_createFromImage(paint->image, NULL);
    sfSprite *board = sfSprite_create();
    sfSprite_setTexture(board,text_bord , 0);
    sfRenderWindow_drawSprite(paint->window, board, NULL);
    sfTexture_destroy(text_bord);
    sfSprite_destroy(board);
}

int paint_win(sfEvent event, struct paint_t *paint, struct pen_t *pen)
{
    sfVector2f pos = paint->pos;
    sfVector2f size_win = paint->size_win;
    int size = pen->size_pen / 6;
    if (size <= 0)
        size = 1;
    if (pen->gomme == 1)
        size = pen->size_eraser / 3;
    sfVector2u size_img = sfImage_getSize(paint->image);
    if (sfMouse_isButtonPressed(0) && pos.x < size_img.x
    && pos.y < size_img.y && pos.x > 0 && pos.y > paint->tool_bare) {
        square_cercle(paint, pen, size);
    }
    display_draw(paint);
    if (pos.x < size_img.x
    && pos.y < size_img.y && pos.x > 0 && pos.y > paint->tool_bare)
        hitbox_pixel(paint, pen, size);
}
