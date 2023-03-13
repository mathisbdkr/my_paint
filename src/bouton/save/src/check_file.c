/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** check_file
*/

#include "../include/my.h"

static int open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    close(fd);
    if (fd == 3) {
        return 1;
    }
    return 0;
}

static int check_ext(char **tab)
{
    if (my_strlen(tab[1]) != 4)
        return 1;
    char *png = "png";
    char *jpg = "jpg";
    char *bmp = "bmp";
    int k = 0;
    while (tab[1][k] == png[k]) {
        k++;
    }
    while (tab[1][k] == jpg[k]) {
        k++;
    }
    while (tab[1][k] == bmp[k]) {
        k++;
    }
    if (k != 3)
        return 1;
}

int check_file(struct save_t *save, char *path, char *path_file)
{
    int len = my_strlen(path);
    int i = 0;
    while (path[i] != '.' && i < len) {
        i++;
    }
    if (i == len) {
        return 1;
    }
    char **tab = my_str_to_word_array(path, '.');
    if (check_ext(tab) == 1)
        return 1;
    return 0;
}
