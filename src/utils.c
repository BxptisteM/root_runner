/*
** EPITECH PROJECT, 2023
** @BxptisteM | global game jam
** File description:
** root runner
*/

#include "../includes/my.h"
#include "../includes/struct.h"

int ac_errors(int ac, char **av)
{
    // if (ac > 1){
    //     my_putstr_err("Too many arguments.");
    //     return (84);
    // }
    // if (av[1] != "-h") {
    //     my_putstr_err("Bad arguments");
    //     return (84);
    // }
    // return (0);
}

int root_runner_help(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        printf("LORE:\n\tRoot Runner is a runner where you embody a knight who must reach his castle to defend it against an attack of roots.\nYou must defeat your enemies on the way !\n");
        printf("GAMEPLAY:\n\tuse the spacebar to jump.\n\tuse the 'R' key to attack\n");
        printf("CREDITS:\n\t@Bxptiste#0666(DEV)\n\t@NoXe#7330 (DEV)\n\t@Calvi_kulle#8852 (DEV)\n\t@Paulnofake#5008 (DEV)\n\t@Lil Nosh#9100 (SOUNDS)\n\t@Cheesecake 🍰#0666 (VISUALS)\n");
    }
    return (0);
}

void close_window(game_t *all)
{
    sfEvent event;

    if (event.type == sfEvtClosed) {
    sfRenderWindow_close(all->params.window);
    }
}
