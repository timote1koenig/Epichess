/*
** EPITECH PROJECT, 2024
** Project
** File description:
** main.c
*/
#include "../include/epichess.h"

void help_function(void)
{
    printf("Epichess Manual:\n"
           "This is a classic game who end when a one of the king die!\n"
           "To start the game tou just have to execute the program\n"
           "You can change the color of the board by adding a -c && rgb value"
           " of each player:\n"
           "./Epichess -c 255 0 0 0 0 255\n"
           "for the player one, it's 255 0 0\n"
           "for the player two it's 0 0 255\n"
           "Good game, Have fun!\n");
}

void get_color(char **argv, sfColor *color_dark, sfColor *color_clear)
{
    for (int i = 2; i < 8; i ++) {
        if (argv[i] == NULL)
            return;
        for (int j = 0; argv[i][j] != '\0'; j ++) {
            if (argv[i][j] > '9' || argv[i][j] < '0')
                return;
        }
    }
    color_clear->r = my_getnbr(argv[2]);
    color_clear->g = my_getnbr(argv[3]);
    color_clear->b = my_getnbr(argv[4]);
    color_dark->r = my_getnbr(argv[5]);
    color_dark->g = my_getnbr(argv[6]);
    color_dark->b = my_getnbr(argv[7]);
}

void poll_event(main_t *main)
{
    while (sfRenderWindow_pollEvent(main->window->wind, &main->window->event)) {
        if (main->window->event.type == sfEvtClosed)
            sfRenderWindow_close(main->window->wind);
        if (main->window->event.type == sfEvtMouseButtonPressed)
            manage_mouv(main);
    }
}

int main(int argc, char **argv)
{
    sfColor *color_dark = init_color(0, 0, 0);
    sfColor *color_clear = init_color(255, 255, 255);
    main_t *main;

    if (argc != 1 && strcmp("-h", argv[1]) == 0) {
        help_function();
        return 0;
    }
    if (argc != 1 && strcmp("-c", argv[1]) == 0)
        get_color(argv, color_dark, color_clear);
    main = init_main(color_dark, color_clear);
    while (sfRenderWindow_isOpen(main->window->wind)) {
        sfRenderWindow_clear(main->window->wind, (sfColor){16, 32, 16, 1});
        poll_event(main);
        if (who_win(main) == 1)
            sfRenderWindow_close(main->window->wind);
        display_game(main);
        sfRenderWindow_display(main->window->wind);
    }
    free_all(main, color_clear, color_dark);
    return 0;
}
