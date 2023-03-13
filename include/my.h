/*
** EPITECH PROJECT, 2022
** bspaint
** File description:
** paint
*/

#ifndef PAINT_H_
    #define PAINT_H_

    #include "include.h"
    #include "draw/struct_draw.h"
    #include "menu/struct_menu.h"
    #include "draw/proto_draw.h"
    #include "menu/proto_menu.h"

void init_struct(struct paint_t *paint, struct button_s *boutton);

sfVector2f get_position(float x, float y);
int close_win(struct paint_t *paint, sfEvent event);

sfVector2i vec_u_to_i(float x, float y);
char *my_strcpy(char* dest, char* src);
int my_strcmp(const char* s1, const char* s2);

#endif /* !paint_H_ */
