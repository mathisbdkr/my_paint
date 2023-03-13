/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** color_pallet
*/

#include "../../../../include/my.h"

static sfColor color_pallet_pt2(int nb, struct pen_t *pen, int n)
{
    sfColor yanis = sfColor_fromRGB(185,138,131);
    sfColor barbapapa = sfColor_fromRGBA(254,174,201,255);
    if (nb == 4)
        return sfBlue;
    if (nb == 5)
        return sfYellow;
    if (nb == 6)
        return yanis;
    if (nb == 7) {
        return barbapapa;
    }
    return sfWhite;
}

sfColor color_pallet(int nb, struct pen_t *pen, int n)
{
    sfColor gomme = sfBlack;
    sfColor color_one = sfWhite;
    if (pen->back_color == 1) {
        gomme = sfWhite;
        color_one = sfBlack;
    }
    if (nb == 0) {
        if (n == 0)
            pen->gomme = 1;
        return gomme;
    }
    if (n == 0)
        pen->gomme = 0;
    if (nb == 1)
        return color_one;
    if (nb == 2)
        return sfRed;
    if (nb == 3)
        return sfGreen;
    return color_pallet_pt2(nb, pen, n);
}
