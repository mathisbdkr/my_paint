/*
** EPITECH PROJECT, 2023
** test
** File description:
** file_type
*/

#include "../include/my.h"

char *resize_name(char *name)
{
    int len = my_strlen(name);
    if (len >= 6 && len > 9) {
        for (int i = 6; i < 9; i++) {
            name[i] = '.';
        }
        name[9] = '\0';
    }
    return name;
}

static char *rm_space(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            str[i] = '\0';
            return str;
        }
    }
}

int file_type(struct save_t *save, char *name)
{
    struct stat sb;
    char *tmp = malloc(sizeof(char) * 1000);
    tmp[0] = '\0';
    tmp = my_strcpy(tmp, save->dir_patch);
    tmp = my_strcat(tmp, name);
    rm_space(tmp);
    stat(tmp, &sb);
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
