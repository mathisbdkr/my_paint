/*
** EPITECH PROJECT, 2023
** test
** File description:
** file_type
*/

#include "../include/my.h"

char *resize_name(char *name)
{
    if (my_strlen(name) >= 6 && my_strlen(name) >= 9) {
        for (int i = 6; i < 9; i++) {
            name[i] = '.';
        }
        name[9] = '\0';
    }
    return name;
}

int file_type(struct save_t *save, char *name)
{
    struct stat sb;
    stat(name, &sb);
    if (S_ISDIR(sb.st_mode)) {
        sfSprite_setPosition(save->dir_sprite, save->pos_txt);
        sfRenderWindow_drawSprite(save->window, save->dir_sprite, NULL);
        return 1;
    } else {
        sfSprite_setPosition(save->file_sprite, save->pos_txt);
        sfRenderWindow_drawSprite(save->window, save->file_sprite, NULL);
        return 0;
    }
}
