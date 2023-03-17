/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** color_wheel
*/

#include "../../../../include/my.h"

static sfColor get_pixel_color(sfImage *image, float x, float y)
{
    sfColor color = sfImage_getPixel(image, x, y);
    int r = color.r;
    int g = color.g;
    int b = color.b;
    color.r = r;
    color.g = b;
    color.b = g;
    return color;
}

static void wheel(struct paint_t *paint, struct pen_t *pen)
{
    sfTexture *wheeltexture = sfTexture_createFromFile("img/wheel.png", NULL);
    sfSprite *wheelsprite = sfSprite_create();
    sfSprite_setTexture(wheelsprite, wheeltexture, sfTrue);
    sfSprite_setPosition(wheelsprite,
    get_position(paint->size_win.x - 155, 100));
    sfVector2f pos = paint->pos;
    if (sfMouse_isButtonPressed(0) && paint->size_win.x - paint->pos.x <= 154
    && paint->size_win.x - paint->pos.x >= 0 &&
    paint->pos.y <= 254 && paint->pos.y >= 100) {
        sfImage *image = sfTexture_copyToImage(wheeltexture);
        sfColor selectedColor = get_pixel_color(image,
        paint->size_win.x - paint->pos.x, pos.y - 100);
        pen->color_pick = selectedColor;
        sfImage_destroy(image);
    }
    sfRenderWindow_drawSprite(paint->window, wheelsprite, 0);
    sfSprite_destroy(wheelsprite);
    sfTexture_destroy(wheeltexture);
}

static void switch_wheel_pt2(struct paint_t *paint)
{
    int pass = 0;
    if (sfMouse_isButtonPressed(0) && paint->size_win.x - paint->pos.x <= 154
    && paint->size_win.x - paint->pos.x >= 0 &&
    paint->pos.y <= 254 && paint->pos.y >= 100) {
    } else if (sfMouse_isButtonPressed(0) && paint->wheel_active == 1) {
        paint->wheel_active = 0;
        pass = 2;
    }
    while (sfMouse_isButtonPressed(0) && pass == 2) {
    }
}

static void switch_wheel(struct paint_t *paint)
{
    int pass = 0;
    if (sfMouse_isButtonPressed(0) && paint->pos.x <= 1180 + 30
    && paint->pos.x >= 1180 && paint->pos.y <= 90 && paint->pos.y >= 60) {
        if (paint->wheel_active == 0)
            paint->wheel_active = 1;
        else
            paint->wheel_active = 0;
        pass = 1;
    }
    if (pass == 1) {
        while (sfMouse_isButtonPressed(0)) {
        }
    }
    switch_wheel_pt2(paint);
}

void color_wheel(struct paint_t *paint, struct pen_t *pen, int pass)
{
    sfTexture *texture = sfTexture_createFromFile("img/wheel.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, get_position(1180, 60));
    sfSprite_setScale(sprite, get_position(0.22, 0.22));
    sfRenderWindow_drawSprite(paint->window, sprite, 0);
    switch_wheel(paint);
    if (paint->wheel_active == 1) {
        wheel(paint, pen);
        sfRenderWindow_setMouseCursorVisible(paint->window, true);
    }
}
