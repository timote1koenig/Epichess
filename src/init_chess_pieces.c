/*
** EPITECH PROJECT, 2024
** Project
** File description:
** init_chess_pieces.c
*/
#include "../include/epichess.h"

sfColor change_color(sfColor origin, sfColor *black_color,
    sfColor *clear_color)
{
    if (origin.r == 255 && origin.g == 255 && origin.b == 255 &&
        origin.a == 255)
        return *clear_color;
    if (origin.r == 0 && origin.g == 0 && origin.b == 0 &&
        origin.a == 255)
        return *black_color;
    return origin;
}

sfTexture *init_pieces_sprite(sfColor *dark_color, sfColor *clear_color)
{
    sfImage* pawn_image = sfImage_createFromFile("pieces.png");
    int width = sfImage_getSize(pawn_image).x;
    int height = sfImage_getSize(pawn_image).y;
    sfTexture *texture;

    for (int y = 0; y < height; y ++) {
        for (int x = 0; x < width; x ++) {
            sfImage_setPixel(pawn_image, x, y,
                change_color(sfImage_getPixel(pawn_image, x, y)
                , dark_color, clear_color));
        }
    }
    sfImage_saveToFile(pawn_image, "colored_pawn.png");
    sfImage_destroy(pawn_image);
    texture = sfTexture_createFromFile("colored_pawn.png", NULL);
    return texture;
}
