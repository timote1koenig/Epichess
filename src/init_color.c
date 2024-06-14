/*
** EPITECH PROJECT, 2024
** Project
** File description:
** init_color.c
*/
#include "../include/epichess.h"

sfColor *init_color(int r, int g, int b)
{
    sfColor *temp = malloc(sizeof(sfColor));

    temp->r = r;
    temp->g = g;
    temp->b = b;
    temp->a = 255;
    return temp;
}
