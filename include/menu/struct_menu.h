/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** struct_menu
*/

#ifndef STRUCT_MENU_H_
    #define STRUCT_MENU_H_

    #include "../include.h"

struct button_s {
    sfRenderWindow *window;
    sfVector2f pos;
    sfRectangleShape *rect;
    int **def_button;
    sfColor outcolor;
    sfColor color;
    sfVector2f dimention;
    sfVector2f posi;
};

#endif /* !STRUCT_MENU_H_ */
