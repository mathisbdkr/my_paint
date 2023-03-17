/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** get_rect
*/

#include "../include/my.h"

sfIntRect get_rect(int top, int left, int width, int height)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}
