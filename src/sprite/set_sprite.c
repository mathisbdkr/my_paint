/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** set_sprite
*/

#include "../../include/my.h"

void set_pen(struct paint_t *paint)
{
    sfSprite *pen = sfSprite_create();
    sfSprite_setTexture(pen,
    sfTexture_createFromFile("img/pen.png", NULL), 0);
    sfVector2u scale = sfTexture_getSize(sfSprite_getTexture(pen));
    sfVector2f size = get_position(scale.x,scale.y);
    sfSprite_setScale(pen, get_position(0.1, 0.1));
    paint->pen = pen;
}

void set_eraser(struct paint_t *paint)
{
    sfSprite *eraser = sfSprite_create();
    sfSprite_setTexture(eraser,
    sfTexture_createFromFile("img/eraser.png", NULL), 0);
    sfVector2u scale = sfTexture_getSize(sfSprite_getTexture(eraser));
    sfVector2f size = get_position(scale.x,scale.y);
    sfSprite_setScale(eraser, get_position(0.1, 0.1));
    paint->eraser = eraser;
}

void set_fleche(struct paint_t *paint)
{
    sfSprite *fleche = sfSprite_create();
    sfSprite_setTexture(fleche,
    sfTexture_createFromFile("img/fleche.png", NULL), 0);
    sfSprite_setPosition(fleche, get_position(5, 5));
    paint->fleche = fleche;
}
