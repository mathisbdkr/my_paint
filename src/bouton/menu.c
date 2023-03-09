/*
** EPITECH PROJECT, 2023
** test
** File description:
** menu
*/

#include "../../include/my.h"

void menu_redir(struct button_s *boutton, struct paint_t *paint)
{
    if (boutton->def_button[0][5] == 1) {
        save_menu(paint->image);
        boutton->def_button[0][5] = 0;
    }
}
