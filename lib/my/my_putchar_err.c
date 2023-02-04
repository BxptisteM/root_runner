/*
** EPITECH PROJECT, 2022
** B-CPE-100-NAN-1-1-cpoolday07-baptiste.moreau
** File description:
** Lib
*/

#include <unistd.h>

int my_putchar_err(char c)
{
        write (2, &c, 1);
        return (0);
}
