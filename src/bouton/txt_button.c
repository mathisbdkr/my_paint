/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** txt_button
*/

#include "../../include/my.h"

void txt_button_help(struct button_s *boutton)
{
    sfText *liste = sfText_create();
    sfFont *font = sfFont_createFromFile("font/calibril.ttf");
    sfText_setPosition(liste, get_position(77, 0));
    sfText_setColor(liste, sfBlack);
    sfText_setFont(liste, font);
    sfText_setScale(liste, get_position(0.7, 0.7));
    sfText_setString(liste, "help");
    sfRenderWindow_drawText(boutton->window, liste, NULL);
    sfText_destroy(liste);
    sfFont_destroy(font);
}

void txt_button_save(struct button_s *boutton)
{
    sfText *liste = sfText_create();
    sfFont *font = sfFont_createFromFile("font/calibril.ttf");
    sfText_setPosition(liste, get_position(30, 0));
    sfText_setColor(liste, sfBlack);
    sfText_setFont(liste, font);
    sfText_setScale(liste, get_position(0.7, 0.7));
    sfText_setString(liste, "File");
    sfRenderWindow_drawText(boutton->window, liste, NULL);
    sfText_destroy(liste);
    sfFont_destroy(font);
    txt_button_help(boutton);
}
