/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mathis.brehm
** File description:
** proto_menu
*/

#ifndef PROTO_MENU_H_
    #define PROTO_MENU_H_

    #include "../include.h"
    #include "struct_menu.h"

void button(struct button_s *boutton, sfEvent event, int i);
void menu_redir(struct button_s *boutton, struct paint_t *paint, sfEvent event);
int menu_save(sfEvent event, struct paint_t *paint);
void init_window(MenuSaveWindow *menu_save_window, struct paint_t *paint);
void set_text(MenuSaveWindow *menu_save_window);
void is_hover(MenuSaveWindow *menu_save_window, sfEvent event);
void is_clicked(MenuSaveWindow *menu_save_window, sfEvent event);
void set_color_hovered(MenuSaveWindow *menu_save_window);
void destroy_menu(MenuSaveWindow *menu_save_window,
    sfImage *image, struct paint_t *paint);
char *save_menu(sfImage *image, int mode, char *path);
void txt_button_save(struct button_s *boutton);

#endif /* !PROTO_MENU_H_ */
