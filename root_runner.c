/*
** EPITECH PROJECT, 2022
** open_window
** File description:
** SFML bs
*/

#include "includes/my.h"
#include "includes/struct.h"

void start_button(game_t *all, sfEvent event)
{
    if (event.mouseButton.x >= 580 && event.mouseButton.x <= 1330 &&
        event.mouseButton.y >= 450 && event.mouseButton.y <= 690) {
        game_window_manager(all);
    }
}

void menu(game_t *all)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(all->params.window)) {
        while (sfRenderWindow_pollEvent(all->params.window, &event)) {
            close_window(all);
            sfRenderWindow_clear(all->params.window, sfBlack);
            start_button(all, event);
    sfRenderWindow_drawSprite(all->params.window, all->objs[0]->sprite, NULL);
    sfRenderWindow_drawSprite(all->params.window, all->objs[1]->sprite, NULL);
            sfRenderWindow_display(all->params.window);
        }
    }
}

int main(int ac, char **av)
{
    if (ac > 2){
        my_putstr_err("Too many arguments.");
    }
    if (av[1] = "-h") {
        my_putstr("Remake of the Duck Hunt video game\n");
    }
    if (ac > 2){
        my_putstr_err("Too many arguments.");
    }
    if (av[1] != "-h") {
        my_putstr_err("Bad arguments");
    }
    if (ac == 1) {
    game_t all;
    init_music(&all);
    start(&all);
    menu(&all);
    return (0);
    }
}
