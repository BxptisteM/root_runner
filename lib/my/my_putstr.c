/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** *str
*/

#include "../../includes/my.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
