/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** search_bare
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

static void save_search(struct save_t *save, int len, char *lettre, int k)
{
    if (len == 0) {
        save->enter_path[0] = lettre[0];
        save->enter_path[1] = '\0';
    } else {
        save->enter_path = my_strcat(save->enter_path, lettre);
    }
    txt_save(save, save->enter_path, 110);
    while (sfKeyboard_isKeyPressed(k)) {
    }
}

void search_bare(struct save_t *save)
{
    bare_prompt(save);
    int k = 0;int pass = 0;
    int len = my_strlen(save->enter_path);
    char *lettre = malloc(sizeof(char) + 2);
    for (k; k <= 101 && len < 34; k++) {
        if (sfKeyboard_isKeyPressed(k) && k < 26) {
            lettre[0] = k + 97;
            lettre[1] = '\0';
            pass = 1;
            break;
        }
        if (sfKeyboard_isKeyPressed(k) && k >= 26) {
            all_keyboard(save, k);
            break;
        }
    }
    if (pass == 0)
        return;
    save_search(save, len, lettre, k);
}
