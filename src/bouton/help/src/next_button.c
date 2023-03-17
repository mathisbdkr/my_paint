/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** next_button
*/

#include "../include/my.h"

static void rect(struct help_t *help, int x, int y, sfColor color)
{
    sfRectangleShape *center = sfRectangleShape_create();
    sfRectangleShape_setSize(center,get_position(25, 50));
    sfRectangleShape_setPosition(center,get_position(x, y));
    sfRectangleShape_setFillColor(center, color);
    sfRenderWindow_drawRectangleShape(help->window, center, 0);
}

static void is_houver(struct help_t *help, sfVector2f pos)
{
    if (pos.x <= 25 && pos.x >= 0 &&
    pos.y <= 359 + 50 && pos.y >= 359) {
        rect(help, 0, 359, sfColor_fromRGBA(23,20,47, 200));
    } else {
        rect(help, 0, 359, sfColor_fromRGBA(23,20,47, 100));
    }
    if (pos.x <= 1341 + 25 && pos.x >= 1341 &&
    pos.y <= 359 + 50 && pos.y >= 359) {
        rect(help, 1341, 359, sfColor_fromRGBA(23,20,47, 200));
    } else {
        rect(help, 1341, 359, sfColor_fromRGBA(23,20,47, 100));
    }
}

static void is_clicked_two(struct help_t *help, sfVector2f pos)
{
    int pass = 0;
    if (pos.x <= 1341 + 25 && pos.x >= 1341 &&
    pos.y <= 359 + 50 && pos.y >= 359 &&
    sfMouse_isButtonPressed(0) && help->img_display < 3) {
        help->img_display++;
        pass = 1;
    } else if (pos.x <= 1341 + 25 && pos.x >= 1341 &&
    pos.y <= 359 + 50 && pos.y >= 359 &&
    sfMouse_isButtonPressed(0) && help->img_display == 3) {
        help->img_display = 0;
        pass = 1;
    }

    while (sfMouse_isButtonPressed(0) && pass == 1) {
    }
}

static void is_clicked_one(struct help_t *help, sfVector2f pos)
{
    int pass = 0;
    if (pos.x <= 25 && pos.x >= 0 &&
    pos.y <= 359 + 50 && pos.y >= 359 &&
    sfMouse_isButtonPressed(0) && help->img_display > 0) {
        help->img_display--;
        pass = 1;
    } else if (pos.x <= 25 && pos.x >= 0 &&
    pos.y <= 359 + 50 && pos.y >= 359 &&
    sfMouse_isButtonPressed(0) && help->img_display == 0) {
        help->img_display = 3;
        pass = 1;
    }

    while (sfMouse_isButtonPressed(0) && pass == 1) {
    }
}

void next_button(struct help_t *help)
{
    is_houver(help, help->pos);
    is_clicked_one(help, help->pos);
    is_clicked_two(help, help->pos);
}
