/*
** EPITECH PROJECT, 2024
** Project
** File description:
** init_window.c
*/
#include "../include/epichess.h"

static sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};

    return (sfRenderWindow_create(mode, "Epichess", sfResize | sfClose, NULL));
}

window_t *init_window(void)
{
    window_t *window = malloc(sizeof(window_t));

    window->wind = create_window();
    return window;
}
