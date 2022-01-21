/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** env_exec.c
*/

#include "my.h"

char *re_mal(char *buffer, char *bis)
{
    int a = 0;
    char *str;

    if (bis == NULL)
        return buffer;
    if (buffer == NULL)
        return (NULL);
    for (; buffer[a] != '\0'; a++);
    for (int b = 0; bis[b] != '\0'; b++, a++);
    str = malloc(sizeof(char) * (a + 1));
    if (str == NULL)
        return (NULL);
    for (a = 0; buffer[a] != '\0'; a++)
        str[a] = buffer[a];
    for (int e = 0; bis[e] != '\0'; e++, a++)
        str[a] = bis[e];
    str[a] = '\0';
    return (str);
}

void env_exec(char ***tab_env, char *tab)
{
    for (int a = 0; (*tab_env)[a] != NULL; a++) {
        (*tab_env)[a] = re_mal((*tab_env)[a], "/");
        (*tab_env)[a] = re_mal((*tab_env)[a], tab);
    }
}
