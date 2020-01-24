/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** space.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "printf/my.h"

char **read_user_input(char **argv, char **envp, t_data *cordonnee)
{
    size_t sizeb = 1000;
    char *buffer = NULL;
    cordonnee->y = find_home_path(envp);
    char *envp2 = my_strdup(&envp[cordonnee->y][5]);

    buffer = malloc(sizeof(char) * sizeb);
    if (getline(&buffer, &sizeb, stdin) == -1)
        exit (0);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            buffer[i] = '\0';
    }
    buffer = one_space(buffer);
    argv = count_word(buffer);
    if (my_cd(argv, argv[1], envp2) == 0)
        return (0);
    if (my_unsetenv(argv, argv[1]) == 0)
        return (0);
    my_exit(argv);
    if (my_setenv(argv, argv[1], argv[2], envp) == 0)
        return (0);
    if (parsing_path(argv, argv[0], envp) == 0)
        shell_loop(argv, envp, cordonnee);
    return (argv);
}