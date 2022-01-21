/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strcmp.c
*/

#include "my.h"

int my_strcmp(char *str, char *str_bis)
{
    if (my_strlen(str) != my_strlen(str_bis))
        return (1);
    for (int a = 0; str[a] != '\0' && str_bis[a] != '\0'; a++)
        if (str[a] != str_bis[a])
            return (1);
    return (0);
}
