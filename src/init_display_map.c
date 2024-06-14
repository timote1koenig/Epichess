/*
** EPITECH PROJECT, 2024
** Project
** File description:
** init_display_map.c
*/
#include "../include/epichess.h"

sfIntRect set_rect(char pawn)
{
    sfIntRect rect = {0, 0, 75, 100};

    if (pawn > 'Z')
        rect.top = 100;
    if (pawn == 'R' || pawn == 'r')
        rect.left = 0;
    if (pawn == 'H' || pawn == 'h')
        rect.left = 300;
    if (pawn == 'B' || pawn == 'b')
        rect.left = 75;
    if (pawn == 'Q' || pawn == 'q')
        rect.left = 150;
    if (pawn == 'K' || pawn == 'k')
        rect.left = 225;
    if (pawn == 'P' || pawn == 'p')
        rect.left = 375;
    return rect;
}

sfSprite *init_sprite(sfTexture *pawn_texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, pawn_texture, sfFalse);
    return sprite;
}

display_board_t **set_display_map(char **map, sfTexture *pawn_texture,
                                  display_board_t **display_map)
{
    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j ++) {
            display_map[i][j].type = map[i][j];
            display_map[i][j].sprite = init_sprite(pawn_texture);
            display_map[i][j].rect = set_rect(map[i][j]);
            sfSprite_setTextureRect(display_map[i][j].sprite,
                display_map[i][j].rect);
        }
    }
    return display_map;
}

display_board_t **init_display_map(char **map, sfTexture *pawn_texture)
{
    display_board_t **display_map = malloc(sizeof(display_board_t *) * 8);

    for (int i = 0; i < 8; i ++) {
        display_map[i] = malloc(sizeof(display_board_t) * 8);
    }
    display_map = set_display_map(map, pawn_texture, display_map);
    return display_map;
}

void update_map(main_t *main)
{
    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j ++) {
            main->display_map[i][j].type = main->map[i][j];
            main->display_map[i][j].rect = set_rect(main->map[i][j]);
            sfSprite_setTextureRect(main->display_map[i][j].sprite,
                main->display_map[i][j].rect);
        }
    }
}
