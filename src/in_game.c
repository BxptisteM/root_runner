/*
** EPITECH PROJECT, 2022
** @BxptisteM | in game fct
** File description:
** in_game.c
*/

#include "../includes/my.h"
#include "../includes/struct.h"
#include <stdlib.h>

void init_game_music(game_t *all)
{
    sfMusic *music = sfMusic_createFromFile("ressources/sounds/musics/in_game.wav");
    all->objs[11] = malloc(sizeof(object_t));
    all->objs[11]->music = music;
    sfMusic_play(all->objs[11]->music);
    sfMusic_setLoop(all->objs[11]->music, sfTrue);
}

void hit_music(game_t *all)
{
    sfMusic *music = sfMusic_createFromFile("ressources/sounds/effects/hit_song.wav");
    all->objs[19] = malloc(sizeof(object_t));
    all->objs[19]->music = music;
    sfMusic_play(all->objs[19]->music);
    sfMusic_setLoop(all->objs[19]->music, sfTrue);
}

void game_background(game_t *all)
{
    sfTexture *texture3 = sfTexture_createFromFile("ressources/sprites/backgrounds/Background.png", NULL);
    sfSprite *sprite3 = sfSprite_create();

    all->objs[3] = malloc(sizeof(object_t));
    all->objs[3]->texture = texture3;
    all->objs[3]->sprite = sprite3;
    all->objs[3]->scale.x = 1.6;
    all->objs[3]->scale.y = 1;
    all->objs[3]->pos.x = 0;
    all->objs[3]->pos.y = 0;
    sfSprite_setTexture(all->objs[3]->sprite, all->objs[3]->texture, sfTrue);
    sfSprite_setScale(all->objs[3]->sprite, all->objs[3]->scale);
    sfSprite_setPosition(all->objs[3]->sprite, all->objs[3]->pos);
}

void game_background2(game_t *all)
{
    all->params.x_move = 1920;
    sfTexture *texture3 = sfTexture_createFromFile("ressources/sprites/backgrounds/Background.png", NULL);
    sfSprite *sprite3 = sfSprite_create();

    all->objs[13] = malloc(sizeof(object_t));
    all->objs[13]->texture = texture3;
    all->objs[13]->sprite = sprite3;
    all->objs[13]->scale.x = 1.6;
    all->objs[13]->scale.y = 1;
    all->objs[13]->pos.x = all->params.x_move;
    all->objs[13]->pos.y = 0;
    sfSprite_setTexture(all->objs[13]->sprite, all->objs[13]->texture, sfTrue);
    sfSprite_setScale(all->objs[13]->sprite, all->objs[13]->scale);
    sfSprite_setPosition(all->objs[13]->sprite, all->objs[13]->pos);
}

void game_target(game_t *all)
{
    sfTexture *texture4 = sfTexture_createFromFile("ressources/sprites/hostiles/arbre1.png", NULL);
    sfSprite *sprite4 = sfSprite_create();

    int j = 870;
    srand(time(NULL));

    all->objs[4] = malloc(sizeof(object_t));
    all->objs[4]->texture = texture4;
    all->objs[4]->sprite = sprite4;
    all->objs[4]->scale.x = 1;
    all->objs[4]->scale.y = 1;
    all->objs[4]->pos.x = 1900;
    all->objs[4]->pos.y = j;
    sfSprite_setTexture(all->objs[4]->sprite, all->objs[4]->texture, sfTrue);
    sfSprite_setTextureRect(all->objs[4]->sprite, (sfIntRect){0, 0, 250, 250});
    sfSprite_setScale(all->objs[4]->sprite, all->objs[4]->scale);
    sfSprite_setPosition(all->objs[4]->sprite, all->objs[4]->pos);

}

void health(game_t *all)
{
    sfTexture *texture7 = sfTexture_createFromFile("ressources/sprites/ath/heart.png", NULL);
    sfSprite *sprite7 = sfSprite_create();

    all->objs[7] = malloc(sizeof(object_t));
    all->objs[7]->texture = texture7;
    all->objs[7]->sprite = sprite7;
    all->objs[7]->scale.x = 0.4;
    all->objs[7]->scale.y = 0.4;
    all->objs[7]->pos.x = 0;
    all->objs[7]->pos.y = 0;
    sfSprite_setTexture(all->objs[7]->sprite, all->objs[7]->texture, sfTrue);
    sfSprite_setScale(all->objs[7]->sprite, all->objs[7]->scale);
    sfSprite_setPosition(all->objs[7]->sprite, all->objs[7]->pos);
}

void health2(game_t *all)
{
    sfTexture *texture8 = sfTexture_createFromFile("ressources/sprites/ath/heart.png", NULL);
    sfSprite *sprite8 = sfSprite_create();

    all->objs[8] = malloc(sizeof(object_t));
    all->objs[8]->texture = texture8;
    all->objs[8]->sprite = sprite8;
    all->objs[8]->scale.x = 0.4;
    all->objs[8]->scale.y = 0.4;
    all->objs[8]->pos.x = 90;
    all->objs[8]->pos.y = 0;
    sfSprite_setTexture(all->objs[8]->sprite, all->objs[8]->texture, sfTrue);
    sfSprite_setScale(all->objs[8]->sprite, all->objs[8]->scale);
    sfSprite_setPosition(all->objs[8]->sprite, all->objs[8]->pos);
}

void health3(game_t *all)
{
    sfTexture *texture9 = sfTexture_createFromFile("ressources/sprites/ath/heart.png", NULL);
    sfSprite *sprite9 = sfSprite_create();

    all->objs[9] = malloc(sizeof(object_t));
    all->objs[9]->texture = texture9;
    all->objs[9]->sprite = sprite9;
    all->objs[9]->scale.x = 0.4;
    all->objs[9]->scale.y = 0.4;
    all->objs[9]->pos.x = 180;
    all->objs[9]->pos.y = 0;
    sfSprite_setTexture(all->objs[9]->sprite, all->objs[9]->texture, sfTrue);
    sfSprite_setScale(all->objs[9]->sprite, all->objs[9]->scale);
    sfSprite_setPosition(all->objs[9]->sprite, all->objs[9]->pos);
}

void game_window_manager(game_t *all)
{
    int vie = 3;
    float j = 3;
    sfSoundBuffer *soundBuffer = sfSoundBuffer_createFromFile("ressources/sounds/effects/hit_song.wav");
    sfSound *sound = sfSound_create();
    sfEvent event;
    sfTexture *newtexture = sfTexture_createFromFile("ressources/sprites/ath/bad_heart.png", NULL);
    sfSprite *target = all->objs[4]->sprite;
    sfClock *clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(all->params.window, 32);
    sfTime time;
    init_game_music(all);
    while (sfRenderWindow_isOpen(all->params.window)) {
        while (sfRenderWindow_pollEvent(all->params.window, &event)) {
            close_window(all);
        }
        if (all->objs[3]->pos.x != -1920) {
            all->objs[3]->pos.x = all->objs[3]->pos.x - 1;
            sfSprite_setPosition(all->objs[3]->sprite,all->objs[3]->pos);
            if (all->objs[3]->pos.x <= -1920) {
                all->objs[3]->pos.x = 1920;
            }
        }
        if (all->objs[13]->pos.x != -1920) {
            all->objs[13]->pos.x = all->objs[13]->pos.x - 1;
            sfSprite_setPosition(all->objs[13]->sprite,all->objs[13]->pos);
            if (all->objs[13]->pos.x <= -1920) {
                all->objs[13]->pos.x = 1920;
            }
        }
        if (all->objs[4]->pos.x != -20) {
            all->objs[4]->pos.x = all->objs[4]->pos.x - j;
            sfSprite_setPosition(all->objs[4]->sprite,all->objs[4]->pos);
            if (all->objs[4]->pos.x <= 100) {
                all->objs[4]->pos.x = 1900;
                j = j * 1.2;
                if (vie == 1) {
                    all->objs[9]->texture = newtexture;
                    sfSprite_setTexture(all->objs[7]->sprite, newtexture, sfTrue);
                    sfSound_setBuffer(sound, soundBuffer);
                    sfSound_play(sound);
                    vie = vie - 1;
                }
                if (vie == 2) {
                    all->objs[9]->texture = newtexture;
                    sfSprite_setTexture(all->objs[8]->sprite, newtexture, sfTrue);
                    sfSound_setBuffer(sound, soundBuffer);
                    sfSound_play(sound);
                    vie = vie - 1;
                }
                if (vie == 3) {
                    all->objs[9]->texture = newtexture;
                    sfSprite_setTexture(all->objs[9]->sprite, newtexture, sfTrue);
                    sfSound_setBuffer(sound, soundBuffer);
                    sfSound_play(sound);
                    vie = vie - 1;
                }
                }
                if (vie == 0) {
                    game_over_screen(all);
            }
        }
        sfRenderWindow_clear(all->params.window, sfBlack);
        sfRenderWindow_drawSprite(all->params.window, all->objs[3]->sprite, NULL);
        sfRenderWindow_drawSprite(all->params.window, all->objs[13]->sprite, NULL);
        sfRenderWindow_drawSprite(all->params.window, all->objs[7]->sprite, NULL);
        sfRenderWindow_drawSprite(all->params.window, all->objs[8]->sprite, NULL);
        sfRenderWindow_drawSprite(all->params.window, all->objs[9]->sprite, NULL);
        sfRenderWindow_drawSprite(all->params.window, target, NULL);
        sfRenderWindow_display(all->params.window);
    }
}