/*
** EPITECH PROJECT, 2022
** CPOOL FUNCTION
** File description:
** my_putchar
*/

#include "../Include/my.h"


void my_putchar(char c)
{
    write(1, &c, 1);
}
