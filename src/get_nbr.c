/*
** EPITECH PROJECT, 2024
** Project
** File description:
** get_nbr.c
*/
#include "../include/epichess.h"

int my_getnbr(char const *str)
{
    int i = 0;
    long result = 0;

    while (str[i] != '\0'){
        if (str[i] >= '0' && str[i] <= '9'){
            result = (result * 10) + (str[i] - 48);
        }
        i ++;
    }
    return (int)result;
}
