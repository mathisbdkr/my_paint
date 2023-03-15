/*
** EPITECH PROJECT, 2022
** bspaint
** File description:
** paint
*/

#ifndef PAINT_H_
    #define PAINT_H_

    #include "../../../../include/my.h"
    #include "include.h"
    #include "struct.h"

void init_save(struct save_t *save, int mode, int back_color);

sfVector2f get_position(float x, float y);

sfVector2i vec_u_to_i(float x, float y);
int ls_vide(struct save_t *save);
int file_type(struct save_t *save, char *name);
void dir_sprite(struct save_t *save);
void back_sprite(struct save_t *save);
void file_sprite(struct save_t *save);
char *resize_name(char *name);
void lst_file(struct save_t *save, sfEvent event);
int rond_button(struct save_t *save, int id, int x, int y);
void search_bare(struct save_t *save);
void ext_file(struct save_t *save);
int menu_save(sfEvent event, struct paint_t *paint);
int check_file(struct save_t *save, char *path, char *path_file);
void utils_file_manager(struct save_t *save, sfEvent event);
void back_button(struct save_t *save);
void all_keyboard(struct save_t *save, int k);
void bare_prompt(struct save_t *save);

char *my_strcpy(char* dest, char* src);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_strcat(char* src, char* dest);
char **my_str_to_word_array(char *str, char sep);
int my_strcmp(const char* s1, const char* s2);

#endif /* !paint_H_ */
