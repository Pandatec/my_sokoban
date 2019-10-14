/*
** EPITECH PROJECT, 2018
** win or lose
** File description:
** define win and lose condition
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

int final_display(int key)
{
    if (key == 1) {
        write(1, "Level Complete!\n", 17);
        return (0);
    }
    if (key == 2) {
        write(1, "You lose! Try Again!\n", 21);
        return (1);
    }
    return (0);
}

int lose(char *map, char *map_base)
{
    int nb_base = 0;
    int len = my_strlen(map) + 1;
    int counts = 0;

    for (int i = 0; map_base[i] != '\0'; i += 1) {
        if (map_base[i] == 'O')
            nb_base += 1;
    }
    for (int i = 0; map[i] != '\0'; i += 1) {
        if (map[i] == 'X' && ((map[i + 1] == '#' && map[i - len] == '#') ||
        (map[i - 1] == '#' && map[i - len] == '#') ||
        (map[i + 1] == '#' && map[i + len] == '#') ||
        (map[i - 1] == '#' && map[i + len] == '#')))
            counts += 1;
    }
    if (counts == nb_base)
        return (1);
    return (0);
}

int win_or_lose(char *map, char *map_base)
{
    int count = 0;
    int base = 0;
    int loser = 0;

    for (int i = 0; map_base[i] != '\0'; i += 1) {
        if (map_base[i] == 'O')
            base += 1;
    }
    for (int i = 0; map[i] != '\0'; i += 1) {
        if (map[i] == 'X' && map_base[i] == 'O')
            count += 1;
    }
    loser = lose(map, map_base);
    if (count == base)
        return (1);
    else if (loser != 0)
        return (2);
    else
        return (0);
}

int verify_map(char *map)
{
    int nb_O = 0;
    int nb_X = 0;
    int nb_P = 0;

    for (int i = 0; map[i] != '\0'; i += 1) {
        if (map[i] == 'O')
            nb_O += 1;
        if (map[i] == 'X')
            nb_X += 1;
        if (map[i] == 'P')
            nb_P += 1;
        if (map[i] != '#' && map[i] != 'P' && map[i] != 'X' && map[i] != 'O' &&
            map[i] != ' ' && map[i] != '\n')
            return (2);
    }
    if (nb_O > nb_X || nb_P != 1)
        return (1);
    else
        return (0);
}
