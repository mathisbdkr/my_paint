/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** bare_prompt
*/

#include "../../include/my.h"

static void txt_save(struct save_t *save, char *name, int x)
{
    sfText *liste = sfText_create();
    sfFont *font = sfFont_createFromFile("font/calibril.ttf");
    sfText_setPosition(liste, get_position(x, 398));
    sfText_setColor(liste, sfWhite);
    sfText_setFont(liste, font);
    sfText_setScale(liste, get_position(0.6, 0.6));
    sfText_setString(liste, name);
    sfRenderWindow_drawText(save->window, liste, NULL);
    sfText_destroy(liste);
    sfFont_destroy(font);
}

static void search_rect(struct save_t *save, int x, int size, sfColor color)
{
    sfRectangleShape *bare = sfRectangleShape_create();
    sfRectangleShape_setSize(bare,get_position(size, 20));
    sfRectangleShape_setPosition(bare,get_position(x, 400));
    sfRectangleShape_setFillColor(bare, color);
    sfRectangleShape_setOutlineThickness(bare, 1);
    sfRectangleShape_setOutlineColor(bare, sfColor_fromRGB(11,38,205));
    sfRenderWindow_drawRectangleShape(save->window, bare, 0);
}

void bare_prompt(struct save_t *save)
{
    search_rect(save, 100, 300, sfColor_fromRGB(28,25,52));
    search_rect(save, 400, 100, sfColor_fromRGB(23,20,47));
    txt_save(save, save->enter_path, 110);
    txt_save(save, save->txt_mode, 35);
    if (save->mode != 1)
        ext_file(save);
}
