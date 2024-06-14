/*
** EPITECH PROJECT, 2024
** Project
** File description:
** epichess.h
*/

#ifndef EPICHESS_EPICHESS_H
    #define EPICHESS_EPICHESS_H

    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <math.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <math.h>

typedef struct WINDOW {
    sfRenderWindow *wind;
    sfEvent event;
} window_t;

typedef struct chess_board_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfUint8 *pixel_array;
} chess_board_t;

typedef struct display_board_s {
    sfSprite *sprite;
    sfIntRect rect;
    char type;
} display_board_t;


typedef struct main_s {
    char turn;
    sfVector2i click;
    sfTexture *pawn_texture;
    char **map;
    display_board_t **display_map;
    window_t *window;
    chess_board_t *board;
} main_t;

void free_array(char **str_array);
char **init_map(void);
chess_board_t *init_chess_board(sfColor *color_dark, sfColor *color_clear);
window_t *init_window(void);
sfColor *init_color(int r, int g, int b);
main_t *init_main(sfColor *dark_color, sfColor *clear_color);
void free_all(main_t *main, sfColor *clear, sfColor *dark);
void display_game(main_t *main);
void display_start_page(main_t *main);
sfTexture *init_pieces_sprite(sfColor *dark_color, sfColor *clear_color);
display_board_t **init_display_map(char **map, sfTexture *pawn_texture);
void manage_mouv(main_t *main);
sfVector2i get_click(main_t *main);
void update_map(main_t *main);
int is_mouv_okay(main_t *main, sfVector2i block);
int who_win(main_t *main);
int my_getnbr(char const *str);

#endif //EPICHESS_EPICHESS_H
