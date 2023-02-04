/*
** EPITECH PROJECT, 2022
** @BxptisteM | struct.h
** File description:
** strcuture for my_hunter.c
*/

#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <stdbool.h>

#ifndef __game
    #define __game
typedef struct params_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfIntRect rect;
    int x_move;
} params_t;

typedef struct object_s {
    sfTexture *texture;
    sfTexture *texture_hover;
    sfTexture *texture_hover2;
    sfTexture *texture_hover3;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfMusic *music;
    bool hover;
    bool hover2;
    bool hover3;

} object_t;

typedef struct game_s {
    params_t params;
    object_t **objs;
} game_t;
#endif
