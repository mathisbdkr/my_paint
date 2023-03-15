/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** exit_event
*/

#include "../../../include/my.h"

void exit_event(MenuSaveWindow *menu_save_window)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        sfRenderWindow_close(menu_save_window->Window);
    }
    int pass = 0;
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow
    (menu_save_window->Window);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords
    (menu_save_window->Window,pos_mouse, NULL);
    sfVector2u size_win = sfRenderWindow_getSize(menu_save_window->Window);
    if (pos.x <= size_win.x && pos.x >= 0 &&
    pos.y <= size_win.y && pos.y >= 0) {
    } else if (sfMouse_isButtonPressed(0)) {
        sfRenderWindow_close(menu_save_window->Window);
        pass = 1;
    }
    while (sfMouse_isButtonPressed(0) && pass == 1) {
    }
    while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
    }
}
