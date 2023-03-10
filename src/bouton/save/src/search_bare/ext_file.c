/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** ext_file
*/

#include "../../include/my.h"

static void ext_rect(struct save_t *save, sfColor color)
{
    sfRectangleShape *bare = sfRectangleShape_create();
    sfRectangleShape_setSize(bare,get_position(100, 74));
    sfRectangleShape_setPosition(bare,get_position(400, 346));
    sfRectangleShape_setFillColor(bare, color);
    sfRectangleShape_setOutlineThickness(bare, 1);
    sfRectangleShape_setOutlineColor(bare, sfColor_fromRGB(11,38,205));
    sfRenderWindow_drawRectangleShape(save->window, bare, 0);
}

static void txt_ext(struct save_t *save, int x, int y, char *text)
{
    sfText *liste = sfText_create();
    sfFont *font = sfFont_createFromFile("font/calibril.ttf");
    sfText_setPosition(liste, get_position(x, y));
    sfText_setColor(liste, sfWhite);
    sfText_setFont(liste, font);
    sfText_setScale(liste, get_position(0.7, 0.7));
    sfText_setString(liste, text);
    sfRenderWindow_drawText(save->window, liste, NULL);
    sfText_destroy(liste);
    sfFont_destroy(font);
}

static int search_rect(struct save_t *save, int size, sfColor color, int id)
{
    sfVector2f pos = save->pos;
    int x = 400;
    int y = 345 + size;
    sfRectangleShape *bare = sfRectangleShape_create();
    sfRectangleShape_setSize(bare,get_position(100, 24));
    sfRectangleShape_setPosition(bare,get_position(x, y));
    sfRectangleShape_setFillColor(bare, color);
    sfRectangleShape_setOutlineThickness(bare, 1);
    sfRectangleShape_setOutlineColor(bare, sfColor_fromRGB(11,38,205));
    sfRenderWindow_drawRectangleShape(save->window, bare, 0);
    if (sfMouse_isButtonPressed(0) && pos.x <= x + 100 && pos.x >= x &&
    pos.y <= y + 24 && pos.y >= y)
        return id;
    return 0;
}

static void selected_ext(struct save_t *save, sfVector2f pos)
{
    ext_rect(save, sfColor_fromRGB(23,20,47));
    int select = 0;
    select += search_rect(save, 1, sfColor_fromRGB(23,20,47), 1);
    select += search_rect(save, 26, sfColor_fromRGB(23,20,47), 2);
    select += search_rect(save, 51, sfColor_fromRGB(23,20,47), 3);
    if (select == 1)
        save->extention = ".png";
    if (select == 2)
        save->extention = ".jpg";
    if (select == 3)
        save->extention = ".bmp";
    txt_ext(save, 420, 342, ".png\n.jpg\n.bmp");
    if (select != 0) {
        save->ext_select = 0;
        while (sfMouse_isButtonPressed(0)) {
        }
    }
}

void ext_file(struct save_t *save)
{
    sfVector2f pos = save->pos;
    int pass = 0;
    if (sfMouse_isButtonPressed(0) && pos.x <= 400 + 100 && pos.x >= 400 &&
    pos.y <= 400 + 20 && pos.y >= 400) {
        if (save->ext_select == 0) {
            save->ext_select = 1;
            pass = 1;
        }
    }
    if (pass == 1) {
        while (sfMouse_isButtonPressed(0)) {
        }
    }
    if (save->ext_select == 1)
        selected_ext(save, pos);
    else
        txt_ext(save, 420, 395, save->extention);
}
