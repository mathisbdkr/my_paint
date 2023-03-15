/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** init_struct
*/

#include "../include/my.h"

static void init_mode(struct save_t *save, int mode)
{
    save->mode = mode;
    if (mode == 1)
        save->txt_mode = "Open file";
    if (mode == 2)
        save->txt_mode = "Save";
    if (mode == 3)
        save->txt_mode = "Save as";
}

void init_save(struct save_t *save, int mode, int back_color)
{
    sfVideoMode vmode = { 600, 500 , 32 };
    save->window = sfRenderWindow_create(vmode, "save file (tha le flow)",
    sfNone, NULL);
    sfVector2i pos = {200, 100};
    sfRenderWindow_setPosition(save->window, pos);
    dir_sprite(save);
    file_sprite(save);
    save->dir_patch = "./";
    save->enter_path = malloc(sizeof(char) * 1000);
    save->enter_path[0] = '\0';
    save->ext_select = 0;
    save->extention = ".png";
    save->back_color = back_color;
    back_sprite(save);
    init_mode(save, mode);
}
