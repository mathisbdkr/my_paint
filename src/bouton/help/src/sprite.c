/*
** EPITECH PROJECT, 2023
** test
** File description:
** sprite
*/

#include "../include/my.h"

void help_one(struct help_t *help)
{
    sfSprite *dir = sfSprite_create();
    sfSprite_setTexture(dir,
    sfTexture_createFromFile("img/help/help_base.png", NULL), 0);
    help->help_one = dir;
}

void help_two(struct help_t *help)
{
    sfSprite *file = sfSprite_create();
    sfSprite_setTexture(file,
    sfTexture_createFromFile("img/help/menu.png", NULL), 0);
    help->help_two = file;
}

void help_three(struct help_t *help)
{
    sfSprite *file = sfSprite_create();
    sfSprite_setTexture(file,
    sfTexture_createFromFile("img/help/open.png", NULL), 0);
    help->help_three = file;
}

void help_four(struct help_t *help)
{
    sfSprite *file = sfSprite_create();
    sfSprite_setTexture(file,
    sfTexture_createFromFile("img/help/save.png", NULL), 0);
    help->help_four = file;
}
