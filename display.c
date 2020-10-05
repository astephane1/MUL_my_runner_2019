/*
** EPITECH PROJECT, 2019
** repository
** File description:
** runner
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "runner.h"

void choice_color(runner_t *runner);

void change_sprite(runner_t *runner);

int start_p(runner_t *runner, sprite_t *sprite, offset_t *offset, sfEvent event)
{
    runner->menu.pick = 0;
    sfSprite *space = create_sprite(0.34, "assets/space.png", 32, 507);
    sfSprite *start_screen_sprite = start_screen();
    change_sprite(runner);
    while (sfRenderWindow_isOpen(runner->window)) {
        sfRenderWindow_clear(runner->window, sfCyan);
        event_loop(event, runner, sprite, offset);
        sfRenderWindow_drawSprite(runner->window, start_screen_sprite, NULL);
        display_start(runner);
        choice_color(runner);
        sfRenderWindow_drawSprite(runner->window, space, NULL);
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            sfRenderWindow_clear(runner->window, sfCyan);
            return (0);
        }
        sfRenderWindow_display(runner->window);
    }
}

sfSprite *start_screen(void)
{
    sfTexture *back = sfTexture_createFromFile("assets/zelda.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){0, 0});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

void reset_ground(runner_t *runner, sprite_t *sprite)
{
    sfSprite_destroy(sprite->back[15]);
    sfSprite_destroy(sprite->back[14]);
    sprite->back[14] = ground_sprite08(runner, sprite, 0, 0);
    sprite->back[15] = ground_sprite08(runner, sprite, 790, 0);

}
