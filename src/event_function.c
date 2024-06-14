/*
** EPITECH PROJECT, 2024
** Project
** File description:
** event_function.c
*/
#include "../include/epichess.h"

sfVector2i get_click(main_t *main)
{
    sfVector2i click = sfMouse_getPositionRenderWindow(main->window->wind);
    return click;
}
