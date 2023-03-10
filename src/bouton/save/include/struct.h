/*
** EPITECH PROJECT, 2023
** new
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "my.h"

struct save_t {
    sfRenderWindow *window;
    sfVector2f pos;
    char *file;
    char **tab;
    int nb_file;
    sfSprite *dir_sprite;
    sfSprite *file_sprite;
    sfVector2f pos_txt;
    struct paint_t *paint;
    int is_save;
    char *dir_patch;
    char *enter_path;
};

#endif /* !STRUCT_H_ */
