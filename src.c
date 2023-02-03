/*
** EPITECH PROJECT, 2022
** graphic
** File description:
** graphic
*/

#include "./include/my.h"
#include "./include/struct.h"

void game_background(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;

    sfTexture *texture3 = sfTexture_createFromFile("main-menu.png", NULL);
    sfSprite *sprite3 = sfSprite_create();

    sfVector2f scale = {1, 1};
    sfVector2f position = {0, 0};

    sfSprite_setTexture(sprite3, texture3, sfTrue);
    sfSprite_setScale(sprite3, scale);
    sfSprite_setPosition(sprite3, position);
    sfRenderWindow_drawSprite(window, sprite3, NULL);
}

void windows(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfEvent event;

    sfTexture *texture3 = sfTexture_createFromFile("main.png", NULL);
    sfSprite *sprite3 = sfSprite_create();

    sfVector2f scale = {1, 1};
    sfVector2f position = {0, 0};

    sfSprite_setTexture(sprite3, texture3, sfTrue);
    sfSprite_setScale(sprite3, scale);
    sfSprite_setPosition(sprite3, position);

    window = sfRenderWindow_create(mode, "My_Hunter", sfResize | sfClose, NULL);

    while (sfRenderWindow_isOpen(window)) {
        (sfRenderWindow_pollEvent(window, &event));
            if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            }
            sfRenderWindow_display(window);
            printf("c'est ouvert chacal\n");
    sfRenderWindow_drawSprite(window, sprite3, NULL);

    }

}

int main(void)
{
    windows();
    return 0;
}
