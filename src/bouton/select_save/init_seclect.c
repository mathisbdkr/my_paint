/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** init_seclect
*/

#include "../../../include/my.h"

void destroy_menu(MenuSaveWindow *menu_save_window,
    sfImage *image, struct paint_t *paint)
{
    if (menu_save_window->mode == 2) {
        fopen(paint->path_name, "w");
        sfImage_saveToFile(paint->image, paint->path_name);
    } else {
        char *path = save_menu(image, menu_save_window->mode,
        paint->path_name, paint->back_color);
        paint->path_name = path;
    }
    if (paint->path_name != NULL) {
        paint->image = sfImage_createFromFile(paint->path_name);
    }
    sfRenderWindow_close(menu_save_window->Window);
    sfRectangleShape_destroy(menu_save_window->openFileButton);
    sfRectangleShape_destroy(menu_save_window->saveButton);
    sfRectangleShape_destroy(menu_save_window->saveAsButton);
    sfText_destroy(menu_save_window->openFileText);
    sfText_destroy(menu_save_window->saveText);
    sfText_destroy(menu_save_window->saveAsText);
    sfFont_destroy(menu_save_window->font);
    sfRenderWindow_destroy(menu_save_window->Window);
}

void init_window(MenuSaveWindow *menu_save_window, struct paint_t *paint)
{
    menu_save_window->WindowMode.bitsPerPixel = 32;
    menu_save_window->WindowMode.height = 135;
    menu_save_window->WindowMode.width = 100;
    menu_save_window->Window = sfRenderWindow_create(
    menu_save_window->WindowMode, "Fenêtre parent", sfNone, NULL);

    sfVector2i window_pos1 = sfRenderWindow_getPosition(paint->window);
    sfVector2i window_pos2;
    window_pos2.x = window_pos1.x + 100;
    window_pos2.y = window_pos1.y + 100;
    menu_save_window->mode = 0;
    menu_save_window->path = paint->path_name;
    sfRenderWindow_setPosition(menu_save_window->Window, window_pos2);

}
