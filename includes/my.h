/*
** EPITECH PROJECT, 2022
** @BxptisteM | my.h
** File description:
** my.h | my_hunter.c
*/

#include "struct.h"
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/System/Time.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef my_hunter
    #define my_hunter
void target_move(game_t *all);
int my_putchar_err(char c);
int my_putchar(char c);
void my_putstr_err(char const *str);
void my_putstr(char const *str);
void close_window(game_t *all);
void game_window_manager(int ac, char **av, game_t *all);
void game_target(game_t *all);
void game_background(game_t *all);
void init_music(game_t *all);
int start(game_t *ALL);
void menu(int ac, char **av, game_t *ALL);
int ac_errors(int ac, char **av);
void create_window(game_t *all);
int root_runner_help(char **av);
int choice(game_t *all,int ac, char *av[]);
void health(game_t *all);
void health2(game_t *all);
void health3(game_t *all);
void game_over_background(game_t *all);
void game_over_screen(int ac, char **av, game_t *all);
void main_menu_button(game_t *all);
void quit_button(game_t *all);
void game_background2(game_t *all);
int main(int ac, char **av);
void player(game_t *all);
#endif
