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

char **position_a(int *a, char *buffer)
{
    int k = 0;
    int i = 0;
    int r = 0;
    char **a_position = NULL;
    char *temp = NULL;

    a_position = malloc(sizeof(char*) * *a + 1);
    while (r < *a) {
        temp = malloc(sizeof(char) * my_strlen(buffer));
        i = 0;
        while (buffer[i] != ' ' && buffer[i] != '\0') {
            temp[i] = buffer[i];
            i++;
        }
        buffer = &buffer[i+1];
        a_position[k] = temp;
        k++;
        r++;
    }
    return (a_position);
}