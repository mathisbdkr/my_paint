/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** main
*/

#include "../include/my.h"

static int close_win(struct save_t *save, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(save->window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        sfRenderWindow_close(save->window);
    }
}

static void mouse(struct save_t *save, sfEvent event)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(save->window);
    save->pos = sfRenderWindow_mapPixelToCoords(save->window,pos_mouse, NULL);
}

static void loop(struct save_t *save, sfEvent event, sfImage *image)
{
    char *name;
    while (sfRenderWindow_isOpen(save->window)) {
        save->is_save = 0;
        sfRenderWindow_requestFocus(save->window);
        sfRenderWindow_clear(save->window, sfColor_fromRGB(37,31,75));
        sfRenderWindow_pollEvent(save->window, &event);
        mouse(save, event);
        close_win(save, event);
        lst_file(save, event);
        rond_button(save, 0, 150, 450);
        rond_button(save, 1, 350, 450);
        if (save->is_save == 1) {
            fopen("./backup/save.bmp", "w");
            sfImage_saveToFile(image, "./backup/save.bmp");
        }
        sfRenderWindow_display(save->window);
    }
}

void save_menu(sfImage *image)
{
    struct save_t *save = malloc(sizeof(struct save_t));
    init_save(save);
    sfEvent event;
    loop(save, event, image);
    sfSprite_destroy(save->dir_sprite);
    sfSprite_destroy(save->file_sprite);
    free(save->file);
    free(save->tab);
    sfRenderWindow_destroy(save->window);
    free(save);
    while (sfMouse_isButtonPressed(0)) {
    }
}
