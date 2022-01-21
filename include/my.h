/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

#define READ_SIZE (1)

char **my_str_to_word_array(char *str);
int my_strlen(char *str);
char *my_int_to_str(int nb);
char *my_revstr(char *str);
void minishell(char **env);
char *get_next_line(int fd);
char *get_env(char **env, char *elem);
char **path_to_word_array(char *str);
int check_perm(char *str);
void env_exec(char ***tab_env, char *tab);
int my_strcmp(char *str, char *str_bis);
void execute(char *exec, char **tab, char **env);
int my_isnum(char *av);
int my_getnbr(char const *str);
int check_orders(char **tab, char ***env);
int my_strncmp(char *av, char *str, int n);
int my_strncmp_env(char *tab, char *env, int size);
int setenv_unsetenv(char **tab, char ***env);
char *my_strcpy(char *dest, char *src);
char *re_mal(char *buffer, char *bis);
int compar(char *env, char *elem);
void env_fct(char **env);
void my_unsetenv(char **tab, char ***env, int size_tab);
void free_tab(char **tab);
int count_size_tab(char **tab);
char **copy_envp(char **envp);
void env_name(char **env);
int size_env_name(char *env);
void cd(char ***env, char *str);
void my_setenv(char **tab, char ***env);
void print_error(char *str);
int setenv_condition(char *tab);

#endif
