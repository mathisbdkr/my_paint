/*
** EPITECH PROJECT, 2023
** test
** File description:
** menu
*/

#include "../../include/my.h"

void menu_redir(struct button_s *boutton)
{
    if (boutton->def_button[0][5] == 1) {
        save_menu();
        boutton->def_button[0][5] = 0;
    }
}
