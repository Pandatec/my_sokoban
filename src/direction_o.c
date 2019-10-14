/*
** EPITECH PROJECT, 2018
** direction_O.c
** File description:
** direction personage with O
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

void up_o(char *map, char *map_base, int len, int pos_P)
{
    if (map[pos_P - len] != '#') {
        if (map_base[pos_P] == 'O') {
            map[pos_P] = 'O';
            pos_P = my_pos_p(map);
        }
        if (map[pos_P - len] == 'O') {
            map[pos_P - len] = 'P';
            map[pos_P] = ' ';
            pos_P = my_pos_p(map);
        }
    }
}

void down_o(char *map, char *map_base, int len, int pos_P)
{
    if (map[pos_P + len] != '#') {
        if (map_base[pos_P] == 'O') {
            map[pos_P] = 'O';
            pos_P = my_pos_p(map);
        }
        if (map[pos_P + len] == 'O') {
            map[pos_P + len] = 'P';
            map[pos_P] = ' ';
            pos_P = my_pos_p(map);
        }
    }
}

void left_o(char *map, char *map_base, int pos_P)
{
    if (map[pos_P + 1] != '#') {
        if (map_base[pos_P] == 'O') {
            map[pos_P] = 'O';
            pos_P = my_pos_p(map);
        }
        if (map[pos_P - 1] == 'O') {
            map[pos_P - 1] = 'P';
            map[pos_P] = ' ';
            pos_P = my_pos_p(map);
        }
    }
}

void right_o(char *map, char *map_base, int pos_P)
{
    if (map[pos_P - 1] != '#') {
        if (map_base[pos_P] == 'O') {
            map[pos_P] = 'O';
            pos_P = my_pos_p(map);
        }
        if (map[pos_P + 1] == 'O') {
            map[pos_P + 1] = 'P';
            map[pos_P] = ' ';
            pos_P = my_pos_p(map);
        }
    }
}
char *reboot(char *map, char *map_base)
{
    for (int i = 0; map_base[i]; i += 1)
        map[i] = map_base[i];
    return (map);
}
