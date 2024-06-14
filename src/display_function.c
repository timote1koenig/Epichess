/*
** EPITECH PROJECT, 2024
** Project
** File description:
** display_function.c
*/
#include "../include/epichess.h"

void display_pieces(main_t *main, int i, int j)
{
    sfVector2f pose = {(j * 111) + 310,(i * 110) + 67};

    if (main->display_map[i][j].type != '.') {
        sfSprite_setPosition(main->display_map[i][j].sprite, pose);
        sfRenderWindow_drawSprite(main->window->wind,
            main->display_map[i][j].sprite, sfFalse);
    }
}

void display_game(main_t *main)
{
    sfRenderWindow_drawSprite(main->window->wind, main->board->sprite, sfFalse);
    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j ++) {
            display_pieces(main, i, j);
        }
    }
}
