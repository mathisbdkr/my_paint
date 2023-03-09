/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** boutt_save
*/

#include "../../include/my.h"

static void save_txt(struct save_t *save, int x, int y)
{
    sfVector2f pos = save->pos;
    sfText *liste = sfText_create();
    sfFont *font = sfFont_createFromFile("font/calibril.ttf");
    save->pos_txt = get_position(x, y - 35);
    sfText_setPosition(liste, get_position(x, y));
    sfText_setColor(liste, sfWhite);
    sfText_setFont(liste, font);
    sfText_setScale(liste, get_position(0.6, 0.6));
    sfText_setString(liste, "Save");
    sfRenderWindow_drawText(save->window, liste, NULL);
}

static void cancel(struct save_t *save, int x, int y)
{
    sfVector2f pos = save->pos;
    sfText *liste = sfText_create();
    sfFont *font = sfFont_createFromFile("font/calibril.ttf");
    save->pos_txt = get_position(x, y - 35);
    sfText_setPosition(liste, get_position(x, y));
    sfText_setColor(liste, sfWhite);
    sfText_setFont(liste, font);
    sfText_setScale(liste, get_position(0.6, 0.6));
    sfText_setString(liste, "Cancel");
    sfRenderWindow_drawText(save->window, liste, NULL);
}

static void rond(struct save_t *save, float rad, int x, int y)
{
    sfCircleShape *cercle = sfCircleShape_create();
    sfCircleShape_setRadius(cercle, rad);
    sfCircleShape_setPosition(cercle, get_position(x, y));
    sfCircleShape_setFillColor(cercle, sfColor_fromRGB(23,20,47));
    sfRenderWindow_drawCircleShape(save->window, cercle, 0);
}

static void bas_rect(struct save_t *save, int x, int y)
{
    sfRectangleShape *center = sfRectangleShape_create();
    sfRectangleShape_setSize(center,get_position(100, 25));
    sfRectangleShape_setPosition(center,get_position(x, y));
    sfRectangleShape_setFillColor(center, sfColor_fromRGB(23,20,47));
    sfRenderWindow_drawRectangleShape(save->window, center, 0);
}

int rond_button(struct save_t *save, int id, int x, int y)
{
    sfVector2f pos = save->pos;
    bas_rect(save, x, y);
    rond(save, 12.5, x - 12.5, y);
    rond(save, 12.5, (x + 100) - 12.5, y);
    if (id == 0)
        cancel(save, x + 25, y);
    if (id == 1)
        save_txt(save, x + 30, y);
    x -= 12.5;
    if (sfMouse_isButtonPressed(0) && pos.x <= x + 125 && pos.x >= x &&
    pos.y <= y + 25 && pos.y >= y && id == 0) {
        sfRenderWindow_close(save->window);
    }
    if (sfMouse_isButtonPressed(0) && pos.x <= x + 125 && pos.x >= x &&
    pos.y <= y + 25 && pos.y >= y && id == 1) {
        save->is_save = 1;
    }
    return 0;
}
