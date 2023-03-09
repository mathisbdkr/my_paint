/*
** EPITECH PROJECT, 2023
** new
** File description:
** ls
*/

#include "../include/my.h"

int len_file(struct dirent *file, DIR *dir)
{
    file = readdir(dir);
    struct stat sb;
    if (file) {
        char *name = file->d_name;
        if (name[0] != '.') {
            return my_strlen(file->d_name);
        }
    } else {
        return -5;
    }
}

int nom_file(struct dirent *file, DIR *dir, struct save_t *save)
{
    file = readdir(dir);
    struct stat sb;
    if (file) {
        char *name = file->d_name;
        if (name[0] != '.') {
            save->file = my_strcat(save->file, name);
            save->file = my_strcat(save->file, " ");
        }
    } else {
        return 84;
    }
}

void file_char(struct save_t *save, int res, int nb)
{
    save->file = malloc(sizeof(char) * (res + 3) + nb);
    save->file[0] = '\0';
    DIR *dir = opendir("./");
    struct dirent *file = readdir(dir);
    save->file = my_strcat(save->file, file->d_name);
    save->file = my_strcat(save->file, " ");
    while (dir) {
        if (nom_file(file, dir, save) == 84)
            break;
    }
}

int ls_vide(struct save_t *save)
{
    DIR *dir = opendir("./");
    if (dir == NULL) {
        return 1;
    }
    struct dirent *file = readdir(dir);
    int len = 0;
    int res = my_strlen(file->d_name);
    int nb = 0;
    while (dir) {
        len = len_file(file, dir);
        if (len == -5)
            break;
        res += len;
        nb++;
    }
    file_char(save, res, nb);
}
