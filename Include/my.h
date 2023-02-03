/*
** EPITECH PROJECT, 2022
** my
** File description:
** my
*/

#ifndef MY_H
    #define MY_H
    #include <SFML/Window.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/Sound.h>
    #include <stdlib.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <stdio.h>
    #include <unistd.h>

    //My Lib
    int my_putchar(char c);
    int my_isneg(int nb);
    int my_put_nbr(int nb);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_getnbr(char const *str);
    char *my_strcpy(char *dest, char const *src);
    int my_printf(const char *format, ...);

    void main_menu(sfRenderWindow* window);
#endif
