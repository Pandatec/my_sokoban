/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** create a sokoban
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

char *read_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *str;
    struct stat filestat;

    if (fd == -1) {
        write(1, "Failure open\n", 14);
        exit (84);
    }
    stat(filepath, &filestat);
    if (filestat.st_size == 0) {
        write(1, "Fail stat\n", 11);
        exit (84);
    }
    str = malloc(sizeof(char) * (filestat.st_size) + 100);
    if (str == NULL)
        exit (84);
    read(fd, str, filestat.st_size);
    str[filestat.st_size] = '\0';
    return (str);
}

void display(char *map, char *map_base, int key, int len)
{
    int pos_P = my_pos_p(map);

    switch (key) {
    case KEY_UP:
        up(map, len, pos_P);
        up_o(map, map_base, len, pos_P);
        break;
    case KEY_DOWN:
        down(map, len, pos_P);
        down_o(map, map_base, len, pos_P);
        break;
    case KEY_LEFT:
        left(map, pos_P);
        left_o(map, map_base, pos_P);
        break;
    case KEY_RIGHT:
        right(map, pos_P);
        right_o(map, map_base, pos_P);
        break;
    }
}

void usage(void)
{
    write(1, "USAGE\n", 6);
    write(1, "   ./my_sokoban map\n", 19);
    write(1, "DESCRIPTION\n", 12);
    write(1, "   map file representing the warehouse map,", 42);
    write(1, " containing '#' for wall,\n", 26);
    write(1, "       'P' for the players, 'X'for boxes", 39);
    write(1, " and 'O' for storage locations.\n", 32);
}

int init(char *map, int len, int key, int res)
{
    char *map_base = malloc(sizeof(char) * (lenmax(map) + 1));

    verify_malloc(map_base, map);
    initscr();
    keypad(stdscr, true);
    while (1) {
        clear();
        printw(map);
        key = getch();
        if (COLS < len)
            mvprintw(LINES / 2, (COLS - 14) / 2, "size too small");
        else if (key == ' ')
            reboot(map, map_base);
        else
            display(map, map_base, key, len);
        res = win_or_lose(map, map_base);
        if (key == 'q' || res == 1 || res == 2)
            break;
    }
    endwin();
    return (res);
}

int main(int ac, char **av)
{
    char *map;
    int len = 0;
    int key = 0;
    int res = 0;

    (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') ? usage() : 0;
    if (ac != 2) {
        write(1, "Invalid argument\n", 18);
        return (84);
    } else if (ac == 2) {
        map = read_map(av[1]);
        len = my_strlen(map) + 1;
        res = verify_map(map);
        if (res == 1 || res == 2) {
            free_all(map);
            return (84);
        } else
            res = init(map, len, key, res);
    }
    final_display(res);
    return (0);
}
