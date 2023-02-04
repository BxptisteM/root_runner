/*
** EPITECH PROJECT, 2022
** @BxptisteM | in game fct
** File description:
** in_game.c
*/

#include "../includes/my.h"
#include "../includes/struct.h"
#include <stdlib.h>

void init_music(game_t *all)
{
    //sfMusic *music = sfMusic_createFromFile("ressources/sounds/musics/Relapse21_-_SNES.wav"); //chill
    sfMusic *music = sfMusic_createFromFile("ressources/sounds/musics/Relapse21-SNES-2.wav"); //combat
    all->objs[2] = malloc(sizeof(object_t));
    all->objs[2]->music = music;
    sfMusic_play(all->objs[2]->music);
    sfMusic_setLoop(all->objs[2]->music, sfTrue);
}

void game_background(game_t *all)
{
    sfTexture *texture3 = sfTexture_createFromFile("ressources/sprites/backgrounds/BG.png", NULL);
    sfSprite *sprite3 = sfSprite_create();

    all->objs[3] = malloc(sizeof(object_t));
    all->objs[3]->texture = texture3;
    all->objs[3]->sprite = sprite3;
    all->objs[3]->scale.x = 1;
    all->objs[3]->scale.y = 1;
    all->objs[3]->pos.x = 0;
    all->objs[3]->pos.y = 0;
    sfSprite_setTexture(all->objs[3]->sprite, all->objs[3]->texture, sfTrue);
    sfSprite_setScale(all->objs[3]->sprite, all->objs[3]->scale);
    sfSprite_setPosition(all->objs[3]->sprite, all->objs[3]->pos);
}
void game_target(game_t *all)
{
    sfTexture *texture4 = sfTexture_createFromFile("ressources/sprites/hostiles/arbre1.png", NULL);
    sfSprite *sprite4 = sfSprite_create();

    int j = 0;
    const int min = 80, max = 900;
    srand(time(NULL));
    j = (rand() % (max + 1 - min)) + min;

    all->objs[4] = malloc(sizeof(object_t));
    all->objs[4]->texture = texture4;
    all->objs[4]->sprite = sprite4;
    all->objs[4]->scale.x = 1;
    all->objs[4]->scale.y = 1;
    all->objs[4]->pos.x = 0;
    all->objs[4]->pos.y = j;
    sfSprite_setTexture(all->objs[4]->sprite, all->objs[4]->texture, sfTrue);
    sfSprite_setTextureRect(all->objs[4]->sprite, (sfIntRect){0, 0, 250, 250});
    sfSprite_setScale(all->objs[4]->sprite, all->objs[4]->scale);
    sfSprite_setPosition(all->objs[4]->sprite, all->objs[4]->pos);
}

void game_window_manager(game_t *all)
{
    sfEvent event;
    sfSprite *target = all->objs[4]->sprite;
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;

    while (sfRenderWindow_isOpen(all->params.window)) {
        while (sfRenderWindow_pollEvent(all->params.window, &event)) {
            close_window(all);
        }

        sfRenderWindow_clear(all->params.window, sfBlack);
        sfRenderWindow_drawSprite(all->params.window, all->objs[3]->sprite, NULL);
        time = sfClock_getElapsedTime(clock);

        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.1) {
            sfSprite_move(target, (sfVector2f){12, 0});
            sfClock_restart(clock);
        }
        sfRenderWindow_drawSprite(all->params.window, target, NULL);
        sfRenderWindow_display(all->params.window);
    }
}
