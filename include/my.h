/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

char *read_map(char *);
void display(char *, char *, int, int);
void usage(void);
int init(char *, int, int, int);
int main(int , char **);
int my_strlen(char const *);
int my_pos_p(char const *);
int lenmax(char const *);
void up(char *, int, int);
void down(char *, int, int);
void left(char *, int);
void right(char *, int);
void up_o(char *, char *, int, int);
void down_o(char *, char *, int, int);
void left_o(char *, char *, int);
void right_o(char *, char *, int);
char *reboot(char *, char *);
char *verify_malloc(char *, char*);
int lose(char *, char *);
int win_or_lose(char *, char *);
int final_display(int );
int verify_map(char *);
void free_all(char *);

#endif
