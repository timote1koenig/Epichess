/*
** EPITECH PROJECT, 2024
** Project
** File description:
** map_creation.c
*/
#include "../include/epichess.h"
#include <stdlib.h>

void free_array(char **str_array)
{
    for (int i = 0; i < 9; i ++) {
        free(str_array[i]);
    }
    free(str_array);
}

char **set_pieces(char **map)
{
    char *back = "RHBQKBHR";
    char *front = "PPPPPPPP";
    char *back_2 = "rhbqkbhr";
    char *front_2 = "pppppppp";

    for (int i = 0; i < 8; i ++) {
        map[0][i] = back[i];
        map[7][i] = back_2[i];
        map[1][i] = front[i];
        map[6][i] = front_2[i];
        map[2][i] = '.';
        map[3][i] = '.';
        map[4][i] = '.';
        map[5][i] = '.';
    }
    for (int i = 0; i < 8; i ++) {
        map[i][8] = '\0';
    }
    return map;
}

char **init_map(void)
{
    char **map = malloc(sizeof(char *) * 9);

    for (int i = 0; i < 9; i ++) {
        map[i] = malloc(sizeof(char) * 9);
    }
    map = set_pieces(map);
    return map;
}
