/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** free_tab.c
*/

#include "my.h"

void free_tab(char **tab)
{
    int b = 0;

    for (; tab[b] != NULL; b++);
    for (int a = 0; a != b; a++) {
        free(tab[a]);
    }
    free(tab);
    tab = NULL;
}
