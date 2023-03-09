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

static void loop(struct save_t *save, sfEvent event)
{
    char *name;
    while (sfRenderWindow_isOpen(save->window)) {
        sfRenderWindow_requestFocus(save->window);
        sfRenderWindow_clear(save->window, sfColor_fromRGB(37,31,75));
        sfRenderWindow_pollEvent(save->window, &event);
        mouse(save, event);
        close_win(save, event);
        lst_file(save, event);
        sfRenderWindow_display(save->window);
    }
}

void save_menu(void)
{
    struct save_t *save = malloc(sizeof(struct save_t));
    init_save(save);
    sfEvent event;
    loop(save, event);
    sfSprite_destroy(save->dir_sprite);
    sfSprite_destroy(save->file_sprite);
    free(save->file);
    sfRenderWindow_destroy(save->window);
    free(save);
}
