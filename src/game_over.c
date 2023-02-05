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

    all->objs[11] = malloc(sizeof(object_t));
    all->objs[11]->texture = texture;
    all->objs[11]->sprite = sprite;
    all->objs[11]->scale.x = 1;
    all->objs[11]->scale.y = 1;
    all->objs[11]->pos.x = 0;
    all->objs[11]->pos.y = 0;
    sfSprite_setTexture(all->objs[11]->sprite, all->objs[11]->texture, sfTrue);
    sfSprite_setScale(all->objs[11]->sprite, all->objs[11]->scale);
    sfSprite_setPosition(all->objs[11]->sprite, all->objs[11]->pos);
}

void main_menu_button(game_t *all)
{
    sfTexture *texture = sfTexture_createFromFile("ressources/sprites/menu/menu_back.png", NULL);
    sfTexture *texture5 = sfTexture_createFromFile("ressources/sprites/menu/menu_back2.png", NULL);

    sfSprite *sprite = sfSprite_create();

    all->objs[13] = malloc(sizeof(object_t));
    all->objs[13]->texture = texture;
    all->objs[13]->texture_hover3 = texture5;
    all->objs[13]->sprite = sprite;
    all->objs[13]->scale.x = 1;
    all->objs[13]->scale.y = 1;
    all->objs[13]->pos.x = 105;
    all->objs[13]->pos.y = 560;
    sfSprite_setTexture(all->objs[13]->sprite, all->objs[13]->texture, sfTrue);
    sfSprite_setScale(all->objs[13]->sprite, all->objs[13]->scale);
    sfSprite_setPosition(all->objs[13]->sprite, all->objs[13]->pos);
}

void handle_menu_button_hover(game_t *all)
{
    sfFloatRect menu_button_bound = sfSprite_getGlobalBounds(all->objs[13]->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->params.window);
    sfVector2f mouse_pos_f = {(float) mouse_pos.x, (float) mouse_pos.y};

    if (sfFloatRect_contains(&menu_button_bound, mouse_pos_f.x, mouse_pos_f.y))
    {
        all->objs[13]->hover3 = true;
        sfSprite_setTexture(all->objs[13]->sprite, all->objs[13]->texture_hover3, sfTrue);
    }
    else
    {
        all->objs[13]->hover3 = false;
        sfSprite_setTexture(all->objs[13]->sprite, all->objs[13]->texture, sfTrue);
    }
}

void quit_button(game_t *all)
{
    sfTexture *texture6 = sfTexture_createFromFile("ressources/sprites/menu/quit.png", NULL);
    sfTexture *texture7 = sfTexture_createFromFile("ressources/sprites/menu/quit2.png", NULL);

    sfSprite *sprite = sfSprite_create();

    all->objs[12] = malloc(sizeof(object_t));
    all->objs[12]->texture = texture6;
    all->objs[12]->texture_hover2 = texture7;
    all->objs[12]->sprite = sprite;
    all->objs[12]->scale.x = 1;
    all->objs[12]->scale.y = 1;
    all->objs[12]->pos.x = 1140;
    all->objs[12]->pos.y = 560;
    sfSprite_setTexture(all->objs[12]->sprite, all->objs[12]->texture, sfTrue);
    sfSprite_setScale(all->objs[12]->sprite, all->objs[12]->scale);
    sfSprite_setPosition(all->objs[12]->sprite, all->objs[12]->pos);
}

void handle_quit_button_hover(game_t *all)
{
    sfFloatRect quit_button_bounds = sfSprite_getGlobalBounds(all->objs[12]->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->params.window);
    sfVector2f mouse_pos_f = {(float) mouse_pos.x, (float) mouse_pos.y};

    if (sfFloatRect_contains(&quit_button_bounds, mouse_pos_f.x, mouse_pos_f.y))
    {
        all->objs[12]->hover2 = true;
        sfSprite_setTexture(all->objs[12]->sprite, all->objs[12]->texture_hover2, sfTrue);
    }
    else
    {
        all->objs[12]->hover2 = false;
        sfSprite_setTexture(all->objs[12]->sprite, all->objs[12]->texture, sfTrue);
    }
}

void free_resources(game_t *all)
{
    free(all->objs[0]);
    free(all->objs[1]);
    free(all->objs[2]);
    free(all->objs[3]);
    free(all->objs[4]);
    free(all->objs[5]);
    free(all->objs[6]);
    free(all->objs[7]);
    free(all->objs[8]);
    free(all->objs[9]);
    free(all->objs[10]);
    free(all->objs[11]);
    free(all->objs[12]);
    free(all->objs[13]);
    free(all->objs[14]);
    //free(all->objs[15]);
    printf("la valeur 1 à été libérée\n");
    //free(all->objs);
}

void reset_data(game_t *all)
{
    all->params.vie = 3;
    all->params.j = 3;
}

void restart_program(int ac, char **av, game_t *all)
{
    free_resources(all);
    reset_data(all);
    sfRenderWindow_destroy(all->params.window);
    main(ac, av);
}

void menu_back(int ac, char **av, game_t *all, sfEvent event)
{
    if (event.mouseButton.x >= 100 && event.mouseButton.x <= 825 &&
        event.mouseButton.y >= 560 && event.mouseButton.y <= 860) {
        printf("Going back to main menu !\n");
        restart_program(ac, av, all);
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

void game_over_screen(int ac, char **av, game_t *all)
{
    sfEvent event;
    sfSoundBuffer *soundBuffer = sfSoundBuffer_createFromFile("ressources/sounds/musics/death_song.wav");
    sfSound *sound = sfSound_create();
    sfMusic_destroy(all->objs[9]->music);
    sfSound_setBuffer(sound, soundBuffer);
    sfSound_play(sound);
    while (sfRenderWindow_isOpen(all->params.window)) {
        while (sfRenderWindow_pollEvent(all->params.window, &event)) {
            close_window(all);
            sfRenderWindow_clear(all->params.window, sfBlack);
            sfRenderWindow_drawSprite(all->params.window, all->objs[11]->sprite, NULL);
            sfRenderWindow_drawSprite(all->params.window, all->objs[12]->sprite, NULL);
            sfRenderWindow_drawSprite(all->params.window, all->objs[13]->sprite, NULL);
            sfRenderWindow_display(all->params.window);
            handle_menu_button_hover(all);
            handle_quit_button_hover(all);
            menu_back(ac, av, all, event);
            quit_game(all, event);
        }
    }
}
