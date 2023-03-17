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

void init_help(struct help_t *help);

void help_one(struct help_t *help);
void help_two(struct help_t *help);
void help_three(struct help_t *help);
void help_four(struct help_t *help);

void next_button(struct help_t *help);

sfIntRect get_rect(int top, int left, int width, int height);
sfVector2f get_position(float x, float y);

char *my_strcpy(char* dest, char* src);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_strcat(char* src, char* dest);
char **my_str_to_word_array(char *str, char sep);
int my_strcmp(const char* s1, const char* s2);

#endif /* !paint_H_ */
