/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** main
*/

#include "../include/my.h"

static char *save_path(struct save_t *save, sfImage *image)
{
    if (save->is_save == 1 && save->mode != 1) {
        char *tmp = save->dir_patch;
        tmp = my_strcat(tmp, save->enter_path);
        tmp = my_strcat(tmp, save->extention);
        fopen(tmp, "w");
        sfImage_saveToFile(image, tmp);
        return tmp;
    }
    if (save->is_save == 1 && save->mode == 1) {
        char *tmp = save->dir_patch;
        tmp = my_strcat(tmp, save->enter_path);
        if (check_file(save, save->enter_path, tmp) == 0) {
            return tmp;
        }
        save->is_save = 0;
        save->enter_path[0] = '\0';
    }
    return NULL;
}

static void loop_pt1(struct save_t *save, sfEvent event, sfImage *image)
{
    save->is_save = 0;
    sfRenderWindow_requestFocus(save->window);
    sfRenderWindow_clear(save->window, sfColor_fromRGB(37,31,75));
    sfRenderWindow_pollEvent(save->window, &event);
    utils_file_manager(save, event);
    lst_file(save, event);
    rond_button(save, 0, 150, 450);
    rond_button(save, 1, 350, 450);
    search_bare(save);
}

static char *loop(struct save_t *save, sfEvent event, sfImage *image)
{
    char *name;
    int pass = 0;
    while (sfRenderWindow_isOpen(save->window) && pass == 0) {
        loop_pt1(save, event, image);
        if (save->is_save == 1) {
            return save_path(save, image);
        }
        sfRenderWindow_display(save->window);
    }
}

char *save_menu(sfImage *image, int mode, char *path_name)
{
    struct save_t *save = malloc(sizeof(struct save_t));
    init_save(save, mode);
    sfEvent event;
    char *path = loop(save, event, image);
    sfSprite_destroy(save->dir_sprite);
    sfSprite_destroy(save->file_sprite);
    free(save->file);
    free(save->tab);
    free(save->enter_path);
    sfRenderWindow_destroy(save->window);
    free(save);
    while (sfMouse_isButtonPressed(0)) {
    }
    return path;
}
