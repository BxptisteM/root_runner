/*
** EPITECH PROJECT, 2023
** @BxptisteM |global game jam
** File description:
** root runner
*/

#include "includes/my.h"
#include "includes/struct.h"

void create_window(game_t *all)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920,1080, 32};

    window = sfRenderWindow_create (video_mode, "root_runner", sfDefaultStyle, NULL);
    all->params.mode.width = 1920;
    all->params.mode.height = 1080;
    all->params.mode.bitsPerPixel = 32;
    all->params.window = window;
}

int main(int ac, char **av)
{
    // if (ac_errors(ac, av) == 84) {
    //     return (84);
    // }
    // root_runner_help(av);
    if (ac == 1) {
    game_t all;
    init_music(&all);
    start(&all);
    menu(&all);
    return (0);
    }
}
