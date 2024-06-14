/*
** EPITECH PROJECT, 2024
** Project
** File description:
** test_mouv_pieces.c
*/
#include "../include/epichess.h"

int is_attack_ok(char **map, sfVector2i start, sfVector2i end,char joueur) {
    int deltaX = abs( end.x - start.x);
    int deltaY = abs(end.y - start.y);

    if (deltaX == 1 && deltaY == 1) {
        if (joueur == 'p' && end.y < start.y &&
            map[end.y][end.x] != '.' && map[end.y][end.x] < 'a') {
            return 1;
        }
        if (joueur == 'P' && end.y > start.y &&
            map[end.y][end.x] != '.' && map[end.y][end.x] > 'Z') {
            return 1;
        }
    }
    return 0;
}

static int pawn_mouv(main_t *main, sfVector2i block, char piece)
{
    sfVector2i position = main->click;

    if (piece == 'P' && position.x == block.x) {
        if (block.y - position.y == 1 && main->map[block.y][block.x] == '.')
            return 1;
        if (position.y == 1 && block.y - position.y == 2 &&
            main->map[block.y][block.x] == '.' &&
            main->map[block.y][block.x - 1] == '.')
            return 1;
    }
    if (piece == 'p' && position.x == block.x) {
        if (position.y - block.y == 1 && main->map[block.y][block.x] == '.')
            return 1;
        if (position.y == 6 && position.y - block.y == 2 &&
            main->map[block.y][block.x] == '.' &&
            main->map[block.y][block.x + 1] == '.')
            return 1;
    }
    return is_attack_ok(main->map, position, block, piece);
}

int test_clear_route(sfVector2i start, sfVector2i end, char **map)
{
    int deltaX = (end.x - start.x > 0) ? 1 : ((end.x - start.x < 0) ? -1 : 0);
    int deltaY = (end.y - start.y > 0) ? 1 : ((end.y - start.y < 0) ? -1 : 0);
    int x = start.x + deltaX;
    int y = start.y + deltaY;

    while (x != end.x || y != end.y) {
        if (map[y][x] != '.') {
            return 0;
        }
        x += deltaX;
        y += deltaY;
    }
    return 1;
}

int rook_mouv(main_t *main, sfVector2i block)
{
    sfVector2i position = main->click;

    if ( position.x == block.x || position.y == block.y)
        if (test_clear_route(position, block, main->map) == 1)
            return 1;
    return 0;
}

static int bishop_mouv(main_t *main, sfVector2i block)
{
    sfVector2i position = main->click;

    if (abs(position.x - block.x) == abs(position.y - block.y))
        if (test_clear_route(position, block, main->map) == 1)
            return 1;
    return 0;
}

static int queen_mouv(main_t *main, sfVector2i block)
{
    sfVector2i position = main->click;

    if (position.x == block.x || position.y == block.y ||
        abs(position.x - block.x) == abs(position.y - block.y))
        if (test_clear_route(position, block, main->map) == 1)
            return 1;
    return 0;
}

static int king_mouv(main_t *main, sfVector2i block)
{
    sfVector2i position = main->click;

    if (abs(position.x - block.x) <= 1 && abs(position.y - block.y) <= 1)
        return 1;
    return 0;
}

static int horse_mouv(main_t *main, sfVector2i block)
{
    sfVector2i position = main->click;
    int diff_x = abs(position.x - block.x);
    int diff_y = abs(position.y - block.y);

    if ((diff_x == 1 && diff_y == 2) || (diff_x == 2 && diff_y == 1))
        return 1;
    return 0;
}

int is_mouv_okay(main_t *main, sfVector2i block)
{
    char piece = main->map[main->click.y][main->click.x];
    int result = 0;

    if (piece == 'R' || piece == 'r')
        result += rook_mouv(main, block);
    if (piece == 'Q' || piece == 'q')
        result += queen_mouv(main, block);
    if (piece == 'K' || piece == 'k')
        result += king_mouv(main, block);
    if (piece == 'H' || piece == 'h')
        result += horse_mouv(main, block);
    if (piece == 'B' || piece == 'b')
        result += bishop_mouv(main, block);
    if (piece == 'P' || piece == 'p')
        result += pawn_mouv(main, block, piece);
    if (result != 0)
        return 0;
    return 1;
}

