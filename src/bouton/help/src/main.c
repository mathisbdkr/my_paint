/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** main
*/

#include "../include/my.h"

static int close_win(struct help_t *help, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        sfRenderWindow_close(help->window);
    }
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(help->window);
    }
}

static void image_display(struct help_t *help)
{
    sfVector2u size_win = sfRenderWindow_getSize(help->window);
    sfSprite_setTextureRect(help->help_one,
    get_rect(26, 0, size_win.x, size_win.y));
    sfSprite_setTextureRect(help->help_two,
    get_rect(26, 0, size_win.x, size_win.y));
    sfSprite_setTextureRect(help->help_three,
    get_rect(52, 0, size_win.x, size_win.y));
    sfSprite_setTextureRect(help->help_four,
    get_rect(52, 0, size_win.x, size_win.y));
    if (help->img_display == 0)
        sfRenderWindow_drawSprite(help->window, help->help_one, 0);
    if (help->img_display == 1)
        sfRenderWindow_drawSprite(help->window, help->help_two, 0);
    if (help->img_display == 2)
        sfRenderWindow_drawSprite(help->window, help->help_three, 0);
    if (help->img_display == 3)
        sfRenderWindow_drawSprite(help->window, help->help_four, 0);
}

void help_menu(void)
{
    struct help_t *help = malloc(sizeof(struct help_t));
    init_help(help);
    sfEvent event;
    while (sfRenderWindow_isOpen(help->window)) {
        sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(help->window);
        help->pos = sfRenderWindow_mapPixelToCoords(help->window,
        pos_mouse, NULL);
        sfRenderWindow_clear(help->window, sfWhite);
        sfRenderWindow_pollEvent(help->window, &event);
        close_win(help, event);
        image_display(help);
        next_button(help);
        sfRenderWindow_display(help->window);
    }
    sfSprite_destroy(help->help_one);
    sfSprite_destroy(help->help_two);
    sfSprite_destroy(help->help_three);
    sfSprite_destroy(help->help_four);
    sfRenderWindow_destroy(help->window);
    free(help);
}
