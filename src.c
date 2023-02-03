/*
** EPITECH PROJECT, 2022
** graphic
** File description:
** graphic
*/

#include "./Include/my.h"

void windows(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfEvent event;

    window = sfRenderWindow_create(mode, "My_Hunter", sfResize | sfClose, NULL);

    while (sfRenderWindow_isOpen(window)) {
        (sfRenderWindow_pollEvent(window, &event));
            if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            }
            sfRenderWindow_display(window);
    }

}

int main(void)
{
    windows();
    return 0;
}
