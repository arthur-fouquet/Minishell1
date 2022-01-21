/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** minishell.c
*/

#include "my.h"

void print_perm(int perm, char **tab)
{
    if (perm == 1) {
        write(2, tab[0], my_strlen(tab[0]));
        write(2, ": Command not found.\n", 21);
    } if (perm == 2) {
        write(2, tab[0], my_strlen(tab[0]));
        write(2, ": Permission denied.\n", 21);
    }
}

char *find_fill_perm(char **tab, char **envi)
{
    char *str = NULL;
    int w = 0;
    int perm = check_perm(tab[0]);

    if (perm == 0)
        return (tab[0]);
    if (tab[0][0] == '.' && tab[0][1] == '/') {
        print_perm(perm, tab);
        return (NULL);
    }
    env_exec(&envi, tab[0]);
    for (; envi[w] != NULL; w++) {
        perm = check_perm(envi[w]);
        if (perm == 0)
            str = envi[w];
    }
    if (str == NULL)
        print_perm(perm, tab);
    return (str);
}

char *get_exec(char **env, char **tab)
{
    char **envi = NULL;
    char *return_str = NULL;

    envi = path_to_word_array(get_env(env, "PATH"));
    if (envi == NULL) {
        write(2, tab[0], my_strlen(tab[0]));
        write(2, ": Command not found.\n", 21);
        return (NULL);
    }
    return_str = find_fill_perm(tab, envi);
    return (return_str);
}

char **get_input(void)
{
    char *str = get_next_line(0);
    char **tab = NULL;

    if (str == NULL)
        exit(84);
    tab = my_str_to_word_array(str);
    if (tab == NULL)
        exit(84);
    return (tab);
}

void minishell(char **envp)
{
    char *exec = NULL;
    char **tab = NULL;
    char **env = copy_envp(envp);
    int returned = 0;

    while (4) {
        env_name(envp);
        tab = get_input();
        if (tab[0] == NULL)
            returned = 1;
        returned = check_orders(tab, &env);
        if (tab[0] != 0 && returned == 0)
            exec = get_exec(env, tab);
        if (exec != NULL && returned == 0)
            execute(exec, tab, env);
        free_tab(tab);
    }
    free_tab(env);
}
