/*
** EPITECH PROJECT, 2023
** test
** File description:
** sprite
*/

#include "../include/my.h"

void dir_sprite(struct save_t *save)
{
    sfSprite *dir = sfSprite_create();
    sfSprite_setTexture(dir,
    sfTexture_createFromFile("img/dir.png", NULL), 0);
    sfSprite_setScale(dir, get_position(0.08,0.08));
    sfSprite_setPosition(dir, get_position(5, 5));
    save->dir_sprite = dir;
}

void file_sprite(struct save_t *save)
{
    sfSprite *file = sfSprite_create();
    sfSprite_setTexture(file,
    sfTexture_createFromFile("img/file.png", NULL), 0);
    sfSprite_setScale(file, get_position(0.08,0.08));
    sfSprite_setPosition(file, get_position(5, 5));
    save->file_sprite = file;
}

void back_sprite(struct save_t *save)
{
    sfSprite *file = sfSprite_create();
    sfSprite_setTexture(file,
    sfTexture_createFromFile("img/back.png", NULL), 0);
    sfSprite_setScale(file, get_position(0.06,0.06));
    sfSprite_setPosition(file, get_position(5, 5));
    save->retoure = file;
}
