/*
** EPITECH PROJECT, 2023
** bs
** File description:
** word_array
*/

#include "../include/my.h"

int len_nbm(char *str, char sep)
{
    int nbm = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep || str[i] == '\t') {
            nbm++;
        }
    }
    return nbm;
}

int len_mot(char *str, int i, char sep)
{
    int nb = 0;
    while (str[i] == sep || str[i] == '\n' || str[i] == '\t') {
        i++;
    }
    while (str[i] != '\0' && str[i] != sep && str[i] != '\n'
    && str[i] != '\t') {
        nb++;
        i++;
    }
    return nb;
}

int pass_sep(char *str, int i, char sep)
{
    int pass = 0;
    if (i == 0)
        return 0;
    while (str[i - 1] == sep || str[i - 1] == '\t') {
        i++;
        pass = 1;
    }
    if (pass == 1) {
        i--;
        pass = 0;
    }
    return i;
}

char **verif_tab(char **tab, int z, char sep)
{
    int i = 0;
    int pass = 0;
    if (tab[0][0] == '\0') {
        pass = 1;
        for (i; i < z; i++) {
            tab[i] = tab[i + 1];
        }
        tab[i] = '\0';
    }
    if (pass == 1)
        z--;
    if (tab[z][0] == '\0') {
        tab[z] = '\0';
    }
    return tab;
}

char **my_str_to_word_array(char *str, char sep)
{
    int i = 0;int z = 0;
    int y = 0;
    char **test = malloc(sizeof(char *) * (len_nbm(str, sep) + 30));
    test[z] = malloc(sizeof(char) * (len_mot(str, 0, sep) + 20));
    while (str[i]) {
        i = pass_sep(str, i, sep);
        if (i > 0 && str[i - 1] == sep || i > 0 && str[i - 1] == '\t') {
            test[z][y - 1] = '\0';
            z++;
            y = 0;
            test[z] = malloc(sizeof(char) * (len_mot(str, i, sep) + 20));
            test[z][y] = '\0';
        }
        test[z][y] = str[i];
        y++;
        i++;
    }
    test[z + 1] = NULL;
    return test;
}
