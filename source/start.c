/*
** EPITECH PROJECT, 2022
** open_window
** File description:
** SFML bs
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>

void create_window(game_t *all)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920,1080, 32};

    window = sfRenderWindow_create (video_mode, "hunt", sfDefaultStyle, NULL);
    all->params.mode.width = 1920;
    all->params.mode.height = 1080;
    all->params.mode.bitsPerPixel = 32;
    all->params.window = window;
}

void create_background(game_t *all)
{
    sfTexture *texture = sfTexture_createFromFile("pictures/main_menu.png", NULL);
    sfSprite *sprite = sfSprite_create();

    all->objs[0] = malloc(sizeof(object_t));
    all->objs[0]->texture = texture;
    all->objs[0]->sprite = sprite;
    all->objs[0]->scale.x = 1;
    all->objs[0]->scale.y = 1;
    all->objs[0]->pos.x = 0;
    all->objs[0]->pos.y = 0;
    sfSprite_setTexture(all->objs[0]->sprite, all->objs[0]->texture, sfTrue);
    sfSprite_setScale(all->objs[0]->sprite, all->objs[0]->scale);
    sfSprite_setPosition(all->objs[0]->sprite, all->objs[0]->pos);
}

void create_start_button(game_t *all)
{
    sfTexture *texture2 = sfTexture_createFromFile("pictures/p.png", NULL);
    sfSprite *sprite2 = sfSprite_create();

    all->objs[1] = malloc(sizeof(object_t));
    all->objs[1]->texture = texture2;
    all->objs[1]->sprite = sprite2;
    all->objs[1]->scale.x = 1;
    all->objs[1]->scale.y = 1;
    all->objs[1]->pos.x = 580;
    all->objs[1]->pos.y = 440;
    sfSprite_setTexture(all->objs[1]->sprite, all->objs[1]->texture, sfTrue);
    sfSprite_setScale(all->objs[1]->sprite, all->objs[1]->scale);
    sfSprite_setPosition(all->objs[1]->sprite, all->objs[1]->pos);
}

void create_objects(game_t *all)
{
    all->objs = malloc(sizeof(object_t *) * (6 + 1));
    create_background(all);
    create_start_button(all);
    game_background(all);
    game_target(all);
}

int start(game_t *all)
{
    create_window(all);
    create_objects(all);

    return (0);
}
