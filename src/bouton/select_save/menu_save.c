/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** menu_save
*/

#include "../../../include/my.h"

static void set_txt_save(MenuSaveWindow *menu_save_window)
{
    sfColor txt_color = sfWhite;
    if (menu_save_window->path == NULL) {
        txt_color = sfColor_fromRGB(20,20,20);
    }
    menu_save_window->saveText = sfText_create();
    sfText_setString(menu_save_window->saveText, "Save");
    sfText_setFont(menu_save_window->saveText, menu_save_window->font);
    sfText_setCharacterSize(menu_save_window->saveText, 16);
    sfText_setColor(menu_save_window->saveText, txt_color);
    sfText_setPosition(menu_save_window->saveText, (sfVector2f){15, 55});
}

void set_text(MenuSaveWindow *menu_save_window)
{
    menu_save_window->font = sfFont_createFromFile("font/army.ttf");

    menu_save_window->openFileText = sfText_create();
    sfText_setString(menu_save_window->openFileText, "Open file");
    sfText_setFont(menu_save_window->openFileText, menu_save_window->font);
    sfText_setCharacterSize(menu_save_window->openFileText, 16);
    sfText_setPosition(menu_save_window->openFileText, (sfVector2f){15, 15});

    set_txt_save(menu_save_window);

    menu_save_window->saveAsText = sfText_create();
    sfText_setString(menu_save_window->saveAsText, "Save as");
    sfText_setFont(menu_save_window->saveAsText, menu_save_window->font);
    sfText_setCharacterSize(menu_save_window->saveAsText, 16);
    sfText_setPosition(menu_save_window->saveAsText, (sfVector2f){15, 95});
}

void is_hover(MenuSaveWindow *menu_save_window, sfEvent event)
{
    sfFloatRect openbound =
    sfRectangleShape_getGlobalBounds(menu_save_window->openFileButton);
    if (sfFloatRect_contains(&openbound,event.mouseMove.x, event.mouseMove.y))
        menu_save_window->is_open_file_hovered = true;
    else
        menu_save_window->is_open_file_hovered = false;
    sfFloatRect saveButtonBounds =
    sfRectangleShape_getGlobalBounds(menu_save_window->saveButton);
    if (sfFloatRect_contains(&saveButtonBounds,
    event.mouseMove.x, event.mouseMove.y) && menu_save_window->path != NULL)
        menu_save_window->is_save_hovered = true;
    else
        menu_save_window->is_save_hovered = false;
    sfFloatRect saveAsButtonBounds =
    sfRectangleShape_getGlobalBounds(menu_save_window->saveAsButton);
    if (sfFloatRect_contains(&saveAsButtonBounds,
    event.mouseMove.x, event.mouseMove.y))
        menu_save_window->is_save_as_hovered = true;
    else
        menu_save_window->is_save_as_hovered = false;
}

void is_clicked(MenuSaveWindow *menu_save_window, sfEvent event)
{
    if (event.mouseButton.button == sfMouseLeft) {
        if (menu_save_window->is_open_file_hovered) {
            menu_save_window->mode = 1;
        }
        if (menu_save_window->is_save_hovered &&
        menu_save_window->path != NULL) {
            menu_save_window->mode = 2;
        }
        if (menu_save_window->is_save_as_hovered) {
            menu_save_window->mode = 3;
        }
    }
}

void set_color_hovered(MenuSaveWindow *menu_save_window)
{
    sfColor color = sfColor_fromRGB(46, 42, 85);
    if (menu_save_window->is_open_file_hovered) {
        sfRectangleShape_setFillColor(menu_save_window->openFileButton, color);
    } else {
        sfRectangleShape_setFillColor(menu_save_window->openFileButton,
        sfColor_fromRGB(36, 32, 75));
    }
    if (menu_save_window->is_save_hovered) {
        sfRectangleShape_setFillColor(menu_save_window->saveButton, color);
    } else {
        sfRectangleShape_setFillColor(menu_save_window->saveButton,
        sfColor_fromRGB(36, 32, 75));
    }
    if (menu_save_window->is_save_as_hovered) {
        sfRectangleShape_setFillColor(menu_save_window->saveAsButton, color);
    } else {
        sfRectangleShape_setFillColor(menu_save_window->saveAsButton,
        sfColor_fromRGB(36, 32, 75));
    }
}
