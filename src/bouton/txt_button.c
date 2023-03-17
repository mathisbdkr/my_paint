/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** txt_button
*/

#include "../../include/my.h"

void txt_button_help(struct button_s *boutton)
{
    sfText_setPosition(boutton->txt, get_position(77, 0));
    sfText_setColor(boutton->txt, sfBlack);
    sfText_setFont(boutton->txt, boutton->font);
    sfText_setScale(boutton->txt, get_position(0.7, 0.7));
    sfText_setString(boutton->txt, "help");
    sfRenderWindow_drawText(boutton->window, boutton->txt, NULL);
}

void txt_button_save(struct button_s *boutton)
{
    sfText_setPosition(boutton->txt, get_position(30, 0));
    sfText_setColor(boutton->txt, sfBlack);
    sfText_setFont(boutton->txt, boutton->font);
    sfText_setScale(boutton->txt, get_position(0.7, 0.7));
    sfText_setString(boutton->txt, "File");
    sfRenderWindow_drawText(boutton->window, boutton->txt, NULL);
    txt_button_help(boutton);
}
