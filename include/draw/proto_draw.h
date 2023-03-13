/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** proto_draw
*/

#ifndef PROTO_DRAW_H_
    #define PROTO_DRAW_H_

    #include "../include.h"
    #include "struct_draw.h"

void draw_all(struct paint_t *paint, sfEvent event, struct pen_t *pen);
void init_pen(struct paint_t *paint, struct pen_t *pen);

int paint_win(sfEvent event, struct paint_t *paint, struct pen_t *pen);

void hitbox_pixel(struct paint_t *paint, struct pen_t *pen, int size);

int check_pixel(float y,float x, float size, struct paint_t *paint);
sfColor color_pallet(int nb, struct pen_t *pen, int n);
void color_select(struct paint_t *paint, struct pen_t *pen, sfEvent event);
void set_pen(struct paint_t *paint);
void set_eraser(struct paint_t *paint);
void pen_size(struct paint_t *paint, struct pen_t *pen, sfEvent event);
void square_cercle(struct paint_t *paint, struct pen_t *pen, float size);
void draw_circle(struct paint_t *paint, struct pen_t *pen, int radius);
void pixel(struct paint_t *paint, struct pen_t *pen, float size);
void select_type(struct paint_t *paint, struct pen_t *pen, sfEvent event);
void pen_shape(struct paint_t *paint, struct pen_t *pen, sfEvent event);
void set_fleche(struct paint_t *paint);
void back_color(struct paint_t *paint, struct pen_t *pen);
void jour_nuit(struct paint_t *paint);
void back_change(struct paint_t *paint, struct pen_t *pen);

#endif /* !PROTO_DRAW_H_ */
