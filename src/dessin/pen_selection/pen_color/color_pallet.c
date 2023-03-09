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
    if (nb == 6)
        return yanis;
    if (nb == 7)
        return barbapapa;
    return sfWhite;
}

sfColor color_pallet(int nb, struct pen_t *pen, int n)
{
    if (nb == 0) {
        if (n == 0)
            pen->gomme = 1;
        return sfBlack;
    }
    if (n == 0)
        pen->gomme = 0;
    if (nb == 1)
        return sfWhite;
    if (nb == 2)
        return sfRed;
    if (nb == 3)
        return sfGreen;
    if (nb == 4)
        return sfBlue;
    if (nb == 5)
        return sfYellow;
    return color_pallet_pt2(nb, pen, n);
}
