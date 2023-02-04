/*
** EPITECH PROJECT, 2023
** @BxptisteM | global game jam
** File description:
** root runner
*/

#include "../includes/my.h"
#include "../includes/struct.h"

void game_over_background(game_t *all)
{
    sfTexture *texture = sfTexture_createFromFile("ressources/sprites/menu/game_over.png", NULL);
    sfSprite *sprite = sfSprite_create();

    all->objs[14] = malloc(sizeof(object_t));
    all->objs[14]->texture = texture;
    all->objs[14]->sprite = sprite;
    all->objs[14]->scale.x = 1;
    all->objs[14]->scale.y = 1;
    all->objs[14]->pos.x = 0;
    all->objs[14]->pos.y = 0;
    sfSprite_setTexture(all->objs[14]->sprite, all->objs[14]->texture, sfTrue);
    sfSprite_setScale(all->objs[14]->sprite, all->objs[14]->scale);
    sfSprite_setPosition(all->objs[14]->sprite, all->objs[14]->pos);
}

void main_menu_button(game_t *all)
{
    sfTexture *texture = sfTexture_createFromFile("ressources/sprites/menu/menu_back.png", NULL);
    sfTexture *texture5 = sfTexture_createFromFile("ressources/sprites/menu/menu_back2.png", NULL);

    sfSprite *sprite = sfSprite_create();

    all->objs[16] = malloc(sizeof(object_t));
    all->objs[16]->texture = texture;
    all->objs[16]->texture_hover3 = texture5;
    all->objs[16]->sprite = sprite;
    all->objs[16]->scale.x = 1;
    all->objs[16]->scale.y = 1;
    all->objs[16]->pos.x = 105;
    all->objs[16]->pos.y = 560;
    sfSprite_setTexture(all->objs[16]->sprite, all->objs[16]->texture, sfTrue);
    sfSprite_setScale(all->objs[16]->sprite, all->objs[16]->scale);
    sfSprite_setPosition(all->objs[16]->sprite, all->objs[16]->pos);
}

void handle_menu_button_hover(game_t *all)
{
    sfFloatRect menu_button_bound = sfSprite_getGlobalBounds(all->objs[16]->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->params.window);
    sfVector2f mouse_pos_f = {(float) mouse_pos.x, (float) mouse_pos.y};

    if (sfFloatRect_contains(&menu_button_bound, mouse_pos_f.x, mouse_pos_f.y))
    {
        all->objs[16]->hover3 = true;
        sfSprite_setTexture(all->objs[16]->sprite, all->objs[16]->texture_hover3, sfTrue);
    }
    else
    {
        all->objs[16]->hover3 = false;
        sfSprite_setTexture(all->objs[16]->sprite, all->objs[16]->texture, sfTrue);
    }
}

void quit_button(game_t *all)
{
    sfTexture *texture6 = sfTexture_createFromFile("ressources/sprites/menu/quit.png", NULL);
    sfTexture *texture7 = sfTexture_createFromFile("ressources/sprites/menu/quit2.png", NULL);

    sfSprite *sprite = sfSprite_create();

    all->objs[15] = malloc(sizeof(object_t));
    all->objs[15]->texture = texture6;
    all->objs[15]->texture_hover2 = texture7;
    all->objs[15]->sprite = sprite;
    all->objs[15]->scale.x = 1;
    all->objs[15]->scale.y = 1;
    all->objs[15]->pos.x = 1140;
    all->objs[15]->pos.y = 560;
    sfSprite_setTexture(all->objs[15]->sprite, all->objs[15]->texture, sfTrue);
    sfSprite_setScale(all->objs[15]->sprite, all->objs[15]->scale);
    sfSprite_setPosition(all->objs[15]->sprite, all->objs[15]->pos);
}

void handle_quit_button_hover(game_t *all)
{
    sfFloatRect quit_button_bounds = sfSprite_getGlobalBounds(all->objs[15]->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->params.window);
    sfVector2f mouse_pos_f = {(float) mouse_pos.x, (float) mouse_pos.y};

    if (sfFloatRect_contains(&quit_button_bounds, mouse_pos_f.x, mouse_pos_f.y))
    {
        all->objs[15]->hover2 = true;
        sfSprite_setTexture(all->objs[15]->sprite, all->objs[15]->texture_hover2, sfTrue);
    }
    else
    {
        all->objs[15]->hover2 = false;
        sfSprite_setTexture(all->objs[15]->sprite, all->objs[15]->texture, sfTrue);
    }
}

void menu_back(game_t *all, sfEvent event)
{
    if (event.mouseButton.x >= 100 && event.mouseButton.x <= 825 &&
        event.mouseButton.y >= 560 && event.mouseButton.y <= 860) {
        printf("Going back to main menu !\n");
        //free(all->objs);
        menu(all);// retour au menu principal
    }
}

void quit_game(game_t *all, sfEvent event)
{
    if (event.mouseButton.x >= 1140 && event.mouseButton.x <= 1820 &&
        event.mouseButton.y >= 560 && event.mouseButton.y <= 820) {
        printf("Exiting\n");
        free(all->objs);
        sfRenderWindow_destroy(all->params.window);
        exit(0);
    }
}

void init_game_over_music(game_t *all)
{
    sfMusic *music = sfMusic_createFromFile("ressources/sounds/musics/menu.wav");
    all->objs[17] = malloc(sizeof(object_t));
    all->objs[17]->music = music;
    sfMusic_play(all->objs[17]->music);
    sfMusic_setLoop(all->objs[17]->music, sfTrue);
}

void game_over_screen(game_t *all)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(all->params.window)) {
        while (sfRenderWindow_pollEvent(all->params.window, &event)) {
            close_window(all);
            sfRenderWindow_clear(all->params.window, sfBlack);
            //boutons ici
            sfRenderWindow_drawSprite(all->params.window, all->objs[14]->sprite, NULL);
            sfRenderWindow_drawSprite(all->params.window, all->objs[15]->sprite, NULL);
            sfRenderWindow_drawSprite(all->params.window, all->objs[16]->sprite, NULL);
            sfRenderWindow_display(all->params.window);
            handle_menu_button_hover(all);
            handle_quit_button_hover(all);
            menu_back(all, event);
            quit_game(all, event);
        }
    }
}
