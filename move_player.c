/*
** EPITECH PROJECT, 2019
** display
** File description:
** runner
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

sfSprite *create_sprite_player(runner_t *runner,
sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile("assets/mega.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){0, 390});
    sfSprite_setScale(sprites, (sfVector2f){3, 3});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

void move_rect_player(sfIntRect *rect)
{
    int big_value = 80;
    int offset = 20;
    if (rect->left < big_value - offset) {
        rect->left += offset;
    }
    else {
        rect->left = 0;
    }
}

void player_move(sfIntRect *rect, runner_t *runner, sprite_t *sprite)
{
    sfSprite_setTextureRect(sprite->player, runner->rect_player);
    sfTime timing;
    float sec = 0;
    timing = sfClock_getElapsedTime(runner->clock);
    sec = timing.microseconds / 50000;

    if (sec / runner->clock_counter >= 3) {
        runner->clock_counter++;
        move_rect_player(rect);
    }
}
