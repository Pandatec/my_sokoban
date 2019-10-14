/*
** EPITECH PROJECT, 2018
** strlen
** File description:
** different strlen for position
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

int my_strlen(char const *str)
{
    int counts = 0;

    for (; str[counts] != '\n'; counts += 1);
    return (counts);
}

int my_pos_p(char const *str)
{
    int counts = 0;

    for (; str[counts] != 'P'; counts += 1);
    return (counts);
}

int lenmax(char const *str)
{
    int counts = 0;

    for (; str[counts] != '\0'; counts += 1);
    return (counts);
}

char *verify_malloc(char *str, char *map)
{
    for (int i = 0; map[i]; i += 1)
        str[i] = map[i];
    if (str == NULL)
        exit (84);
    return (str);
}

void free_all(char *map)
{
    write(1, "Invalid map\n", 13);
    free(map);
}
