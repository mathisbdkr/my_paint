/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** converte
*/

#include "../include/my.h"

sfVector2f get_position(float x, float y)
{
    sfVector2f vector;
    vector.x = x;
    vector.y = y;
    return (vector);
}

sfVector2i vec_u_to_i(float x, float y)
{
    sfVector2i vector;
    vector.x = x;
    vector.y = y;
    return (vector);
}
