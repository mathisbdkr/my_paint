/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** select_mode
*/

#include "../../../include/my.h"

static sfRectangleShape *make_btn(MenuSaveWindow *menu_save_window,
sfRectangleShape *rect, int y)
{
    rect = sfRectangleShape_create();
    sfColor color = sfColor_fromRGB(36, 32, 75);
    sfRectangleShape_setSize(rect,
    get_position(80,30));
    sfRectangleShape_setPosition(rect,
    get_position(10,y));
    sfRectangleShape_setFillColor(rect, color);
    return rect;
}

static void draw_save_menu(MenuSaveWindow *menu_save_window)
{
    sfRenderWindow_clear(menu_save_window->Window,
    sfColor_fromRGB(36, 32, 75));
    sfRenderWindow_drawRectangleShape(menu_save_window->Window,
    menu_save_window->openFileButton, NULL);
    sfRenderWindow_drawText(menu_save_window->Window,
    menu_save_window->openFileText, NULL);
    sfRenderWindow_drawRectangleShape(menu_save_window->Window,
    menu_save_window->saveButton, NULL);
    sfRenderWindow_drawText(menu_save_window->Window,
    menu_save_window->saveText, NULL);
    sfRenderWindow_drawRectangleShape(menu_save_window->Window,
    menu_save_window->saveAsButton, NULL);
    sfRenderWindow_drawText(menu_save_window->Window,
    menu_save_window->saveAsText, NULL);
    sfRenderWindow_display(menu_save_window->Window);
}

static void loop_menu_pt2(MenuSaveWindow *menu_save_window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(menu_save_window->Window, &event)) {
        if (event.type == sfEvtMouseMoved) {
            is_hover(menu_save_window, event);
        }
        if (event.type == sfEvtMouseButtonReleased) {
            is_clicked(menu_save_window, event);
        }
    }
}

static void loop_menu(MenuSaveWindow *menu_save_window, sfEvent event)
{
    while (sfRenderWindow_isOpen(menu_save_window->Window) &&
    menu_save_window->mode == 0) {
        sfRenderWindow_requestFocus(menu_save_window->Window);
        loop_menu_pt2(menu_save_window, event);
        set_color_hovered(menu_save_window);
        draw_save_menu(menu_save_window);
    }
}

int menu_save(sfEvent event, struct paint_t *paint)
{
    MenuSaveWindow menu_save_window;
    init_window(&menu_save_window, paint);
    menu_save_window.openFileButton =
    make_btn(&menu_save_window, menu_save_window.openFileButton, 10);
    menu_save_window.saveButton =
    make_btn(&menu_save_window, menu_save_window.saveButton, 50);
    menu_save_window.saveAsButton =
    make_btn(&menu_save_window, menu_save_window.saveAsButton, 90);

    set_text(&menu_save_window);
    loop_menu(&menu_save_window, event);
    menu_save_window.is_open_file_hovered = false;
    menu_save_window.is_save_hovered = false;
    menu_save_window.is_save_as_hovered = false;

    destroy_menu(&menu_save_window, paint->image, paint);
    return menu_save_window.mode;
}
