/*
** EPITECH PROJECT, 2023
** test
** File description:
** lst_file
*/

#include "../../include/my.h"

static void txt(struct save_t *save, char *name, int y, int x)
{
    sfText *liste = sfText_create();
    sfFont *font = sfFont_createFromFile("font/calibril.ttf");
    sfText_setPosition(liste, get_position(x, y));
    sfText_setColor(liste, sfWhite);
    sfText_setFont(liste, font);
    sfText_setScale(liste, get_position(0.5, 0.5));
    resize_name(name);
    sfText_setString(liste, name);
    sfRenderWindow_drawText(save->window, liste, NULL);
    sfText_destroy(liste);
    sfFont_destroy(font);
}

static int texte_pt2(struct save_t *save, char *name, int y, int x)
{
    sfVector2f pos = save->pos;
    int type = file_type(save, name);
    y -= 35;
    if (pos.x <= x + 47 && pos.x >= x &&
    pos.y <= y + 55 && pos.y >= y && sfMouse_isButtonPressed(0) && type == 1) {
        save->dir_patch = my_strcat(save->dir_patch, name);
        save->dir_patch = my_strcat(save->dir_patch, "/");
        while (sfMouse_isButtonPressed(0)){
        }
        return 1;
    }
    if (pos.x <= x + 47 && pos.x >= x &&
    pos.y <= y + 55 && pos.y >= y && sfMouse_isButtonPressed(0)
    && type == 0 && save->mode == 1) {
        save->enter_path = my_strcat(save->enter_path, name);
        while (sfMouse_isButtonPressed(0)){
        }
        return 1;
    }
}

static int texte(struct save_t *save, char *name, int y, int x)
{
    sfVector2f pos = save->pos;
    save->pos_txt = get_position(x, y - 35);
    int type = file_type(save, name);
    int k = 0;
    while (name[k] != '\0' && name[k] != ' ') {
        k++;
    }
    name[k] = '\0';
    int i = 0;
    i = texte_pt2(save, name, y, x);
    if (i == 1) {
        return 1;
    }
    txt(save, name, y, x);
    return 0;
}

void lst_file(struct save_t *save, sfEvent event)
{
    int y = 75;int x = 70;
    int n = 0;int nb = 0;
    if (ls_vide(save) == 1)
        return;
    save->tab = my_str_to_word_array(save->file, ' ');
    for (nb = 0; save->tab[nb] != NULL; nb++) {
    }
    int back = 0;
    save->tab[nb - 1][my_strlen(save->tab[nb - 1]) - 1] = '\0';
    for (int i = 0, n = 0; save->tab[i] != NULL && back == 0; i++) {
        back = texte(save, save->tab[i], y, x);
        y += 125;
        n++;
        if (n >= 3 && back == 0) {
            y = 75;
            x += 135;
            n = 0;
        }
    }
}
