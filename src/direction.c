/*
** EPITECH PROJECT, 2018
** direction.c
** File description:
** direction personage
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

void up(char *map, int len, int pos_P)
{
    if (map[pos_P - len] != '#') {
        if (map[pos_P - len] == ' ') {
            map[pos_P - len] = 'P';
            map[pos_P] = ' ';
            pos_P = my_pos_p(map);
        }
        if (map[pos_P - len] == 'X' && map[pos_P - (len * 2)] != '#' &&
            map[pos_P - (len * 2)] != 'X') {
            map[pos_P - (len * 2)] = 'X';
            map[pos_P - len] = 'P';
            map[pos_P] = ' ';
            pos_P = my_pos_p(map);
        }
    }
}

void down(char *map, int len, int pos_P)
{
    if (map[pos_P + len] != '#') {
        if (map[pos_P + len] == ' ') {
            map[pos_P + len] = 'P';
            map[pos_P] = ' ';
            pos_P = my_pos_p(map);
        }
        if (map[pos_P + len] == 'X' && map[pos_P + (len * 2)] != '#' &&
            map[pos_P + (len * 2)] != 'X') {
            map[pos_P + (len * 2)] = 'X';
            map[pos_P + len] = 'P';
            map[pos_P] = ' ';
            pos_P = my_pos_p(map);
        }
    }
}

void left(char *map, int pos_P)
{
    if (map[pos_P - 1] != '#') {
        if (map[pos_P - 1] == ' ') {
            map[pos_P - 1] = 'P';
            map[pos_P] = ' ';
            pos_P = my_pos_p(map);
        }
        if (map[pos_P - 1] == 'X' && map[pos_P - 2] != '#' &&
            map[pos_P - 2] != 'X') {
            map[pos_P - 2] = 'X';
            map[pos_P - 1] = 'P';
            map[pos_P] = ' ';
            pos_P = my_pos_p(map);
        }
    }
}

void right(char *map, int pos_P)
{
    if (map[pos_P + 1] != '#') {
        if (map[pos_P + 1] == ' ') {
            map[pos_P + 1] = 'P';
            map[pos_P] = ' ';
            pos_P = my_pos_p(map);
        }
        if (map[pos_P + 1] == 'X' && map[pos_P + 2] != '#' &&
            map[pos_P + 2] != 'X') {
            map[pos_P + 2] = 'X';
            map[pos_P + 1] = 'P';
            map[pos_P] = ' ';
            pos_P = my_pos_p(map);
        }
    }
}
