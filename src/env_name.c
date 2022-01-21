/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** env_name.c
*/

#include "my.h"

int strlen_host(char *str)
{
    int a = 0;

    for (; str[a] != '\0' && str[a] != '.'; a++);
    return (a);
}

void get_pwd(char **pwd)
{
    int a = 0;

    for (int b = 0; (*pwd)[b] != '\0'; b++)
        if ((*pwd)[b] == '/')
            a++;
    while (a != 0) {
        if ((*pwd)[0] == '/')
            a--;
        (*pwd)++;
    }
}

void env_name_bis(char *pwd, char *home)
{
    write(1, " ", 1);
    if (my_strcmp(pwd, home) == 0)
        write(1, "~", 1);
    else
        write(1, pwd, my_strlen(pwd));
    write(1, "]$ ", 3);
}

void env_name(char **env)
{
    char *user = get_env(env, "USER");
    char *hostname = get_env(env, "HOST");
    char *pwd = NULL;
    char *home = get_env(env, "HOME");

    if (env[0] == NULL) {
        write(1, "> ", 2);
        return;
    }
    write(1, "[", 1);
    if (user != NULL)
        write(1, user, my_strlen(user));
    write(1, "@", 1);
    if (hostname != NULL)
        write(1, hostname, strlen_host(hostname));
    pwd = getcwd(pwd, 0);
    get_pwd(&pwd);
    if (home != NULL)
        get_pwd(&home);
    env_name_bis(pwd, home);
}
