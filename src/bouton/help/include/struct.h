/*
** EPITECH PROJECT, 2023
** new
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "my.h"

struct help_t {
    sfRenderWindow *window;
    sfSprite *help_one;
    sfSprite *help_two;
    sfSprite *help_three;
    sfSprite *help_four;
    sfVector2f pos;
    int img_display;
};

#endif /* !STRUCT_H_ */
