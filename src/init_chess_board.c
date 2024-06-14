/*
** EPITECH PROJECT, 2024
** Project
** File description:
** init_pixel_array.c
*/
#include "../include/epichess.h"

#include <SFML/Graphics.h>

static sfUint8 *init_color_square(sfUint8 *board, int *indice, sfColor *color)
{
    int limit = *indice + 440;

    for (int i = *indice; i < limit; i += 4) {
        board[i] = color->r;
        board[i + 1] = color->g;
        board[i + 2] = color->b;
        board[i + 3] = color->a;
        *indice += 4;
    }
    return board;
}

sfUint8 *init_line(sfUint8 *board, int *indice, sfColor *color_1,
    sfColor *color_2)
{
    for (int i = 0; i < 8; i++) {
        board = init_color_square(board, indice,
            (i % 2 == 0) ? color_1 : color_2);
    }
    return board;
}

sfUint8 *init_color_of_board(sfUint8 *board, sfColor *color_dark,
    sfColor *color_clear)
{
    int indice = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; i % 2 == 0 && j < 110; j++) {
            init_line(board, &indice, color_dark, color_clear);
        }
        for (int k = 0; i % 2 != 0 && k < 110; k++) {
            init_line(board, &indice, color_clear, color_dark);
        }
    }
    return board;
}

chess_board_t *init_chess_board(sfColor *color_dark, sfColor *color_clear)
{
    chess_board_t *board = malloc(sizeof(chess_board_t));
    int width = 880;
    int height = 880;
    sfVector2f position = {300, 50};

    board->texture = sfTexture_create(width, height);
    board->pixel_array = malloc(sizeof(sfUint8) * (width * height * 4));
    board->sprite = sfSprite_create();
    board->pixel_array = init_color_of_board(board->pixel_array,
        color_dark, color_clear);
    sfTexture_updateFromPixels(board->texture, board->pixel_array, width,
        height, 0, 0);
    sfSprite_setTexture(board->sprite, board->texture, sfTrue);
    sfSprite_setPosition(board->sprite, position);
    return board;
}
