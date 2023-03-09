/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** proto_menu
*/

#ifndef PROTO_MENU_H_
    #define PROTO_MENU_H_

    #include "../include.h"
    #include "struct_menu.h"

void button(struct button_s *boutton, sfEvent event, int i);
void menu_redir(struct button_s *boutton);
void save_menu(void);

#endif /* !PROTO_MENU_H_ */
