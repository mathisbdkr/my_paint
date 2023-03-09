/*
** EPITECH PROJECT, 2023
** test
** File description:
** lst_file
*/

#include "../../include/my.h"

static void texte(struct save_t *save, char *name, int y, int x)
{
    sfVector2f pos = save->pos;
    sfText *liste = sfText_create();
    sfFont *font = sfFont_createFromFile("font/calibril.ttf");
    save->pos_txt = get_position(x, y - 35);
    file_type(save, name);
    sfText_setPosition(liste, get_position(x, y));
    sfText_setColor(liste, sfWhite);
    sfText_setFont(liste, font);
    sfText_setScale(liste, get_position(0.5, 0.5));
    resize_name(name);
    sfText_setString(liste, name);
    sfRenderWindow_drawText(save->window, liste, NULL);
    y -= 35;
    if (pos.x <= x + 47 && pos.x >= x &&
    pos.y <= y + 55 && pos.y >= y && sfMouse_isButtonPressed(0)) {
        my_putstr(name);
        my_putchar('\n');
    }
    sfText_destroy(liste);
    sfFont_destroy(font);
}

void lst_file(struct save_t *save, sfEvent event)
{
    int y = 75;
    int x = 70;
    int n = 0;
    int nb = 0;
    if (ls_vide(save) == 1)
        return;
    save->tab = my_str_to_word_array(save->file, ' ');
    for (nb = 0; save->tab[nb] != NULL; nb++) {
    }
    save->tab[nb - 1][my_strlen(save->tab[nb - 1]) - 1] = '\0';
    for (int i = 0, n = 0; save->tab[i] != NULL; i++) {
        texte(save, save->tab[i], y, x);
        y += 125;
        n++;
        if (n >= 3) {
            y = 75;
            x += 135;
            n = 0;
        }
    }
}
