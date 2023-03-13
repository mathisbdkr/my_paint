/*
** EPITECH PROJECT, 2023
** test
** File description:
** menu
*/

#include "../../include/my.h"

void menu_redir(struct button_s *boutton, struct paint_t *paint, sfEvent event)
{
    int mode = 0;
    if (boutton->def_button[0][5] == 1) {
        sfRenderWindow_setMouseCursorVisible(paint->window, sfTrue);
        mode = menu_save(event, paint);
        boutton->def_button[0][5] = 0;
        sfRenderWindow_setMouseCursorVisible(paint->window, sfFalse);
    }
}
