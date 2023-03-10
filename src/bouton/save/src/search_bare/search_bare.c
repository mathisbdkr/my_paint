/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** search_bare
*/

#include "../../include/my.h"

static void txt_save(struct save_t *save, char *name)
{
    sfText *liste = sfText_create();
    sfFont *font = sfFont_createFromFile("font/calibril.ttf");
    sfText_setPosition(liste, get_position(40, 398));
    sfText_setColor(liste, sfWhite);
    sfText_setFont(liste, font);
    sfText_setScale(liste, get_position(0.6, 0.6));
    sfText_setString(liste, name);
    sfRenderWindow_drawText(save->window, liste, NULL);
    sfText_destroy(liste);
    sfFont_destroy(font);
}

static void txt(struct save_t *save, char *name)
{
    sfText *liste = sfText_create();
    sfFont *font = sfFont_createFromFile("font/calibril.ttf");
    sfText_setPosition(liste, get_position(110, 398));
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

static void save_search(struct save_t *save, int len, char *lettre, int k)
{
    if (len == 0) {
        save->enter_path[0] = lettre[0];
        save->enter_path[1] = '\0';
    } else {
        save->enter_path = my_strcat(save->enter_path, lettre);
    }
    txt(save, save->enter_path);
    while (sfKeyboard_isKeyPressed(k)) {
    }
}

void search_bare(struct save_t *save)
{
    search_rect(save, 100, 300, sfColor_fromRGB(28,25,52));
    search_rect(save, 400, 100, sfColor_fromRGB(23,20,47));
    txt(save, save->enter_path);
    txt_save(save, "Save as");
    ext_file(save);
    int k = 0;
    int len = my_strlen(save->enter_path);
    char *lettre = malloc(sizeof(char) + 2);
    int pass = 0;
    for (k; k <= 26 && len < 34; k++) {
        if (sfKeyboard_isKeyPressed(k)) {
            lettre[0] = k + 97;
            lettre[1] = '\0';
            pass = 1;
            break;
        }
    }
    if (pass == 0)
        return;
    save_search(save, len, lettre, k);
}
