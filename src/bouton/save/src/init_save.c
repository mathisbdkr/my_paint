/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** init_struct
*/

#include "../include/my.h"

void init_save(struct save_t *save)
{
    sfVideoMode mode = { 600, 500 , 32 };
    save->window = sfRenderWindow_create(mode, "save file (tha le flow)",
    sfClose, NULL);
    sfVector2i pos = {50, 50};
    sfRenderWindow_setPosition(save->window, pos);
    dir_sprite(save);
    file_sprite(save);
}
