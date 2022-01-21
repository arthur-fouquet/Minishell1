/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** cd.c
*/

#include "my.h"

void check_str(char ***env, char **str)
{
    char *arg = NULL;

    if ((*str)[0] == '~') {
        arg = get_env((*env), "HOME");
        if (arg == NULL) {
            write(2, "cd: No home directory.\n", 23);
            free(*str);
            (*str) = NULL;
            return;
        }
        (*str)++;
        (*str) = re_mal(arg, (*str)); 
    }
    if ((*str)[0] == '-') {
        arg = get_env((*env), "OLDPWD");
        if (arg == NULL) {
            write(2, ": No such file or directory.\n", 29);
            free(*str);
            (*str) = NULL;
            return;
        }
        (*str)++;
        (*str) = re_mal(arg, (*str));
    }
}

void cd(char ***env, char *str)
{
    char *pwd = NULL;
    char *pwd_bis = NULL;
    char *tab_old[3] = {"", "OLDPWD", NULL};
    char *tab_bis[3] = {"", "PWD", NULL};

    pwd = getcwd(pwd, 0);
    tab_old[2] = pwd;
    check_str(env, &str);
    if (str == NULL)
        return;
    if (chdir(str) == -1) {
        print_error(str);
        return;
    }
    my_setenv(tab_old, env);
    pwd_bis = getcwd(pwd_bis, 0);
    tab_bis[2] = pwd_bis;
    my_setenv(tab_bis, env);
}
