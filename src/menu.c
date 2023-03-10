/*
** EPITECH PROJECT, 2023
** @BxptisteM |global game jam
** File description:
** root runner
*/

#include "../includes/my.h"
#include "../includes/struct.h"

void init_music(game_t *all)
{
    sfMusic *music = sfMusic_createFromFile("ressources/sounds/musics/menu.wav");
    all->objs[2] = malloc(sizeof(object_t));
    all->objs[2]->music = music;
    sfMusic_play(all->objs[2]->music);
    sfMusic_setLoop(all->objs[2]->music, sfTrue);
}

void create_background(game_t *all)
{
    sfTexture *texture = sfTexture_createFromFile("ressources/sprites/menu/main_menu.png", NULL);
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
    sfTexture *texture1 = sfTexture_createFromFile("ressources/sprites/menu/start.png", NULL);
    sfTexture *texture5 = sfTexture_createFromFile("ressources/sprites/menu/start2.png", NULL);
    sfSprite *sprite = sfSprite_create();

    all->objs[1] = malloc(sizeof(object_t));
    all->objs[1]->texture = texture1;
    all->objs[1]->texture_hover = texture5;
    all->objs[1]->sprite = sprite;
    all->objs[1]->scale.x = 1;
    all->objs[1]->scale.y = 1;
    all->objs[1]->pos.x = 580;
    all->objs[1]->pos.y = 440;
    all->objs[1]->hover = false;
    sfSprite_setTexture(all->objs[1]->sprite, all->objs[1]->texture, sfTrue);
    sfSprite_setScale(all->objs[1]->sprite, all->objs[1]->scale);
    sfSprite_setPosition(all->objs[1]->sprite, all->objs[1]->pos);
}

void handle_start_button_hover(game_t *all)
{
    sfFloatRect start_button_bounds = sfSprite_getGlobalBounds(all->objs[1]->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->params.window);
    sfVector2f mouse_pos_f = {(float) mouse_pos.x, (float) mouse_pos.y};

    if (sfFloatRect_contains(&start_button_bounds, mouse_pos_f.x, mouse_pos_f.y))
    {
        all->objs[1]->hover = true;
        sfSprite_setTexture(all->objs[1]->sprite, all->objs[1]->texture_hover, sfTrue);
    }
    else
    {
        all->objs[1]->hover = false;
        sfSprite_setTexture(all->objs[1]->sprite, all->objs[1]->texture, sfTrue);
    }
}

void create_objects(game_t *all)
{
    all->objs = malloc(sizeof(object_t *) * (14 + 1));
    create_background(all);
    create_start_button(all);
    game_background(all);
    game_background2(all);
    game_target(all);
    health(all);
    health2(all);
    health3(all);
    player(all);
    game_over_background(all);
    main_menu_button(all);
    quit_button(all);
}

int start(game_t *all)
{
    create_window(all);
    create_objects(all);

    return (0);
}

void start_button(int ac, char **av, game_t *all, sfEvent event)
{
    if (event.mouseButton.x >= 580 && event.mouseButton.x <= 1330 &&
        event.mouseButton.y >= 450 && event.mouseButton.y <= 690) {
        sfSoundBuffer *soundBuffer = sfSoundBuffer_createFromFile("ressources/sounds/effects/SFX_6.wav");
        sfSound *sound = sfSound_create();
        sfSound_setBuffer(sound, soundBuffer);
        sfSound_play(sound);
        sfMusic_destroy(all->objs[2]->music);
        game_window_manager(ac, av, all);
    }
}

void menu(int ac, char **av, game_t *all)
{
    sfEvent event;
    init_music(all);
    while (sfRenderWindow_isOpen(all->params.window)) {
        while (sfRenderWindow_pollEvent(all->params.window, &event)) {
            close_window(all);
            sfRenderWindow_clear(all->params.window, sfBlack);
            start_button(ac, av, all, event);
            sfRenderWindow_drawSprite(all->params.window, all->objs[0]->sprite, NULL);
            sfRenderWindow_drawSprite(all->params.window, all->objs[1]->sprite, NULL);
            sfRenderWindow_display(all->params.window);
            handle_start_button_hover(all);
        }
    }
}
