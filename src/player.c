/*
** EPITECH PROJECT, 2023
** @BxptisteM |global game jam
** File description:
** root runner
*/

#include "../includes/my.h"
#include "../includes/struct.h"

void player(game_t *all)
{
    sfTexture *texture6 = sfTexture_createFromFile("ressources/sprites/player/knight.png", NULL);
    sfSprite *sprite6 = sfSprite_create();

    all->objs[6] = malloc(sizeof(object_t));
    all->objs[6]->texture = texture6;
    all->objs[6]->sprite = sprite6;
    all->objs[6]->scale.x = 1.6;
    all->objs[6]->scale.y = 1;
    all->objs[6]->pos.x = 0;
    all->objs[6]->pos.y = 0;

    sfRenderWindow_drawSprite(all->params.window, sprite6, NULL);
    sfRenderWindow_display(all->params.window);
}
