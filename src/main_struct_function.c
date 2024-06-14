/*
** EPITECH PROJECT, 2024
** Project
** File description:
** manage_main_struct.c
*/
#include "../include/epichess.h"

main_t *init_main(sfColor *dark_color, sfColor *clear_color)
{
    main_t *main = malloc(sizeof(main_t));

    main->pawn_texture = init_pieces_sprite(dark_color, clear_color);
    main->board = init_chess_board(dark_color, clear_color);
    main->window = init_window();
    main->map = init_map();
    main->turn = 'a';
    main->display_map = init_display_map(main->map, main->pawn_texture);
    main->click.y = -1;
    main->click.x = -1;
    return main;
}

void free_display_board(display_board_t **display_map)
{
    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j ++) {
            sfSprite_destroy(display_map[i][j].sprite);
        }
        free(display_map[i]);

    }
    free(display_map);
}

void free_window(window_t *window)
{
    sfRenderWindow_destroy(window->wind);
    free(window);
}

void free_all(main_t *main, sfColor *clear, sfColor *dark)
{
    free(clear);
    free(dark);
    free_display_board(main->display_map);
    free_window(main->window);
    free(main->board->pixel_array);
    sfSprite_destroy(main->board->sprite);
    sfTexture_destroy(main->board->texture);
    sfTexture_destroy(main->pawn_texture);
    free_array(main->map);
    free(main->board);
    free(main);
}

