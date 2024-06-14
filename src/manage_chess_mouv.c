/*
** EPITECH PROJECT, 2024
** Project
** File description:
** manage_chess_mouv.c
*/
#include "../include/epichess.h"

sfVector2i get_case(sfVector2i click)
{
    click.x = ((click.x - 300) / 110);
    click.y = ((click.y - 50) / 110);
    return click;
}

static void end_of_turn(main_t *main)
{
    main->map[main->click.y][main->click.x] = '.';
    update_map(main);
    if (main->turn == 'A')
        main->turn = 'a';
    else
        main->turn = 'A';
}

static void choose_pieces(main_t *main, sfVector2i box) {
    int y = box.y;
    int x = box.x;

    if (main->map[y][x] != '.' &&
        (main->map[y][x] >= main->turn &&
         main->map[y][x] <= main->turn + 25)) {
        main->click = box;
    }
}

static void choose_dest(main_t *main, sfVector2i box)
{
    int y = box.y;
    int x = box.x;

    if ((main->map[y][x] < main->turn ||
        main->map[y][x] > main->turn + 25)) {
        if (is_mouv_okay(main, box) == 0) {
            main->map[y][x] = main->map[main->click.y][main->click.x];
            end_of_turn(main);
        }
    }
    main->click.x = -1;
    main->click.y = -1;
}

void manage_mouv(main_t *main)
{
    sfVector2i click = get_click(main);
    sfVector2i box;

    if (click.x > 300 && click.x < 1210 && click.y > 50 && click.y < 930)
        box = get_case(click);
    else
        return;
    if (main->click.y == -1 && main->click.x == -1)
        choose_pieces(main, box);
    else
        choose_dest(main, box);
}
