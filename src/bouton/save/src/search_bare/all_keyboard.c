/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** all_keyboard
*/

#include "../../include/my.h"

void all_keyboard(struct save_t *save, int k)
{
    char *lettre = malloc(sizeof(char) + 2);
    int len = my_strlen(save->enter_path);
    if (k == 59)
        save->enter_path[len - 1] = '\0';
    if (k == 48)
        save->enter_path = my_strcat(save->enter_path, ".\0");
    if (k == 34)
        save->enter_path = my_strcat(save->enter_path, "_\0");
    if (k == 32)
        save->enter_path = my_strcat(save->enter_path, "-\0");
    if (k == 36)
        sfRenderWindow_close(save->window);
    if (k == 58)
        save->is_save = 1;
    while (sfKeyboard_isKeyPressed(k)) {
    }
}
