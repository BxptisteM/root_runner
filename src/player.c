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
    sfIntRectre

    all->objs[6] = malloc(sizeof(object_t));
    all->objs[6]->texture = texture6;
    all->objs[6]->sprite = sprite6;
    all->objs[6]->scale.x = 1.7;
    all->objs[6]->scale.y = 1.7;
    all->objs[6]->pos.x = 400;
    all->objs[6]->pos.y = 850;
    sfSprite_setTexture(all->objs[6]->sprite, all->objs[6]->texture, sfTrue);
    sfSprite_setScale(all->objs[6]->sprite, all->objs[6]->scale);
    sfSprite_setPosition(all->objs[6]->sprite, all->objs[6]->pos);

    all.objs[6].sfIntRect{0, 0, 32, 32};
    while (sfRenderWindow_isOpen(window))
    {
        // Gérer les événements
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        rectSourceSprite.left += 32;
        if (rectSourceSprite.left == 256)
            rectSourceSprite.left = 0;
        sfSprite_setTextureRect(sprite6, rectSourceSprite);
    }
    return 0;
}
