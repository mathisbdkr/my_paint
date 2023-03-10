/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** main
*/

#include "../include/my.h"


int force_resize(struct paint_t *paint,  sfVector2u size_win_base)
{
    sfVector2u force_size_window = {768, 432};
    sfVector2i force_pos__window = {300, 100};
    if (sfRenderWindow_getSize(paint->window).x <= 768.f &&
    sfRenderWindow_getSize(paint->window).y <= 432.f) {
        sfRenderWindow_setSize(paint->window, force_size_window);
        sfRenderWindow_setPosition(paint->window, force_pos__window);
        my_putstr("\033[34m[System] minimal screen size : 1370x800\033[0m\n");
        my_putstr("\033[33m[System] auto resize on 1370x800\033[0m\n");
        sfRenderWindow_setSize(paint->window, force_size_window);
    }
    return 0;
}

void mouse(struct paint_t *paint, struct button_s *boutton, sfEvent event)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(paint->window);
    paint->pos = sfRenderWindow_mapPixelToCoords(paint->window,pos_mouse, NULL);
    boutton->pos = paint->pos;
    sfVector2u size_win_base = sfRenderWindow_getSize(paint->window);
    sfVector2i tmp = vec_u_to_i(size_win_base.x, size_win_base.y);
    paint->size_win = sfRenderWindow_mapPixelToCoords(paint->window, tmp, NULL);
    force_resize(paint, size_win_base);
    if (paint->pos.x < paint->size_win.x
    && paint->pos.y < paint->size_win.y &&
    paint->pos.x > 0 && paint->pos.y > paint->tool_bare) {
        sfRenderWindow_setMouseCursorVisible(paint->window, sfFalse);
        paint->display_pixel == 0;
    } else {
        sfRenderWindow_setMouseCursorVisible(paint->window, sfTrue);
        paint->display_pixel == 1;
    }
}

void loop(struct paint_t *paint, struct button_s *boutton, sfEvent event)
{
    struct pen_t *pen = malloc(sizeof(struct pen_t));
    init_pen(paint, pen);
    while (sfRenderWindow_isOpen(paint->window)) {
        sfRenderWindow_clear(paint->window, sfWhite);
        sfRenderWindow_pollEvent(paint->window, &event);
        mouse(paint, boutton, event);
        close_win(paint, event);
        draw_all(paint, event, pen);
        for (int i = 0; i < 2 && paint->tool_bare == 100; i++) {
            button(boutton, event, i);
        }
        sfRenderWindow_display(paint->window);
        menu_redir(boutton, paint);
    }
}

int main(int argc, char **argv)
{
    struct paint_t *paint = malloc(sizeof(struct paint_t));
    struct button_s *boutton = malloc(sizeof(struct button_s));
    init_struct(paint, boutton);
    sfEvent event;
    loop(paint, boutton, event);
    fopen("./backup/backup.jpg", "w");
    sfImage_saveToFile(paint->image, "./backup/backup.jpg");
    sfImage_destroy(paint->image);
    sfSprite_destroy(paint->eraser);
    sfSprite_destroy(paint->fleche);
    sfSprite_destroy(paint->pen);
    sfRenderWindow_destroy(paint->window);
    free(paint);
}
