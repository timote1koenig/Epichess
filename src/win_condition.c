/*
** EPITECH PROJECT, 2024
** Project
** File description:
** win_condition.c
*/

#include "../include/epichess.h"
#include <stdio.h>

int who_win(main_t *main)
{
    int k = 0;
    int K = 0;

    for (int y = 0; y < 8; y ++) {
        for (int x = 0; x < 8; x ++) {
            if (main->map[y][x] == 'k')
                k += 1;
            if (main->map[y][x] == 'K')
                K += 1;
        }
    }
    if (K == 1 && k != 1) {
        printf("Player 2 win\n");
        return 1;
    }
    if (k == 1 && K != 1) {
        printf("Player 1 win\n");
        return 1;
    }
    return 0;
}
